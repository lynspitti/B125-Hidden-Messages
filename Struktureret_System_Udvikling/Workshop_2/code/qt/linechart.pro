QT += charts
QT += serialport
QT += core

SOURCES += \
    main.cpp

target.path = $$[QT_INSTALL_EXAMPLES]/charts/linechart
INSTALLS += target

HEADERS += \
    sensors.h
