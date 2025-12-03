#include "mainwindow.h"
#include "./ui_mainwindow.h"
#include <QMessageBox>
#include "aboutdialog.h"
#include "account.h"
#include "investiments.h"
#include "savings.h"


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
    account *profile = new account(this);
    profile->show();
}

void MainWindow::on_pushButton_2_clicked()
{
    savings *save = new savings(this);
    save->show();
}

void MainWindow::on_pushButton_3_clicked()
{
    investiments *invest = new investiments(this);
    invest->show();
}

void MainWindow::on_pushButton_5_clicked()
{
    AboutDialog about(this);
    about.exec();
}
