//This file is Main menu of application

#include <QMenu>
#include <QAction>

class FileMenu: public QMenu
{
    public:
        explicit FileMenu(QWidget* parent = nullptr);
        ~FileMenu();


        void setItems();

    private:
        QMenu* createMenu;
        QAction* createFileAction;
        QAction* createProjectAction;

        QMenu* openMenu;
        QAction* openFileAction;
        QAction* openProjectAction;


};
