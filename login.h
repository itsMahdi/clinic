#ifndef LOGIN_H
#define LOGIN_H

#include <QMainWindow>

#include <QMessageBox>
#include <QDebug>
#include <QSqlDatabase>
#include <QSqlDriver>
#include <QSqlError>
#include <QSqlQuery>

namespace Ui {
class LogIn;
}

class LogIn : public QMainWindow
{
    Q_OBJECT

public:
    explicit LogIn(QWidget *parent = 0);
    ~LogIn();

private:
    Ui::LogIn *ui;
};

#endif // LOGIN_H
