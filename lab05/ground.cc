
#include <iostream>
#include <string>

#include "ground.h"

Ground::Ground(std::string package) : Delivery(package) {
  std::cout << "Creating a ground package." << std::endl;
  //IncrementCount();
  set_days(5);
}

Ground::~Ground() {
  std::cout << "Deleting a ground package." << std::endl;
  //DecrementCount();
}

void Ground::Transport() {
  std::cout << "This is being transported via truck." << std::endl;
  std::cout << "It will take exactly ";
  std::cout << days_to_deliver_<< " days." << std::endl;
}
/**/
