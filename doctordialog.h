#ifndef DOCTORDIALOG_H
#define DOCTORDIALOG_H

#include <QDialog>

namespace Ui {
class DoctorDialog;
}

class DoctorDialog : public QDialog
{
    Q_OBJECT

public:
    explicit DoctorDialog(QWidget *parent = 0);
    ~DoctorDialog();

private slots:
    void on_pushButton_back_dr_clicked();

private:
    Ui::DoctorDialog *ui;
};

#endif // DOCTORDIALOG_H
