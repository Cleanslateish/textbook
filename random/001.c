#include <cs50.h>
#include <stdio.h>

int first = 13;
int second = 10;
int third = 5;
int fourth = 1;
int fifth = 0;

void main(void){
    printf("BEFORE:\n%i\n%i\n%i\n%i\n%i\n", first, second, third, fourth, fifth);

    printf("AFTER:\n%i\n%i\n%i\n%i\n%i\n", first % 10, second % 10, third % 10, fourth % 10, fifth % 10);

}
