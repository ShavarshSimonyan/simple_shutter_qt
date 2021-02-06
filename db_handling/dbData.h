#ifndef DBDATA_H
#define DBDATA_H

#include <QScopedPointer>
#include <QString>
#include <QList>
#include <QObject>

struct dbEntry
{
    dbEntry (const QString &name = "",
             const QString &secondName = "",
             const int score = 0);
    QString mFirstName;
    QString mSecondName;
    int mScore;
};

class dbData: public QObject
{
    Q_OBJECT
public:
    static QScopedPointer<dbData>& getInstance ();
    void enterData (const QString &, const QString &, const int);
    int getGameLevel () const;
    QList<dbEntry> retrieveData ();
    virtual ~dbData ();
public slots:
    void setGameLevel (const QString &);
private:
    dbData ();

    bool connectToDB ();

    int mCurrentUserID;
    int mCurrentGameLevel;

    static QScopedPointer <dbData> mInstance;

    static const QString mMainTableName;
    static const QString mLevelTableName;
};
#endif // DBDATA_H
