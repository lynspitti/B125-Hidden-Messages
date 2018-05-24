#ifndef DATA_STRUCKT_H
#define DATA_STRUCKT_H

#include <iostream>
#include <vector>

class Data_Struct {
  protected:
    int _Value;
    int _Type;
    unsigned long _TimeStamp;
  public:
    int GetValue(){return _Value;}
    int GetType(){return _Type;}
    unsigned long GetTime(){return _TimeStamp;}
  Data_Struct(int Value,int Type,unsigned long TimeStamp);
};

class DataContainer {
  private:
    int _Type;
    std::vector<Data_Struct> Datas;
  public:
    void AddData(Data_Struct Data) {
      Datas.push_back(Data);
    }
    int GetData(unsigned int position) {
      if (Datas.size() < position) {
        Data_Struct data = Datas.at(position);
        return data.GetValue();
      }
      throw std::invalid_argument( "Requested position out off bounds" );
    }

  DataContainer(int Type){
    _Type = Type;
  }
};

class Temp : public Data_Struct {
  public:
    int GetTemp(){
      return _Value;
    }
  Temp(int Value, unsigned long TimeStamp): Data_Struct(Value,0,TimeStamp){
  }
};

class Humidity : public Data_Struct {
  public:
    int GetHumidity(){
      return _Value;
    }
  Humidity(int Value, unsigned long TimeStamp): Data_Struct(Value,1,TimeStamp){
  }
};

#endif // DATA_STRUCKT_H
