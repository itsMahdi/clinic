#ifndef RECEPTIONDIALOG_H
#define RECEPTIONDIALOG_H

#include <QDialog>

namespace Ui {
class ReceptionDialog;
}

class ReceptionDialog : public QDialog
{
    Q_OBJECT

public:
    explicit ReceptionDialog(QWidget *parent = 0);
    void update_table();
    ~ReceptionDialog();

private slots:
    void on_pushButton_back_recp_clicked();

    void on_pushButton_recp_search_pt_clicked();

    void on_comboBox_recp_problem_currentIndexChanged(const QString &arg1);

    void on_comboBox_recp_dr_currentIndexChanged(const QString &arg1);

    void on_lineEdit_recp_pt_id_editingFinished();

    void on_pushButton_2_clicked();

    void on_pushButton_add_recp_clicked();

private:
    Ui::ReceptionDialog *ui;
};

#endif // RECEPTIONDIALOG_H
