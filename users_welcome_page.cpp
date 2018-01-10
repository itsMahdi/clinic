#include "users_welcome_page.h"
#include "ui_users_welcome_page.h"

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
