#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>

QT_BEGIN_NAMESPACE
namespace Ui { class MainWindow; }
QT_END_NAMESPACE

class MainWindow : public QMainWindow
{
    Q_OBJECT

public:
    explicit MainWindow(QWidget *parent = nullptr);
    ~MainWindow();

private slots:
    void on_pushButton_clicked();      // Account button
    void on_pushButton_2_clicked();    // Saving button
    void on_pushButton_3_clicked();    // Investments button
    void on_pushButton_4_clicked();    // Consultant button

private:
    Ui::MainWindow *ui;

    // --- Custom internal functions (no extra files required) ---
    void openAccountSection();
    void openSavingSection();
    void openInvestmentSection();
    void openConsultantSection();
};

#endif // MAINWINDOW_H
