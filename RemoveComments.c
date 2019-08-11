/*
	Program to remove all comments from a C program.
*/

#include "RemoveComments.h"

int removeCommentsAndWrite(char* file) {
	FILE* fp = fopen(file, "r");
	if (fp == NULL) {
		return -1;
	}

	FILE* sol = fopen("./RemoveCommentsSolution.c", "w");
	if (sol == NULL) {
		return -2;
	}

	char* line = (char*)calloc(1, MAX_LINE_LEN * sizeof(char));
	bool inStr = false, singleComment = false, multiComment = false;

	while (fgets(line, MAX_LINE_LEN, fp) != NULL) {
		int len = strlen(line);
		printf("line: %s\n", line);
		singleComment = false;

		for (int i = 0; i < len; i++) {
			if (line[i] == '/' && !inStr) {
				/*
					Could be one of the following:
					1. The slash that starts a multi-line comment
					2. The slash that ends a multi-line comment
					3. One of the slashes that start a single line comment
					4. Others. These are ignored.
				*/
				if (!singleComment && !multiComment) {
					// If we are not in a comment, then look for 1 or 3 above.
					if (i + 1 < len) {
						if (line[i + 1] == '/')
							singleComment = true;
						else if (line[i + 1] == '*')
							multiComment = true;
					}
				}
				else if (multiComment) {
					// If we are already inside a multi-line comment, then
					// check for case 2.
					if (i - 1 >= 0 && line[i - 1] == '*') {
						multiComment = false;
						i++; // Increment to avoid printing the / after the *
					}
				}
			}

			if (line[i] == '"' && 
				!singleComment && !multiComment && 
				(i - 1 >= 0 && line[i - 1] != '\\')) {
				inStr = !inStr;
			}

			if (!singleComment && !multiComment) {
				fputc(line[i], sol);
			}
		}
		
		if (!singleComment && !multiComment)
			fputc('\n', sol);
	}

	fclose(sol);
	fclose(fp);
	free(line);

	return 0;
}