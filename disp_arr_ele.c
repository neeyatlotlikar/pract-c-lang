#include <stdio.h>

int main(void) {
	int i;
	char *arr[] = {"Ram", "Krishna", "Hari", "Murari"};

        int NUM_OF_ELE = sizeof(arr) / sizeof(arr[0]);

	for (i = 0; i < NUM_OF_ELE; printf("%s\n", arr[i]), i++);

	return 0;
}
