#include <stdio.h>
#include <stdlib.h>
#include <string.h>

void clear_input_buffer(){
  int c;
  while((c = getchar()) != '\n' && c != EOF){}
  
}

struct Contact{
  char name[50];
  char phoneNumber[50];
  char email[100];
};



void add_contact(){
  clear_input_buffer();
  char contact_info_buffer[100];
  struct Contact contact1;
  

  printf("$|Contact Name: ");
  if(fgets(contact_info_buffer, sizeof(contact_info_buffer), stdin)  != NULL){
    printf("\n");
    
    //Remove the newline charcter if it exists
    contact_info_buffer[strcspn(contact_info_buffer, "\n")] = '\0';
    
    //Add newline character (fgets doesn't do this for us)
    strcat(contact_info_buffer, "\n");
  }else{
    printf("Error reading input.\n");
  }
  strcpy(contact1.name, contact_info_buffer); 
  


  printf("$|Contact Phone Number: ");
  if(fgets(contact_info_buffer, sizeof(contact_info_buffer), stdin)  != NULL){
    printf("\n");
    
    //Remove the newline charcter if it exists
    contact_info_buffer[strcspn(contact_info_buffer, "\n")] = '\0';
    
    //Add newline character (fgets doesn't do this for us)
    strcat(contact_info_buffer, "\n");
  }else{
    printf("Error reading input.\n");
  }
  strcpy(contact1.phoneNumber, contact_info_buffer); 
  
  printf("$|Contact Email: ");
  if(fgets(contact_info_buffer, sizeof(contact_info_buffer), stdin)  != NULL){
    printf("\n");
    
    //Remove the newline charcter if it exists
    contact_info_buffer[strcspn(contact_info_buffer, "\n")] = '\0';
    
    //Add newline character (fgets doesn't do this for us)
    strcat(contact_info_buffer, "\n");
  }else{
    printf("Error reading input.\n");
  }
  strcpy(contact1.email, contact_info_buffer); 


  FILE *file = fopen("contacts.txt", "a");

  if (file == NULL){

    printf("Error opening file!\n");
    return;
  }

  fprintf(file, "%s", contact1.name);
  fprintf(file, "%s", contact1.phoneNumber);
  fprintf(file, "%s\n", contact1.email);

  fclose(file);

    

}






void main_menu(){
  int choice = 10;
  printf("1|Add Contact\n");
  printf("2|View Contacts\n");
  printf("3|Delete Contact\n");
  printf("0|Exit\n");
  printf("\n");

  printf("$|Please input a  number from the list on screen.\n");
  printf("\n");
  printf("$|Choice: ");
  scanf("%d", &choice); 
  printf("\n");

  switch(choice){
    case 0:
      printf("\n");
      printf("$|Exiting-x\n");
      break;

    case 1:
      printf("$|Add Contact-x\n");
      add_contact();
      main_menu();
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




int main(){
  main_menu();
  return 0;
}
