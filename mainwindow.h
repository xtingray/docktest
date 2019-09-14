#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>
#include <QHash>
#include <QAction>
#include <QListWidget>
#include <QMenu>
#include <QTextEdit>

#include "buttonbar.h"
#include "dockcomponent.h"

class MainWindow : public QMainWindow
{
    Q_OBJECT

public:
    MainWindow();

private:
    void addButtonBar(Qt::ToolBarArea area);
    void createActions();
    void createDockWindow();
    void addDockComponent(QWidget *widget, Qt::DockWidgetArea area, const QString &code, QKeySequence shortcut);
    Qt::ToolBarArea toToolBarArea(Qt::DockWidgetArea area);

    QTextEdit *textEdit;
    QHash<Qt::ToolBarArea, ButtonBar *> m_buttonBars;
    QHash<ButtonBar *, QList<DockComponent*> > m_dockComponents;
};
#endif
