#ifndef RECEIVER_H
#define RECEIVER_H

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

#include "data_struckt.h"
using namespace std;


class Receiver
{
    public:
        Data_Struct receiveData(QString portName);
    Receiver();
};

#endif // RECEIVER_H
