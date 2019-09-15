#include "dockcomponent.h"

DockComponent::DockComponent(const QString &title, const QIcon &icon, const QString &code, QWidget *parent): QDockWidget(title, parent)
{
    setFeatures(QDockWidget::NoDockWidgetFeatures);
    setWindowIcon(icon);

    currentButton = new DockButton(this);
    currentButton->setToolTip(title);

    setObjectName("DockComponent-" + code);
    name = title;
    expanded = true;
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

bool DockComponent::isExpanded()
{
    return expanded;
}

void DockComponent::setShortcut(QKeySequence shortcut)
{
    currentButton->setShortcut(shortcut);
}

void DockComponent::setPerspective(int wSpace)
{
    currentPerspective = wSpace;
}

int DockComponent::perspective() const
{
    return currentPerspective;
}
