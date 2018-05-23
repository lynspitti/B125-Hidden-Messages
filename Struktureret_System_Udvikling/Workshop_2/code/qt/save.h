#ifndef SAVE_H
#define SAVE_H

#include <string>
#include <iostream>
#include <fstream>

#include "data_struckt.h"
using namespace std;

class Save_Handler {
  private:
    string _Path;
  public:
    void SaveData(Data_Struct Data);
  Save_Handler(string Path);
};

#endif // SAVE_H
