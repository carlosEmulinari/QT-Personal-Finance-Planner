#include "mainwindow.h"
#include "ui_mainwindow.h"
#include <QMessageBox>
#include <QDate>


MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::MainWindow)
{
    ui->setupUi(this);
}

MainWindow::~MainWindow()
{
    delete ui;
}

// ---------------- Button Slot Functions ----------------

void MainWindow::on_pushButton_clicked()
{
    hide();
    Account = new class Account(this);
    Account->show();
}

void MainWindow::on_pushButton_2_clicked()
{
    hide();
    Savings = new class Savings(this);
    Savings->show();
}

void MainWindow::on_pushButton_3_clicked()
{
    hide();
    Investiments = new class Investiments(this);
    Investiments->show();
}

void MainWindow::on_pushButton_4_clicked()
{
    hide();
    Consultant = new class Consultant(this);
    Consultant->show();
}
