#include "consultant.h"
#include "ui_consultant.h"
#include <QMessageBox>
#include <QDate>

Consultant::Consultant(QWidget *parent)
    : QWidget(parent)
    , ui(new Ui::Consultant)
{
    ui->setupUi(this);
}

void Consultant::openConsultantSection()
{
    QString consultantName = "Marcos Oliveira";   // ← change to your consultant
    QString consultantRole = "Financial Advisor"; // ← his function

    QString message;
    message += "Consultant Name: " + consultantName + "\n";
    message += "Function: " + consultantRole;

    QMessageBox::information(this, "Consultant Info", message);
}

Consultant::~Consultant()
{
    delete ui;
}
