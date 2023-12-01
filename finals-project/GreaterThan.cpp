#include "GreaterThan.h"

#include <memory>

using std::shared_ptr;

bool GreaterThan::operator()(shared_ptr<UserAccount> &a,
                             shared_ptr<UserAccount> &b) {
  // Since we're using account numbers, sort by that
  return a->getAccountNumber() < b->getAccountNumber();
}
