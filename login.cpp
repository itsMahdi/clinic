#include "login.h"
#include "ui_login.h"

LogIn::LogIn(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::LogIn)
{
    ui->setupUi(this);
}

LogIn::~LogIn()
{
    delete ui;
}

LogIn::connect_to_db(){
    const QString DRIVER("QSQLITE");

    if(QSqlDatabase::isDriverAvailable("DRIVER"))
    {
        QSqlDatabase db = QSqlDatabase::addDatabase(DRIVER);

        db.setDatabaseName(":/resources/files/Main_database.db");

        if(!db.open())
        {
            qWarning() << "MainWindow::DatabaseConnect - ERROR: " << db.lastError().text();
           // ui->label_status->setText("Data Base is not connected");
        }
        //else
           // ui->label_status->setText("Data Base is connected");
    }
    else
        qWarning() << "MainWindow::DatabaseConnect - ERROR: no driver " << DRIVER << " available";
}
