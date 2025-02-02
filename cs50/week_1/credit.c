#include <cs50.h>
#include <stdio.h>

    // printf("%li\n", card_number % 10);

    /* What's supposed to happen:
     * input: 123456789
     * credit_card = 123456789
     * buffer = 0;
     *                    credit_card = 123456789;
     * 123456789 % 10 --> buffer = 9;
     * 123456789 / 10 --> credit_card = 12345678;
     * 12345678  % 10 --> buffer = 8;
     * 12345678  / 10 --> credit_card = 1234567;
     *
     * example number: 4003600000000014 = 16 numbers
     */

// Severely limited during this, as im using knowledge that's been taught up to this point in CS50 and this is week 1
// Which meant i had to get very creative. This can be done in a way more concise way.
// This was fun.
// The base of this entire program is:  Luhn's Algorithm.

void get_check_sum(int length);


long int card_number = 0;
long int card_buffer = 0;

int number_buffer = 0;
int initial_sum = 0;
int remaining_numbers_sum = 0;
int check_sum = 0;
int last_two_digits = 0; // This should be called first_two_digits but i don't know how to refactor in nvim yet, and i was tired when i wrote this.
int digit_count = 0;

string card_type = "";

void main(void){
    do{
        card_number = get_long("Card Number: ");
    }while(card_number < 1);

    card_buffer = card_number;

    while(card_buffer > 100){
        digit_count++;
        card_buffer = card_buffer / 10;
        last_two_digits = card_buffer;
    }
    digit_count += 2;

    card_buffer = card_number;

    // If American Express:
    if(last_two_digits == 15 || last_two_digits == 34 || last_two_digits == 37){
        get_check_sum(digit_count);
        card_type = "AMEX\n";

    // If MasterCard:
    }else if(last_two_digits == 51 || last_two_digits == 52 || last_two_digits == 53 || last_two_digits == 54 || last_two_digits == 55){
        get_check_sum(digit_count);
        card_type = "MASTERCARD\n";

    // If Visa:
    }else if(last_two_digits == 13 || last_two_digits == 16 || last_two_digits / 10 == 4){
        get_check_sum(digit_count);
        card_type = "VISA\n";

    // If invalid:
    }else{
        card_type = "INVALID\n";
    }

    if(check_sum % 10 == 0){
        printf("Number: %li\n", card_number);
        printf("%s\n", card_type);
    }else{
        printf("%s\n", card_type);
    }
}

void get_check_sum(int length){
    int counter = 0;
    while(card_buffer != 404){
        counter++;

        // every other number do this (i.e., every even number)
        if(counter % 2 == 0){
            // pluck out the last number from the credit card number and store that one number non-destructively.
            number_buffer = card_buffer % 10;
            // pluck out the last number from the credit card number and store the rest, making the whole number smaller in length by one.
            card_buffer = card_buffer / 10;

            number_buffer = number_buffer * 2;

            if(number_buffer >= 10){
                // number_buffer buffer so that we can get both numbers of a double digit number.
                // for example, 12, buffer takes care of 2 and number_buffer takes care of 1.
                int buffer = number_buffer;
                buffer = buffer % 10;
                number_buffer = number_buffer / 10;

                initial_sum += buffer;
                initial_sum += number_buffer;
            }else{
                initial_sum += number_buffer;
            }
        }else{
            remaining_numbers_sum += card_buffer % 10;
            card_buffer = card_buffer / 10;
        }

        if(counter >= length){
            card_buffer = 404;
            check_sum = initial_sum + remaining_numbers_sum;
        }
    }
}
