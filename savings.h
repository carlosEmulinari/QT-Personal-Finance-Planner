#ifndef SAVINGS_H
#define SAVINGS_H

#include <QWidget>
#include <QSerialPort>

namespace Ui {
class Savings;
}

class Savings : public QWidget
{
    Q_OBJECT

public:
    explicit Savings(QWidget *parent = nullptr);
    ~Savings();

private:
    Ui::Savings *ui;
    QSerialPort *serial;
    void openSavingSection();
};

#endif // SAVINGS_H
