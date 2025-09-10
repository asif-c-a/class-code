#include <stdio.h>
#include <stdlib.h>

struct node {
	int data;
	struct node *link;
};

void addStart(struct node **head) {
	int n;
	printf("Input the value to be added at the start : ");
	scanf("%d", &n);

	struct node *new = (struct node *)malloc(sizeof(struct node));
	new->data = n;
	new->link = *head;
	*head = new;
}

void addAny(struct node **head) {
	int n, p;
	printf("Input the node after which the node is to be added and value to add : ");
	scanf("%d %d", &p, &n);

	struct node *new = (struct node *)malloc(sizeof(struct node));
	new->data = n;

	if (*head == NULL) {
		*head = new;
		return;
	}

	struct node *curr = *head;
	while (curr->link != NULL && curr->data != p) {
		curr = curr->link;
	}

	new->link = curr->link;
	curr->link = new;
}

void addEnd(struct node **head) {
	int n;
	printf("Input the value to be added at the end : ");
	scanf("%d", &n);

	struct node *new = (struct node *)malloc(sizeof(struct node));
	new->data = n;
	new->link = NULL;

	if (*head == NULL) {
		*head = new;
		return;
	}

	struct node *curr = *head;
	while (curr->link != NULL) {
		curr = curr->link;
	}
	curr->link = new;
}

void remStart(struct node **head) {
	if (*head == NULL) {
		printf("Nothing to remove.\n");
		return;
	}

	struct node *curr = *head;
	*head = curr->link;
	free(curr);
}

void remAny(struct node **head) {
	int p;
	printf("Input the node data to be deleted : ");
	scanf("%d", &p);

	if (*head == NULL) {
		printf("Nothing to remove.\n");
		return;
	}

	struct node *curr = *head, *prev = *head;
	while (curr->link != NULL && curr->data != p) {
		prev = curr;
		curr = curr->link;
	}

	if (curr->link != NULL)
		prev->link = curr->link;
	else
		prev->link = NULL;
	
	free(curr);
}

void remEnd(struct node **head) {
	if (*head == NULL) {
		printf("Nothing to remove.\n");
		return;
	}

	struct node *curr = *head, *prev = *head;
	while (curr->link != NULL) {
		prev = curr;
		curr = curr->link;
	}

	prev->link = NULL;
	free(curr);
	
}

void display(struct node *head) {
	struct node *curr = head;
	while (curr != NULL) {
		printf("%d -> ", curr->data);
		curr = curr->link;
	}
	printf("NULL\n");
}

int main() {
	struct node *head = NULL;
	int flag = 1, ch;

	printf("1. Add at Start\n2. Add at End\n3. Add Anywhere\n4. Remove from Start\n5. Remove from End\n6. Remove anywhere\n7. Display Linked List\n8. Exit\n");
	
	do
	{	
		printf("Select option [1/2/3/4/5/6/7/8] : ");
		scanf("%d", &ch);

		switch (ch)
		{
			case 1:
				addStart(&head);
				break;
			
			case 2:
				addEnd(&head);
				break;
			
			case 3:
				addAny(&head);
				break;
			
			case 4:
				remStart(&head);
				break;
			
			case 5:
				remEnd(&head);
				break;
			
			case 6:
				remAny(&head);
				break;
			
			case 7:
				display(head);
				break;
			
			case 8:
				flag = 0;
				break;
				
			default:
				printf("Incorrect choice.\n");
		}

	}while(flag);

	return 0;
}