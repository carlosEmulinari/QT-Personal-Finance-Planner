#include "securitylogs.h"
#include <QSettings>
#include <QDir>
#include <QFile>
#include <QTextStream>
#include <QDateTime>

// ----------------- ACCOUNT -----------------

void Security::saveUserName(const QString &name)
{
    QSettings settings("PFPApp", "Account");
    settings.setValue("userName", name);

    writeLog("Saved User Name: " + name);
}

QString Security::loadUserName()
{
    QSettings settings("PFPApp", "Account");
    return settings.value("userName", "").toString();
}

// ----------------- SAVINGS -----------------

void Security::saveSavings(double value)
{
    QSettings settings("PFPApp", "Savings");
    settings.setValue("savedAmount", value);

    writeLog("Saved Savings: $" + QString::number(value, 'f', 2));
}

double Security::loadSavings()
{
    QSettings settings("PFPApp", "Savings");
    return settings.value("savedAmount", 0.0).toDouble();
}

// ----------------- INVESTMENTS -----------------

void Security::saveInvestment(double value)
{
    QSettings settings("PFPApp", "Investments");
    settings.setValue("investAmount", value);

    writeLog("Saved Investment: $" + QString::number(value, 'f', 2));
}

double Security::loadInvestment()
{
    QSettings settings("PFPApp", "Investments");
    return settings.value("investAmount", 0.0).toDouble();
}

// ----------------- LOGGING -----------------

void Security::writeLog(const QString &entry)
{
    QString logFilePath = QDir::homePath() + "/PFP.log";

    QFile logFile(logFilePath);
    if (logFile.open(QIODevice::Append | QIODevice::Text)) {
        QTextStream out(&logFile);

        QString timestamp = QDateTime::currentDateTime().toString("yyyy-MM-dd HH:mm:ss");
        out << timestamp << " | " << entry << "\n";

        logFile.close();
    }
}
