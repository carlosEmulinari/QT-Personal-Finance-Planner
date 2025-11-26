#ifndef CONSULTANT_H
#define CONSULTANT_H

#include <QWidget>

namespace Ui {
class Consultant;
}

class Consultant : public QWidget
{
    Q_OBJECT

public:
    explicit Consultant(QWidget *parent = nullptr);
    ~Consultant();

private:
    Ui::Consultant *ui;
    void openConsultantSection();
};

#endif // CONSULTANT_H
