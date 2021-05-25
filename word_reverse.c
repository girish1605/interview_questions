/*
 * Company: Cisco
 * 
 * Question: Write function to reverse every word in the string
 * 
 * Author: Girish Bhangale <girishbhangale@outloo.com>
 */

#include <stdio.h>

#define MAX_SIZE 256

void string_reverse(char *str, int str_len) {
	int i;
	char tmp;
	for(i=0; i<str_len/2; i++) {
		tmp = str[i];
		str[i] = str[str_len-1-i];
		str[str_len-1-i] = tmp;
	}
}

void word_reverse(char *str) {
	int i, j;
	for(i=0; str[i] != '\0'; i=j) {
		if(str[i] == ' ')
			i++;

		for(j=i; str[j] != ' ' && str[j] != '\0'; j++);
		string_reverse(&str[i], j-i);
	}
}


int main() {
	char str[MAX_SIZE];
	printf("Enter the string:\n");
	scanf(" %[^\n]s", str);
	
	word_reverse(str);	
	printf("Output: %s\n", str);

	return 0;
}
