#ifndef USERS_WELCOME_PAGE_H
#define USERS_WELCOME_PAGE_H

#include <QDialog>

namespace Ui {
class Users_welcome_page;
}

class Users_welcome_page : public QDialog
{
    Q_OBJECT

public:
    explicit Users_welcome_page(QWidget *parent = 0);
    ~Users_welcome_page();

private slots:
    void on_pushButton_back_clicked();

    void on_pushButton_pt_duc_clicked();

    void on_pushButton_reception_clicked();

    void on_pushButton_insurance_clicked();

private:
    Ui::Users_welcome_page *ui;
};

#endif // USERS_WELCOME_PAGE_H
