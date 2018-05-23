#include <save.h>
using namespace std;

Save_Handler::Save_Handler(string Path) {
  _Path = Path;
}

void Save_Handler::SaveData(Data_Struct Data) {
  ofstream outfile;

  outfile.open(_Path + "\\Data.data", ios_base::app);
  outfile << "#" << Data.GetValue() << "_";
  outfile << Data.GetType() << "_";
  outfile << Data.GetTime() << "!" "\n";

  outfile.close();
}
