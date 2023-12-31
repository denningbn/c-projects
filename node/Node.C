#include <stdio.h>
#include <stdlib.h>


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
	
	Node_t * first = insert(NULL, 1);

	insert(first,2);
	insert(first,3);
	insert(first,4);

	printNode(first);

	freeAll(first);
	return 0;
}
