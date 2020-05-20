#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <time.h>

/*
 * This program generates all of the possible password combinations
 * seven characters with no punctuation or special characters.
 *
 * It also displays the amount of time it takes to complete.
 *
 * The purpose of this program is to show how EASY it is to brute-force
 * a weak password.
 * */

/* Function prototypes */
void testPassLength(int length, bool printPassword);
bool nextPass(char* password, int length);
char incrementChar(char c);
/*
 * Main functions
 * */
int main(int argc, char** argv) {
	if (argc == 1) {
		printf("No password sizes given. Terminating program.");
		return 1;
	}
	for (int a = 1; a < argc; a++) {
		try {
			int n = atoi(argv[a]);
			if (n == 0) {
				throw 1;
			}
			testPassLength(n, false);
		}
		catch(int err) {
			printf("Error Reading line. Error code %d", err);
		}
	}
	return 0;
}
/*
 * Checks the time it takes to crack an ALPHANUMERIC password
 * of length "length". 
 * */
void testPassLength(int length, bool printPassword) {
	double duration;
	clock_t start = clock();
	char password[length];
	for (int i = 0; i < length; i++) {
		password[i] = '0';
	}
	while (nextPass(password, length)) {
		if (printPassword) {
			printf("%s\n", password);
		}
	}
	/* Print the amount of time */
	duration = (clock() - start) / (double) (CLOCKS_PER_SEC / 1000);
	printf("For password of length %d, a brute-force attack on this computer took %f ms\n", length, duration);
}
/*
 * Given a password of length "length", and a C string
 * containing that password, provide the next alphanumeric
 * password.
 * */
bool nextPass(char* password, int length) {
	if (password[length - 1] == 'z') {
		return false;
	}
	/* For each character */
	int i = 0;
	while (password[i] == 'z') {
		password[i] = '0';
		i++;
	}
	password[i] = incrementChar(password[i]);
	return true;
}

char incrementChar(char c) {
	switch (c) {
		/* Rollover character */
		case 'z':
			return '0';
			break;
		case '9':
			return 'A';
			break;
		case 'Z':
			return 'a';
			break;
		default:
			return c + 1;
			break;
	}
}
