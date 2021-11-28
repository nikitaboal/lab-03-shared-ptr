// Copyright 2021 Your Name <your_email>

#include <gtest/gtest.h>
#include <stdexcept>

#include "sharedptr.hpp"

TEST(ptrTest, nullPtrTest) {
  SharedPtr<size_t> a;
  ASSERT_EQ(a.use_count(), 0);
}

TEST(ptrTest, swapPtrTest) {
int kl1 = 1;
int kl2 = 2;
SharedPtr<int> a(&kl1);
SharedPtr<int> b(&kl2);
a.swapPtr(b);
  ASSERT_EQ(a.get(), &kl2);
}

TEST(ptrTest, resetTest) {
  int kl1 = 1;
  SharedPtr<int> a(&kl1);
  a.reset();
  ASSERT_EQ(a.use_count(), 0);
}

TEST(ptrTest, objectPtrTest) {
  struct Klan {
    size_t in;
    size_t out;
  };
  Klan klan = { 0, 0 };
  SharedPtr<Klan> a(&klan);
  ASSERT_EQ(a.get(), &klan);
}

TEST(ptrTest, sharedPtrTest) {
  int in = 10;
  SharedPtr<int> a(&in);
  SharedPtr<int> b(a);
  SharedPtr<int> c(b);
  ASSERT_EQ(c.use_count(), 3);
}