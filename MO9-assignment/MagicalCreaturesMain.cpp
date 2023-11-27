#include <memory>

#include "Dragon.h"
#include "Elf.h"
#include "Genie.h"
#include "Goblin.h"

using std::shared_ptr, std::vector, std::make_shared, std::cout;

// function that inputs a shared pointer to a dragon
// returns nothing
//  prints the dragon details by calling its toString function
void displayDragons(shared_ptr<Dragon> d) {
  cout << "In display Dragons:\n";
  cout << "I am " << d->getName() << ": " << d->toString() << '\n';
}

int main() {
  // create a vector of shared pointer to Dragons
  vector<shared_ptr<Dragon>> dragonVector;

  // create the individual creatures of type pointer of MagicalCreatures
  shared_ptr<Dragon> dragon =
      make_shared<Dragon>("Jack", "black", "Dragon", 200, 500, true);
  shared_ptr<Dragon> dragoness =
      make_shared<Dragon>("Jill", "white", "Dragon", 100, 500, true);

  shared_ptr<Elf> elf = make_shared<Elf>("Doug", "green", "Elf", 80);
  shared_ptr<Genie> genie =
      make_shared<Genie>("Cosmo", "blue", "Genie", 1000, 40, true);
  shared_ptr<Goblin> goblin =
      make_shared<Goblin>("Harry", "red", "Goblin", 150);

  // print the traits of each creature
  // first using individual getters
  // then by calling the toString function on that creature
  cout << "Printing Traits of each magical creature\n";
  cout << "----------------------------------------\n";
  // Start with the dragon
  cout << "Name: " << dragon->getName() << '\n';
  cout << "Type: " << dragon->getType() << '\n';
  cout << "Color: " << dragon->getColor() << '\n';
  cout << "Age: " << dragon->getAge() << '\n';
  cout << "Talk: " << dragon->talk() << '\n';
  cout << "Live: " << dragon->liveIn() << '\n';
  cout << "To String: " << dragon->toString() << '\n';
  // Now the other dragon
  cout << "----------------------------------------\n";
  cout << "Name: " << dragoness->getName() << '\n';
  cout << "Type: " << dragoness->getType() << '\n';
  cout << "Color: " << dragoness->getColor() << '\n';
  cout << "Age: " << dragoness->getAge() << '\n';
  cout << "Talk: " << dragoness->talk() << '\n';
  cout << "Live: " << dragoness->liveIn() << '\n';
  cout << "To String: " << dragoness->toString() << '\n';
  // Now the elf
  cout << "----------------------------------------\n";
  cout << "Name: " << elf->getName() << '\n';
  cout << "Type: " << elf->getType() << '\n';
  cout << "Color: " << elf->getColor() << '\n';
  cout << "Age: " << elf->getAge() << '\n';
  cout << "Talk: " << elf->talk() << '\n';
  cout << "Live: " << elf->liveIn() << '\n';
  cout << "To String: " << elf->toString() << '\n';
  // Now the genie
  cout << "----------------------------------------\n";
  cout << "Name: " << genie->getName() << '\n';
  cout << "Type: " << genie->getType() << '\n';
  cout << "Color: " << genie->getColor() << '\n';
  cout << "Age: " << genie->getAge() << '\n';
  cout << "Talk: " << genie->talk() << '\n';
  cout << "Live: " << genie->liveIn() << '\n';
  cout << "To String: " << genie->toString() << '\n';
  // Finally the goblin
  cout << "----------------------------------------\n";
  cout << "Name: " << goblin->getName() << '\n';
  cout << "Type: " << goblin->getType() << '\n';
  cout << "Color: " << goblin->getColor() << '\n';
  cout << "Age: " << goblin->getAge() << '\n';
  cout << "Talk: " << goblin->talk() << '\n';
  cout << "Live: " << goblin->liveIn() << '\n';
  cout << "To String: " << goblin->toString() << '\n';

  // push back dragons  to the vector of Dragons
  dragonVector.push_back(dragon);
  dragonVector.push_back(dragoness);

  // loop through the dragon vector using iterators and
  // print the relevant data for each dragon
  // by calling displayDragon function
  vector<shared_ptr<Dragon>>::iterator it;
  for (it = dragonVector.begin(); it != dragonVector.end(); it++)
    displayDragons(*it);

  return 0;
}
