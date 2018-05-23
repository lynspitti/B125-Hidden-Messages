QT += charts
QT += serialport
QT += core

SOURCES += \
    main.cpp \
    receiver.cpp \
    Data_Struckt.cpp \
    save.cpp

target.path = $$[QT_INSTALL_EXAMPLES]/charts/linechart
INSTALLS += target

HEADERS += \
    sensors.h \
    receiver.h \
    data_struckt.h \
    save.h
