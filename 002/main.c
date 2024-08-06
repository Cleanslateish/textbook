#include <stdio.h>


void main_menu(){
  int choice = 10;
  printf("1|Add Contact\n");
  printf("2|View Contacts\n");
  printf("3|Delete Contact\n");
  printf("0|Exit\n");
  printf("\n");

  printf("$|Please type in a number from the list on screen.\n");
  printf("$|Choice: ");
  scanf("%d", &choice); 

  switch(choice){
    case 0:
      printf("\n");
      printf("$|Exiting-x\n");
      break;

    case 1:
      printf("$|Add Contact-x\n");
      break;

    case 2:
      printf("$|View Contacts-x\n");
      break;

    case 3:
      printf("$|Delete Contact-x\n");
      break;

    default: 
      printf("\n");
      printf("$| Please input a number from the shown list|\n");
      printf("\n");
      while((choice = getchar() != '\n' && choice != EOF)){}
      main_menu();
      break;
          
  }

}

void add_contact(){
  char contact_info_buffer[100];
  if(fgets(contact_info_buffer, sizeof(contact_info_buffer), stdin)  != NULL){
    
    
  }
}



int main(){
  main_menu();
  return 0;
}
