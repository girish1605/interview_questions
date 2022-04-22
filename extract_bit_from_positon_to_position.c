#include <stdio.h>

#define CHAR_SIZE 8
#define NIBBLE_SIZE 4

int extract_bit_from_range(unsigned int from, unsigned int to, int num) {
	return num << ((sizeof(num) * CHAR_SIZE) - to) \
				>> ((sizeof(num) * CHAR_SIZE) - to) \
				>> (from / NIBBLE_SIZE) * NIBBLE_SIZE;
}

int main() {
	
	int num = 0x44332211;

	int output = extract_bit_from_range(1, 32, num);

	printf("Output : %X\n", output);

	return 0;
}
