#include <stdlib.h>
#include <assert.h>
#include <stdbool.h>

#include "queue.h"

bool is_empty(const struct queue *queue)
{
	return queue->front == NULL;
}

struct queue *new_queue(void)
{
	struct queue *queue;
	queue = malloc(sizeof(struct queue));
	queue->front = NULL;
	queue->back = NULL;
	return queue;
}
static void destroy_every_nodes(struct node *node)
{
	if (node != NULL)
		destroy_every_nodes(node->next);
	free(node);
}
void destroy_queue(struct queue *queue)
{
	destroy_every_nodes(queue->front);
	free(queue);
}
void push_front(struct queue *queue, struct token value)
{
	struct node *new_node = malloc(sizeof(*new_node));
	new_node->data = value;
	new_node->next = queue->front;
	new_node->prev = NULL;
	if (queue->front != NULL)
		queue->front->prev = new_node;
	else 
		queue->back = new_node;
	queue->front = new_node;
}
void push_back(struct queue *queue, struct token value)
{
	struct node *new_node = malloc(sizeof(*new_node));
	new_node->data = value;
	new_node->next = NULL;
	new_node->prev = queue->back;
	if (queue->back != NULL)
		queue->back->next = new_node;
	else 
		queue->front = new_node;
	queue->back = new_node;
}
struct token pop_front(struct queue *queue)
{
	assert(queue->front != NULL);
	struct node *node_temp = NULL;
	struct token temp = queue->front->data;
	node_temp = queue->front;
	if (queue->front->next == NULL)
		queue->back = NULL;
	else
		queue->front->next->prev = NULL;
	queue->front = queue->front->next;
	free(node_temp);
	return temp;
}
struct token pop_back(struct queue *queue)
{
	assert(queue->back != NULL);
	struct node *node_temp = NULL;
	struct token temp = queue->back->data;
	node_temp = queue->back;
	if (queue->back->prev == NULL)
		queue->front = NULL;
	else
		queue->back->prev->next = NULL;
	queue->back = queue->back->prev;
	free(node_temp);
	return temp;
}
struct token peek_front(const struct queue *queue)
{
	assert(queue->front != NULL);
	return queue->front->data;
}
struct token peek_back(const struct queue *queue)
{
	assert(queue->back != NULL);
	return queue->back->data;
}
