TEMPLATE        = app
DESTDIR         = ..
CONFIG          += qt debug_and_release warn_on build_all

QT += core gui

MOC_DIR         = ../.moc

CONFIG(debug, debug|release) {
    OBJECTS_DIR = ../.objs_d
    TARGET      = recovery-terminal_d
    LIBS        += -L.. ../libqtermwidget_d.a
} else {
    OBJECTS_DIR = ../.objs
    TARGET      = recovery-terminal
    LIBS        += -L.. ../libqtermwidget.a
}

SOURCES         = mainwindow.cpp \
                main.cpp

HEADERS         = mainwindow.h

FORMS           = mainwindow.ui

INCLUDEPATH     = ../lib

#LIBS           += -L.. -lqtermwidget



maemo5 {
    target.path = /opt/src/bin
    INSTALLS += target
}
