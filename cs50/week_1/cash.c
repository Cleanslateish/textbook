#include <cs50.h>
#include <stdio.h>

const int quarter =   25;
const int dime    =   10;
const int nickle  =    5;
const int penny   =    1;

int coins_needed = 0;
int change_owed = 0;

void main(void){
    
    do{
        change_owed = get_int("Change_owed: ");
    }while(change_owed < 1);

    do{
        if(quarter <= change_owed){
            change_owed -= quarter;
            coins_needed++;
        }else if(dime <= change_owed){
            change_owed -= dime;
            coins_needed++;
        }else if(nickle <= change_owed){
            change_owed -= nickle;
            coins_needed++;
        }else{
            change_owed -= penny;
            coins_needed++;
        }
    }while(change_owed > 0);
    
    printf("%i\n", coins_needed);
}


// Greedy Algorithm:
// According to the National Institute of Standards and Technology (NIST),
// a greedy algorithm is one “that always takes the best immediate, or local, solution while finding an answer. 
// Greedy algorithms find the overall, or globally, optimal solution for some optimization problems, 
// but may find less-than-optimal solutions for some instances of other problems.”

// What’s all that mean? Well, suppose that a cashier owes a customer some change and in that cashier’s drawer
// are quarters (25¢), dimes (10¢), nickels (5¢), and pennies (1¢). The problem to be solved is to decide which
// coins and how many of each to hand to the customer. Think of a “greedy” cashier as one who wants to take the
// biggest bite out of this problem as possible with each coin they take out of the drawer. For instance,
// if some customer is owed 41¢, the biggest first (i.e., best immediate, or local) bite that can be taken is 25¢.
// (That bite is “best” inasmuch as it gets us closer to 0¢ faster than any other coin would.)
// Note that a bite of this size would whittle what was a 41¢ problem down to a 16¢ problem, since 41 - 25 = 16.
// That is, the remainder is a similar but smaller problem. Needless to say, another 25¢ bite would be too big
// (assuming the cashier prefers not to lose money), and so our greedy cashier would move on to a bite of size 10¢,
// leaving him or her with a 6¢ problem. At that point, greed calls for one 5¢ bite followed by one 1¢ bite,
// at which point the problem is solved. The customer receives one quarter, one dime, one nickel, and one penny: four coins in total.

// It turns out that this greedy approach (i.e., algorithm) is not only locally optimal but also globally so for America’s currency
// (and also the European Union’s). That is, so long as a cashier has enough of each coin, this largest-to-smallest approach will yield the fewest coins possible.
