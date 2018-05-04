class Data_Struct{
  protected:
    int Value;
    int Type;
    unsigned long TimeStamp;
  public:
    int GetValue(); 
    int GetType();
    int GetTime();
  Data_Struct(int Value,int Type,int TimeStamp);
};

class Measurement_Module : public Data_Struct {
  virtual Data_Struct Get_Measurement();
};

class Temp_Measurement : public Measurement_Module {
  public:
    virtual Data_Struct Get_Measurement(){
      int temp = random(0,40); // Random relative temp between 0 to 40 celsius
      unsigned long TimeStamp = millis();
      Data_Struct data (temp, 1, TimeStamp); // Type = 1 designates a temp measurement
      return data;
    }
};

class Humidity_Measurement : protected Measurement_Module {
  virtual Data_Struct Get_Measurement(){
    int humid = random(25,95); // Random relative humidity between 25% to 95%
    unsigned long TimeStamp = millis();
    Data_Struct data (humid, 0, TimeStamp);  // Type = 0 designates a humidity measurement
    return data;
  }
};



class Temp : public Data_Struct {
  public:
    int GetTemp();
  Temp(int Value, int Type, int TimeStamp): Data_Struct(Value,Type,TimeStamp){
      
  }
};

class Humidity : public Data_Struct {
  public:
    int GetHumidity();
  Humidity(int Value, int Type, int TimeStamp): Data_Struct(Value,Type,TimeStamp){
    
  }
};


void SendData(Data_Struct *Data){
  Serial.print("#");
  Serial.print(Data->GetValue(),DEC);
  Serial.print("_");
  Serial.print(Data->GetType(),DEC);
  Serial.print("_");
  Serial.print(Data->GetTime(),DEC);
  Serial.print("!");
  delay(300);
  // Sending dataStruct contents starting and ending with special characters
}


void setup() {
  Serial.begin(9600);
}

void loop() {
  delay(5000);
  Temp currentTemp ();
  Humidity currentHumidity ();
  SendData(&currentTemp);
  SendData(&currentHumidity);
}






