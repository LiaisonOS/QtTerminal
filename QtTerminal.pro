QT += core gui widgets

TARGET   = QtTerminal
TEMPLATE = app

CONFIG  += c++17

SOURCES += main.cpp MainWindow.cpp
HEADERS += MainWindow.h

QTERMWIDGET_LIB = /home/va2ops/LiaisonOS/libs/qtermwidget/build/libqtermwidget6.a
QTERMWIDGET_INC = /home/va2ops/LiaisonOS/libs/qtermwidget/lib

INCLUDEPATH += $$QTERMWIDGET_INC /home/va2ops/LiaisonOS/libs/qtermwidget/build/lib
LIBS += $$QTERMWIDGET_LIB -lutf8proc
