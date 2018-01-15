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
    ~ReceptionDialog();

private:
    Ui::ReceptionDialog *ui;
};

#endif // RECEPTIONDIALOG_H
