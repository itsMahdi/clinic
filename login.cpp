#include "login.h"
#include "ui_login.h"
#include <QMessageBox>
#include <QDebug>
#include <QSqlDatabase>
#include <QSqlDriver>
#include <QSqlError>
#include <QSqlQuery>
LogIn::LogIn(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::LogIn)
{
    ui->setupUi(this);
    connect_to_db();


}

LogIn::~LogIn()
{
    delete ui;
}

void LogIn::connect_to_db(){
    const QString DRIVER("QSQLITE");

    if(QSqlDatabase::isDriverAvailable("DRIVER"))
    {
        QSqlDatabase db = QSqlDatabase::addDatabase(DRIVER);

        db.setDatabaseName(":/resources/files/Main_database.db");

        if(!db.open())
        {
            qWarning() << "MainWindow::DatabaseConnect - ERROR: " << db.lastError().text();
            ui->label_connection_status->setText("Data Base is not connected");
        }
        else
            ui->label_connection_status->setText("Data Base is connected");
    }
    else
        qWarning() << "MainWindow::DatabaseConnect - ERROR: no driver " << DRIVER << " available";
}
