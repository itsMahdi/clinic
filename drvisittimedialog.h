#ifndef DRVISITTIMEDIALOG_H
#define DRVISITTIMEDIALOG_H

#include <QDialog>

namespace Ui {
class DrVisitTimeDialog;
}

class DrVisitTimeDialog : public QDialog
{
    Q_OBJECT

public:
    explicit DrVisitTimeDialog(QWidget *parent = 0);

    void update_table();
    void clear_form();
    ~DrVisitTimeDialog();

private slots:
    void on_pushButton_back_v_time_clicked();

    void on_pushButton_add_v_time_clicked();

    void on_lineEdit_id_editingFinished();

    void on_pushButton_v_time_clicked();

    void on_tableView_visit_time_doubleClicked(const QModelIndex &index);

    void on_pushButton_edit_v_time_clicked();

private:
    Ui::DrVisitTimeDialog *ui;
};

#endif // DRVISITTIMEDIALOG_H
