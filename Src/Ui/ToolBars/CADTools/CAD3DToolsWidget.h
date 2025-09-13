#ifndef CAD3DTOOLSWIDGET_H
#define CAD3DTOOLSWIDGET_H

#include <QWidget>
#include <QToolButton>
#include <QComboBox>
#include <QHBoxLayout>
#include <QGridLayout>
#include <QLabel>
#include <QVBoxLayout>

class QJsonObject;

class CAD3DToolsWidget : public QWidget
{
    Q_OBJECT
public:
    explicit CAD3DToolsWidget(QWidget *parent = nullptr);
    ~CAD3DToolsWidget();

    void setItems();


    inline void setToolTipLineButton(QString title){lineButton->setToolTip(title);}
    inline void setToolTipArcButton(QString title){arcButton->setToolTip(title);}
    inline void setToolTipPolylineButton(QString title){polylineButton->setToolTip(title);}
    inline void setToolTipCircleButton(QString title){circleButton->setToolTip(title);}
    inline void setToolTipRectangleButton(QString title){rectangleButton->setToolTip(title);}

    inline void setToolTipSphere(QString title){sphereButton->setToolTip(title);}
    inline void setToolTipCilindr(QString title){cilinderButton->setToolTip(title);}
    inline void setToolTipParallelepiped(QString title){parallelepipedButton->setToolTip(title);}
    inline void setToolTipCone(QString title){coneButton->setToolTip(title);}
    inline void setToolTipPyramid(QString title){pyramideButton->setToolTip(title);}
    inline void setToolTipTorus(QString title){torusButton->setToolTip(title);}

private:
    QHBoxLayout* mainHBoxLayout;

    QGridLayout* primitiveGridLayout;
    QToolButton* lineButton;
    QToolButton* arcButton;
    QToolButton* polylineButton;
    QToolButton* circleButton;
    QToolButton* rectangleButton;

    QLabel* separator;


    QVBoxLayout* figure3DVBoxLayout;
    QHBoxLayout* figure3DHBoxLayout;
    QToolButton* cilinderButton;
    QToolButton* sphereButton;
    QToolButton* parallelepipedButton;
    QToolButton* coneButton;
    QToolButton* pyramideButton;
    QToolButton* torusButton;

    QHBoxLayout* xyzHBoxLayout;
    QToolButton* xyButton;
    QToolButton* xzButton;
    QToolButton* yzButton;
    QToolButton* xyzButton;
    QToolButton* xyFButton;
    QToolButton* xzFButton;
    QToolButton* yzFButton;

    QGridLayout* figure3DGridLayout;
    QToolButton* holeButton;
    QToolButton* pullButton;
    QToolButton* chamferButton;
    QToolButton* grooveButton;

};

#endif // CAD3DTOOLSWIDGET_H
