#include <iostream>
#include "viewer.h"

// When the Viewer gets an update, it should display the new values.

void Viewer::Update(const State& state) {
  state_ = state;
  Display();
}

void Viewer::Display() {
  std::cout << "WEATHER UPDATE:";
  std::cout << " Temperature: " << state_.temperature;
  std::cout << " Humidity: " << state_.humidity << std::endl;
}
