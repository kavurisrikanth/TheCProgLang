/* Copy input to output replacing one or more strings with a single space */

#include "Exercise1-9.h"

int replaceMultipleSpaces(char* file) {
	if (file == NULL) {
		fprintf(stderr, "No file to open.\n");
		return -1;
	}

	FILE* prob;
	errno_t errno = fopen_s(&prob, file, "r");
	if (file == NULL) {
		fprintf(stderr, "Couldn't open file: %s\n", file);
		return -2;
	}

	return 0;
}