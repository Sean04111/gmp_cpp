//
// Created by Sean on 3/5/25.
//
#pragma once
#ifndef THREAD_H
#define THREAD_H
#include "routine.h"

namespace gmp {
class Thread {
public:
  // work on a routine
  virtual void work_on(Routine routine) = 0;

  // take it as a placeholder
  virtual void others();

  virtual ~Thread() = 0;
};
} // namespace gmp

#endif // THREAD_H
