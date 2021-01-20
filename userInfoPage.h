#ifndef USERINFOPAGE_H
#define USERINFOPAGE_H

#include <QWidget>
#include <QTextEdit>
#include <QPushButton>
#include <QVBoxLayout>
#include <QLabel>

class userInfoPage: public QWidget
{
    Q_OBJECT
public:
    userInfoPage (int w, int h, QWidget *parent);

    void setCurrentScore (int);
public slots:
    void okButtonClicked ();
    void cancelButtonClicked ();
private:
    void openDB ();

    QTextEdit *mUserFirstName;
    QTextEdit *mUserSecondName;

    QLabel *mScoreInfo;

    QPushButton *mCancelButton;
    QPushButton *mOkButton;

    QVBoxLayout *mMainLayout;
    int mWidth;
    int mHeight;

    int mCurrentUserID;

    int mCurrentScore;

    static const int mScoreHeight = 50;
    static const int mScoreWidth = 160;
};
#endif // USERINFOPAGE_H
