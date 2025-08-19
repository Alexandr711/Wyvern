#ifndef MAINTOOLBAR_H
#define MAINTOOLBAR_H

#include <QToolBar>
#include <QToolButton>
#include <QString>

class MainToolBar : public QToolBar
{
public:
    explicit MainToolBar(QWidget* parent = nullptr);
    ~MainToolBar();

    void setItems();
    
    void setOpenButtonToolTipTitle(QString);
    void setCreateButtonToolTipTitle(QString);
    void setSaveButtonToolTipTitle(QString);
    void setSaveAllButtonToolTipTitle(QString);
    void setUndoButtonToolTipTitle(QString);
    void setReturnButtonToolTipTitle(QString);

    QToolButton* getOpenButton();
    QToolButton* getCreateButton();
    QToolButton* getSaveButton();
    QToolButton* getSaveAllButton();
    QToolButton* getUndoButton();
    QToolButton* getReturnButton();

private:

    QToolButton* openButton;
    QToolButton* createButton;
    QToolButton* saveButton;
    QToolButton* saveAllButton;
    QToolButton* undoButton;
    QToolButton* returnButton;
};

#endif // MAINTOOLBAR_H
