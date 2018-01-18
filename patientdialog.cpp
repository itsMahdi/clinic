#include "patientdialog.h"
#include "ui_patientdialog.h"
#include "users_welcome_page.h"

PatientDialog::PatientDialog(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::PatientDialog)
{
    ui->setupUi(this);
    ui->comboBox_gender->addItem("male");
    ui->comboBox_gender->addItem("female");

    ui->comboBox_p_insu->addItem("tamin ejtemaee");
    ui->comboBox_p_insu->addItem("sepah");
    ui->comboBox_p_insu->addItem("niroye mosalah");
    ui->comboBox_p_insu->addItem("takmili");
    ui->comboBox_p_insu->addItem("rostaee");
    ui->comboBox_p_insu->addItem("no insurance");
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
