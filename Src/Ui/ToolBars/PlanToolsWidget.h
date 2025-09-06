#ifndef PLANTOOLSWIDGET_H
#define PLANTOOLSWIDGET_H

#include <QWidget>
#include <QToolButton>
#include <QHBoxLayout>

class PlanToolsWidget: public QWidget
{
    Q_OBJECT
public:
    PlanToolsWidget(QWidget* parent = nullptr);

private:
    QToolButton* lineButton;
    QToolButton* arcButton;
    QToolButton* polylineButton;
    QToolButton* circleButton;
    QToolButton* rectangleButton;

    Q
};

#endif // PLANTOOLSWIDGET_H
