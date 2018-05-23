#include <receiver.h>

Receiver::Receiver(){}

Data_Struct Receiver::receiveData(QString portName) {
    QSerialPort serial;
    serial.setPortName(portName);
    serial.open(QIODevice::ReadOnly);
    serial.setBaudRate(QSerialPort::Baud9600);
    serial.setDataBits(QSerialPort::Data8);
    serial.setParity(QSerialPort::NoParity);
    serial.setStopBits(QSerialPort::OneStop);
    serial.setFlowControl(QSerialPort::NoFlowControl);

    if (!serial.isOpen()) {
        qDebug() << serial.errorString() << "on port:" << portName;
        qDebug() << "Please restart the program!";
        while(true){}
    } else {
       qDebug() << "Serial opened!";
       if (!serial.waitForReadyRead(-1))
           qDebug() << "error: " << serial.errorString();
       else {
           serial.waitForBytesWritten(5100);
           QByteArray datas = serial.readAll();
           while (serial.waitForReadyRead(100))
               datas += serial.readAll();
           QString hello = datas;

           QRegExp rx("(\\#|\\!)");
           QRegExp rx2("(\\_)");

           QStringList query = hello.split(rx);

           foreach (const QString &str, query) {
               if (str.size() != 0) {
                   QStringList data = str.split(rx2);
                   if (data.size() == 3){
                       if (data.at(0).size() != 0 && data.at(1).size() != 0 && data.at(2).size() != 0) {
                           int value = data.at(0).toInt();
                           int type = data.at(1).toInt();
                           unsigned long timeStamp = data.at(2).toLong();

                           Data_Struct d(value, type, timeStamp);
                           return d;
                       }
                   }
               }
           }
       }
   }
}
