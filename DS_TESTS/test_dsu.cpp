// Copyright 2026 Ivan Trushkov
#include <gtest/gtest.h>

#include "../lib_disjoint_set_union/dsu.h"

TEST(DSUConstructors, InitConstructor) {
  DSU a(4);
  size_t expected_data[] = {0, 1, 2, 3};
  size_t expected_rank[] = {0, 0, 0, 0};
  const size_t* actual_data = a.get_data();
  const size_t* actual_rank = a.get_rank();

  EXPECT_EQ(a.get_size(), 4);
  for (size_t i = 0; i < a.get_size(); i++) {
    EXPECT_EQ(actual_data[i], expected_data[i]);
    EXPECT_EQ(actual_rank[i], expected_rank[i]);
  }
}
