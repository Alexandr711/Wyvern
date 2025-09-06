#ifndef MECHANICALENGINERINGTABWIDGET_H
#define MECHANICALENGINERINGTABWIDGET_H

#include <QWidget>

namespace Ui {
class MechanicalEngineringTabWidget;
}

class MechanicalEngineringTabWidget : public QWidget
{
    Q_OBJECT

public:
    explicit MechanicalEngineringTabWidget(QWidget *parent = nullptr);
    ~MechanicalEngineringTabWidget();

private:
    Ui::MechanicalEngineringTabWidget *ui;
};

#endif // MECHANICALENGINERINGTABWIDGET_H
