#include "serialcomm.h"

SerialComm::SerialComm(QObject *parent)
    : QObject(parent)
{
    connect(&serial, &QSerialPort::readyRead, this, &SerialComm::readData);
}

bool SerialComm::autoConnect()
{
    qDebug() << "[SerialComm] Searching for available ports...";

    QList<QSerialPortInfo> ports = QSerialPortInfo::availablePorts();
    for (const QSerialPortInfo &info : ports) {
        qDebug() << "[SerialComm] Found port:" << info.portName()
        << "Description:" << info.description();

        if (info.portName().startsWith("ttyUSB") || info.portName().startsWith("ttyACM")) {
            serial.setPort(info);
            serial.setBaudRate(QSerialPort::Baud9600);

            if (serial.open(QIODevice::ReadWrite)) {
                qDebug() << "[SerialComm] Successfully connected to" << info.portName();
                return true;
            } else {
                qDebug() << "[SerialComm] Failed to open" << info.portName()
                << "Error:" << serial.errorString();
            }
        }
    }

    qDebug() << "[SerialComm] No Arduino found or permission denied.";
    return false;
}

bool SerialComm::isConnected() const
{
    return serial.isOpen();
}

void SerialComm::sendData(const QString &data)
{
    if (serial.isOpen()) {
        QByteArray payload = data.toUtf8();
        serial.write(payload);
        qDebug() << "[SerialComm] Sent data:" << payload;
    } else {
        qDebug() << "[SerialComm] Attempted to send but serial not open.";
    }
}

void SerialComm::readData()
{
    static QByteArray buffer;
    buffer.append(serial.readAll());

    int index;
    while ((index = buffer.indexOf('\n')) != -1) {
        QByteArray line = buffer.left(index).trimmed();
        buffer.remove(0, index + 1);

        if (!line.isEmpty()) {
            emit newData(QString::fromUtf8(line));
        }
    }
}
