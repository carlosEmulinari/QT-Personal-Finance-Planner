#include "savings.h"
#include "securitylogs.h"
#include "ui_savings.h"
#include <QMessageBox>
#include <QSettings>
#include <QDialog>

savings::savings(QWidget *parent)
    : QWidget(parent)
    , ui(new Ui::savings)
{
    ui->setupUi(this);

    QSettings settings("PFPApp", "Savings");
    QString savedValue = settings.value("savedAmount", "").toString();

    if (!savedValue.isEmpty()) {
        ui->lineEditSaving->setText(savedValue);
    }

}

void savings::openSavingsSection()
{
    QString value = ui->lineEditSaving->text();

    if (value.isEmpty())
        value = "0.00";

    double savedMoney = value.toDouble();

    // -------- SAVE PERMANENTLY --------
    Security::saveSavings(savedMoney);

    QString message = "Total Saved Money: $" + QString::number(savedMoney, 'f', 2);

    QMessageBox::information(this, "Saving Info", message);

    ui->lineEditSaving->setText(QString::number(Security::loadSavings()));

    connect(ui->closeButton, &QPushButton::clicked, this, &QWidget::close);

}

savings::~savings()
{
    delete ui;
}
