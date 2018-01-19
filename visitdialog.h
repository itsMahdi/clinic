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
    explicit VisitDialog(QWidget *parent = 0);
    ~VisitDialog();

private slots:
    void on_pushButton_back_visit_clicked();

private:
    Ui::VisitDialog *ui;
};

#endif // VISITDIALOG_H
