#include "insudetaildialog.h"
#include "ui_insudetaildialog.h"
#include "insurancedialog.h"

InsuDetailDialog::InsuDetailDialog(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::InsuDetailDialog)
{
    ui->setupUi(this);
}

InsuDetailDialog::~InsuDetailDialog()
{
    delete ui;
}

void InsuDetailDialog::on_pushButton_insu_det_back_clicked()
{
    close();
    //InsuranceDialog *b;
    //b = new InsuranceDialog;
    //b->show();
   // hide();
}
