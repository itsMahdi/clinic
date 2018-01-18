#include "drvisittimedialog.h"
#include "ui_drvisittimedialog.h"

DrVisitTimeDialog::DrVisitTimeDialog(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::DrVisitTimeDialog)
{
    ui->setupUi(this);
}

DrVisitTimeDialog::~DrVisitTimeDialog()
{
    delete ui;
}

void DrVisitTimeDialog::on_pushButton_back_v_time_clicked()
{
    close();
}
