#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>
#include "account.h"
#include "savings.h"
#include "investiments.h"
#include "consultant.h"



QT_BEGIN_NAMESPACE
namespace Ui { class MainWindow; }
QT_END_NAMESPACE

class MainWindow : public QMainWindow
{
    Q_OBJECT
public:
    explicit MainWindow(QWidget *parent = nullptr, SerialComm *serialComm = nullptr);
    ~MainWindow();

private slots:
    void on_pushButton_clicked();      // Account button
    void on_pushButton_2_clicked();    // Saving button
    void on_pushButton_3_clicked();    // Investments button
    void on_pushButton_4_clicked();    // Consultant button

private:
    Ui::MainWindow *ui;
    Account *Account;
    Savings *Savings;
    Investiments *Investiments;
    Consultant *Consultant;
    SerialComm *serial;
};

#endif // MAINWINDOW_H
