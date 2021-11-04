//Copyright 2021 Matthew abobus1488822@yandex.ru

#include <gtest/gtest.h>

#include <investigation.hpp>
#include <stdexcept>

TEST(Equality,kbytes_2_elems){
  EXPECT_EQ(kbytes_to_elems(1),256);
}

TEST(Equality, straight_exp){
  EXPECT_EQ(straight_experiment(0),2);
}

TEST(Equality, reverse_exp){
  EXPECT_EQ(reverse_experiment(0),2);
}

TEST(Equality, random_exp){
  EXPECT_EQ(random_experiment(0),2);
}
