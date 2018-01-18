#ifndef PATIENTDIALOG_H
#define PATIENTDIALOG_H

#include <QDialog>

namespace Ui {
class PatientDialog;
}

class PatientDialog : public QDialog
{
    Q_OBJECT

public:
    explicit PatientDialog(QWidget *parent = 0);

    void update_table();
    ~PatientDialog();

private slots:
    void on_pushButton_back_pt_clicked();

    void on_pushButton_add_pt_clicked();

private:
    Ui::PatientDialog *ui;
};

#endif // PATIENTDIALOG_H
