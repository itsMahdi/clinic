#include "receptiondialog.h"
#include "ui_receptiondialog.h"
#include "users_welcome_page.h"
#include "patientdialog.h"

#include <QDialog>
#include <QDebug>
#include <QSqlDatabase>
#include <QSqlDriver>
#include <QSqlError>
#include <QSqlQuery>
#include<QSqlQueryModel>
#include <QMessageBox>

ReceptionDialog::ReceptionDialog(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::ReceptionDialog)
{
    ui->setupUi(this);
    ui->comboBox_recp_problem->addItem("general practitioner");
    ui->comboBox_recp_problem->addItem("cardiologist");
    ui->comboBox_recp_problem->addItem("neurologist");
    ui->comboBox_recp_problem->addItem("oncologist");
    ui->comboBox_recp_problem->addItem("orthopedist");
    ui->comboBox_recp_problem->addItem("plastic surgeon");
    ui->comboBox_recp_problem->addItem("psychologist");
    ui->comboBox_recp_problem->addItem("urologist");

    //ui->dateEdit->setDate();
    update_table();
}

ReceptionDialog::~ReceptionDialog()
{
    delete ui;
}

void ReceptionDialog::on_pushButton_back_recp_clicked()
{
    close();
    //Users_welcome_page *b;
   // b = new Users_welcome_page;
    //b->show();
   // hide();
}

void ReceptionDialog::on_pushButton_recp_search_pt_clicked()
{
    PatientDialog *b;
    b = new PatientDialog;
    b->show();
    hide();

}

void ReceptionDialog::on_comboBox_recp_problem_currentIndexChanged(const QString &arg1)
{
    QString exp = ui->comboBox_recp_problem->currentText();
    QSqlQuery query;
    query.prepare("SELECT family FROM doctor_document WHERE "
                  "exp = :exp");
    query.bindValue(":exp",exp);
    if(query.exec())
    {
        ui->comboBox_recp_dr->clear();
        while (query.next()) {
            QString a=query.value(0).toString();
            ui->comboBox_recp_dr->addItem("Dr. "+query.value(0).toString());
        }
    }
}

void ReceptionDialog::on_comboBox_recp_dr_currentIndexChanged(const QString &arg1)
{
    QString family = ui->comboBox_recp_dr->currentText();
    family.remove(0,4);
    qWarning()<<family<< " s sss";
    QSqlQuery query;
    query.prepare("SELECT * FROM doctor_document WHERE family=:family");
    query.bindValue(":family",family);
    if(query.exec())
    {
        int flag=0;
        while (query.next()) {
            flag=1;
            ui->lineEdit_recp_dr_id->setText(query.value(0).toString());
            ui->lineEdit_drVisitCost->setText(query.value(9).toString());
        }
        if(flag==0)
        {
            ui->lineEdit_recp_dr_id->setText("");
            ui->lineEdit_drVisitCost->setText("");
        }
    }else{
        qWarning()<<query.lastError().text();
    }


}

void ReceptionDialog::on_lineEdit_recp_pt_id_editingFinished()
{
    int p_id=ui->lineEdit_recp_pt_id->text().toInt();

    QSqlQuery query;
    query.prepare("SELECT name,family,expire_year,expire_mounth,expire_day FROM patient_document WHERE "
              "p_id=:p_id");
    query.bindValue(":p_id",p_id);

    if(query.exec())
    {
        int flag=0;
        while (query.next()) {
            flag=1;
            ui->lineEdit_recp_pt_name->setText(query.value(0).toString()+" "+query.value(1).toString());
            ui->lineEdit_expyr->setText(query.value(2).toString());
            ui->lineEdit_expmounth->setText(query.value(3).toString());
            ui->lineEdit_expday->setText(query.value(4).toString());
        }
        if(flag==0)
        {
            ui->lineEdit_recp_pt_name->setText("");
            ui->lineEdit_expyr->setText("");
            ui->lineEdit_expmounth->setText("");
            ui->lineEdit_expday->setText("");
        }
    }else{
        qWarning()<<query.lastError().text();
    }




}

void ReceptionDialog::on_pushButton_2_clicked() //calculate
{
    int p_id = ui->lineEdit_recp_pt_id->text().toInt();
    QSqlQuery query;
    query.prepare("SELECT insurance_name from patient_document WHERE p_id=:p_id");
    query.bindValue(":p_id",p_id);

    int insu_cost,cost,dr_cost;
    if(query.exec())
    {
        QString insurance_name;
        while (query.next()) {
            insurance_name = query.value(0).toString();
        }
        QSqlQuery query2;
        query2.prepare("SELECT cost_cover FROM insurance_company WHERE name=:insurance_name");
       query2.bindValue(":insurance_name",insurance_name);
       if(query2.exec()){
           while (query2.next())
              insu_cost=query2.value(0).toString().toInt();
       }else
           qWarning()<<"query 2 cost error: "<<query2.lastError().text();

           int d_id = ui->lineEdit_recp_dr_id->text().toInt();
           QSqlQuery query3;
           query3.prepare("SELECT cost FROM doctor_document WHERE d_id=:d_id");
          query3.bindValue(":d_id",d_id);
          if(query3.exec()){
              while (query3.next())
                 dr_cost=query3.value(0).toInt();
          }else
              qWarning()<<"query 3 cost error: "<<query2.lastError().text();

          cost=dr_cost-insu_cost;

          if(cost>0) ui->lineEdit_cost_insu->setText(QString::number(cost));
          else ui->lineEdit_cost_insu->setText("0");

    }else{
        qWarning()<<query.lastError().text();
    }
}

void ReceptionDialog::on_pushButton_add_recp_clicked()
{
    int r_id = ui->lineEdit_recp_id->text().toInt();
    int p_id = ui->lineEdit_recp_pt_id->text().toInt();
    int d_id = ui->lineEdit_recp_dr_id->text().toInt();
    int cost = ui->lineEdit_cost_insu->text().toInt();
    QString date=ui->dateEdit->text();
    QString time=ui->timeEdit_time->text();

    QSqlQuery query;
    query.prepare("INSERT INTO reception (r_id,p_id,d_id,date,time,cost) VALUES "
                  "(:r_id,:p_id,:d_id,:date,:time,:cost)");
    query.bindValue(":r_id",r_id);
    query.bindValue(":p_id",p_id);
    query.bindValue(":d_id",d_id);
    query.bindValue(":date",date);
    query.bindValue(":time",time);
    query.bindValue(":cost",cost);

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

void ReceptionDialog::update_table(){
    QSqlDatabase db;
    QSqlQuery *query = new QSqlQuery(db);
    query->prepare("SELECT * FROM reception");
    if (!query->exec())
        QMessageBox::critical(this,"ERROR","table error");

    QSqlQueryModel *querymodel= new QSqlQueryModel();
    querymodel->setQuery(*query);
    ui->tableView_recp->setModel(querymodel);

}
