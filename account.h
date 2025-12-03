#ifndef ACCOUNT_H
#define ACCOUNT_H
#include <QMessageBox>
#include <QWidget>
#include <QDate>
#include <QDialog>


namespace Ui {
class account;
}

class account : public QWidget
{
    Q_OBJECT

public:
    explicit account(QWidget *parent = nullptr);
    ~account();

    void openAccountSection();

private:
    Ui::account *ui;
};

#endif
