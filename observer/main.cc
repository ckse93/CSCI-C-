#include <iostream>

#include "state.h"
#include "weather.h"
#include "viewer.h"
#include "database.h"

int main() {
  State state(10,20,30.4);
  Weather * weather = new Weather(state);
  Viewer * view = new Viewer(weather);
  weather->RegisterObserver(view);

  Database * db = new Database(weather);
  weather->RegisterObserver(db);
  // Instantiate Weather, Viewer, Database.
  // Register Observers with Subject

  while (true) {
    // Enter in -100 when you want to quit
    // Uncomment this when above is complete

    if (0 == weather->TakeMeasurements()) {
      std::cout << "bye" << std::endl;
      return 1;
    }
  }
}
