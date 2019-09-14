#ifndef BUTTONBAR_H
#define BUTTONBAR_H

#include "dockbutton.h"
#include "dockcomponent.h"

#include <QToolBar>
#include <QButtonGroup>
#include <QAction>

class DockButton;
class DockCompoennt;

class ButtonBar : public QToolBar
{
    Q_OBJECT

    public:
        ButtonBar(Qt::ToolBarArea area, QWidget *parent = nullptr);
        ~ButtonBar();

        void addButton(DockButton *viewButton);

    private slots:
        void closeOtherPanels(QAbstractButton *source);

    private:
        QButtonGroup m_buttons;
};

#endif
