#ifndef ROOT_H
#define ROOT_H

#include <gtest/gtest.h>

extern "C" {
#include "myfunc.h"
}

TEST(one_solve, minus) {
    solve s=root(1,2,1);
    ASSERT_EQ(s.number_s, 1);
    ASSERT_NEAR(s.s1, -1, 0.00001);
}

TEST(one_solve, plus) {
    solve s=root(2,-4,2);
    ASSERT_EQ(s.number_s, 1);
    ASSERT_NEAR(s.s1, 1, 0.00001);
}

TEST(one_solve, drob) {
    solve s=root(8,8,2);
    ASSERT_EQ(s.number_s, 1);
    ASSERT_NEAR(s.s1,-0.5 , 0.00001);
}

TEST(two_solves, minus) {
    solve s=root(16,27,11);
    ASSERT_EQ(s.number_s, 2);
    ASSERT_NEAR(s.s1, -0.6875, 0.00001);
    ASSERT_NEAR(s.s2, -1, 0.00001);
}

TEST(two_solves, plus) {
    solve s=root(1,-12,11);
    ASSERT_EQ(s.number_s, 2);
    ASSERT_NEAR(s.s1, 11, 0.00001);
    ASSERT_NEAR(s.s2, 1, 0.00001);
}

TEST(two_solves, drob) {
    solve s=root(1,12,2);
    ASSERT_EQ(s.number_s, 2);
    ASSERT_NEAR(s.s1,-0.16904 , 0.00001);
    ASSERT_NEAR(s.s2,-11.83095 , 0.00001);
}

TEST(zero_solves, minus) {
    solve s=root(16,20,11);
    ASSERT_EQ(s.number_s, 0);
}

TEST(zero_solves, plus) {
    solve s=root(5,-33,112);
    ASSERT_EQ(s.number_s, 0);
}

TEST(not_equation, seven) {
    solve s=root(0,0,7);
    ASSERT_EQ(s.number_s, 0);
}

TEST(infinity, infinity) {
    solve s=root(0,0,0);
    ASSERT_EQ(s.number_s, -1);
}

TEST(one_solve, linear) {
    solve s=root(0,8,-73);
    ASSERT_EQ(s.number_s, 1);
    ASSERT_NEAR(s.s1,9.125 , 0.00001);
}
#endif // ROOT_H
