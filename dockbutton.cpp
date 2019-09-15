#include "dockbutton.h"
#include "dockcomponent.h"

DockButton::DockButton(DockComponent *dockComp, QWidget *parent) : QToolButton(parent), dockComponent(dockComp), m_area(Qt::LeftToolBarArea)
{
    setText(dockComponent->windowTitle());
    setIcon(dockComponent->windowIcon());
}

DockButton::~DockButton()
{
}

void DockButton::setArea(Qt::ToolBarArea area)
{
    m_area = area;
    update();
}

void DockButton::mousePressEvent(QMouseEvent *event)
{
    dockComponent->setExpandingFlag();
    QToolButton::mousePressEvent(event);
}

void DockButton::toggleView()
{
    dockComponent->setUpdatesEnabled(false);
    dockComponent->toggleViewAction()->trigger();
    dockComponent->setUpdatesEnabled(true);
}

DockComponent *DockButton::toolView() const
{
    return dockComponent;
}

Qt::ToolBarArea DockButton::area() const
{
    return m_area;
}
