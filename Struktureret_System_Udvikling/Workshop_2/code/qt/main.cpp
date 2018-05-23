// Chart includes
#include <QtWidgets/QApplication>
#include <QtWidgets/QMainWindow>
#include <QtCharts/QChartView>
#include <QtCharts/QLineSeries>

// Serial includes
#include <QSerialPort>
#include <QSerialPortInfo>

// Other includes
#include <QIODevice>
#include <QTimer>
#include <QCoreApplication>
#include <QDebug>

#include <string>
#include <vector>
#include <fstream>
#include <iostream>

#include <receiver.h>
#include <save.h>
#include <data_struckt.h>

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

int main(int argc, char *argv[]) {
    QCoreApplication a(argc, argv);
    QString portName = commPort();

    Receiver receive;
    Save_Handler save("D:\\Dev\\B125-Hidden-Messages\\Struktureret_System_Udvikling\\Workshop_2\\code\\qt");

    while(1){
        Data_Struct d = receive.receiveData(portName);
        save.SaveData(d);
    }


    /*
    //QString arduino = QString("Arduino");
    QSerialPort serial;
    foreach (const QSerialPortInfo &info, QSerialPortInfo::availablePorts()) {
        QString manufacturer = info.manufacturer();
        QString portName = info.portName();
        if (manufacturer.contains(arduino)) {
            serial.setPort(info);
            serial.setBaudRate(QSerialPort::Baud9600);
            serial.setDataBits(QSerialPort::Data8);
            serial.setParity(QSerialPort::NoParity);
            serial.setStopBits(QSerialPort::OneStop);
            serial.setFlowControl(QSerialPort::NoFlowControl);
            serial.open(QIODevice::ReadWrite);
            if (!serial.isOpen())
                qDebug() << serial.errorString() << "on port:" << portName;
            else {
                qDebug() << "Serial opened!";
                QObject::connect(&serial, &QSerialPort::readyRead, [&] {
                    qDebug() << "New data available: " << serial.bytesAvailable();
                    QByteArray datas = serial.readAll();
                    qDebug() << datas;
                });
           }
           //serial.flush();
           // serial.close();
       }
    }*/
    return a.exec();
}

/*int main(int argc, char *argv[])
{
    QApplication a(argc, argv);

//![1]
    QLineSeries *series = new QLineSeries();
//![1]

//![2]
    series->append(0, 6);
    series->append(2, 4);
    series->append(3, 8);
    series->append(7, 4);
    series->append(10, 5);
    *series << QPointF(11, 1) << QPointF(13, 3) << QPointF(17, 6) << QPointF(18, 3) << QPointF(20, 2);
//![2]

//![3]
    QChart *chart = new QChart();
    chart->legend()->hide();
    chart->addSeries(series);
    chart->createDefaultAxes();
    chart->setTitle("Simple line chart example");
//![3]

//![4]
    QChartView *chartView = new QChartView(chart);
    chartView->setRenderHint(QPainter::Antialiasing);
//![4]


//![5]
    QMainWindow window;
    window.setCentralWidget(chartView);
    window.resize(400, 300);
    window.show();
//![5]

    return a.exec();
}
*/
