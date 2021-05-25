/*
 * Company: Qualcomm
 * 
 * Question: Write function to reverse bits of num
 * 
 * Author: Girish Bhangale <girishbhangale@outloo.com>
 */


#include <stdio.h>

#define SIZE_CHAR 8

void print_bitwise(unsigned int num) {
	int i;
	for (i=(sizeof(num) * SIZE_CHAR) - 1; i >=0; i--) {
		printf("%d ", (num & (1 << i)) >> i);
	}
	printf("\n");	
}


void bitwise_reverse(unsigned int num) {
	int i;
	int num_size = sizeof(num) * SIZE_CHAR;
	int revbit = 0;
	
	for(i=0; i< num_size ; i++) {
		revbit |= ((num & (1 << i)) >> i) << (num_size - 1 - i);
	}

	print_bitwise(revbit);
}

int main() {

	unsigned int num = 0;

	printf("Enter the number: ");
	scanf("%d", &num);

	print_bitwise(num);
	bitwise_reverse(num);

}
