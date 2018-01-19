#include "insudetaildialog.h"
#include "ui_insudetaildialog.h"
#include "insurancedialog.h"

#include <QDialog>
#include <QDebug>
#include <QSqlDatabase>
#include <QSqlDriver>
#include <QSqlError>
#include <QSqlQuery>
#include<QSqlQueryModel>
#include <QMessageBox>

InsuDetailDialog::InsuDetailDialog(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::InsuDetailDialog)
{
    ui->setupUi(this);
    update_table();
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

void InsuDetailDialog::on_pushButton_add_insu_det_clicked()
{
    QString name = ui->lineEdit_name_insu->text();
    int cost= ui->lineEdit_cover_cost->text().toInt();

    QSqlQuery query;
    query.prepare("INSERT INTO insurance_company (name,cost_cover) "
                  "VALUES (:name,:cost)");
    query.bindValue(":name",name);
    query.bindValue(":cost",cost);

    if (query.exec())
    {
        update_table();
    }
    else
    {
        qWarning()<<"ERROR IN ADD TO DB "<<query.lastError().text();
        QMessageBox::critical(this,"error in add","ERROR data not added");
    }
}

void InsuDetailDialog::update_table(){
    QSqlDatabase db;
    QSqlQuery *query = new QSqlQuery(db);
    query->prepare("SELECT * FROM insurance_company");
    if (!query->exec())
        QMessageBox::critical(this,"ERROR","table error");

    QSqlQueryModel *querymodel= new QSqlQueryModel();
    querymodel->setQuery(*query);
    ui->tableView_insu_detail->setModel(querymodel);

}
