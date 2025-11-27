#ifndef SERIALCOMM_H
#define SERIALCOMM_H

#include <QObject>
#include <QSerialPort>
#include <QSerialPortInfo>
#include <QDebug>

class SerialComm : public QObject
{
    Q_OBJECT

public:
    explicit SerialComm(QObject *parent = nullptr);

    bool autoConnect();
    bool isConnected() const;
    void sendData(const QString &data);

signals:
    void newData(const QString &data);

private slots:
    void readData();

private:
    QSerialPort serial;
};

#endif
