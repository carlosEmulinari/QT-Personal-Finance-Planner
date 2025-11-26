#include "savings.h"
#include "ui_savings.h"
#include <QMessageBox>
#include <QDate>
#include <QSerialPort>
#include <QSerialPortInfo>

Savings::Savings(QWidget *parent)
    : QWidget(parent)
    , ui(new Ui::Savings)
{
    ui->setupUi(this);
    serial = new QSerialPort(this);
    serial->setPortName("COM3");            // Change for your Arduino port
    serial->setBaudRate(QSerialPort::Baud9600);

    if (!serial->open(QIODevice::WriteOnly)) {
        QMessageBox::warning(this, "Warning", "Cannot open COM3 for Arduino.");
    }
}

void Savings::openSavingSection()
{
    QString value = ui->lineEditSaving->text();

    if (value.isEmpty())
        value = "0.00";

    QString message = "Total Saved Money: $" + value;

    QMessageBox::information(this, "Saving Info", message);

    if (serial && serial->isOpen()) {

        QString command = "SAVE:" + value + "\n";
        serial->write(command.toUtf8());

    } else {

        QMessageBox::warning(this, "Arduino Error",
                             "Unable to send data.\nArduino is not connected.");
    }
}

Savings::~Savings()
{
    if (serial && serial->isOpen())
        serial->close();

    delete ui;
}
