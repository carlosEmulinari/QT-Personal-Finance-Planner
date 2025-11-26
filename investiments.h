#ifndef INVESTIMENTS_H
#define INVESTIMENTS_H

#include <QWidget>
#include <QSerialPort>

namespace Ui {
class Investiments;
}

class Investiments : public QWidget
{
    Q_OBJECT

public:
    explicit Investiments(QWidget *parent = nullptr);
    ~Investiments();

private:
    Ui::Investiments *ui;
    QSerialPort *serial;
    void openInvestmentSection();
};

#endif // INVESTIMENTS_H
