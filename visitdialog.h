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

private:
    Ui::VisitDialog *ui;
};

#endif // VISITDIALOG_H
