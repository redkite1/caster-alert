TEMPLATE = app
QT = gui \
    core \
    network
CONFIG += qt \
    release \
    warn_on
DESTDIR = bin
OBJECTS_DIR = build
MOC_DIR = build
UI_DIR = build
FORMS = ui/casteralertlistenergui.ui
HEADERS = src/casteralertlistenerimpl.h \
    libs/src/casteralert.h
SOURCES = src/casteralertlistenerimpl.cpp \
    src/main.cpp \
    libs/src/casteralert.cpp
