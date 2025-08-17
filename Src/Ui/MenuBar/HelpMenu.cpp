#include "HelpMenu.h"

HelpMenu::HelpMenu(QWidget* parent):
    QMenu(parent)
{
    changeLanguageMenu = new QMenu(this);
    englishAction = new QAction(this);
    russianAction = new QAction(this);

    changeColorThemeMenu = new QMenu(this);
    darkColorTheme = new QAction(this);
    lightColorTheme = new QAction(this);

    helpAction = new QAction(this);
}

HelpMenu::~HelpMenu(){}

void HelpMenu::setItems()
{
    addMenu(changeColorThemeMenu);
    changeColorThemeMenu->addAction(darkColorTheme);
    changeColorThemeMenu->addAction(lightColorTheme);
    darkColorTheme->setCheckable(true);
    lightColorTheme->setCheckable(true);

    addMenu(changeLanguageMenu);
    changeLanguageMenu->addAction(englishAction);
    changeLanguageMenu->addAction(russianAction);
    englishAction->setCheckable(true);
    russianAction->setCheckable(true);

    addSeparator();
    addAction(helpAction);
}
