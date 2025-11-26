#include "account.h"
#include "ui_account.h"
#include <QMessageBox>
#include <QDate>


Account::Account(QWidget *parent)
    : QWidget(parent)
    , ui(new Ui::Account)
{
    ui->setupUi(this);
}

void Account::openAccountSection()
{
    QString userName = ui->lineEditUserName->text();
    QString currentDate = QDate::currentDate().toString("dd/MM/yyyy");

    if (userName.isEmpty())
        userName = "Unknown User";

    QString message = "User: " + userName + "\nDate: " + currentDate;

    QMessageBox::information(this, "Account Info", message);
}

Account::~Account()
{
    delete ui;
}
