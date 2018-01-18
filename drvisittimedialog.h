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
    ~DrVisitTimeDialog();

private slots:
    void on_pushButton_back_v_time_clicked();

private:
    Ui::DrVisitTimeDialog *ui;
};

#endif // DRVISITTIMEDIALOG_H
