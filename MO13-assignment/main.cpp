#include <cstdlib>
#include <memory>

#include "Dragon.h"
#include "Elf.h"
#include "Genie.h"
#include "Goblin.h"
#include "MagicalCreatures.h"

using std::vector, std::shared_ptr, std::string, std::make_shared, std::cin,
    std::cout;

// implement printCreature method for printing a creature
// as follows
/*
  cout<<endl;
                cout << "I am a : " << (m)->getType() << endl;
                cout << "My name is : " << (m)->getName() << endl;
                cout << "My color is : " << (m)->getColor() << endl;
    cout<<"My speech :"<<(m)->talk()<<endl;
    cout<<"My habitat: "<<(m)->liveIn()<<endl;
                cout << "I am " << (m)->getAge() <<" years of age." <<
  endl<<endl; cout<<"Displaying the "<<(m)->getType()<<" Object"<<endl;
     cout<<m->toString()<<endl;
*/
void displayCreatures(vector<shared_ptr<MagicalCreatures>> m) {
  // Generate an iterator
  vector<shared_ptr<MagicalCreatures>>::iterator it;

  // Loop through the vector
  for (it = m.begin(); it != m.end(); it++) {
    cout << "I am a: " << it->get()->getType() << ".\n";
    cout << "My name is: " << it->get()->getName() << ".\n";
    cout << "My color is: " << it->get()->getColor() << ".\n";
    cout << "My speech: " << it->get()->talk() << '\n';
    cout << "My habitat: " << it->get()->liveIn() << '\n';
    cout << "I am " << it->get()->getAge() << " years of age.\n\n";
    cout << "Displaying the " << it->get()->getType() << " object\n";
    cout << it->get()->toString() << "\n\n";
  }
}

void swap(vector<shared_ptr<MagicalCreatures>> *m, int source,
          int destination) {
  // Temporary shared pointer for the swap
  shared_ptr<MagicalCreatures> tmp = m->at(source);
  // Now that source pointer is saved, we can take the element at the
  // destination and overwrite the source
  m->at(source) = m->at(destination);
  // Move the temp pointer to the destination
  m->at(destination) = tmp;
}

int partition(vector<shared_ptr<MagicalCreatures>> *m, int start, int end) {
  // implement partition search space
  string pivot = m->at(start).get()->getName();
  int count = 0;
  for (int i = start + 1; i <= end; i++)
    if (m->at(i).get()->getName() <= pivot) count++;

  // Put the pivot in the correct place
  int pivot_index = start + count;
  swap(m, pivot_index, start);
  int i = start, j = end;

  while (i < pivot_index && j > pivot_index) {
    while (m->at(i).get()->getName() <= pivot) i++;

    while (m->at(j).get()->getName() > pivot) j--;

    if (i < pivot_index && j > pivot_index) swap(m, i++, j--);
  }

  return pivot_index;
}

void recursiveQuickSort(vector<shared_ptr<MagicalCreatures>> *m, int start,
                        int end) {
  if (start >= end) return;

  int p = partition(m, start, end);

  // Sort the left
  recursiveQuickSort(m, start, p - 1);

  // Sort the right part
  recursiveQuickSort(m, p + 1, end);
}

int recursiveBinarySearch(vector<shared_ptr<MagicalCreatures>> m, int first,
                          int last, string name) {
  if (last >= first) {
    int mid = (first + last) / 2;

    // Check if the name is present at mid
    if (m.at(mid).get()->getName() == name) return mid;
    // If name is smaller than mid, it must be in the left half
    else if (m.at(mid).get()->getName() > name)
      return recursiveBinarySearch(m, first, mid - 1, name);
    // If name is smaller, ignore right half
    else
      return recursiveBinarySearch(m, mid + 1, last, name);
  }

  // If we get here, the value isn't present
  return -1;
}

void searchCreature(vector<shared_ptr<MagicalCreatures>> m) {
  // Loop forever until user enters N
  while (true) {
    string name;
    cout << "Please enter the name of the Creature\n";
    cin >> name;
    if (name == "N") exit(0);
    int index = recursiveBinarySearch(m, 0, m.size() - 1, name);
    if (index == -1) {
      cout << "Creature Not Found\n";
    } else {
      cout << "Creature found at index " << index << '\n';
      cout << "Here is is " << m.at(index).get()->toString() << '\n';
    }
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
  cout << "*****AFTER SORTING *******\n";
  recursiveQuickSort(&creatures, 0, creatures.size() - 1);
  displayCreatures(creatures);
  searchCreature(creatures);
  return 0;
}
