#ifndef INSUDETAILDIALOG_H
#define INSUDETAILDIALOG_H

#include <QDialog>

namespace Ui {
class InsuDetailDialog;
}

class InsuDetailDialog : public QDialog
{
    Q_OBJECT

public:
    explicit InsuDetailDialog(QWidget *parent = 0);
    ~InsuDetailDialog();

private slots:
    void on_pushButton_insu_det_back_clicked();

private:
    Ui::InsuDetailDialog *ui;
};

#endif // INSUDETAILDIALOG_H
