// QIncludes
#include <QtWidgets/QApplication>
#include <QtWidgets/QMainWindow>
#include <QtCharts/QChartView>
#include <QtCharts/QLineSeries>
#include <QSerialPort>
#include <QSerialPortInfo>
#include <QIODevice>
#include <QTimer>
#include <QCoreApplication>
#include <QDebug>

// Includes
#include <string>
#include <vector>
#include <fstream>
#include <iostream>

// Headers
#include <receiver.h>
#include <save.h>
#include <data_struct.h>
#include <display.h>

using namespace std;
QT_CHARTS_USE_NAMESPACE
QT_USE_NAMESPACE

// Get port information
QString commPort() {
    QString arduino = QString("Arduino");
    foreach (const QSerialPortInfo &info, QSerialPortInfo::availablePorts()) {
        QString manufacturer = info.manufacturer();
        QString portName = info.portName();
        if (manufacturer.contains(arduino))
            return portName;
    }
}

// Main loop
int main(int argc, char *argv[]) {
    QCoreApplication app(argc, argv);
    QString CommunicationPort = commPort();
    string Data_Path = "D:\\Dev\\B125-Hidden-Messages\\Struktureret_System_Udvikling\\Workshop_2\\code\\qt";
    //Display_Handler display;
    Receiver receive;
    Save_Handler save(Data_Path);

    while(true) {
        Data_Struct data = receive.receiveData(CommunicationPort);
        save.SaveData(data);
    }
    return app.exec();
}
