#include <iostream>

#include "database.h"

void Database::Update(const State& stateinput) {
  std::cout<<"updated in the DB" << std::endl;
  state_ = stateinput;
  Save();
}

void Database::Save() {
  std::cout << "saved" << std::endl;
  // ?? FAKE SAVE -- can print something out to report save.
}
