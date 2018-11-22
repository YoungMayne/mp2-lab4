#include "pch.h"
#include "queue.h"

TEST(queue, can_create_queue) {
	ASSERT_NO_THROW(queue<int> q(10));
}

TEST(queue, can_not_create_queue_with_negative_size) {
	ASSERT_ANY_THROW(queue<int> q(-1));
}

TEST(queue, can_not_create_queue_with_too_large_size) {
	ASSERT_ANY_THROW(queue<int> q(2147483647));
}

TEST(queue, can_push_elem) {
	queue<int> q(1);
	ASSERT_NO_THROW(q.push(1));
}

TEST(queue, can_pop_elem) {
	queue<int> q(1);
	q.push(1);
	EXPECT_EQ(q.pop(), 1);
}

TEST(queue, get_true_if_queue_is_full) {
	queue<int> q(1);
	q.push(1);
	EXPECT_TRUE(q.full());
}

TEST(queue, get_true_if_queue_is_empty) {
	queue<int> q(1);
	q.push(1);
	q.pop();
	EXPECT_TRUE(q.empty());
}