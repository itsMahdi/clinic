#include "doctor_dialog_page.h"
#include "ui_doctor_dialog_page.h"

Doctor_dialog_page::Doctor_dialog_page(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::Doctor_dialog_page)
{
    ui->setupUi(this);
}

Doctor_dialog_page::~Doctor_dialog_page()
{
    delete ui;
}
