#ifndef PFP_STORAGE_H
#define PFP_STORAGE_H

#include <QString>

class Security
{
public:
    // Account
    static void saveUserName(const QString &name);
    static QString loadUserName();

    // Savings
    static void saveSavings(double value);
    static double loadSavings();

    // Investments
    static void saveInvestment(double value);
    static double loadInvestment();

    // Logging
    static void writeLog(const QString &entry);
};

#endif
