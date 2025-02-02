#include <stdio.h>
#include <unistd.h>

void step_animation(char c){
    printf("%c\b", c);
    fflush(stdout);
    usleep(200000);
}

int main(){
    printf("Loading ");
    while(1){
        step_animation('\\');
        step_animation('-');
        step_animation('/');
        step_animation('|');
    }
}
