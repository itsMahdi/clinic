#include "login.h"
#include "ui_login.h"

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
    //db
    if(QSqlDatabase::isDriverAvailable(DRIVER))
    {
        QSqlDatabase db = QSqlDatabase::addDatabase(DRIVER);

        db.setDatabaseName("/home/fateme/projects/database/clinic/files/Main_database.db");

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

void LogIn::on_pushButton_login_clicked()
{
    if(ui->checkBox_admin->isChecked())
    {
        // you should go in admin mode
        if(1 )//ui->lineEdit_username == 'admin' && ui->lineEdit_password=='admin')
        {
            admin_welcome_page = new Admin_welcome_page;
            admin_welcome_page->show();
            hide();
        }
    }
    else
        if(1 )//ui->lineEdit_username == 'admin' && ui->lineEdit_password=='admin')
        {
            users_welcome_page = new Users_welcome_page;
            users_welcome_page->show();
            hide();
        }
}
