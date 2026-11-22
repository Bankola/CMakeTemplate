// Copyright 2026 Trushkov Ivan
#include <gtest/gtest.h>

#include <stdexcept>

#include "../lib_queue_on_massive/queue.h"

TEST(QueueInit, NewQueueIsEmpty) {
  TQueueOnMass<int> q(3);
  EXPECT_TRUE(q.is_empty());
  EXPECT_FALSE(q.is_full());
}

TEST(QueueInit, NewQueueNotFullUntilCapacity) {
  TQueueOnMass<int> q(2);
  EXPECT_FALSE(q.is_full());
}

TEST(QueuePush, PushMakesNonEmpty) {
  TQueueOnMass<int> q(3);
  q.push(42);
  EXPECT_FALSE(q.is_empty());
}

TEST(QueuePush, PushUpToCapacityIsFull) {
  TQueueOnMass<int> q(2);
  q.push(1);
  EXPECT_FALSE(q.is_full());
  q.push(2);
  EXPECT_TRUE(q.is_full());
}

TEST(QueuePush, PushOverflowThrows) {
  TQueueOnMass<int> q(1);
  q.push(1);
  EXPECT_THROW(q.push(2), std::out_of_range);
}

TEST(QueueFront, FrontReturnsFirstPushed) {
  TQueueOnMass<int> q(3);
  q.push(10);
  q.push(20);
  EXPECT_EQ(q.front(), 10);
  EXPECT_EQ(q.back(), 20);
}

TEST(QueueFront, FrontDoesNotRemoveElement) {
  TQueueOnMass<int> q(3);
  q.push(7);
  EXPECT_EQ(q.front(), 7);
  EXPECT_EQ(q.front(), 7);
  EXPECT_FALSE(q.is_empty());
}

TEST(QueueFront, FrontOnEmptyThrows) {
  TQueueOnMass<int> q(3);
  EXPECT_THROW(q.front(), std::out_of_range);
}

TEST(QueuePop, PopReturnsFirstPushed) {
  TQueueOnMass<int> q(3);
  q.push(1);
  q.push(2);
  EXPECT_EQ(q.pop(), 1);
}

TEST(QueuePop, PopRemovesElement) {
  TQueueOnMass<int> q(3);
  q.push(1);
  q.push(2);
  q.pop();
  EXPECT_EQ(q.front(), 2);
}

TEST(QueuePop, PopOnEmptyThrows) {
  TQueueOnMass<int> q(3);
  EXPECT_THROW(q.pop(), std::out_of_range);
}

TEST(QueuePop, PopUntilEmpty) {
  TQueueOnMass<int> q(3);
  q.push(1);
  q.push(2);
  q.pop();
  q.pop();
  EXPECT_TRUE(q.is_empty());
}

TEST(QueueFifo, ElementsComeOutInDirectOrder) {
  TQueueOnMass<int> q(3);
  q.push(1);
  q.push(2);
  q.push(3);
  EXPECT_EQ(q.pop(), 1);
  EXPECT_EQ(q.pop(), 2);
  EXPECT_EQ(q.pop(), 3);
}

TEST(QueueFifo, WrapAroundWorksCorrectly) {
  TQueueOnMass<int> q(3);
  q.push(1);
  q.push(2);
  q.push(3);
  EXPECT_EQ(q.pop(), 1);
  q.push(4);
  EXPECT_TRUE(q.is_full());
  EXPECT_EQ(q.pop(), 2);
  EXPECT_EQ(q.pop(), 3);
  EXPECT_EQ(q.pop(), 4);
  EXPECT_TRUE(q.is_empty());
}

TEST(QueueCopy, CopyConstructorCopiesElements) {
  TQueueOnMass<int> a(3);
  a.push(10);
  a.push(20);
  TQueueOnMass<int> b(a);
  EXPECT_EQ(b.front(), 10);
  EXPECT_EQ(b.pop(), 10);
  EXPECT_EQ(b.pop(), 20);
}

TEST(QueueCopy, CopyIsIndependent) {
  TQueueOnMass<int> a(3);
  a.push(1);
  TQueueOnMass<int> b(a);
  b.push(2);
  EXPECT_EQ(a.size(), 1);
  EXPECT_EQ(b.size(), 2);
  EXPECT_EQ(b.back(), 2);
}

TEST(QueueCopy, CopyAssignmentCopiesElements) {
  TQueueOnMass<int> a(3);
  a.push(1);
  a.push(2);
  TQueueOnMass<int> b(5);
  b.push(99);
  b = a;
  EXPECT_EQ(b.front(), 1);
  EXPECT_EQ(b.pop(), 1);
  EXPECT_EQ(b.pop(), 2);
  EXPECT_TRUE(b.is_empty());
}

TEST(QueueCopy, SelfAssignmentSafe) {
  TQueueOnMass<int> a(3);
  a.push(5);
  a = a;
  EXPECT_EQ(a.front(), 5);
}
