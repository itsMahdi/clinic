#include "patientdialog.h"
#include "ui_patientdialog.h"
#include "users_welcome_page.h"

#include <QDialog>
#include <QDebug>
#include <QSqlDatabase>
#include <QSqlDriver>
#include <QSqlError>
#include <QSqlQuery>
#include<QSqlQueryModel>
#include <QMessageBox>

PatientDialog::PatientDialog(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::PatientDialog)
{
    ui->setupUi(this);
    update_table();

    ui->comboBox_gender->addItem("male");
    ui->comboBox_gender->addItem("female");

//    ui->comboBox_p_insu->addItem("tamin ejtemaee");
//    ui->comboBox_p_insu->addItem("sepah");
//    ui->comboBox_p_insu->addItem("niro haye mosalah");
//    ui->comboBox_p_insu->addItem("takmili");
//    ui->comboBox_p_insu->addItem("rostaee");
//    ui->comboBox_p_insu->addItem("no insurance");

    QSqlQuery query;
    query.prepare("SELECT name FROM insurance_company");
    if(query.exec())
    {
        ui->comboBox_p_insu->clear();
        while (query.next()) {
            ui->comboBox_p_insu->addItem(query.value(0).toString());
        }
    }

}

PatientDialog::~PatientDialog()
{
    delete ui;
}

void PatientDialog::on_pushButton_back_pt_clicked()
{
        close();
//    Users_welcome_page *b;
//    b = new Users_welcome_page;
//    b->show();
//    hide();

}

void PatientDialog::on_pushButton_add_pt_clicked()
{
    int id= ui->lineEdit_id_pt->text().toInt();
    QString name=ui->lineEdit_name_pt->text();
    QString family=ui->lineEdit_family_pt->text();
    QString gender = ui->comboBox_gender->currentText();
    QString birthday = ui->lineEdit_birthday_pt->text();
    QString tell = ui->lineEdit_tel_pt->text();
    QString address = ui->lineEdit_adrs_pt->text();
    QString insurancename = ui->comboBox_p_insu->currentText();
    int exp_m = ui->lineEdit_authority_m->text().toInt();
    int exp_y = ui->lineEdit_authority_y->text().toInt();
    int exp_d = ui->lineEdit_authority_d->text().toInt();
    QSqlQuery query;

    query.prepare("INSERT INTO patient_document  "
                  "(p_id,name,family,gender,birthday,tel,address,"
                  "insurance_name,expire_year,expire_mounth,expire_day)"
                  " VALUES(:id,:name,:family,:gender,:birthday,:tell,"
                  ":address,:insurancename,:exp_y,:exp_m,"
                  ":exp_d) ");
    query.bindValue(":id",id);
    query.bindValue(":name",name);
    query.bindValue(":family",family);
    query.bindValue(":gender",gender);
    query.bindValue(":birthday",birthday);
    query.bindValue(":tell",tell);
    query.bindValue(":address",address);
    query.bindValue(":insurancename",insurancename);
    query.bindValue(":exp_y",exp_y);
    query.bindValue(":exp_m",exp_m);
    query.bindValue(":exp_d",exp_d);

    if (query.exec())
    {
        ui->label_status->setText(name + family + "added successfully!");
        update_table();
    }
    else
    {
        qWarning()<<"ERROR IN ADD TO DB "<<query.lastError().text();
        QMessageBox::critical(this,"error in add","ERROR data not added");
    }

}


void PatientDialog::update_table(){
    QSqlDatabase db;
    QSqlQuery *query = new QSqlQuery(db);
    query->prepare("SELECT p_id,name,family,gender,birthday,tel,address,"
                   "insurance_name FROM patient_document");
    if (!query->exec())
        QMessageBox::critical(this,"ERROR","table error");

    QSqlQueryModel *querymodel= new QSqlQueryModel();
    querymodel->setQuery(*query);
    ui->tableView_pt->setModel(querymodel);

}

