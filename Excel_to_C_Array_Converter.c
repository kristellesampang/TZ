/** 
Note: only one function can be called at a time, so comment out the function not used
For online compilers, this website works best: https://www.codechef.com/c-online-compiler
**/

// Libraries used
#include <stdio.h>
#include <string.h>
#include <stdlib.h>

#define MAX_LINE_LENGTH 12 // size of part number

// String input for used parts 
char string_input[MAX_LINE_LENGTH];
char char_float_input[MAX_LINE_LENGTH];

 
// Function to read string user inputted values from Excel
 void read_string_input(){
	// Prompt the user
	printf("Please paste all the used part of this model\n");
	
	// Reads the user input
	while(fgets(string_input, sizeof(string_input), stdin)){
		// Prints nothing if a new line is read, used for formatting
		if(!(strcmp(string_input,"\n"))){
		    printf("");
		}
		// Prints the user input in the format of a string array
		else{
		    printf("\"%s\",", string_input);
		}
	}
	return;;
 }
 
 // Function to read float user inputted values from Excel
 void read_float_input(){
	 // Prompt the user
	 printf("Please paste the quantities used in this model\n");
	 
	 int i = 0;
	 
	 
	 // Reads the user input
	 while(fgets(char_float_input, sizeof(char_float_input), stdin)){
		// Prints nothing if a new line is read, used for matting 
		if(!(strcmp(char_float_input,"\n"))){
		    continue;
		}
		// Convert from string to float
		else{
			printf("%s,", char_float_input);
			
		}
	 }
	 return;
 }
 
 int main() {
	
	// Calls the functions
	read_string_input();
	read_float_input();
	
	return 0;
 }