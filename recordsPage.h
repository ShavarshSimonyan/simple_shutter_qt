#ifndef RECORDSPAGE_H
#define RECORDSPAGE_H

#include <QTableWidget>
#include <QWidget>
#include <QPushButton>
#include <QList>

class recordsPage: public QTableWidget
{
public:
    recordsPage (QWidget * parent = 0, const int w = 0, const int h = 0);
    virtual ~recordsPage ();
private:
    static const int mColumnCount = 3;
};

class recordsMenu: public QWidget
{
    Q_OBJECT
public:
    recordsMenu (QWidget * parent = 0, const int w = 0, const int h = 0);
public slots:
    void show ();
    void hide ();
    void nextPage ();
    void previousPage ();
private:
    void updateTable ();

    int mPageWidth;
    int mPageHeight;

    QList<recordsPage *> mRecordPages;
    QList<recordsPage *>::iterator mCurrentPage;

    QPushButton *mClose;
    QPushButton *mNext;
    QPushButton *mPrev;
};
#endif // RECORDSPAGE_H
