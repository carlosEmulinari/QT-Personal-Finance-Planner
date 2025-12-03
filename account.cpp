#include "account.h"
#include "securitylogs.h"
#include "./ui_account.h"
#include <QDate>
#include <QMessageBox>
#include <QSettings>
#include <QDialog>

account::account(QWidget *parent)
    : QWidget(parent)
    , ui(new Ui::account)
{
    ui->setupUi(this);
}

void account::openAccountSection()
{
    QString userName = ui->lineEditUserName->text();
    QString currentDate = QDate::currentDate().toString("dd/MM/yyyy");

    if (userName.isEmpty())
        userName = "Unknown User";

    Security::saveUserName(userName);


    QString message = "User: " + userName + "\nDate: " + currentDate;

    QMessageBox::information(this, "Account Info", message);

    ui->lineEditUserName->setText(Security::loadUserName());


    connect(ui->closeButton, &QPushButton::clicked, this, &QWidget::close);

}

account::~account()
{
    delete ui;
}
