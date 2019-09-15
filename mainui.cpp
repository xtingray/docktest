#include "mainui.h"

#include <QBoxLayout>
#include <QDebug>

MainUI::MainUI(): TabbedMainWindow()
{
    setWindowTitle("Dock Test");
    setWindowIcon(QIcon("icons/test.png"));
    setObjectName("TupMainWindow");

    setAcceptDrops(true);

    setCurrentPerspective(Animation);
    createDocks();

    QMainWindow *w1 = new QMainWindow;
    w1->setWindowTitle("Tab 1");
    w1->setWindowIcon(QIcon("icons/test.png"));

    QGraphicsView *view = new QGraphicsView;
    w1->setCentralWidget(view);

    addWidget(w1);

    QMainWindow *w2 = new QMainWindow;
    w2->setWindowTitle("Tab 2");
    w2->setWindowIcon(QIcon("icons/test.png"));
    QBoxLayout *layout = new QBoxLayout(QBoxLayout::TopToBottom);
    w2->setLayout(layout);

    addWidget(w2);
}

void MainUI::createDocks()
{
    QListWidget *leftList = new QListWidget();
    leftList->addItems(QStringList() << "Hello! I am the left dock! ;)");

    DockComponent *leftDock = addDockComponent(leftList, Qt::LeftDockWidgetArea, Animation, "Left Dock", QKeySequence(tr("Ctrl+L")));
    addToPerspective(leftDock->toggleViewAction(), Animation);

    QListWidget *rightList = new QListWidget();
    rightList->addItems(QStringList() << "Hello! I am the right dock! ;)");

    DockComponent *rightDock = addDockComponent(rightList, Qt::RightDockWidgetArea, Animation, "Right Dock", QKeySequence(tr("Ctrl+R")));
    addToPerspective(rightDock->toggleViewAction(), Animation);

    QListWidget *bottomList = new QListWidget();
    bottomList->addItems(QStringList() << "Hello! I am the bottom dock! ;)");

    DockComponent *bottomDock = addDockComponent(bottomList, Qt::BottomDockWidgetArea, Animation, "Bottom Dock", QKeySequence(tr("Ctrl+B")));
    addToPerspective(bottomDock->toggleViewAction(), Animation);
}
