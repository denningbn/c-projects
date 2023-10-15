#include <stdio.h>
#include <stdlib.h>


//Hello! This is my version of Nodes in C. I had a class a few semesters ago where we were writing a bunch of data structures out in java and figured it would be fun to that in C, especially since it's been a long time since I had to do some real programming.
//This is an unordered linked list that uses integers as the value. I'll probably use this for a hash table later on.
//

struct Node {
	int val;
	struct Node * next;
};

typedef struct Node Node_t;

void printNode(Node_t * node)
{
	printf("%d", node->val);

	if (node->next != NULL)
	{
		printf(", ");
		printNode(node->next);
	}
	else
	{
		printf("\n");
	}
}

Node * insert(Node_t * node, int val)
{
	if (node == NULL)
	{
		node = (Node_t *) malloc(sizeof(Node_t));

		if (node == NULL)
		{
			printf("Memory allocation failed");
			return NULL;
		}

		node->val = val;
	
		return node;
	}
	else
	{
		node->next = insert(node->next, val);
		return node;
	}
}

void freeAll(Node_t * node)
{
	if (node == NULL) return;
	else
	{
		freeAll(node->next);
		free(node);
	}
}

int main()
{
	Node_t * first = (Node_t *) malloc(sizeof(Node_t));
	first->val=0;
	
	insert(first, 1);
	insert(first, 2);
	insert(first, 3);

	printNode(first);

	freeAll(first);
	return 0;
}
