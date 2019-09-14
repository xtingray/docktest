#include "buttonbar.h"

ButtonBar::ButtonBar(Qt::ToolBarArea area, QWidget *parent) : QToolBar(parent)
{
    setMovable(false);
    setIconSize(QSize(16, 16));
    m_buttons.setExclusive(true);

    switch (area) {
        case Qt::LeftToolBarArea:
             {
                setWindowTitle(tr("Left button bar"));
             }
             break;
        case Qt::RightToolBarArea:
             {
                setWindowTitle(tr("Right button bar"));
             }
             break;
        case Qt::BottomToolBarArea:
             {
                setWindowTitle(tr("Bottom button bar"));
             }
             break;
        case Qt::TopToolBarArea:
             {
                setWindowTitle(tr("Top button bar"));
             }
             break;
        default: break;
    }

    setObjectName("ButtonBar-"+windowTitle());

    connect(&m_buttons, SIGNAL(buttonClicked(QAbstractButton *)), this, SLOT(closeOtherPanels(QAbstractButton *)));
}

ButtonBar::~ButtonBar()
{
}

void ButtonBar::addButton(DockButton *dockButton)
{
    QAction *action = addWidget(dockButton);
    m_buttons.addButton(dockButton);

    action->setVisible(true);

    addSeparator();

    if (!isVisible()) 
        show();
}

void ButtonBar::closeOtherPanels(QAbstractButton *source)
{
    foreach (QAbstractButton *item, m_buttons.buttons()) {
        DockButton *button = static_cast<DockButton *>(item);
        if (source != button) {
            if (button->toolView()->isVisible()) {
                button->blockSignals(true);
                button->toggleView();
                button->blockSignals(false);
                break;
            }
        }
    }

    static_cast<DockButton *>(source)->toggleView();
}
