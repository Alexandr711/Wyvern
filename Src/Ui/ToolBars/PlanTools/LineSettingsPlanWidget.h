#ifndef LINESETTINGSPLANWIDGET_H
#define LINESETTINGSPLANWIDGET_H

#include <QWidget>

namespace Ui {
class LineSettingsPlanWidget;
}

class LineSettingsPlanWidget : public QWidget
{
    Q_OBJECT

public:
    explicit LineSettingsPlanWidget(QWidget *parent = nullptr);
    ~LineSettingsPlanWidget();

private:
    Ui::LineSettingsPlanWidget *ui;
};

#endif // LINESETTINGSPLANWIDGET_H
