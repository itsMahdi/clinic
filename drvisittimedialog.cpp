#include "drvisittimedialog.h"
#include "ui_drvisittimedialog.h"

#include <QDialog>
#include <QDebug>
#include <QSqlDatabase>
#include <QSqlDriver>
#include <QSqlError>
#include <QSqlQuery>
#include<QSqlQueryModel>
#include <QMessageBox>

DrVisitTimeDialog::DrVisitTimeDialog(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::DrVisitTimeDialog)
{
    ui->setupUi(this);

    ui->comboBox_weekday->addItem("Saturday");
    ui->comboBox_weekday->addItem("Sunday");
    ui->comboBox_weekday->addItem("Monday");
    ui->comboBox_weekday->addItem("Tuesday");
    ui->comboBox_weekday->addItem("Wednesday");
    ui->comboBox_weekday->addItem("Thursday");
    ui->comboBox_weekday->addItem("Friday");

    update_table();

}

DrVisitTimeDialog::~DrVisitTimeDialog()
{
    delete ui;
}

void DrVisitTimeDialog::on_pushButton_back_v_time_clicked()
{
    close();
}

void DrVisitTimeDialog::on_pushButton_add_v_time_clicked()
{
    int id = ui->lineEdit_id->text().toInt();
    QString name = ui->lineEdit_name->text();
    QString day = ui->comboBox_weekday->currentText();
    QString start_time = ui->lineEdit_from->text();
    QString finish_time = ui->lineEdit_till->text();

    QSqlQuery query;
    query.prepare("INSERT INTO dr_visit_time(d_id ,name ,day ,start , finish ) "
                  "VALUES ( :d_id , :name , :day , :start_time , :finish_time )");
    query.bindValue(":d_id",id);
    query.bindValue(":name",name);
    query.bindValue(":day",day);
    query.bindValue(":start_time",start_time);
    query.bindValue(":finish_time",finish_time);

    if (query.exec())
    {
        //ui->label_status->setText( "added successfully!");
        update_table();
        //clear_form();
    }
    else
    {
        qWarning()<<"ERROR IN ADD TO DB "<<query.lastError().text();
        QMessageBox::critical(this,"error in add","ERROR data not added");
    }

}

void DrVisitTimeDialog::update_table(){
    QSqlDatabase db;
    QSqlQuery *query = new QSqlQuery(db);
    query->prepare("SELECT * FROM dr_visit_time");
    if (!query->exec())
        QMessageBox::critical(this,"ERROR","table error");

    QSqlQueryModel *querymodel= new QSqlQueryModel();
    querymodel->setQuery(*query);
    ui->tableView_visit_time->setModel(querymodel);
}

void DrVisitTimeDialog::on_lineEdit_id_editingFinished()
{
    int id = ui->lineEdit_id->text().toInt();

    QSqlQuery query;
    query.prepare("SELECT * FROM doctor_document WHERE d_id=:id");
    query.bindValue(":id",id);
    if (query.exec())
    {
        QString name;
        while(query.next())
        name = query.value(1).toString();

        ui->lineEdit_name->setText(name);
    }
    else
        qWarning()<<"ERROR in getting name :"<<query.lastError().text();

}

void DrVisitTimeDialog::on_pushButton_v_time_clicked() //delete
{
    int id = ui->lineEdit_id->text().toInt();

    QSqlQuery query;
    query.prepare("DELETE FROM dr_visit_time WHERE d_id=:id");
    query.bindValue(":id",id);
    if (query.exec())
    {
        QMessageBox::information(this,"delete visit time","selected visit time deleted!");
        clear_form();
    }
    else
        qWarning()<<"ERROR in getting name :"<<query.lastError().text();
}

void DrVisitTimeDialog::on_tableView_visit_time_doubleClicked(const QModelIndex &index)
{
    int row = ui->tableView_visit_time->currentIndex().row();
    QString id = ui->tableView_visit_time->model()->index(row,0).data().toString();
    QSqlQuery query;
    query.prepare("select * from dr_visit_time "
                  "where d_id=:id");
    query.bindValue(":id",id);
    if(!query.exec())
        qWarning()<<"SELECT ON TABLE WAS NOT OK";
    else{
        while(query.next())
        {
            ui->lineEdit_id->setText(query.value(0).toString());
            ui->lineEdit_name->setText(query.value(1).toString());
            int index = ui->comboBox_weekday->findText(query.value(2).toString());
            if (index>=0)
                ui->comboBox_weekday->setCurrentIndex(index);
            ui->lineEdit_from->setText(query.value(3).toString());
            ui->lineEdit_till->setText(query.value(4).toString());
        }
    }
}


void DrVisitTimeDialog::clear_form(){
    ui->lineEdit_id->setText("");
    ui->lineEdit_name->setText("");
    ui->comboBox_weekday->setCurrentIndex(0);
    ui->lineEdit_from->setText("");
    ui->lineEdit_till->setText("");
}

void DrVisitTimeDialog::on_pushButton_edit_v_time_clicked()
{

}
