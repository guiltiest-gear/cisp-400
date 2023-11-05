#include <iostream>
#include <memory>
#include <typeinfo>

#include "Dragon.h"
#include "Elf.h"
#include "Genie.h"
#include "Goblin.h"
#include "MagicalCreatures.h"

using std::vector, std::shared_ptr, std::make_shared, std::cout;

void displayCreatures(vector<shared_ptr<MagicalCreatures>> creatures) {
  // write the method signature and contents
  // Create an iterator to loop over the contents
  vector<shared_ptr<MagicalCreatures>>::iterator it;
  for (it = creatures.begin(); it != creatures.end(); it++) {
    cout << "I am a : " << it->get()->getType() << '\n';
    cout << "My name is : " << it->get()->getName() << '\n';
    cout << "My color is : " << it->get()->getColor() << '\n';
    cout << "My speech: " << it->get()->talk() << '\n';
    cout << "My habitat: " << it->get()->liveIn() << '\n';
    cout << "I am " << it->get()->getAge() << " years of age.\n\n";
    cout << "Displaying the " << it->get()->getType() << " Object\n";
    cout << it->get()->toString() << "\n\n";
  }
}

int main() {
  // create a vector of pointer to MagicalCreatures
  vector<shared_ptr<MagicalCreatures>> creatures;

  // create the individual creatures of type pointer of MagicalCreatures
  shared_ptr<Dragon> dragon =
      make_shared<Dragon>("Jack", "black", "Dragon", 200, 500, true);
  shared_ptr<Elf> elf = make_shared<Elf>("Doug", "green", "Elf", 80);
  shared_ptr<Genie> genie =
      make_shared<Genie>("Cosmo", "blue", "Genie", 1000, 40, true);
  shared_ptr<Goblin> goblin =
      make_shared<Goblin>("Harry", "red", "Goblin", 150);

  // push back each specific creature to the vector of MagicalCreatures

  creatures.push_back(dragon);
  creatures.push_back(elf);
  creatures.push_back(genie);
  creatures.push_back(goblin);
  displayCreatures(creatures);
}
