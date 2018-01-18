#include "receptiondialog.h"
#include "ui_receptiondialog.h"
#include "users_welcome_page.h"
#include "patientdialog.h"

ReceptionDialog::ReceptionDialog(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::ReceptionDialog)
{
    ui->setupUi(this);
    ui->comboBox_recp_problem->addItem("general practitioner");
    ui->comboBox_recp_problem->addItem("cardiologist");
    ui->comboBox_recp_problem->addItem("neurologist");
    ui->comboBox_recp_problem->addItem("oncologist");
    ui->comboBox_recp_problem->addItem("orthopedist");
    ui->comboBox_recp_problem->addItem("plastic surgeon");
    ui->comboBox_recp_problem->addItem("psychologist");
    ui->comboBox_recp_problem->addItem("urologist");
}

ReceptionDialog::~ReceptionDialog()
{
    delete ui;
}

void ReceptionDialog::on_pushButton_back_recp_clicked()
{
    close();
    //Users_welcome_page *b;
   // b = new Users_welcome_page;
    //b->show();
   // hide();
}

void ReceptionDialog::on_pushButton_recp_search_pt_clicked()
{
    PatientDialog *b;
    b = new PatientDialog;
    b->show();
    hide();

}
