#include <stdio.h>
#include <stdlib.h>

struct node {
	int info;
	struct node *link;
};

void display(struct node *start);
struct node *create_list(struct node *start);
// void search(struct node *start, int data);
void *delete(struct node *start, int data);
// void count(struct node *start);
struct node *append(struct node *start, int data);
struct node *topup(struct node *start, int data);

int main(void) {
	struct node *start = NULL;
	int choice, data, item, pos;

	while (1) {
		printf("\n");
		printf("1. Create List\n");
		printf("2. Display\n");
		printf("3. Count\n");
		printf("4. Search\n");
		printf("5. Add a node to an empty list or to the beginning of "
		       "the list\n");
		printf("6. Add an element to the list's end\n");
		printf("7. Delete\n");
		printf("8. Quit\n");
		printf("Enter your chosen option: ");
		scanf("%d", &choice);

		switch (choice) {
		case 1:
			start = create_list(start);
			break;
		case 2:
			display(start);
			break;
		case 3:
			// count(start);
			break;
		case 4:
			printf("Enter data to search for: ");
			scanf("%d", &data);
			// search(start, data);
			break;
		case 5:
			printf("Enter a value at the list's beginning: ");
			scanf("%d", &data);
			start = topup(start, data);
			break;
		case 6:
			printf("Enter a value at the list's ending: ");
			scanf("%d", &data);
			start = append(start, data);
			break;
		case 7:
			printf("Enter data to delete: ");
			scanf("%d", &data);
			start = delete (start, data);
			break;
		case 8:
			exit(EXIT_SUCCESS);
		default:
			printf("Please choose a valid option.\n");
		}
	}

	return 0;
}

void display(struct node *start) {
	struct node *p;
	if (start == NULL) {
		printf("The list is empty.\n");
		return;
	}
	p = start;
	printf("List:\n");
	while (p != NULL) {
		printf("%d ", p->info);
		p = p->link;
	}
	printf("\n");
}

struct node *topup(struct node *start, int data) {
	struct node *tmp;
	tmp = (struct node *)malloc(sizeof(struct node));
	tmp->info = data;
	tmp->link = start;
	start = tmp;
	return start;
}

struct node *append(struct node *start, int data) {
	struct node *p, *tmp;
	tmp = (struct node *)malloc(sizeof(struct node));
	tmp->info = data;
	p = start;
	while (p->link != NULL) {
		p = p->link;
	}
	p->link = tmp;
	tmp->link = NULL;
	return start;
}

struct node *create_list(struct node *start) {
	int i, n, data;
	printf("How many nodes should the list possess? ");
	scanf("%d", &n);
	start = NULL;
	if (n == 0) {
		return start;
	}
	printf("Enter the value you want to insert: ");
	scanf("%d", &data);
	start = topup(start, data);
	for (i = 2; i <= n; i++) {
		printf("Enter the value you want to insert: ");
		scanf("%d", &data);
		start = append(start, data);
	}
	return start;
}

void *delete(struct node *start, int data) {
	struct node *tmp, *p;
	if (start == NULL) {
		printf("List is empty right now\n");
		return start;
	}
	if(start->info == data) {
		tmp = start;
		start = tmp->link;
		free(tmp);
		return start;
	}
	p = start;
	while(p->link!=NULL){
		if(p->link->info == data){
			tmp = p->link;
			p->link = tmp->link;
			free(tmp);
			return start;
		}
		p = p->link;
	}
	printf("Entered data %d not found in the list\n", data);
	return start;
}

