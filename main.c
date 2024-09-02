#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#define ARR_LIMIT 50
#define i16 int
#define i32 long
void printHeaders(FILE *file) {

	fprintf(file, "%s", "#include <stdio.h>\n#include <stdint.h>\n#include <stdlib.h>\n");
	fprintf(file, "%s", "int main(int argc, char *argv[]) {\n\n  long number;\n\n");
	fprintf(file, "%s", "  printf(\"Enter your number:\");\n  scanf(\"%ld\", &number);\n  printf(\"\\n\");\n\n");
}

int printLine(i32 i) {
	if (i == 1) {
		printf("%ld line has been printed.\n", i);
	} else {
		printf("%ld lines have been printed.\n", i);
	}
	return 0;
}

int checkNum(i32 number){
	if (number < 0) {
		printf("\nThe number entered is negative. \n\nTerminating.\n");
		exit(1);
	}
	printf("\n");

	if (number == 0) {
		printf("The number entered is either zero or not a number. \n\nTerminating.\n");
		exit(1);
	} else {
	    return 0;
	}
}

int main (i16 argc, char *argv[]) {

	i32 i;
	i32 number = 0;
	char fileName[ARR_LIMIT] = "output.c";
	char stringToPrint[150];
	char trueOrFalse[ARR_LIMIT];

	printf("What do you want the output file name to be? \n");
	printf("No input will default to output.c: ");
	scanf("%[^\n]s", fileName);

	printf("\nWhat number would you like this even/odd checker to go to?\n");
	printf("Input an integer. No commas, please: ");
	scanf("%ld", &number);
    checkNum(number);
	printf("Would you like to see on the terminal what line is being written?\n");
	printf("Typing 'yes' will print to the terminal. All other answers will not print anything.\n");
	printf("Input your choice: ");
	char userAnswer[ARR_LIMIT];
	scanf("%s", userAnswer);
	FILE *file = fopen(fileName, "w");
	if (file == NULL) {
		printf("\nCreation of file failed. \n\nTerminating.\n");
		return 1;
	}
	printf("\n\nFile created.\n\n");
	printHeaders(file);
	for (i = 0; i < number + 1; i++) {
		if(i % 2 == 0)
			strcpy(trueOrFalse, "\"Your number is even.\\n\"");
		else
			strcpy(trueOrFalse, "\"Your number is odd.\\n\"");
		sprintf(stringToPrint, "if (number == %ld) \n      printf(%s); \n", i, trueOrFalse);
		fprintf(file, "%s", stringToPrint);
		if (strcmp(userAnswer, "yes" ) == 0) {
			printLine(i);
		} else {

		}
	}

	fprintf(file, "}\n");
	printf("\nAll done!\n\n");
	return 0;
}
