#ifndef OPENDIALOG_H
#define OPENDIALOG_H

#include <QFileDialog>

class OpenDialog : public QFileDialog
{
public:
    OpenDialog(QWidget* parent = nullptr);
};

#endif // OPENDIALOG_H
