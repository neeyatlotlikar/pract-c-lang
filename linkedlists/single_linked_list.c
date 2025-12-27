#include <stdio.h>
#include <stdlib.h>

struct node {
	int info;
	struct node *link;
};

void display(struct node *start);
struct node *create_list(struct node *start);
void search(struct node *start, int data);
void *delete(struct node *start, int data);
void count(struct node *start);

int main(void) {
	struct node *start = NULL;
	int choice, data, item, pos;

	while (1) {
		printf("1. Create List\n");
		printf("2. Display\n");
		printf("3. Count\n");
		printf("4. Search\n");
		printf("5. Delete\n");
		printf("6. Quit\n");
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
			count(start);
			break;
		case 4:
			printf("Enter data to search for: ");
			scanf("%d", &data);
			search(start, data);
			break;
		case 5:
			printf("Enter data to delete: ");
			scanf("%d", &data);
			delete (data);
			break;
		case 6:
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
	printf("\n\n");
}
