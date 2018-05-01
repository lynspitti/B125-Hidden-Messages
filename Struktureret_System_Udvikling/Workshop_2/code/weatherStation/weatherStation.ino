class Measurement_Module {
  virtual Get_Measurement();
};
// one two testing GitHubDesktop
class Temp_Measurement : public Measurement_Module {
  virtual Get_Measurement();
  Data_Struct Get_Measurement(){
    int temp = random(0,40); // Random relative temp between 0 to 40 celsius
    unsigned long TimeStamp = millis();
    Data_Struct data (temp, 1, TimeStamp); // Type = 1 equals temp measurement
    return data;
  }
};

class Humidity_Measurement : public Measurement_Module {
  virtual Get_Measurement(); 
  Data_Struct Get_Measurement(){
    int humid = random(25,95); // Random relative humidity between 25% to 95%
    unsigned long TimeStamp = millis();
    Data_Struct data (humid, 0, TimeStamp);  // Type = 0 equals humidity measurement
    return data;
  }
};

class Data_Struct{
  protected
    int Value;
    int Type;
    unsigned long TimeStamp;
  public
    int GetValue(); 
    int GetType();
    int GetTime();
  Data_Struct(int Value,int Type,int TimeStamp);
};

class Temp : public Data_Struct {
  public
    int GetTemp();
  Temp(int Value, int Type, int TimeStamp): Data_Struct(Value,Type,TimeStamp){
      
  }
};

class Humidity : public Data_Struct {
  public
    int GetHumidity();
  Humidity(int Value, int Type, int TimeStamp): Data_Struct(Value,Type,TimeStamp){
    
  }
};

class Communicator {
  void SendData(Data_Struct)(){
    
  }
};

void setup() {
  Serial.begin(9600);
}

void loop() {
  Delay(5000);
}
