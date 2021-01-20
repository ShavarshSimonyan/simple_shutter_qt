#include "dbData.h"

#include <QtSql/QSql>
#include <QtSql/QSqlDatabase>
#include <QtSql/QSqlQuery>
#include <QtSql/QSqlError>

#include <QDateTime>
#include <QDebug>
#include <QDir>
#include <QMessageBox>

QScopedPointer <dbData> dbData::mInstance(nullptr);

dbData::dbData (): mCurrentUserID(0)
{}

QScopedPointer<dbData>& dbData::getInstance()
{
    if (!mInstance)
    {
        mInstance.reset(new dbData());
        if (!mInstance->connectToDB())
            QMessageBox::critical(nullptr, "Title", "Fatal Error: Failed to connect to database.");
    }

    return mInstance;
}

bool dbData::connectToDB ()
{
    QString strDbName = QString("spaceWars.db");
    QDir dbFile (strDbName);
    bool bExists = dbFile.exists();
    QSqlDatabase db = QSqlDatabase::addDatabase("QSQLITE");
    db.setDatabaseName(strDbName);
    bool ok = db.open();
    if (!ok)
    {
        qDebug() << "error connecting to db";
        return false;
    }

    if (!bExists)
    {
        QSqlQuery query;
        if (!query.exec("SELECT name FROM sqlite_master WHERE type='table';"))
        {
            qDebug() << query.lastError().text();
            return false;
        }
        else
        {
            QString strMainTable;
            while (query.next())
            {
                strMainTable = query.value(0).toString();
                if (strMainTable == "MAIN")
                    break;
                else
                    strMainTable.clear();
            }

            if (strMainTable.isEmpty() &&
                !query.exec("CREATE TABLE MAIN (id INT PRIMARY KEY NOT NULL, "
                            "name VARCHAR(40), secondname VARCHAR(40), "
                            "score INT);"))
            {
                qDebug() << query.lastError().text();
                return false;
            }

            if (!query.exec("SELECT MAX(id) FROM MAIN;"))
            {
                qDebug() << query.lastError().text();
                return false;
            }
            else if (query.next())
                mCurrentUserID = query.value(0).toInt();
        }
    }

    return true;
}

QList<dbEntry> dbData::retrieveData ()
{
    QList<dbEntry> res;
    static QString strQuery = QString("SELECT name, secondname, score FROM MAIN;");
    QSqlQuery query;
    if (!query.exec(strQuery))
        qDebug() << query.lastQuery() << "\n\n" << query.lastError().text();
    else
    {
        while (query.next())
        {
            QString name = query.value(0).toString();
            QString secondName = query.value(1).toString();
            int score = query.value(2).toInt();
            res.push_back(dbEntry(name, secondName, score));
        }
    }
    return res;
}

void dbData::enterData (const QString &firstname,
                            const QString &secondname,
                            const int score)
{
    QString strQuery = QString("INSERT INTO MAIN (id, name, secondname, score)"
                          " VALUES (%1, \'%2\', \'%3\', \'%4\');")
       .arg(++mCurrentUserID)
       .arg(firstname)
       .arg(secondname)
       .arg(score);
    QSqlQuery query;
    if (!query.exec(strQuery))
        qDebug() << query.lastQuery() << "\n\n" << query.lastError().text();
}

dbEntry::dbEntry (const QString &name,
                  const QString &secondName,
                  const int score):mFirstName(name),
                                   mSecondName(secondName),
                                   mScore(score)
{}
