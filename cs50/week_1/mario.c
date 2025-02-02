#include <cs50.h>
#include <stdio.h>

// TO COMPILE WITH CS50: gcc filename.c -o output_name -lcs50 (library cs50)

void main(void){ 
    int structure_height = 0;

    do{
        printf("Choose a number between 0 and 9 (1 through 8).\n");
        structure_height = get_int("Structure height: ");
    }while(structure_height < 1 || structure_height > 8);

    // Column placer
    for(int i = 0; i < structure_height; i++){
    // Row placer
        for(int j = 0; j < structure_height + 1; j++){
    // If row block location is not correct then place empty space
            if(j < structure_height - i){
                printf(" ");
    // Else if it is, place a block
            }else{
                printf("#");
    // If block placed is at the edge then place two empty spaces
                if(j == structure_height){
                    printf("  ");
    // Then place left aligned pyramid after those two empty spaces
                    for(int k = 0; k < i + 1; k++){
                        printf("#");
                    }
                }
            }
        }
        printf("\n");
    }
}
