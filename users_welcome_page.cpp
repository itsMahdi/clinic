#include "users_welcome_page.h"
#include "ui_users_welcome_page.h"
#include <login.h>
Users_welcome_page::Users_welcome_page(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::Users_welcome_page)
{
    ui->setupUi(this);
}

Users_welcome_page::~Users_welcome_page()
{
    delete ui;
}

void Users_welcome_page::on_pushButton_back_clicked()
{
    LogIn *a;
    a = new LogIn;
    a->show();
    hide();
}
