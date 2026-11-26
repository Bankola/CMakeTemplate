// Copyright 2026 Trushkov Ivan
#include <gtest/gtest.h>

#include <stdexcept>

#include "../lib_stack_on_massive/stack.h"

TEST(StackInit, NewStackIsEmpty) {
  TStackOnMass<int> s(3);
  EXPECT_TRUE(s.is_empty());
  EXPECT_FALSE(s.is_full());
}

TEST(StackInit, NewStackNotFullUntilCapacity) {
  TStackOnMass<int> s(2);
  EXPECT_FALSE(s.is_full());
}

TEST(StackPush, PushMakesNonEmpty) {
  TStackOnMass<int> s(3);
  s.push(42);
  EXPECT_FALSE(s.is_empty());
}

TEST(StackPush, PushUpToCapacityIsFull) {
  TStackOnMass<int> s(2);
  s.push(1);
  EXPECT_FALSE(s.is_full());
  s.push(2);
  EXPECT_TRUE(s.is_full());
}

TEST(StackPush, PushOverflowThrows) {
  TStackOnMass<int> s(1);
  s.push(1);
  EXPECT_THROW(s.push(2), std::out_of_range);
}

TEST(StackTop, TopReturnsLastPushed) {
  TStackOnMass<int> s(3);
  s.push(10);
  s.push(20);
  EXPECT_EQ(s.top(), 20);
}

TEST(StackTop, TopDoesNotRemoveElement) {
  TStackOnMass<int> s(3);
  s.push(7);
  EXPECT_EQ(s.top(), 7);
  EXPECT_EQ(s.top(), 7);
  EXPECT_FALSE(s.is_empty());
}

TEST(StackTop, TopOnEmptyThrows) {
  TStackOnMass<int> s(3);
  EXPECT_THROW(s.top(), std::out_of_range);
}

TEST(StackPop, PopReturnsLastPushed) {
  TStackOnMass<int> s(3);
  s.push(1);
  s.push(2);
  EXPECT_EQ(s.pop(), 2);
}

TEST(StackPop, PopRemovesElement) {
  TStackOnMass<int> s(3);
  s.push(1);
  s.push(2);
  s.pop();
  EXPECT_EQ(s.top(), 1);
}

TEST(StackPop, PopOnEmptyThrows) {
  TStackOnMass<int> s(3);
  EXPECT_THROW(s.pop(), std::out_of_range);
}

TEST(StackPop, PopUntilEmpty) {
  TStackOnMass<int> s(3);
  s.push(1);
  s.push(2);
  s.pop();
  s.pop();
  EXPECT_TRUE(s.is_empty());
}

TEST(StackLifo, ElementsComeOutInReverseOrder) {
  TStackOnMass<int> s(3);
  s.push(1);
  s.push(2);
  s.push(3);
  EXPECT_EQ(s.pop(), 3);
  EXPECT_EQ(s.pop(), 2);
  EXPECT_EQ(s.pop(), 1);
}

TEST(StackCopy, CopyConstructorCopiesElements) {
  TStackOnMass<int> a(3);
  a.push(10);
  a.push(20);
  TStackOnMass<int> b(a);
  EXPECT_EQ(b.top(), 20);
  EXPECT_EQ(b.pop(), 20);
  EXPECT_EQ(b.pop(), 10);
}

TEST(StackCopy, CopyIsIndependent) {
  TStackOnMass<int> a(3);
  a.push(1);
  TStackOnMass<int> b(a);
  b.push(2);
  EXPECT_EQ(a.top(), 1);
  EXPECT_EQ(b.top(), 2);
}

TEST(StackCopy, CopyAssignmentCopiesElements) {
  TStackOnMass<int> a(3);
  a.push(1);
  a.push(2);
  TStackOnMass<int> b(5);
  b.push(99);
  b = a;
  EXPECT_EQ(b.top(), 2);
  EXPECT_EQ(b.pop(), 2);
  EXPECT_EQ(b.pop(), 1);
  EXPECT_TRUE(b.is_empty());
}

TEST(StackCopy, SelfAssignmentSafe) {
  TStackOnMass<int> a(3);
  a.push(5);
  a = a;
  EXPECT_EQ(a.top(), 5);
}

TEST(Stack, TopFunction) {
  TStackOnMass<int> a(3);
  a.push(5);
  a.top() = 10;
  EXPECT_EQ(a.top(), 10);
}
