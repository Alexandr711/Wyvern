#ifndef MAINTOOLBAR_H
#define MAINTOOLBAR_H

#include <QToolBar>
#include <QToolButton>

class MainToolBar : public QToolBar
{
public:
    explicit MainToolBar(QWidget* parent = nullptr);
    ~MainToolBar();

    void setItems();

private:

    QToolButton* openButton;
    QToolButton* createButton;
    QToolButton* saveButton;
    QToolButton* saveAllButton;
    QToolButton* undoButton;
    QToolButton* returnButton;
};

#endif // MAINTOOLBAR_H
