#Creating lib for GUI

find_package(QT NAMES Qt6 Qt5 REQUIRED COMPONENTS Widgets)
find_package(Qt${QT_VERSION_MAJOR} REQUIRED COMPONENTS Widgets)
qt_standard_project_setup()

find_package(Qt6 REQUIRED COMPONENTS Widgets)

add_library(UiLib STATIC MenuBar/FileMenu.h MenuBar/FileMenu.cpp
             MainWindow/MainwWndow.h MainWindow/MainWindow.cpp
             ToolBars/MainToolBar.h ToolBars/MainToolBar.cpp
             Ui.h
)

target_link_libraries(UiLib PUBLIC Qt${QT_VERSION_MAJOR}::Widgets)
target_link_libraries(UiLib PRIVATE Qt6::Widgets)
