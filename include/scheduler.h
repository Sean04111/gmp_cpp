//
// Created by Sean on 3/5/25.
//
#pragma once
#ifndef SCHEDULER_H
#define SCHEDULER_H

#include "thread.h"
#include <map>
#include <vector>

class Scheduler {
public:
  // get an idle thread
  virtual gmp::Thread get_thread() = 0;
  // get next routine to work on
  virtual Routine get_next_routine() = 0;
  virtual ~Scheduler();
};

#endif // SCHEDULER_H
