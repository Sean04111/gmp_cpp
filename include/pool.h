//
// Created by Sean on 3/5/25.
// DESC: routine pool
#pragma once
#ifndef POOL_H
#define POOL_H
#include "common.h"
#include "routine.h"
#include <map>
#include <string>

class Pool {
public:
  virtual void add_routine(Routine routine) = 0;
  virtual void get_routine(std::string routine_id) = 0;
  virtual void upd_routine(std::string routine_id, Routine new_routine) = 0;
  virtual void del_routine(std::string routine_id) = 0;
};

// ordered map based
class routine_pool : public Pool {
private:
public:
};

template <typename T> struct ordered_map_node {
  identify_data<T> *data;
  ordered_map_node<T> *next;
  ordered_map_node<T> *pre;

  ordered_map_node<T>(identify_data<T> *data) { this->data = data; };
};

template <typename T> class OrderedMap {
private:
  std::map<std::string, ordered_map_node<T> *> query_map;
  ordered_map_node<T>* dummy_head;
  ordered_map_node<T>* dummy_tail;

public:
  void add_node(ordered_map_node<T> *node);
  void del_node(std::string id);
  ordered_map_node<T> *get_node(std::string id);
  void upt_node(ordered_map_node<T> *node);

  OrderedMap<T>();
};



#endif // POOL_H


