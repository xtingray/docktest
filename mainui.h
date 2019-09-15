#ifndef MAINUI_H
#define MAINUI_H

#include "tabbedmainwindow.h"

#include <QGraphicsView>

class MainUI : public TabbedMainWindow
{
    Q_OBJECT

    public:
        enum Perspective {
             Animation = 0x01,
             Player = 0x02,
             News = 0x04,
             All = Animation | Player | News
        };

        MainUI();

    private:
        void createDocks();
};

#endif
