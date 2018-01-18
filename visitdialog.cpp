#include "visitdialog.h"
#include "ui_visitdialog.h"

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
