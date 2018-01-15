#include "receptiondialog.h"
#include "ui_receptiondialog.h"

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
