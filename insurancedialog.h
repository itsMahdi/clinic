#ifndef INSURANCEDIALOG_H
#define INSURANCEDIALOG_H

#include <QDialog>

namespace Ui {
class InsuranceDialog;
}

class InsuranceDialog : public QDialog
{
    Q_OBJECT

public:
    explicit InsuranceDialog(QWidget *parent = 0);
    ~InsuranceDialog();

private slots:
    void on_pushButton_insu_detail_clicked();

    void on_pushButton_insu_back_clicked();

private:
    Ui::InsuranceDialog *ui;
};

#endif // INSURANCEDIALOG_H
