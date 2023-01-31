#ifndef QUEUE_H
#define QUEUE_H

#include <stdbool.h>
#include "token.h"

struct node
{
	struct token data;
	struct node *next;
	struct node *prev;
};

struct queue
{
	struct node *front;
	struct node *back;
};

struct queue *new_queue(void);
void destroy_queue(struct queue *queue);

void push_front(struct queue *queue, struct token value);
void push_back(struct queue *queue, struct token value);

struct token pop_front(struct queue *queue);
struct token pop_back(struct queue *queue);

struct token peek_front(const struct queue *queue);
struct token peek_back(const struct queue *queue);

bool is_empty(const struct queue *queue);

#endif
