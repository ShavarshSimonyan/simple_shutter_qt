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
const QString dbData::mMainTableName = "MAIN";
const QString dbData::mLevelTableName = "LEVEL";

dbData::dbData (): mCurrentUserID(0), mCurrentGameLevel(1)
{}

dbData::~dbData ()
{

}
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
    static const QString strDbName = QString("spaceWars.db");
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
            QString strMainTable, strLevelTable, tmp;
            while (query.next())
            {
                tmp = query.value(0).toString();
                if (tmp == mMainTableName)
                {
                    strMainTable = tmp;
                    if (!strLevelTable.isEmpty())
                        break;
                }
                else if (tmp == mLevelTableName)
                {
                    strLevelTable = tmp;
                    if (!strMainTable.isEmpty())
                        break;
                }
            }

            if (strMainTable.isEmpty() &&
                !query.exec(QString("CREATE TABLE %1 (id INT PRIMARY KEY NOT NULL, "
                            "name VARCHAR(40), secondname VARCHAR(40), "
                            "score INT);").arg(mMainTableName)))
            {
                qDebug() << query.lastError().text();
                return false;
            }

            if (!query.exec(QString("SELECT MAX(id) FROM %1;").arg(mMainTableName)))
            {
                qDebug() << query.lastError().text();
                return false;
            }
            else if (query.next())
                mCurrentUserID = query.value(0).toInt();

            if (strLevelTable.isEmpty() &&
                !query.exec(QString("CREATE TABLE %1 (level INT PRIMARY KEY NOT NULL)").arg(mLevelTableName)))
            {
                qDebug() << query.lastError().text();
                return false;
            }

            if (!query.exec(QString("SELECT level FROM %1;").arg(mLevelTableName)))
            {
                qDebug() << query.lastError().text();
                return false;
            }
            else if (query.next())
                mCurrentGameLevel = query.value(0).toInt();
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
    QString strQuery = QString("INSERT INTO %1 (id, name, secondname, score)"
                          " VALUES (%2, \'%3\', \'%4\', \'%5\');")
        .arg (mMainTableName)
       .arg(++mCurrentUserID)
       .arg(firstname)
       .arg(secondname)
       .arg(score);
    QSqlQuery query;
    if (!query.exec(strQuery))
        qDebug() << query.lastQuery() << "\n\n" << query.lastError().text();
}
int dbData::getGameLevel () const
{
    return mCurrentGameLevel;
}

void dbData::setGameLevel (const QString &newVal)
{
    mCurrentGameLevel = newVal.toInt();
    QString strCheckQuery = QString ("SELECT * from %1").arg(mLevelTableName);
    bool isFirstUsage = false;
    QSqlQuery query;
    if (!query.exec(strCheckQuery))
        qDebug() << query.lastQuery() << "\n\n" << query.lastError().text();
    else if (!query.next())
        isFirstUsage = true;

    QString strQuery;
    if (isFirstUsage)
        strQuery = QString("INSERT INTO %1 (level)"
                           " VALUES (%2);").arg(mLevelTableName).arg(mCurrentGameLevel);
     else
        strQuery = QString("UPDATE  %1 set level = %2 WHERE level <> %2;")
                      .arg(mLevelTableName)
                      .arg(mCurrentGameLevel);

    if (!query.exec(strQuery))
        qDebug() << query.lastQuery() << "\n\n" << query.lastError().text();
    /*query.exec("SELECT level from LEVEL");
    qDebug() << "getting values from level tablea\n\t";
    while (query.next())
    {
        qDebug() << query.value(0).toString() << "\n\t";
    }*/
}

dbEntry::dbEntry (const QString &name,
                  const QString &secondName,
                  const int score):mFirstName(name),
                                   mSecondName(secondName),
                                   mScore(score)
{}
