#ifndef DATABASE_H
#define DATABASE_H

#include <QSqlDatabase>
#include <QSqlDriver>
#include <QSqlError>
#include <QSqlQuery>
#include <QtGlobal>
#include <QDebug>

int testDatabase();
int logToDatabase(const QString path, const QString tablename,
                  const QString columnname, const int value);
int logTimetoDatabase(const QString path, const QString tablename);

int logKrake(const QString path, const QString tablename, const double temp, const double trueb, const double ph);


#endif
