#include <stdio.h>
#include <unistd.h>
#include <math.h>

#define WIDTH 80
#define HEIGHT 30

struct Circle{
    int x, y, v_x, v_y, radius;
};

void clear_screen(){
    printf("\e[2J");
}

void reset_cursor(){
    printf("\e[H");
}

void print_frame(struct Circle circle){
    for(int y = 0; y < HEIGHT; y++){
        for(int x = 0; x < WIDTH; x++){
            double distance = sqrt( pow(x - circle.x, 2) + pow(y - circle.y, 2));

            if(distance < circle.radius){
                printf("@");
            }else{
                printf(".");
            }
        }
        printf("\n");
    }
}

void step_animation(struct Circle *circle){
    circle->x += circle->v_x;
    circle->y += circle->v_y;
    
    if(circle->x - circle->radius < 0)
        circle->v_x = - circle->v_x;
    if(circle->x + circle->radius > WIDTH)
        circle->v_x = - circle->v_x;
    if(circle->y - circle->radius < 0)
        circle->v_y = - circle->v_y;
    if(circle->y + circle->radius > HEIGHT)
        circle->v_y = - circle->v_y;
    
}

int main(){
    struct Circle circle1 = {10, 5, 1, 1, 4}; //x, y, v_x, v_y, radius;

    clear_screen();

    while(1){
        print_frame(circle1);
        usleep(100000);
        reset_cursor();
        step_animation(&circle1);
    }
}
