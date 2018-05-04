#include<Arduino.h>
#define Sensors 2
#define Debug 0

class Data_Struct{
  protected:
    int _Value;
    int _Type;
    unsigned long _TimeStamp;
  public:
    int GetValue(){
      return _Value;
    }
    int GetType(){
      return _Type;
    }
    unsigned long GetTime(){
      return _TimeStamp; 
    }
  Data_Struct(int Value,int Type,unsigned long TimeStamp){
    _Value = Value;
    _Type = Type;
    _TimeStamp = TimeStamp;
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

class Measurement_Module {
  public:
    virtual Data_Struct Get_Measurement();
};

class Temp_Measurement : public Measurement_Module {
  public:
    virtual Data_Struct Get_Measurement(){
#if Debug
      char buffer_text[20];
      Serial.println("Temp Start");
#endif
      
      int temp = random(0,40); // Random relative temp between 0 to 40 celsius
      unsigned long TimeStamp = millis();

#if Debug
      sprintf(buffer_text, "Val: %d, Time: %lu",temp, TimeStamp);
      Serial.print(buffer_text);
      Serial.println("");
      delay(100);
#endif

      Temp data (temp, TimeStamp); // Type = 1 designates a temp measurement

#if Debug
      sprintf(buffer_text, "Val: %d, Time: %lu",data.GetValue(), data.GetTime());
      Serial.print(buffer_text);
      Serial.println("");
      delay(100);
#endif
      
      return data;
    }
};

class Humidity_Measurement : public Measurement_Module {
  public:
    virtual Data_Struct Get_Measurement(){
#if Debug
      char buffer_text[20];
      Serial.println("Humidity Start");
#endif
      
      int humid = random(25,95); // Random relative humidity between 25% to 95%
      unsigned long TimeStamp = millis();

#if Debug
      sprintf(buffer_text, "Val: %d, Time: %lu",humid, TimeStamp);
      Serial.print(buffer_text);
      Serial.println("");
      delay(100);
#endif

      Humidity data (humid, TimeStamp);  // Type = 0 designates a humidity measurement

#if Debug
      sprintf(buffer_text, "Val: %d, Time: %lu",data.GetValue(), data.GetTime());
      Serial.print(buffer_text);
      Serial.println("");
      delay(100);
#endif
      
      return data;
    }
};

class Communicator {
  public:
  SendData(Data_Struct *Data){
    //Serial.print("#");
    //Serial.print(Data->GetValue(),DEC);
    //Serial.print("_");
    //Serial.print(Data->GetType(),DEC);
    //Serial.print("_");
    //Serial.print(Data->GetTime());
    //Serial.print("!");

    char buffer_text[11];
    sprintf(buffer_text, "#%d_%d_%lu!",Data->GetValue(), Data->GetType(), Data->GetTime());
    Serial.print(buffer_text);
#if Debug
    Serial.println("");
#endif
    delay(100);
    
    // Sending dataStruct contents starting and ending with special characters
  }
};

Measurement_Module **Sensore_Modules;
Communicator Com_Handler;

void setup() {
  //ComHandler
  Sensore_Modules = new Measurement_Module*[Sensors];
  Sensore_Modules[0] = new Temp_Measurement();
  Sensore_Modules[1] = new Humidity_Measurement();
  
  Serial.begin(9600);
  Serial.println("-PROGRAM START-");
}

void loop() {
  delay(5000);
  for (int i =0; i < Sensors; i++){
    Data_Struct Measure = Sensore_Modules[i]->Get_Measurement();
    Com_Handler.SendData(&Measure);
  }
}






