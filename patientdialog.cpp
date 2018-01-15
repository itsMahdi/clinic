#include "patientdialog.h"
#include "ui_patientdialog.h"

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
