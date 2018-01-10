#ifndef LOGIN_H
#define LOGIN_H
#include <admin_welcome_page.h>
#include <users_welcome_page.h>

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

private slots:
    void on_pushButton_login_clicked();

private:
    Ui::LogIn *ui;
    Admin_welcome_page *admin_welcome_page;
    Users_welcome_page *users_welcome_page;
    void connect_to_db();
};

#endif // LOGIN_H
