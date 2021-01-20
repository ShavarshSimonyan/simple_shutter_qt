#ifndef DBDATA_H
#define DBDATA_H

#include <QScopedPointer>
#include <QString>
#include <QList>

struct dbEntry
{
    dbEntry (const QString &name = "",
             const QString &secondName = "",
             const int score = 0);
    QString mFirstName;
    QString mSecondName;
    int mScore;
};

class dbData
{
public:
    static QScopedPointer<dbData>& getInstance ();
    void enterData (const QString &, const QString &, const int);
    QList<dbEntry> retrieveData ();
private:
    dbData ();

    bool connectToDB ();

    int mCurrentUserID;

    static QScopedPointer <dbData> mInstance;
};
#endif // DBDATA_H
