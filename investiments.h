#ifndef CONSULTANT_H
#define CONSULTANT_H
#include <QDialog>
#include <QWidget>

namespace Ui {
class investiments;
}

class investiments : public QWidget
{
    Q_OBJECT

public:
    explicit investiments(QWidget *parent = nullptr);
    ~investiments();

    void openInvestmentsSection();

private:
    Ui::investiments *ui;
};

#endif
