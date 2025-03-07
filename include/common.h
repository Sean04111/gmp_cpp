//
// Created by Sean on 3/5/25.
//
#pragma once
#ifndef COMMON_H
#define COMMON_H
#include <string>

// data with id
template <typename T> class identify_data {
private:
  std::string id;
  T* data;
public:
  identify_data(std::string id, T* data) {
    this->data = data;
    this->id = id;
  };
  std::string get_id() { return this->id; };

  T* get_data() { return this->data; };

  void set_data(T &data) { this->data = data; }
};

#endif // COMMON_H
