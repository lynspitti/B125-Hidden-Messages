QT += charts
QT += serialport
QT += core

SOURCES += \
    main.cpp \
    receiver.cpp \
    data_struct.cpp \
    save.cpp \
    display.cpp

target.path = $$[QT_INSTALL_EXAMPLES]/charts/linechart
INSTALLS += target

HEADERS += \
    receiver.h \
    data_struct.h \
    save.h \
    display.h
