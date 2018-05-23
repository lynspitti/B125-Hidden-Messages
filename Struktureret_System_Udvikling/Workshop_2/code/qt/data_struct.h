#ifndef DATA_STRUCT_H
#define DATA_STRUCT_H

#include <iostream>
#include <vector>

class Data_Struct {
  protected:
    int _Value;
    int _Type;
    unsigned long _TimeStamp;
  public:
    int GetValue();
    int GetType();
    unsigned long GetTime();
  Data_Struct(int Value, int Type, unsigned long TimeStamp);
};

class DataContainer {
  private:
    int _Type;
    std::vector<Data_Struct> Datas;
  public:
    void AddData(Data_Struct Data);
    int GetData(unsigned int position);
  DataContainer(int Type);
};

class Temp : public Data_Struct {
  public:
    int GetTemp();
  Temp(int Value, unsigned long TimeStamp): Data_Struct(Value, 0, TimeStamp) {}
};

class Humidity : public Data_Struct {
  public:
    int GetHumidity();
  Humidity(int Value, unsigned long TimeStamp): Data_Struct(Value, 1, TimeStamp) {}
};

#endif
