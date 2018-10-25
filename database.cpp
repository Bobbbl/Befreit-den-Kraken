/*--Author: Sebastian Draxinger--*/

#include "database.h"


int testDatabase(){

    qDebug() << "Start Test \n";
    const QString DRIVER("QSQLITE");

    if(!QSqlDatabase::isDriverAvailable(DRIVER))
        qWarning() << "Error: " << "Driver for SQLite is not avaible!";
    
    QSqlDatabase db = QSqlDatabase::addDatabase(DRIVER);
    
    db.setDatabaseName("krakelog.db");

    if(!db.open())
    {
        qWarning() << "Error: " << db.lastError();
        return 0;
    }
    else
        qDebug() << "Success! Database is avaible and can be opened";
    
    QSqlQuery query;

    qDebug("Check timestamp Column");
    
    if(!query.exec("SELECT timestamp FROM krake"))
    {
        qWarning() << "Error: " << query.lastError().text();
        return 0;
    }
    else
        qDebug("timestamp is OK");

    
    qDebug("Check Temperatur Column");

    if(!query.exec("SELECT temperatur FROM krake"))
    {
        qWarning() << "Error: " << query.lastError().text();
        return 0;
    }
    else
        qDebug("temperatur is OK");

    qDebug("Check truebung Column");
    
    if(!query.exec("SELECT truebung FROM krake"))
    {
        qWarning() << "Error: " << query.lastError().text();
        return 0;
    }
    else
        qDebug("truebung is OK");



    qDebug("Check ph Column");
    
    if(!query.exec("SELECT ph FROM krake"))
    {
        qWarning() << "Error: " << query.lastError().text();
        return 0;
    }
    else
        qDebug("ph is OK");

    return 1;

}


int logToDatabase(const QString path, const QString tablename,
                  const QString columnname, const int value){
    /* Test Driver */
    const QString DRIVER("QSQLITE");
    if(!QSqlDatabase::isDriverAvailable(DRIVER))
    {
        qWarning() << "Error: " << "Driver for SQLite is not avaible";
        return 0;
    }

    /* Make a new Database Connection*/
    QSqlDatabase db = QSqlDatabase::addDatabase(DRIVER);
    db.setDatabaseName(path);
    if(!db.open())
    {
        qWarning() << "Error: " << db.lastError();
        return 0;
    }
    else{
        /* Sign a new Query*/
        QSqlQuery query;
        /* Save Value*/
        QString command = "INSERT INTO" + tablename + "(" + columnname + ")" + "VALUES(" + QString::number(value) + ")";
        if(!query.exec(command))
        {
            qWarning() << "Error: " << query.lastError().text();
            return 0;
        }

        return 1;
    }
}

int logTimetoDatabase(const QString path, const QString tablename){
    /* Test Driver */
    const QString DRIVER("QSQLITE");
    if(!QSqlDatabase::isDriverAvailable(DRIVER))
    {
        qWarning() << "Error: " << "Driver for SQLite is not avaible";
        return 0;
    }

    /* Make a new Database Connection*/
    QSqlDatabase db = QSqlDatabase::addDatabase(DRIVER);
    db.setDatabaseName(path);

    if(!db.open())
    {
        qWarning() << "Error: " << db.lastError();
        return 0;
    }
    else{
        /* Sign a new Query*/
        QSqlQuery query;
        /* Save Value*/
        QString command = QString("INSERT INTO " + tablename + "(timestamp) " + "VALUES(datetime('now'))");
        qDebug() << "Command: " << command;
        if(!query.exec(command))
        {
            qWarning() << "Error: " << query.lastError().text();
            return 0;
        }

        return 1;
    }
}


int logKrake(const QString path, const QString tablename, const double temp, const double trueb, const double ph){
    /* Test Driver */
    const QString DRIVER("QSQLITE");
    if(!QSqlDatabase::isDriverAvailable(DRIVER))
    {
        qWarning() << "Error: " << "Driver for SQLite is not avaible";
        return 0;
    }

    /* Make a new Database Connection*/
    QSqlDatabase db = QSqlDatabase::addDatabase(DRIVER);
    db.setDatabaseName(path);

    if(!db.open())
    {
        qWarning() << "Error: " << db.lastError();
        return 0;
    }
    else{
        /* Sign a new Query*/
        QSqlQuery query;
        /* Save Value*/
        QString command = QString("INSERT INTO " + tablename + " "+ QString("VALUES(datetime('now'), %1, %2, %3)").arg(temp,0, 'g', 2).arg(trueb,0, 'g', 2).arg(ph,0, 'g', 2));

        if(!query.exec(command))
        {
            qWarning() << "Error: " << query.lastError().text();
            return 0;
        }

        db.close();
        return 1;
    }
}
