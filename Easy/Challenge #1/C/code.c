#include <stdio.h> 
//#include <string.h>

int main(void){

	char name[64];
	int length = 0;
	int age = 0;
	char username[64];

	printf("Please enter your name: ");
//	scanf"%s", name);
//	fgets(name, 64, stdin);
//	length = strlen(name) - 1;
//	name[length] = '\0';
	scanf ("%[^\n]%*c", name);
	printf("Please enter your age: ");
	scanf("%d", &age);
	printf("Please enter your reddit username: ");
//	fgets(username, 64, stdin);
//	length = strlen(username) - 1;
//	username[length] = '\0';
//	scanf ("%d"); /* If this line is deleted, the program doesn't wait for input. */
	rewind(stdin); /* Ignore the above, it seems this gem puts the reader back at the beginning of stdin. */
	scanf ("%[^\n]%*c", username);
	printf("\nYour name is %s, you are %d years old, and your username is %s\n", name, age, username);
	return(0);
}