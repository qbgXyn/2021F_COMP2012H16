QT       += core gui

greaterThan(QT_MAJOR_VERSION, 4): QT += widgets

CONFIG += c++11

# The following define makes your compiler emit warnings if you use
# any Qt feature that has been marked deprecated (the exact warnings
# depend on your compiler). Please consult the documentation of the
# deprecated API in order to know how to port your code away from it.
DEFINES += QT_DEPRECATED_WARNINGS

SOURCES += \
    Effect/Effect.cpp \
    graphics.cpp \
    Handle/Decoration/Decoration.cpp \
    Handle/Handle.cpp \
    Handle/Unit/Ghost.cpp \
    Handle/Unit/Survivor.cpp \
    Handle/Unit/Unit.cpp \
    Main.cpp \
    mainwindow.cpp \
    Map.cpp \
    menuwindow.cpp \
    util.cpp

HEADERS += \
    Effect/Effect.h \
    graphics.h \
    Handle/Decoration/Decoration.h \
    Handle/Decoration/Item_Handle.h \
    Handle/Decoration/Tree.h \
    Handle/Handle.h \
    Handle/Unit/Ghost.h \
    Handle/Unit/Survivor.h \
    Handle/Unit/Unit.h \
    Handle/Inventory/Item_Inventory.h \
    Item/Item.h \
    mainwindow.h \
    Map.h \
    menuwindow.h \
    util.h

FORMS += \
    mainwindow.ui \
    menuwindow.ui

# Default rules for deployment.
qnx: target.path = /tmp/$${TARGET}/bin
else: unix:!android: target.path = /opt/$${TARGET}/bin
!isEmpty(target.path): INSTALLS += target

RESOURCES += \
    images.qrc
