#include "mainwindow.h"
#include "ui_mainwindow.h"
#include <QMessageBox>

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
    openAccountSection();
}

void MainWindow::on_pushButton_2_clicked()
{
    openSavingSection();
}

void MainWindow::on_pushButton_3_clicked()
{
    openInvestmentSection();
}

void MainWindow::on_pushButton_4_clicked()
{
    openConsultantSection();
}

// ---------------- Custom Internal Functions ----------------

void MainWindow::openAccountSection()
{
    QMessageBox::information(this, "Account", "Opening Account Section...");
}

void MainWindow::openSavingSection()
{
    QMessageBox::information(this, "Saving", "Opening Saving Section...");
}

void MainWindow::openInvestmentSection()
{
    QMessageBox::information(this, "Investments", "Opening Investment Section...");
}

void MainWindow::openConsultantSection()
{
    QMessageBox::information(this, "Consultant", "Opening Consultant Section...");
}
