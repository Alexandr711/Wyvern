#include "HelpMenu.h"

HelpMenu::HelpMenu(QWidget* parent):
    QMenu(parent)
{
    changeLanguageMenu = new QMenu(this);
    englishAction = new QAction(changeLanguageMenu);
    russianAction = new QAction(changeLanguageMenu);

    changeColorThemeMenu = new QMenu(this);
    darkColorTheme = new QAction(changeColorThemeMenu);
    lightColorTheme = new QAction(changeColorThemeMenu);

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
    englishAction->setText("English");
    russianAction->setCheckable(true);
    russianAction->setText("Русский");

    addSeparator();
    addAction(helpAction);
}
