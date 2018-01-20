#ifndef VISITDIALOG_H
#define VISITDIALOG_H

#include <QDialog>

namespace Ui {
class VisitDialog;
}

class VisitDialog : public QDialog
{
    Q_OBJECT

public:
    int login_id;
    explicit VisitDialog(QWidget *parent = 0);
    void update_table();
    ~VisitDialog();

private slots:
    void on_pushButton_back_visit_clicked();

    void on_pushButton_clicked();

private:
    Ui::VisitDialog *ui;
};

#endif // VISITDIALOG_H
