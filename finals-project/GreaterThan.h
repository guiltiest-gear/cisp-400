#pragma once

#include <memory>

#include "UserAccount.h"

class GreaterThan {
 public:
  bool operator()(std::shared_ptr<UserAccount> &a,
                  std::shared_ptr<UserAccount> &b);
};
