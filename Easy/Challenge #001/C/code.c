/*
	Solution for Easy Challenge #001
	Author: Keydrain
	Date:   03/24/15

	Includes 'Extra Credit' file management
	Once the out.log file has been created, it must be deleted to be changed. 
*/


#include <stdio.h> 

int main(void){

	FILE *input, *output;
	char logfile[] = "out.log";
	int c;

	input = fopen(logfile, "r");
	if (input == NULL){

		char name[64];
		int length = 0;
		int age = 0;
		char username[64];
	
		printf("Please enter your name: ");
		scanf ("%[^\n]%*c", name); /* Regex in scanf for C */
		printf("Please enter your age: ");
		scanf("%d", &age);
		printf("Please enter your reddit username: ");
		rewind(stdin); /* This gem puts the reader back at the beginning of stdin. */
		scanf ("%[^\n]%*c", username); /* Regex in scanf for C */
		printf("Your name is %s, you are %d years old, and your username is %s\n", name, age, username);
		
		output = fopen(logfile, "w");
		fprintf(output, "Your name is %s, you are %d years old, and your username is %s\n", name, age, username);
		fclose(output);
		return(0);

	} else {

		while ((c = getc(input)) != EOF) {
			putchar(c);
		}
		fclose(input);
		return(0);

	}
}