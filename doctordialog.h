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
    void update_table();
    void clear_form();
    ~DoctorDialog();

private slots:
    void on_pushButton_back_dr_clicked();

    void on_pushButton_add_dr_clicked();

    void on_pushButton_delete_dr_clicked();

    void on_tableView_dr_doubleClicked(const QModelIndex &index);

    void on_pushButton_edit_dr_clicked();

private:
    Ui::DoctorDialog *ui;
};

#endif // DOCTORDIALOG_H
