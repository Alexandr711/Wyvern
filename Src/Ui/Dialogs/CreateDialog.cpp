#include "CreateDialog.h"
#include "ui_CreateDialog.h"

CreateDialog::CreateDialog(QWidget *parent)
    : QWidget(parent)
    , ui(new Ui::CreateDialog)
{
    ui->setupUi(this);
}

CreateDialog::~CreateDialog()
{
    delete ui;
}
