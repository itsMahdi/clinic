#ifndef DOCTOR_DIALOG_PAGE_H
#define DOCTOR_DIALOG_PAGE_H

#include <QDialog>

namespace Ui {
class Doctor_dialog_page;
}

class Doctor_dialog_page : public QDialog
{
    Q_OBJECT

public:
    explicit Doctor_dialog_page(QWidget *parent = 0);
    ~Doctor_dialog_page();

private:
    Ui::Doctor_dialog_page *ui;
};

#endif // DOCTOR_DIALOG_PAGE_H
