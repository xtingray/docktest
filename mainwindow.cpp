#include <QtWidgets>
#include "mainwindow.h"

MainWindow::MainWindow() : textEdit(new QTextEdit)
{
    setCentralWidget(textEdit);
    addButtonBar(Qt::LeftToolBarArea);
    addButtonBar(Qt::RightToolBarArea);
    addButtonBar(Qt::BottomToolBarArea);

    createActions();
    createDockWindow();

    setWindowTitle(tr("DockWidget Test"));
}

void MainWindow::addButtonBar(Qt::ToolBarArea area)
{
    ButtonBar *bar = new ButtonBar(area, this);
    addToolBar(area, bar);
    m_buttonBars.insert(area, bar);
}

void MainWindow::createActions()
{
    QMenu *menu = menuBar()->addMenu(tr("&File"));

    QAction *action = menu->addAction(tr("&Quit"), this, &QWidget::close);
    action->setShortcuts(QKeySequence::Quit);
    action->setStatusTip(tr("Quit the application"));
}

void MainWindow::createDockWindow()
{
    QListWidget *leftList = new QListWidget();
    leftList->addItems(QStringList() << "Hello! I am the left dock! ;)");

    addDockComponent(leftList, Qt::LeftDockWidgetArea, "Left Dock", QKeySequence(tr("Ctrl+B")));

    QListWidget *rightList = new QListWidget();
    rightList->addItems(QStringList() << "Hello! I am the right dock! ;)");

    addDockComponent(rightList, Qt::RightDockWidgetArea, "Right Dock", QKeySequence(tr("Ctrl+R")));

    QListWidget *bottomList = new QListWidget();
    bottomList->addItems(QStringList() << "Hello! I am the bottom dock! ;)");

    addDockComponent(bottomList, Qt::BottomDockWidgetArea, "Bottom Dock", QKeySequence(tr("Ctrl+B")));
}

void MainWindow::addDockComponent(QWidget *widget, Qt::DockWidgetArea area, const QString &code, QKeySequence shortcut)
{
    DockComponent *dockComponent = new DockComponent(widget->windowTitle(), QPixmap("icons/test.png"), code);

    dockComponent->setShortcut(shortcut);
    dockComponent->setWidget(widget);
    dockComponent->button()->setArea(toToolBarArea(area));
    m_buttonBars[toToolBarArea(area)]->addButton(dockComponent->button());

    addDockWidget(area, dockComponent);

    m_dockComponents[m_buttonBars[toToolBarArea(area)]] << dockComponent;
}

Qt::ToolBarArea MainWindow::toToolBarArea(Qt::DockWidgetArea area)
{
    switch (area) {
        case Qt::LeftDockWidgetArea:
           {
             return Qt::LeftToolBarArea;
           }
           break;
        case Qt::RightDockWidgetArea:
           {
             return Qt::RightToolBarArea;
           }
           break;
        case Qt::TopDockWidgetArea:
           {
             return Qt::TopToolBarArea;
           }
           break;
        case Qt::BottomDockWidgetArea:
           {
             return Qt::BottomToolBarArea;
           }
           break;
        default:
           {
           }
           break;
    }

    return Qt::LeftToolBarArea;
}

