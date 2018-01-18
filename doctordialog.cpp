#include "doctordialog.h"
#include "ui_doctordialog.h"

DoctorDialog::DoctorDialog(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::DoctorDialog)
{
    ui->setupUi(this);
}

DoctorDialog::~DoctorDialog()
{
    delete ui;
}

void DoctorDialog::on_pushButton_back_dr_clicked()
{
    close();
}
