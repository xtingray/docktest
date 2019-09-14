QT += widgets
requires(qtConfig(listwidget))

HEADERS         = buttonbar.h \
                  dockcomponent.h \
                  dockbutton.h \
                  mainwindow.h 
SOURCES         = main.cpp \
                  buttonbar.cpp \
                  dockcomponent.cpp \
                  dockbutton.cpp \
                  mainwindow.cpp
