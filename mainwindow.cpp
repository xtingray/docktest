#include <QtWidgets>
#include "mainwindow.h"

MainWindow::MainWindow(QWidget *parent): QMainWindow(parent)
{
    addButtonBar(Qt::LeftToolBarArea);
    addButtonBar(Qt::RightToolBarArea);
    addButtonBar(Qt::BottomToolBarArea);

    createActions();

    setDockNestingEnabled(false);
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

DockComponent * MainWindow::addDockComponent(QWidget *widget, Qt::DockWidgetArea area, int ws,
                                             const QString &code, QKeySequence shortcut)
{
    DockComponent *dockComponent = new DockComponent(widget->windowTitle(), QPixmap("icons/test.png"), code);

    dockComponent->setShortcut(shortcut);
    dockComponent->setWidget(widget);
    dockComponent->setPerspective(ws);
    dockComponent->button()->setArea(toToolBarArea(area));
    m_buttonBars[toToolBarArea(area)]->addButton(dockComponent->button());

    addDockWidget(area, dockComponent);

    m_dockComponents[m_buttonBars[toToolBarArea(area)]] << dockComponent;

    return dockComponent;
}

Qt::ToolBarArea MainWindow::toToolBarArea(Qt::DockWidgetArea area)
{
    switch (area) {
        case Qt::LeftDockWidgetArea:
           {
             return Qt::LeftToolBarArea;
           }
        case Qt::RightDockWidgetArea:
           {
             return Qt::RightToolBarArea;
           }
        case Qt::TopDockWidgetArea:
           {
             return Qt::TopToolBarArea;
           }
        case Qt::BottomDockWidgetArea:
           {
             return Qt::BottomToolBarArea;
           }
        default:
           {
           }
    }

    return Qt::LeftToolBarArea;
}

void MainWindow::setCurrentPerspective(int workSpace)
{
    if (perspective == workSpace)
        return;

    typedef QList<DockComponent *> Views;
    QList<Views > viewsList = m_dockComponents.values();

    QHash<ButtonBar *, int> hideButtonCount;
    foreach (Views views, viewsList) {
        foreach (DockComponent *view, views) {
            ButtonBar *bar = m_buttonBars[view->button()->area()];

            if (view->perspective() & workSpace) {
                bar->enable(view->button());
                if (view->isExpanded()) {
                    view->blockSignals(true);
                    view->show(); 
                    view->blockSignals(false);
                }
            } else {
                bar->disable(view->button());
                if (view->isExpanded()) {
                    view->blockSignals(true);
                    view->close();
                    view->blockSignals(false);
                }
                hideButtonCount[bar]++;
            }

            if (bar->isEmpty() && bar->isVisible()) {
                bar->hide();
            } else {
                if (!bar->isVisible())
                    bar->show();
            }
        }
    }

    QHashIterator<ButtonBar *, int> barIt(hideButtonCount);
    // This loop hides the bars with no buttons
    while (barIt.hasNext()) {
        barIt.next();
        if (barIt.key()->count() == barIt.value())
            barIt.key()->hide();
    }

    perspective = workSpace;
    emit perspectiveChanged(perspective);
}

int MainWindow::currentPerspective() const
{
    return perspective;
}

void MainWindow::addToPerspective(QAction *action, int workSpace)
{
    if (!m_managedActions.contains(action)) {
        m_managedActions.insert(action, workSpace);

        if (!(workSpace & perspective))
            action->setVisible(false);
    }
}

void MainWindow::addToPerspective(const QList<QAction *> &actions, int workSpace)
{
    foreach (QAction *action, actions)
        addToPerspective(action, workSpace);
}

void MainWindow::addToPerspective(QWidget *widget, int workSpace)
{
    if (QToolBar *bar = dynamic_cast<QToolBar*>(widget)) {
        if (toolBarArea(bar) == 0)
            addToolBar(bar);
    }

    if (!m_managedWidgets.contains(widget)) {
        m_managedWidgets.insert(widget, workSpace);

        if (!(workSpace & perspective))
            widget->hide();
    }
}
