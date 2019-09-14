#ifndef DOCKBUTTON_H
#define DOCKBUTTON_H

#include <QToolButton>
#include <QMouseEvent>

class DockComponent;

class DockButton : public QToolButton
{
    Q_OBJECT

    public:
        DockButton(DockComponent *toolView, QWidget *parent = nullptr);
        ~DockButton();

        void setArea(Qt::ToolBarArea area);
        DockComponent *toolView() const;

    protected:
        virtual void mousePressEvent(QMouseEvent *);
		
    public slots:
        void toggleView();

    private:
        DockComponent *dockComponent;
        Qt::ToolBarArea m_area;
};

#endif