void PatientDialog::on_pushButton_edit_pt_clicked()
{
    int id= ui->lineEdit_id_pt->text().toInt();
    QString name=ui->lineEdit_name_pt->text();
    QString family=ui->lineEdit_family_pt->text();
    QString gender = ui->comboBox_gender->currentText();
    QString birthday = ui->lineEdit_birthday_pt->text();
    QString tell = ui->lineEdit_tel_pt->text();
    QString address = ui->lineEdit_adrs_pt->text();
    QString insurancename = ui->comboBox_p_insu->currentText();
    int exp_m = ui->lineEdit_authority_m->text().toInt();
    int exp_y = ui->lineEdit_authority_y->text().toInt();
    int exp_d = ui->lineEdit_authority_d->text().toInt();
    QSqlQuery query;

    query.prepare("UPDATE patient_document SET name=:name,family=:family "
                  ", gender=:gender "
                  ", birthday=:birthday "
                  ",tel=:tell"
                  ",address=:address"
                  ",insurance_name=:insurancename"
                  ",expire_year=:exp_y,expire_mounth=:exp_m,expire_day=:exp_d "
                  "WHERE p_id=:id");
    query.bindValue(":name",name);
    query.bindValue(":family",family);
    query.bindValue(":gender",gender);
    query.bindValue(":birthday",birthday);
    query.bindValue(":tell",tell);
    query.bindValue(":address",address);
    query.bindValue(":insurancename",insurancename);
    query.bindValue(":exp_y",exp_y);
    query.bindValue(":exp_m",exp_m);
    query.bindValue(":exp_d",exp_d);
    query.bindValue(":id",id);

    if (query.exec())
    {
        //ui->label_status->setText(name + family + "added successfully!");
        update_table();
    }
    else
    {
        qWarning()<<"ERROR IN update TO DB "<<query.lastError().text();
        QMessageBox::critical(this,"error in add","ERROR data not updated");
    }

}

void PatientDialog::on_tableView_pt_doubleClicked(const QModelIndex &index)
{
    //QString val = ui->tableView->model()->data(index).toString();
    int row = ui->tableView_pt->currentIndex().row();
    QString id = ui->tableView_pt->model()->index(row,0).data().toString();
    QSqlQuery query;
    query.prepare("select * from patient_document "
                  "where p_id=:id");
    query.bindValue(":id",id);
    if(!query.exec())
        qWarning()<<"SELECT ON TABLE WAS NOT OK";
    else{
        while(query.next())
        {
            ui->lineEdit_id_pt->setText(query.value(0).toString());
            ui->lineEdit_name_pt->setText(query.value(1).toString());
            ui->lineEdit_family_pt->setText(query.value(2).toString());
            int index = ui->comboBox_gender->findText(query.value(3).toString());
            if (index>=0)
                ui->comboBox_gender->setCurrentIndex(index);
            ui->lineEdit_birthday_pt->setText(query.value(4).toString());
            ui->lineEdit_tel_pt->setText(query.value(5).toString());
            ui->lineEdit_adrs_pt->setText(query.value(6).toString());
            index = ui->comboBox_p_insu->findText(query.value(7).toString());
                        if (index>=0)
                            ui->comboBox_p_insu->setCurrentIndex(index);
            ui->lineEdit_authority_y->setText(query.value(8).toString());
            ui->lineEdit_authority_m->setText(query.value(9).toString());
            ui->lineEdit_authority_d->setText(query.value(10).toString());
        }
    }


}

void PatientDialog::on_pushButton_delete_pt_clicked()
{
    int id= ui->lineEdit_id_pt->text().toInt();
    QSqlQuery query;
    query.prepare("delete from patient_document where p_id=:id ");
    query.bindValue(":id",id);
    if(!query.exec())
        qWarning()<<"ERROR IN DELETE";
    else
    {
        ui->label_status->setText("DELETED SUCCESSFULLY!");
        ui->lineEdit_id_pt->setText("");
        ui->lineEdit_name_pt->setText("");
        ui->lineEdit_family_pt->setText("");
        ui->comboBox_gender->setCurrentIndex(0);
        ui->lineEdit_birthday_pt->setText("");
        ui->lineEdit_tel_pt->setText("");
        ui->lineEdit_adrs_pt->setText("");
        ui->comboBox_p_insu->setCurrentIndex(0);
        ui->lineEdit_authority_y->setText("");
        ui->lineEdit_authority_m->setText("");
        ui->lineEdit_authority_d->setText("");

        update_table();
    }
}
