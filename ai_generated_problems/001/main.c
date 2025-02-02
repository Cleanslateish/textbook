#include <stdio.h>


int main_menu_select_choice(){
  int choice = 10;
  printf("1| Addition\n");
  printf("2| Subtraction\n");
  printf("3| Multiplication\n");
  printf("4| Division\n");
  printf("0| Exit\n");

  printf("Choose a number from the list: ");
  scanf("%d", &choice);
  printf("\n"); 
  
      
  if (choice == 1 || choice == 2 || choice == 3 || choice == 4 || choice == 0){
    return choice;
  }else{
    while ((choice = getchar() != '\n' && choice != EOF)){
      //This is here to clear the input, because a wrong input
      //doesn't clear the input buffer automatically like it does
      //when its correct input. (in this case, we want only int).
    }
    return 10;
  }
}

void add_numbers(){
  float a = 0;
  float b = 0;

  printf("1|Number: ");
  scanf("%f", &a);
  
  printf("2|Number: ");
  scanf("%f", &b);
  printf("\n");

  printf("$|%g + %g = %g|\n", a, b, a + b);
}

void subtract_numbers(){
  float a = 0;
  float b = 0;

  printf("1|Number: ");
  scanf("%f", &a);
  
  printf("2|Number: ");
  scanf("%f", &b);
  printf("\n");

  printf("$|%g - %g = %g|\n", a, b, a - b);
}

void multiply_numbers(){
  float a = 0;
  float b = 0;

  printf("1|Number: ");
  scanf("%f", &a);
  
  printf("2|Number: ");
  scanf("%f", &b);
  printf("\n");


  printf("$|%g x %g = %g|\n", a, b, a * b);
}


void divide_numbers(){
  float a = 0;
  float b = 0;

  printf("1|Number: ");
  scanf("%f", &a);
  
  printf("2|Number: ");
  scanf("%f", &b);
  printf("\n");

  if(a == 0 || b == 0){
    printf("Can't divide by zero. Choose a different number.\n");
    divide_numbers();
  }else{
    printf("$|%g / %g = %g|\n", a, b, a / b);
  }

}

void run_choice(int choice){
  switch(choice){
    case 0:
      printf("\n");
      printf("$|Exiting-x\n");
      break;

    case 1:
      printf("$|Addition-x\n");
      add_numbers();
      printf("\n");
      run_choice(main_menu_select_choice());
      break;

    case 2:
      printf("$|Subtraction-x\n");
      subtract_numbers();
      printf("\n");
      run_choice(main_menu_select_choice());
      break;

      case 3:
      printf("$|Multiplication-x\n");
      multiply_numbers();
      printf("\n");
      run_choice(main_menu_select_choice());
      break;

    case 4:
      printf("$|Division-x\n");
      divide_numbers();
      printf("\n");
      run_choice(main_menu_select_choice());
      break;

    default:
      printf("\n");
      printf("$|Please input a number from the shown list|\n");
      printf("\n");
      run_choice(main_menu_select_choice());
      break;
  }
}




int main(){ 
  run_choice(main_menu_select_choice());
  return 0;
}
