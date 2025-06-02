#include <stdio.h>
#include <stdlib.h>

typedef struct node {
	int val;
	struct node * next;
} node_t;

void print_list(node_t * head) {
	node_t * current = head;

	while (current != NULL) {
		printf("%d\n", current->val);
		current = current->next;
	}  
}

int pop(node_t ** head) {
	int retval = -1;
	node_t * next_node = NULL;

	if (*head == NULL) {
		return -1;
	}

	next_node = (*head)->next;
	retval = (*head)->val;
	free(*head);
	*head = next_node;

	return retval;
}

int remove_by_value(node_t ** head, int val) {
	/* Initialize a variable to store the return value */
	int retval = -1;
	/* Initialize a temp pointer of type node_t that points to NULL */
	node_t * temp = NULL;
	/* Initialize a curr pointer of type node_t that points to the same as the head pointer */
	node_t * curr = *head;
	/* Check if the linked list is empty */
	if (*head == NULL) {
		return -1;
	}
	/* Check if the value is contained in the first item of the list */
	/* This works either if the first item is the only item in the list or if there are other items after it */
	if ((*head)->val == val) {
		temp = *head;
		*head = (*head)->next;
		retval = temp->val;
		free(temp);
		return retval;
	}
	/* Last non-trivial case: go through the linked list and look for the value */
	/* We are looking one item ahead for the value, so we check that this is not the last item */
	while (curr->next != NULL) {
		/* Found the value in the next item with respect to the item that curr is pointing */
		if (curr->next->val == val) {
			retval = curr->next->val;
			temp = curr->next;
			curr->next=temp->next;
			free(temp);
			return retval;
		}
		/* If the value is not found, go to the next item */
		curr = curr->next;
	}
	/* Trivial case: value not found, return -1 */
	return retval;
}

int main() {

	node_t * test_list = (node_t *) malloc(sizeof(node_t));
	test_list->val = 1;
	test_list->next = (node_t *) malloc(sizeof(node_t));
	test_list->next->val = 2;
	test_list->next->next = (node_t *) malloc(sizeof(node_t));
	test_list->next->next->val = 3;
	test_list->next->next->next = (node_t *) malloc(sizeof(node_t));
	test_list->next->next->next->val = 4;
	test_list->next->next->next->next = NULL;

	remove_by_value(&test_list, 3);
	
	print_list(test_list);
}
