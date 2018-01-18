#ifndef ADMIN_WELCOME_PAGE_H
#define ADMIN_WELCOME_PAGE_H

#include <QDialog>

namespace Ui {
class Admin_welcome_page;
}

class Admin_welcome_page : public QDialog
{
    Q_OBJECT

public:
    explicit Admin_welcome_page(QWidget *parent = 0);
    ~Admin_welcome_page();

private slots:
    void on_pushButton_back_clicked();

    void on_pushButton_doctor_info_clicked();

private:
    Ui::Admin_welcome_page *ui;
};

#endif // ADMIN_WELCOME_PAGE_H
