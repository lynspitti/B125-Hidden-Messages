#include "data_struct.h"

Data_Struct::Data_Struct(int Value, int Type, unsigned long TimeStamp) {
  _Value = Value;
  _Type = Type;
  _TimeStamp = TimeStamp;
}

int Data_Struct::GetValue() {
    return _Value;
}

int Data_Struct::GetType() {
    return _Type;
}

unsigned long Data_Struct::GetTime() {
    return _TimeStamp;
}

int Humidity::GetHumidity() {
    return _Value;
}

int Temp::GetTemp() {
    return _Value;
}

DataContainer::DataContainer(int Type) {
  _Type = Type;
}

int DataContainer::GetData(unsigned int position) {
  if (Datas.size() < position) {
    Data_Struct data = Datas.at(position);
    return data.GetValue();
  }
  throw std::invalid_argument( "Requested position out off bounds" );
}

void DataContainer::AddData(Data_Struct Data) {
  Datas.push_back(Data);
}
