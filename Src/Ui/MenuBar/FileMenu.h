//This file is Main menu of application

#include <QMenu>
#include <QAction>

class FileMenu: public QMenu
{
    public:
        explicit FileMenu(QWidget* parent = nullptr);
        ~FileMenu();


        void setItems();
        void createMenuSetTitle(QString);
        void createFileActionSetTitle(QString);
        void createProjectActionSetTitle(QString);

        void openMenuSetTitle(QString);
        void openFileActionSetTitle(QString);
        void openProjectActionSetTitle(QString);

        //Getters
        QAction* getCreateFileAction();
        QAction* getCreateProjectAction();

        QAction* getOpenFileAction();
        QAction* getOpenProjectAction();


    private:
        QMenu* createMenu;
        QAction* createFileAction;
        QAction* createProjectAction;

        QMenu* openMenu;
        QAction* openFileAction;
        QAction* openProjectAction;
};
