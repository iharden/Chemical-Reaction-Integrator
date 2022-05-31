QT       += core gui

greaterThan(QT_MAJOR_VERSION, 4): QT += widgets printsupport

CONFIG += c++17

# You can make your code fail to compile if it uses deprecated APIs.
# In order to do so, uncomment the following line.
#DEFINES += QT_DISABLE_DEPRECATED_BEFORE=0x060000    # disables all the APIs deprecated before Qt 6.0.0

INCLUDEPATH += C:\Boost_1_79_0
INCLUDEPATH += C:\single_headers
INCLUDEPATH += C:\Qt\Tools\mingw810_64\lib\gcc\x86_64-w64-mingw32\8.1.0\include #for omp.h if needed, might be problematic for deployment (.dll stuff)

SOURCES += \
    class_system.cpp \
    functions.cpp \
    integrator.cpp \
    main.cpp \
    mainwindow.cpp \
    qcustomplot.cpp

HEADERS += \
    class_system.hpp \
    functions.hpp \
    integrator.hpp \
    mainwindow.h \
    qcustomplot.h

FORMS += \
    mainwindow.ui

# remove possible other optimization flags
QMAKE_CXXFLAGS_RELEASE -= -O
QMAKE_CXXFLAGS_RELEASE -= -O1
QMAKE_CXXFLAGS_RELEASE -= -O2

# add the desired -O2 if not present
QMAKE_CXXFLAGS_RELEASE += -O2

# Default rules for deployment.
qnx: target.path = /tmp/$${TARGET}/bin
else: unix:!android: target.path = /opt/$${TARGET}/bin
!isEmpty(target.path): INSTALLS += target
