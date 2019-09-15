#ifndef TABBEDMAINWINDOW_H
#define TABBEDMAINWINDOW_H

#include "mainwindow.h"

#include <QTabWidget>

class TabbedMainWindow : public MainWindow
{
    Q_OBJECT

    public:
        enum Perspective {
             Animation = 0x01,
             Player = 0x02,
             Help = 0x04,
             News = 0x08,
             All = Animation | Player | Help | News
        };

        TabbedMainWindow(QWidget *parent = nullptr);
        ~TabbedMainWindow();

        void addWidget(QWidget *widget, bool persistant = true, int perspective = All);
        void removeWidget(QWidget *widget, bool force = false);

        QTabWidget *tabWidget() const;
        void setCurrentTab(int index);
        int tabCount(); 

    protected slots:
        void closeCurrentTab();

    signals:
        void widgetChanged(QWidget *widget);
        void tabHasChanged(int);

    private slots:
        void emitWidgetChanged(int index);

    private:
        QTabWidget *currentTab;
        QWidgetList persistentWidgets;
        QHash<QWidget *, int> tabs;
        QWidgetList pages;
};

#endif
