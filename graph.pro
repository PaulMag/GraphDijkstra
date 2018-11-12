TEMPLATE = app
CONFIG += console c++11
CONFIG -= app_bundle
CONFIG -= qt

SOURCES += \
    main.cpp \
    node.cpp \
    edge.cpp \
    graph.cpp \
    path.cpp

HEADERS += \
    node.h \
    edge.h \
    graph.h \
    path.h
