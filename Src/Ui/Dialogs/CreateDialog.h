#ifndef CREATEDIALOG_H
#define CREATEDIALOG_H

#include <QWidget>

namespace Ui {
class CreateDialog;
}

class CreateDialog : public QWidget
{
    Q_OBJECT

public:
    explicit CreateDialog(QWidget *parent = nullptr);
    ~CreateDialog();

private:
    Ui::CreateDialog *ui;
};

#endif // CREATEDIALOG_H
