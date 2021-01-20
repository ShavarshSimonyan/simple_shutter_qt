#include "userInfoPage.h"
#include "../db_handling/dbData.h"

#include <QGridLayout>
#include <QPalette>
#include <QColor>
#include <QLabel>
#include <QMessageBox>

#include <QDebug>

userInfoPage::userInfoPage (int w, int h, QWidget *parent): QWidget(parent),
                                                            mWidth(w), mHeight (h),
                                                            mCurrentUserID(0),
                                                            mCurrentScore(0)
{
    //set window size
    setFixedSize(mWidth, mHeight);

    //create fields for user information
    QLabel *pFirstNameLabel = new QLabel ("First name: ", this);
    mUserFirstName = new QTextEdit (this);
    mUserFirstName->setFixedSize(this->width() / 2, this->height() / 8);

    QLabel *pSecondNameLabel = new QLabel ("Second name: ", this);
    mUserSecondName = new QTextEdit (this);
    mUserSecondName->setFixedSize(this->width() / 2, this->height() / 8);

    //create grid layout for first name
    QGridLayout *pGridLayout = new QGridLayout (this);

    mScoreInfo = new QLabel("", this);
    mScoreInfo->setFixedSize(mScoreWidth, mScoreHeight);
    mScoreInfo->setAlignment(Qt::AlignCenter);
    setCurrentScore(0);

    pGridLayout->addWidget(pFirstNameLabel, 1, 0);
    pGridLayout->addWidget(mUserFirstName, 1, 1);

    pGridLayout->addWidget(pSecondNameLabel, 2, 0);
    pGridLayout->addWidget(mUserSecondName, 2, 1);

    //create main layout
    mMainLayout = new QVBoxLayout (this);
    mMainLayout->addLayout(pGridLayout);

    //create close button
    mCancelButton = new QPushButton (this);
    mCancelButton->setText("Cancel");
    connect(mCancelButton, SIGNAL(pressed()), this, SLOT(cancelButtonClicked()));
    //move close button to bottom right corner
    mCancelButton->move(this->width() - mCancelButton->width(), this->height() - mCancelButton->height());

    //create OK button
    mOkButton = new QPushButton (this);
    mOkButton->setText("OK");
    connect(mOkButton, SIGNAL(pressed()), this, SLOT(okButtonClicked()));
    //move close button to bottom right corner
    mOkButton->move(this->width() - mOkButton->width() - mCancelButton->width() * 1.2,
                    this->height() - mOkButton->height());

    //set background color
    QPalette pal;
    pal.setColor(QPalette::Background, Qt::gray);
    setAutoFillBackground(true);
    setPalette(pal);
}

void userInfoPage::setCurrentScore (int score)
{
    mCurrentScore = score;
    mScoreInfo->setText(QString("Your score is %1\nEnter your information").arg(mCurrentScore));
    mScoreInfo->move(this->width() / 2 - mScoreInfo->width() / 2, 0);
}

void userInfoPage::okButtonClicked ()
{
    if (mUserFirstName->toPlainText().isEmpty() ||
        mUserSecondName->toPlainText().isEmpty())
    {
        QMessageBox msg(this);
        msg.setText("Incomplete user information!");
        msg.setStandardButtons(QMessageBox::Ok);
        msg.exec();
    }
    else
    {
        dbData::getInstance()->enterData (mUserFirstName->toPlainText(),
                                              mUserSecondName->toPlainText(), mCurrentScore);
        hide();
    }
}

void userInfoPage::cancelButtonClicked ()
{
    mUserFirstName->clear();
    mUserSecondName->clear();
    hide();
}
