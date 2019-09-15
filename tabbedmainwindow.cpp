#include "tabbedmainwindow.h"

TabbedMainWindow::TabbedMainWindow(QWidget *parent): MainWindow(parent)
{
    currentTab = new QTabWidget;
    connect(currentTab, SIGNAL(currentChanged(int)), this, SLOT(emitWidgetChanged(int)));
    setCentralWidget(currentTab);
}

TabbedMainWindow::~TabbedMainWindow()
{
}

void TabbedMainWindow::addWidget(QWidget *widget, bool persistant, int perspective)
{
    if (perspective & currentPerspective())
        currentTab->addTab(widget, widget->windowIcon(), widget->windowTitle());

    if (persistant)
        persistentWidgets << widget;

    pages << widget;
    tabs[widget] = perspective;
}

void TabbedMainWindow::removeWidget(QWidget *widget, bool force)
{
    if (force) 
        persistentWidgets.removeAll(widget);

    if (persistentWidgets.contains(widget))
        return;

    int index = currentTab->indexOf(widget);
    if (index >= 0)
        currentTab->removeTab(index);

    tabs.remove(widget);
    pages.removeAll(widget);
}

int TabbedMainWindow::tabCount()
{
    return pages.count();
}

void TabbedMainWindow::closeCurrentTab()
{
    int index = currentTab->currentIndex();
    if (index >= 0)
        removeWidget(currentTab->widget(index));
}

QTabWidget *TabbedMainWindow::tabWidget() const
{
    return currentTab;
}

void TabbedMainWindow::emitWidgetChanged(int index)
{
    if (index != -1) {
        switch (index) {
           case 0:
                setCurrentPerspective(Animation);
           break;
           case 1:
                setCurrentPerspective(Player);
           break;
           case 2:
                setCurrentPerspective(Help);
           break;
           case 3:
                setCurrentPerspective(News);
           break;
        }
        emit tabHasChanged(index);
    }
}

void TabbedMainWindow::setCurrentTab(int index)
{
    if (index != -1)
        currentTab->setCurrentIndex(index);
}
