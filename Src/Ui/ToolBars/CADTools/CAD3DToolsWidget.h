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
    void setItemsText();
    void setItemsIcons();

    inline void setToolTipLineButton(QString title){lineButton->setToolTip(title);}
    inline void setToolTipArcButton(QString title){arcButton->setToolTip(title);}
    inline void setToolTipPolylineButton(QString title){polylineButton->setToolTip(title);}
    inline void setToolTipCircleButton(QString title){circleButton->setToolTip(title);}
    inline void setToolTipRectangleButton(QString title){rectangleButton->setToolTip(title);}

    inline void setSphereString(QString title){sphereString = title;}
    inline void setCilindrString(QString title){cilindrString = title;}
    inline void setParallelepipedString(QString title){parallelepipedString = title;}
    inline void setConeString(QString title){coneString = title;}
    inline void setPyramidString(QString title){pyramidString = title;}
    inline void setTorusString(QString title){torusString = title;}

    inline void setSphereIcon(QString title){sphereIcon = title;}
    inline void setCilindrIcon(QString title){cilindrIcon = title;}
    inline void setParallelepipedIcon(QString title){parallelepipedIcon = title;}
    inline void setConeIcon(QString title){coneIcon = title;}
    inline void setPyramidIcon(QString title){pyramidIcon = title;}
    inline void setTorusIcon(QString title){torusIcon = title;}

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
    QComboBox* figure3DComboBox;
    QHBoxLayout* xyzHBoxLayout;
    QToolButton* xyButton;
    QToolButton* xzButton;
    QToolButton* yzButton;
    QToolButton* xyzButton;

    QGridLayout* figure3DGridLayout;
    QToolButton* holeButton;
    QToolButton* pullButton;
    QToolButton* chamferButton;
    QToolButton* grooveButton;

    //Names and Icons strings of figure3DComboBox
    QString sphereString;
    QString cilindrString;
    QString parallelepipedString;
    QString coneString;
    QString pyramidString;
    QString torusString;

    QString sphereIcon;
    QString cilindrIcon;
    QString parallelepipedIcon;
    QString coneIcon;
    QString pyramidIcon;
    QString torusIcon;
};

#endif // CAD3DTOOLSWIDGET_H
