#include "recordsPage.h"
#include "../db_handling/dbData.h"

#include <QStringList>
#include <QList>
#include <QPushButton>
#include <QHeaderView>

//////////////////////////////////////recordsPage//////////////////////////////////////////////////
recordsPage::recordsPage (QWidget *parent, const int w, const int h): QTableWidget(parent)
{
    setFixedSize(w, h);
    setColumnCount(mColumnCount);
    QStringList columnNames;
    columnNames << "First name" << "Second name" << "Score";
    setHorizontalHeaderLabels(columnNames);
    verticalHeader()->hide();

    //setting column width
    int columnWidth = this->width() / columnCount() - 1;
    setColumnWidth(0, columnWidth);
    setColumnWidth(1, columnWidth);
    setColumnWidth(2, columnWidth);
}

recordsPage::~recordsPage ()
{}
//////////////////////////////////////recordsMenu//////////////////////////////////////////////////

recordsMenu::recordsMenu(QWidget * parent, const int w, const int h): QWidget(parent), mPageWidth (w), mPageHeight (h)
{
    //set menu size
    setFixedSize(mPageWidth, mPageHeight);

    //
    recordsPage *page = new recordsPage(this, this->width(), this->height() * 3 / 5);
    mRecordPages.push_back(page);
    mCurrentPage = mRecordPages.begin();
    //setup close button
    mClose = new QPushButton(this);
    mClose->setText("close");
    mClose->move(this->width() - mClose->width() - 1, this->height() - mClose->height() - 1);
    connect(mClose, SIGNAL(pressed()), this, SLOT(hide()));

    //set up previous page button
    mPrev = new QPushButton (this);
    mPrev->setText("previous page");
    mPrev->move(0, this->height() - mPrev->height() - 1);
    connect(mPrev, SIGNAL(pressed()), this, SLOT(previousPage()));
    mPrev->setDisabled(true);

    //set up next page button
    mNext = new QPushButton (this);
    mNext->setText("next page");
    mNext->move(mPrev->width() * 1.3, mPrev->y());
    connect(mNext, SIGNAL(pressed()), this, SLOT(nextPage()));

    //set background color
    QPalette pal;
    pal.setColor(QPalette::Background, Qt::white);
    setAutoFillBackground(true);
    setPalette(pal);
}

void recordsMenu::updateTable ()
{
    mRecordPages.clear();
    mRecordPages.push_back(new recordsPage(this, this->width(), this->height() * 3 / 5));
    mRecordPages.back()->hide();

    QList<dbEntry> info = dbData::getInstance()->retrieveData();
    mRecordPages.back()->setRowCount(3);
    int i = 0;
    for (auto it = info.begin(); it != info.end(); ++it)
    {
        mRecordPages.back()->setItem(i, 0, new QTableWidgetItem(it->mFirstName));
        mRecordPages.back()->setItem(i, 1, new QTableWidgetItem(it->mSecondName));
        mRecordPages.back()->setItem(i++, 2, new QTableWidgetItem(QString("%1").arg(it->mScore)));
        if (i % 3 == 0)
        {
            mRecordPages.push_back(new recordsPage(this, this->width(), this->height() * 3 / 5));
            mRecordPages.back()->hide();
            mRecordPages.back()->setRowCount(3);
            i = 0;
        }
    }
}

void recordsMenu::show()
{
    updateTable();
    mCurrentPage = mRecordPages.begin();
    recordsPage* page = *(mCurrentPage);
    page->show();
    QWidget::show();
}

void recordsMenu::hide ()
{
    recordsPage* page = *(mCurrentPage);
    page->hide();
    QWidget::hide();
}

void recordsMenu::nextPage()
{
    auto it = mCurrentPage;
    if (mRecordPages.size()  <= 1)
        return;

    ++it;
    if (it == mRecordPages.end())
        return;

    mNext->setDisabled(false);
    mPrev->setDisabled(false);

    recordsPage* page = *mCurrentPage;
    mCurrentPage = it;
    page->hide();
    page = *mCurrentPage;
    page->show();

    if (++it == mRecordPages.end())
        mNext->setDisabled(true);
}

void recordsMenu::previousPage()
{
    if (mRecordPages.size()  <= 1 || mCurrentPage == mRecordPages.begin())
        return;

    recordsPage* page = *mCurrentPage;
    --mCurrentPage;
    page->hide();
    page = *mCurrentPage;
    page->show();

    mNext->setDisabled(false);
    if (mCurrentPage == mRecordPages.begin())
        mPrev->setDisabled(true);
}
