#ifndef SAVINGS_H
#define SAVINGS_H

#include "ui_savings.h"
#include <QWidget>

namespace Ui {
class savings;
}

class savings : public QWidget
{
    Q_OBJECT

public:
    explicit savings(QWidget *parent = nullptr);
    ~savings();

    void openSavingsSection();

private:
    Ui::savings *ui;
};

#endif
