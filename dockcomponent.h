#ifndef DOCKCOMPONENT_H
#define DOCKCOMPONENT_H

#include "dockbutton.h"

#include <QDockWidget>
#include <QIcon>
#include <QKeySequence>
#include <QAction>

class DockComponent : public QDockWidget
{
    Q_OBJECT

    public:
        DockComponent(const QString &title, const QIcon &icon = QIcon(), const QString &code = QString(), QWidget * parent = nullptr);
        virtual ~DockComponent();

        DockButton *button() const;
        void setExpandingFlag();
        bool isExpanded();

        void setShortcut(QKeySequence shortcut);

        void setPerspective(int wSpace);
        int perspective() const;

    private:
        DockButton *currentButton;
        QString name;
        bool expanded;
        int currentPerspective;
};

#endif
