// Cyrus Duncan CST-221
// Include the Librares needs to run the program
#include <stdlib.h>
#include <unistd.h>
#include <string.h>	
#include<stdio.h>
#include<math.h>
// Parameters 
int rem, temp = 1;
long number = -1.00;
int i = 0, rem;
char hex_arr[50];
int final;

/*
* Method needed to read the number using scanf
*/

void* readNum(){
scanf("%ld", &number);
}
/*
*
*Method to calculate the binary and print it to the console
*/
void* calculateBinary() {
// perameters needed to calcualate the binary
 int remainder; 
 long binaryNumber = number;
 long binary = 0, i = 1;
 
  // while there is still a binary number
    while(binaryNumber != 0) {
    // get the remainder of mod two of the number
        remainder = binaryNumber%2;
        // devide the number by two
        binaryNumber = binaryNumber/2;
        // add the binary with the remander times the temp
        binary= binary + (remainder*i);
        // multiply the temp by 10
        i = i*10;
    }
    // print the binary
    printf("%ld\n", binary);
}
/*
*Methood to calculate the hexid
*/
void* calculateHexidecimal() {
// while number is not equal to 0
while(number != 0)
 {
 // set the remainder equal to number mod 16
rem = number % 16; 
// if remainder is less than 10
if (rem < 10)
{
// set the array equal to counter ++ = 48 + remainder
hex_arr[i++] = 48 + rem;
}
// otherwise
else
{
// add to the hex array 55 + remainder
hex_arr[i++] = 55 + rem;
}
// get the quotient
number /= 16;  
}
// print beginning of the hex string
printf("0x");
// print the hex_arr in reverse order
for(int j = i - 1; j >= 0 ; j--)  
{
// printing contents of hex array
printf("%c", hex_arr[j]);
}  
// create a new line for formating 
printf("\n"); 

}
// method to convert the number
void* convertNumber() {
// call calculate binary
calculateBinary();
// call hexidecimal
calculateHexidecimal();
}
/*
*Method to transform the number
*/
void* transformNumber() {
// create integer of number shifting the number of bits to the left by 16 
int transform = number << 16;
// set int final equal to transform and number togeather
final = transform & number;
// make integer addition to 0x07ff
 int addition = 0x07FF;
// add final and addition togeather
final = final + addition;
// print the new decimal value
printf("decimal value is now: %d\n", final);
// set number equal to the new transformed number
number = final;
// convert the number and grab its binary and hash values
convertNumber();
}


/*
* Method to run the program
*/
int main(void) {
// while number is not less than 0 or greater than 4095
while(number < 0 || number > 4095) {
printf("Hello! Please print an integer between 0 and 4095: ");
// call read number method
readNum();
// if the number is less than 0 ir greater than 4095
if(number < 0 || number > 4095) {
// print an error
printf("Please ensure that the integer is between 0 and 4095!\n");
}

}

convertNumber();
transformNumber();
}
