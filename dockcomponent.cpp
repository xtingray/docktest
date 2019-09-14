#include "dockcomponent.h"

DockComponent::DockComponent(const QString &title, const QIcon &icon, const QString &code, QWidget *parent): QDockWidget(title, parent)
{
    setFeatures(QDockWidget::NoDockWidgetFeatures);
    setWindowIcon(icon);

    currentButton = new DockButton(this);
    currentButton->setToolTip(title);

    setObjectName("DockComponent-" + code);
    name = title;
    expanded = false;
}

DockComponent::~DockComponent()
{
}

DockButton *DockComponent::button() const
{
    return currentButton;
}

void DockComponent::setExpandingFlag() 
{
    if (expanded)
        expanded = false;
    else 
        expanded = true;
}

void DockComponent::setShortcut(QKeySequence shortcut)
{
    currentButton->setShortcut(shortcut);
}

