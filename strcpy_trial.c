#include <stdio.h>
#include <string.h>

int main(void) {
	char path[100];

	// simulate having parsed "/"
	strcpy(path, "/");
	printf("Before: %s\n", path);

	if (strcmp(path, "/") == 0) {
		strcpy(path, "/index.html");
	}

	printf("After: %s\n", path);
	return 0;
}
