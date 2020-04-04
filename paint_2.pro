TEMPLATE = app
CONFIG += console c++11
CONFIG -= app_bundle
CONFIG -= qt

QT += gl
LIBS += /usr/lib/libglut.so /usr/lib/libGL.so

SOURCES += \
    ./src/main.cpp \
    ./src/brush_cl.cpp \
    ./src/button_cl.cpp \
    ./src/glut_callbacks.cpp \
    ./src/list_cl.cpp \
    ./src/paint_cl.cpp \
    ./src/timer_class.cpp \
    ./src/pallete_cl.cpp \
    ./src/cell_cl.cpp

DISTFILES += \
    ./paint_menu.txt

HEADERS += \
    ./src/brush_cl.h \
    ./src/button_cl.h \
    ./src/color_cl.h \
    ./src/glut_callbacks.h \
    ./src/list_cl.h \
    ./src/paint_cl.h \
    ./src/pallete_cl.h \
    ./src/point_cl.h \
    ./src/timer_class.h \
    ./src/cell_cl.h \
    ./src/point_cl.h
