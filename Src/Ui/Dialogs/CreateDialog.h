#ifndef CREATEDIALOG_H
#define CREATEDIALOG_H

#include <QFileDialog>

class CreateDialog : public QFileDialog
{
public:
    CreateDialog(QWidget* parent = nullptr);
};

#endif // CREATEDIALOG_H
