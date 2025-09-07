#ifndef CAD3DTOOLSWIDGET_H
#define CAD3DTOOLSWIDGET_H

#include <QWidget>
#include <QToolButton>
#include <QComboBox>
#include <QHBoxLayout>
#include <QGridLayout>
#include <QLabel>

class CAD3DToolsWidget : public QWidget
{
    Q_OBJECT
public:
    explicit CAD3DToolsWidget(QWidget *parent = nullptr);

    void setItems();

    inline void setToolTipLineButton(QString title){lineButton->setToolTip(title);}
    inline void setToolTipArcButton(QString title){arcButton->setToolTip(title);}


private:
    QHBoxLayout* mainHBoxLayout;

    QGridLayout* primitiveGridLayout;
    QToolButton* lineButton;
    QToolButton* arcButton;
    QToolButton* polylineButton;
    QToolButton* circleButton;
    QToolButton* rectangleButton;

    QLabel* separator;

    QGridLayout* figure3DGridLayout;
    QComboBox* figure3DComboBox;
    QToolButton* holeButton;
    QToolButton* pullButton;
    QToolButton* chamferButton;
};

#endif // CAD3DTOOLSWIDGET_H
