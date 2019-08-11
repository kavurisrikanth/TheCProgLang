#include "Driver.h"

int main(int argc, char **argv) {
	/* Exercise 1-7 */
	fprintf(stdout, "Value of EOF: %d\n", getEOFValue());

	/* Remove comments */
	/*int retval = removeCommentsAndWrite("./RemoveCommentsProblem.c");
	if (retval == -1) {
		fprintf(stderr, "Cannot open file: RemoveCommentsProblem.c\n");
		return 1;
	}
	else if (retval == -2) {
		fprintf(stderr, "Cannot open file: RemoveCommentsSolution.c\n");
		return 1;
	}*/

	return 0;
}