#include<gtest/gtest.h>
#include "../include/common.h"
#include "../include/pool.h"
#include <iostream>
using namespace std;

TEST(GoogleTest, OrderedMapBasic) {
    auto om = OrderedMap<int>();

    for (int j = 0; j < 10; j++) {
        auto i = new int(j);
        auto identify_node = new identify_data<int>(std::to_string(*i),i);
        auto node = new ordered_map_node<int>(identify_node);
        om.add_node(node);
    }

    for (int m = 0;  m< 10; m++) {
        const int i = m;

        const ordered_map_node<int>* node = om.get_node(std::to_string(i));
        identify_data<int>* node_data = node->data;
        int type_data = *node_data->get_data();
        
        EXPECT_EQ(type_data, i);
    }

    for (int j = 0; j < 10; j++) {
        int* m = new int(j);
        int* i = new int(j+1);
        auto identify_node = new identify_data<int>(std::to_string(*m),i);
        auto node = new ordered_map_node<int>(identify_node);
        om.upt_node(node);
        EXPECT_EQ(*om.get_node(std::to_string(*m))->data->get_data(), (*m)+1);
    }

    for (int m = 0; m < 10; m++) {
        om.del_node(std::to_string(m));
        EXPECT_EQ(om.get_node(std::to_string(m)), nullptr);
    }
}