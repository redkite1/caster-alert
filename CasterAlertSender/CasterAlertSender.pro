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
FORMS = ui/casteralertsendergui.ui
HEADERS = src/casteralertsenderimpl.h \
    libs/src/casteralert.h
SOURCES = src/casteralertsenderimpl.cpp \
    src/main.cpp \
    libs/src/casteralert.cpp
RESOURCES += res.qrc
