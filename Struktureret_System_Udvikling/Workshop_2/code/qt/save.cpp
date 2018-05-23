#include <save.h>

Save_Handler::Save_Handler(string Path) {
  _Path = Path;
}

void Save_Handler::SaveData(Data_Struct Data) {
  std::ofstream outfile;

  outfile.open(_Path + "\\Data.data", std::ios_base::app);
  outfile << "#" << Data.GetType() << "_";
  outfile << Data.GetTime() << "_";
  outfile << Data.GetValue() << "!" "\n";

  outfile.close();
}
