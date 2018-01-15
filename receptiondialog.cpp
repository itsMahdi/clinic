#include "receptiondialog.h"
#include "ui_receptiondialog.h"
#include "users_welcome_page.h"

ReceptionDialog::ReceptionDialog(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::ReceptionDialog)
{
    ui->setupUi(this);
}

ReceptionDialog::~ReceptionDialog()
{
    delete ui;
}

void ReceptionDialog::on_pushButton_back_recp_clicked()
{
    Users_welcome_page *b;
    b = new Users_welcome_page;
    b->show();
    hide();
}
