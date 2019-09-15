QT += widgets
requires(qtConfig(listwidget))

HEADERS         = buttonbar.h \
                  dockcomponent.h \
                  dockbutton.h \
                  mainwindow.h \
                  tabbedmainwindow.h \
                  mainui.h

SOURCES         = main.cpp \
                  buttonbar.cpp \
                  dockcomponent.cpp \
                  dockbutton.cpp \
                  mainwindow.cpp \
                  tabbedmainwindow.cpp \
                  mainui.cpp
