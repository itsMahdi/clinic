#include "login.h"
#include "ui_login.h"


LogIn::LogIn(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::LogIn)
{
    ui->setupUi(this);
    ui->comboBox_type_user->addItem("monshi");
    ui->comboBox_type_user->addItem("doctor");
    ui->comboBox_type_user->addItem("admin");

    connect_to_db();


}

LogIn::~LogIn()
{
    delete ui;
}

void LogIn::connect_to_db(){
    const QString DRIVER("QSQLITE");

    if(QSqlDatabase::isDriverAvailable(DRIVER))
    {
        QSqlDatabase db = QSqlDatabase::addDatabase(DRIVER);

        db.setDatabaseName("/home/hebeton/qt-project/clinic-project/clinic/files/Main_database.db");

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
    int type = ui->comboBox_type_user->currentIndex();

    if(type == 0)//ui->lineEdit_username == 'admin' && ui->lineEdit_password=='admin')
    {
        users_welcome_page = new Users_welcome_page;
        users_welcome_page->show();
        hide();
    }
    else{
        if (type == 1)
        {
            doctor_dialog_page = new Doctor_dialog_page;
            doctor_dialog_page->show();
            hide();
        }

        if(type == 2)
        {
            admin_welcome_page = new Admin_welcome_page;
            admin_welcome_page->show();
            hide();
        }

    }


}
