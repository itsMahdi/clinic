#include "patientdialog.h"
#include "ui_patientdialog.h"
#include "users_welcome_page.h"

PatientDialog::PatientDialog(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::PatientDialog)
{
    ui->setupUi(this);
}

PatientDialog::~PatientDialog()
{
    delete ui;
}

void PatientDialog::on_pushButton_back_pt_clicked()
{
        close();
//    Users_welcome_page *b;
//    b = new Users_welcome_page;
//    b->show();
//    hide();

}
