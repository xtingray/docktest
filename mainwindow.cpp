#include <QtWidgets>
#include "mainwindow.h"

MainWindow::MainWindow() : textEdit(new QTextEdit)
{
    setCentralWidget(textEdit);
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
    QListWidget *itemList = new QListWidget();
    itemList->addItems(QStringList() << "Hello! I am the bottom dock! ;)");

    addDockComponent(itemList, Qt::BottomDockWidgetArea, "Bottom Dock", QKeySequence(tr("Ctrl+O")));
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

    // return dockComponent;
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

