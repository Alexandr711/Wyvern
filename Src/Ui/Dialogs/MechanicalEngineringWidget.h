#ifndef MECHANICALENGINERINGWIDGET_H
#define MECHANICALENGINERINGWIDGET_H

#include <QWidget>

namespace Ui {
class MechanicalEngineringWidget;
}

class MechanicalEngineringWidget : public QWidget
{
    Q_OBJECT

public:
    explicit MechanicalEngineringWidget(QWidget *parent = nullptr);
    ~MechanicalEngineringWidget();

private:
    Ui::MechanicalEngineringWidget *ui;
};

#endif // MECHANICALENGINERINGWIDGET_H
