#include "admin_welcome_page.h"
#include "ui_admin_welcome_page.h"

Admin_welcome_page::Admin_welcome_page(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::Admin_welcome_page)
{
    ui->setupUi(this);
}

Admin_welcome_page::~Admin_welcome_page()
{
    delete ui;
}
