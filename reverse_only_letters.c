/*
 * Microsoft 1nd round (coding round) April 20, 2022
 *
 * Given a string s, reverse the string according to the following rules:
 *      All the characters that are not English letters remain in the same position.
 *      All the English letters (lowercase or uppercase) should be reversed.
 * 
 * Example 1:
 *      Input: s = "ab-cd"
 *      Output: "dc-ba"
 * 
 * Example 2:
 *      Input: s = "a-bC-dEf-ghIj"
 *      Output: "j-Ih-gfE-dCba"
 * 
 * Example 3:
 *      Input: s = "Test1ng-Leet=code-Q!"
 *      Output: "Qedo1ct-eeLg=ntse-T!"
 */

#include <stdio.h>
#include <string.h>

int is_alphabet(char ch) {
    return (ch >= 'A' && ch <= 'Z') || (ch >= 'a' && ch <= 'z');
}

void reverseOnlyLetters(char * s){

    int start = 0;
    int end = strlen(s) - 1;
    
    while (start < end) {
        
        while (!is_alphabet(s[start]) && start < end)
            start++;
        
        while (!is_alphabet(s[end]) && start < end)
            end--;
        
        if (start < end) {
            s[start] = s[start] ^ s[end];
            s[end] = s[start] ^ s[end];
            s[start] = s[start] ^ s[end];
            start++;
            end--;
        }
        
    }
}


int main() {
    char str [] = "a!b@C#-dEf-ghIj&K";
    printf("Original string : %s\n", str);
    reverseOnlyLetters(str);
    printf("Reverse string : %s\n", str);

    return 0;
}