#include "visitdialog.h"
#include "ui_visitdialog.h"
#include "login.h"

VisitDialog::VisitDialog(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::VisitDialog)
{
    ui->setupUi(this);
}

VisitDialog::~VisitDialog()
{
    delete ui;
}

void VisitDialog::on_pushButton_back_visit_clicked()
{
    LogIn *a;
    a = new LogIn;
    a->show();
    //hide();
    close();
}
