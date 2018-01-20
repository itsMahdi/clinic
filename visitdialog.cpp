#include "visitdialog.h"
#include "ui_visitdialog.h"
#include "login.h"


#include <QDialog>
#include <QDebug>
#include <QSqlDatabase>
#include <QSqlDriver>
#include <QSqlError>
#include <QSqlQuery>
#include<QSqlQueryModel>
#include <QMessageBox>
VisitDialog::VisitDialog(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::VisitDialog)
{
    ui->setupUi(this);

    update_table();
    ui->label_welcome->setText("WELCOME!");
    int a=login_id;
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

void VisitDialog::on_pushButton_clicked()
{
    int v_id = ui->lineEdit_vid->text().toInt();
    int p_id = ui->lineEdit_pid->text().toInt();
    int d_id = ui->lineEdit_did->text().toInt();
    QString date =ui->dateEdit->text();
    QString des = ui->textEdit_description_visit->toPlainText();
    QString drugs =ui->textEdit_drug->toPlainText();

    QSqlQuery query;
    query.prepare("INSERT INTO visit (v_id,p_id,d_id,date,des,drugs) VALUES "
                  "(:v_id,:p_id,:d_id,:date,:des,:drugs)");
    query.bindValue(":v_id",v_id);
    query.bindValue(":p_id",p_id);
    query.bindValue(":d_id",d_id);
    query.bindValue(":date",date);
    query.bindValue(":des",des);
    query.bindValue(":drugs",drugs);

    if (query.exec())
    {
        ui->label_status->setText("added successfully!");
        update_table();
    }
    else
    {
        qWarning()<<"ERROR IN ADD TO DB "<<query.lastError().text();
        QMessageBox::critical(this,"error in add","ERROR data not added");
    }

}

void VisitDialog::update_table(){
    QSqlDatabase db;
    QSqlQuery *query = new QSqlQuery(db);
    query->prepare("SELECT * FROM visit");
    if (!query->exec())
        QMessageBox::critical(this,"ERROR","table error");

    QSqlQueryModel *querymodel= new QSqlQueryModel();
    querymodel->setQuery(*query);
    ui->tableView_visit->setModel(querymodel);

}
