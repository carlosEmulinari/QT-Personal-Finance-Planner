#include "investiments.h"
#include "securitylogs.h"
#include "./ui_investiments.h"
#include <QMessageBox>
#include <QSettings>
#include <QDialog>

investiments::investiments(QWidget *parent)
    : QWidget(parent)
    , ui(new Ui::investiments)
{
    ui->setupUi(this);

    QSettings settings("PFPApp", "Investments");
    QString savedValue = settings.value("investedAmount", "").toString();

    if (!savedValue.isEmpty()) {
        ui->lineEditInvest->setText(savedValue);
    }
}

void investiments::openInvestmentsSection()
{
    QString investedText = ui->lineEditInvest->text();
    if (investedText.isEmpty())
        investedText = "0.00";

    // Default if empty
    double investedAmount = investedText.isEmpty() ? 0.0 : investedText.toDouble();

    double returnRate = 0.08;     // 8% return example

    double expectedReturn = investedAmount * returnRate;

    Security::saveInvestment(expectedReturn);

    QString message;
    message += "Amount Invested: $" + QString::number(investedAmount, 'f', 2) + "\n";
    message += "Expected Return (8%): $" + QString::number(expectedReturn, 'f', 2);

    QMessageBox::information(this, "Investment Info", message);

    ui->lineEditInvest->setText(QString::number(Security::loadInvestment()));


    connect(ui->closeButton, &QPushButton::clicked, this, &QWidget::close);

}

investiments::~investiments()
{
    delete ui;
}
