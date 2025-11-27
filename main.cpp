#include "serialcomm.h"
#include <QApplication>
#include "mainwindow.h"

int main(int argc, char *argv[])
{
    QApplication a(argc, argv);

    SerialComm serial;
    serial.autoConnect();   // Connect automatically to Arduino

    MainWindow w(nullptr, &serial);
    w.show();

    return a.exec();
}
