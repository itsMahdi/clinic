#include "admin_welcome_page.h"
#include "ui_admin_welcome_page.h"
#include<login.h>
#include "doctordialog.h"
#include "drvisittimedialog.h"

Admin_welcome_page::Admin_welcome_page(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::Admin_welcome_page)
{
    ui->setupUi(this);

}

Admin_welcome_page::~Admin_welcome_page()
{
    delete ui;
}

void Admin_welcome_page::on_pushButton_back_clicked()
{
    LogIn *a;
    a = new LogIn;
    a->show();
    hide();
}

void Admin_welcome_page::on_pushButton_doctor_info_clicked()
{
    DoctorDialog doctorDialog;
    doctorDialog.setModal(true);
    doctorDialog.exec();

}

void Admin_welcome_page::on_pushButton_visit_time_clicked()
{
    DrVisitTimeDialog drVisitTimeDialog;
    drVisitTimeDialog.setModal(true);
    drVisitTimeDialog.exec();

}
