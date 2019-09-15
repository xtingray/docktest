#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>
#include <QToolBar>
#include <QHash>
#include <QAction>
#include <QListWidget>
#include <QMenu>

#include "buttonbar.h"
#include "dockcomponent.h"

class MainWindow : public QMainWindow
{
    Q_OBJECT

public:
    MainWindow(QWidget *parent = nullptr);

    void setCurrentPerspective(int wsp);
    int currentPerspective() const;

    DockComponent * addDockComponent(QWidget *widget, Qt::DockWidgetArea area, int perspective,
                                     const QString &code, QKeySequence shortcut);

    void addToPerspective(QAction *action, int perspective);
    void addToPerspective(QWidget *widget, int workSpace);
    void addToPerspective(const QList<QAction *> &actions, int perspective);

signals:
    void perspectiveChanged(int wps);

private:
    void addButtonBar(Qt::ToolBarArea area);
    void createActions();
    Qt::ToolBarArea toToolBarArea(Qt::DockWidgetArea area);

    QHash<Qt::ToolBarArea, ButtonBar *> m_buttonBars;
    QHash<ButtonBar *, QList<DockComponent*> > m_dockComponents;
    int perspective;
    QHash<QWidget *, int> m_managedWidgets;
    QHash<QAction *, int> m_managedActions;
};
#endif
