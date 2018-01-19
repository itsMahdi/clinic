#include "doctordialog.h"
#include "ui_doctordialog.h"

#include <QDialog>
#include <QDebug>
#include <QSqlDatabase>
#include <QSqlDriver>
#include <QSqlError>
#include <QSqlQuery>
#include<QSqlQueryModel>
#include <QMessageBox>

DoctorDialog::DoctorDialog(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::DoctorDialog)
{
    ui->setupUi(this);

    ui->comboBox_gender_dr->addItem("male");
    ui->comboBox_gender_dr->addItem("female");

    ui->comboBox_expertise_dr->addItem("general practitioner");
    ui->comboBox_expertise_dr->addItem("cardiologist");
    ui->comboBox_expertise_dr->addItem("neurologist");
    ui->comboBox_expertise_dr->addItem("oncologist");
    ui->comboBox_expertise_dr->addItem("orthopedist");
    ui->comboBox_expertise_dr->addItem("plastic surgeon");
    ui->comboBox_expertise_dr->addItem("psychologist");
    ui->comboBox_expertise_dr->addItem("urologist");

    update_table();
}

DoctorDialog::~DoctorDialog()
{
    delete ui;
}

void DoctorDialog::on_pushButton_back_dr_clicked()
{
    close();
}

void DoctorDialog::on_pushButton_add_dr_clicked()
{
    int id = ui->lineEdit_id->text().toInt();
    QString name = ui->lineEdit_name->text();
    QString family = ui->lineEdit_family->text();
    QString exp = ui->comboBox_expertise_dr->currentText();
    QString gender = ui->comboBox_gender_dr->currentText();
    QString birthday = ui->lineEdit_birthday->text();
    QString tell = ui->lineEdit_tell->text();
    QString mail = ui->lineEdit_mail->text();
    QString address = ui->lineEdit_address->text();
    int cost = ui->lineEdit_cost->text().toInt();
    QString user = ui->lineEdit_user->text();
    QString pass=ui->lineEdit_pass->text();

    QSqlQuery query;
    query.prepare("INSERT INTO doctor_document(d_id,name,family,exp,gender,birthday,tell,mail,address,"
                  "cost,user,pass) "
                  "VALUES (:id,:name,:family,:exp,:gender,:birthday,:tell,:mail,:address,:cost,:user,:pass)");
    query.bindValue(":id",id);
    query.bindValue(":name",name);
    query.bindValue(":family",family);
    query.bindValue(":exp",exp);
    query.bindValue(":gender",gender);
    query.bindValue(":birthday",birthday);
    query.bindValue(":tell",tell);
    query.bindValue(":mail",mail);
    query.bindValue(":address",address);
    query.bindValue(":cost",cost);
    query.bindValue(":user",user);
    query.bindValue(":pass",pass);

    if(query.exec())
    {
        ui->label_status->setText("Dr."+name+" "+family+" added successfully");
        update_table();
    }
    else{
        QMessageBox::critical(this,"error","ERROR IN ADDING");
        qWarning()<<"ERROR IN ADD DOCTOR"<<query.lastError();
    }

}

void DoctorDialog::update_table(){
    QSqlDatabase db;
    QSqlQuery *query = new QSqlQuery(db);
    query->prepare("SELECT d_id,name,family,cost,exp,gender,birthday,tell,mail,address"
                   " FROM doctor_document");
    if (!query->exec())
        QMessageBox::critical(this,"ERROR","table error");

    QSqlQueryModel *querymodel= new QSqlQueryModel();
    querymodel->setQuery(*query);
    ui->tableView_dr->setModel(querymodel);
}

void DoctorDialog::on_pushButton_delete_dr_clicked()
{
    //QMessageBox
    int id = ui->lineEdit_id->text().toInt();

    QSqlQuery query;
    query.prepare("DELETE FROM doctor_document WHERE d_id=:id");
    query.bindValue(":id",id);
    if (!query.exec())
    {
        qWarning()<<"ERROR IN DELETE "<<query.lastError().text();
        QMessageBox::critical(this,"ERROR","sorry cant delete!");
    }
    else{
        ui->label_status->setText("Dr. "+ui->lineEdit_id->text()+" deleted successfully!");
        update_table();
    }
}

void DoctorDialog::on_tableView_dr_doubleClicked(const QModelIndex &index)
{
    int row = ui->tableView_dr->currentIndex().row();
    QString id = ui->tableView_dr->model()->index(row,0).data().toString();
    QSqlQuery query;
    query.prepare("SELECT * FROM doctor_document "
                  "WHERE d_id=:id ");
    query.bindValue(":id",id);
    if(!query.exec())
    {
        qWarning()<<"EROOR "<<query.lastError().text();
    }
    else{
        while(query.next())
        {
            ui->lineEdit_id->setText(query.value(0).toString());
            ui->lineEdit_name->setText(query.value(1).toString());
            ui->lineEdit_family->setText(query.value(2).toString());
            int index = ui->comboBox_expertise_dr->findText(query.value(3).toString());
            if (index>=0)
                ui->comboBox_expertise_dr->setCurrentIndex(index);
            index = ui->comboBox_gender_dr->findText(query.value(4).toString());
            if (index>=0)
                ui->comboBox_gender_dr->setCurrentIndex(index);
            ui->lineEdit_birthday->setText(query.value(5).toString());
            ui->lineEdit_tell->setText(query.value(6).toString());
            ui->lineEdit_mail->setText(query.value(7).toString());
            ui->lineEdit_address->setText(query.value(8).toString());
            ui->lineEdit_cost->setText(query.value(9).toString());
            ui->lineEdit_user->setText(query.value(10).toString());
            ui->lineEdit_pass->setText(query.value(11).toString());
        }
    }
}

void DoctorDialog::on_pushButton_edit_dr_clicked()
{
    int id = ui->lineEdit_id->text().toInt();
    QString name = ui->lineEdit_name->text();
    QString family = ui->lineEdit_family->text();
    QString exp = ui->comboBox_expertise_dr->currentText();
    QString gender = ui->comboBox_gender_dr->currentText();
    QString birthday = ui->lineEdit_birthday->text();
    QString tell = ui->lineEdit_tell->text();
    QString mail = ui->lineEdit_mail->text();
    QString address = ui->lineEdit_address->text();
    int cost = ui->lineEdit_cost->text().toInt();
    QString user = ui->lineEdit_user->text();
    QString pass=ui->lineEdit_pass->text();

    QSqlQuery query;
    query.prepare("UPDATE doctor_document SET name=:name,family=:family , "
                  "exp=:exp,"
                  "gender=:gender,birthday=:birthday,tell=:tell,"
                  "mail=:mail,address=:address,"
                  "cost=:cost,user=:user,pass=:pass "
                  "WHERE d_id=:id");
    query.bindValue(":id",id);
    query.bindValue(":name",name);
    query.bindValue(":family",family);
    query.bindValue(":exp",exp);
    query.bindValue(":gender",gender);
    query.bindValue(":birthday",birthday);
    query.bindValue(":tell",tell);
    query.bindValue(":mail",mail);
    query.bindValue(":address",address);
    query.bindValue(":cost",cost);
    query.bindValue(":user",user);
    query.bindValue(":pass",pass);

    if(query.exec())
    {
        ui->label_status->setText("Dr."+name+" "+family+" updated successfully");
        update_table();
    }
    else{
        QMessageBox::critical(this,"error","ERROR IN updating");
        qWarning()<<"ERROR IN update DOCTOR"<<query.lastError();
    }

}
