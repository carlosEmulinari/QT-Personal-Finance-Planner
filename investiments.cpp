#include "investiments.h"
#include "ui_investiments.h"
#include <QMessageBox>
#include <QDate>
#include <QSerialPort>
#include <QSerialPortInfo>


Investiments::Investiments(QWidget *parent)
    : QWidget(parent)
    , ui(new Ui::Investiments)
{
    ui->setupUi(this);

    serial = new QSerialPort(this);
    serial->setPortName("COM3");            // Change to your Arduino COM port
    serial->setBaudRate(QSerialPort::Baud9600);

    if (!serial->open(QIODevice::WriteOnly)) {
        QMessageBox::warning(this, "Warning", "Cannot open COM3 for Arduino.");
    }
}

void Investiments::openInvestmentSection()
{
    QString investedText = ui->lineEditInvest->text();

    // Default if empty
    double investedAmount = investedText.isEmpty() ? 0.0 : investedText.toDouble();

    double returnRate = 0.08;     // 8% return example

    double expectedReturn = investedAmount * returnRate;

    QString message;
    message += "Amount Invested: $" + QString::number(investedAmount, 'f', 2) + "\n";
    message += "Expected Return (8%): $" + QString::number(expectedReturn, 'f', 2);

    QMessageBox::information(this, "Investment Info", message);

    if (serial && serial->isOpen())
    {
        // Only send the invested amount (LCD is too small for full report)
        QString command = "INV:" + QString::number(investedAmount, 'f', 2) + "\n";
        serial->write(command.toUtf8());
    }
    else
    {
        QMessageBox::warning(this, "Arduino Error",
                             "Unable to send data.\nArduino is not connected.");
    }
}

Investiments::~Investiments()
{
    if (serial && serial->isOpen())
        serial->close();

    delete ui;
}
