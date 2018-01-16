#include "insurancedialog.h"
#include "ui_insurancedialog.h"
#include "insudetaildialog.h"
#include "users_welcome_page.h"

InsuranceDialog::InsuranceDialog(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::InsuranceDialog)
{
    ui->setupUi(this);
    ui->comboBox_insu->addItem("tamin ejtemaee");
    ui->comboBox_insu->addItem("sepah");
    ui->comboBox_insu->addItem("takmili");
    ui->comboBox_insu->addItem("rostaee");
    ui->comboBox_insu->addItem("no insurance");
}

InsuranceDialog::~InsuranceDialog()
{
    delete ui;
}

void InsuranceDialog::on_pushButton_insu_detail_clicked()
{
    InsuDetailDialog insuDetaildialog;
    insuDetaildialog.setModal(true);
    insuDetaildialog.exec();

}

void InsuranceDialog::on_pushButton_insu_back_clicked()
{

    Users_welcome_page *b;
    b = new Users_welcome_page;
    b->show();
    hide();

}
