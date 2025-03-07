// //
// // Created by Sean on 3/5/25.
// //
#include "../include/pool.h"
#include <map>
#include <string>

template <typename T> OrderedMap<T>::OrderedMap() {
    this->query_map = std::map<std::string, ordered_map_node<T>*>();
    this->dummy_head = new ordered_map_node<T>(nullptr);
    this->dummy_tail = new ordered_map_node<T>(nullptr);
    // dummy node initialize
    this->dummy_head->next = this->dummy_tail;
    this->dummy_tail->pre = this->dummy_head;
}

template <typename T> void OrderedMap<T>::add_node(ordered_map_node<T> *node) {
    std::string data_id = node->data->get_id();
    if (this->get_node(data_id) == nullptr) {
        node->pre = this->dummy_tail->pre;
        node->next = this->dummy_tail;

        this->dummy_tail->pre->next = node;
        this->dummy_tail->pre = node;
        this->query_map[data_id] = node;
    } else {
        this->upt_node(node);
    }
}

template <typename T> void OrderedMap<T>::del_node(std::string id) {
    auto node = this->get_node(id);
    if (node == nullptr) {
        return;
    } else {
        node->pre->next = node->next;
        node->next->pre = node->pre;

        this->query_map.erase(id);
        delete node;
        return;
    }
}

template <typename T> ordered_map_node<T>* OrderedMap<T>:: get_node(std::string id) {
    return this->query_map[id];
}

template <typename T> void OrderedMap<T>::upt_node(ordered_map_node<T>* node) {
    auto origin_node = this->get_node(node->data->get_id());
    if (origin_node == nullptr) {
        this->add_node(node);
    } else {
        origin_node->data = node->data;
    }
}
