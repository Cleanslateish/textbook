#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>
#include <stdbool.h>

typedef struct{
  char name[50];
  char phoneNumber[50];
  char email[100];
}Contact;

void clear_input_buffer(){
  int c;
  while((c = getchar()) != '\n' && c != EOF){} 
}

bool is_all_digits(const char* str) {
    while (*str) {
        if (*str == '\n') { 
            // Skip the newline character
            str++;
            continue;
        }
        
        if (!isdigit(*str)) {
            return false;
        }
        
        str++;
    }
    return true;
}

bool is_valid_email(const char* email) {
  char fMail[100];
  strcpy(fMail, email);
  fMail[strcspn(fMail, "\n")] = '\0';

  const char* gmail_domain = "@gmail.com";
  size_t email_len = strlen(fMail);
  size_t domain_len = strlen(gmail_domain);

  if (email_len <= domain_len) {
    return false;
  }

  return strcmp(fMail + email_len - domain_len, gmail_domain) == 0;
}

int get_user_input_contact_name(char* name){
  clear_input_buffer();

  //CONTACT NAME
  printf("$|Contact Name: ");
  if(fgets(name, 100, stdin)  != NULL){
   // printf("\n");

    //Remove the newline charcter if it exists
    name[strcspn(name, "\n")] = '\0';
    //Add newline character (fgets doesn't do this for us)
    strcat(name, "\n");

    if(strlen(name) < 1) {
      printf("Name must be at least 1 characters long\n");
      clear_input_buffer();
      return 1;
    }

  }else{
    printf("Error reading input.\n");
    clear_input_buffer();
    return 1;
  }

  return 0;
}

int get_user_input_contact_phone_number(char* phoneNumber){
  clear_input_buffer();
  
  //CONTACT PHONE NUMBER
  printf("$|Contact Phone Number: ");
  if(fgets(phoneNumber, 100, stdin)  != NULL){
   // printf("\n");

    phoneNumber[strcspn(phoneNumber, "\n")] = '\0';
    strcat(phoneNumber, "\n");

    if(!is_all_digits(phoneNumber)){
      printf("Phone number must contain only digits\n");
      clear_input_buffer();
      return 1;
    }

  }else{
    printf("Error reading input.\n");
    clear_input_buffer();
    return 1;
  }

  return 0;
}

int get_user_input_contact_email(char* email){
  clear_input_buffer();

  //CONTACT EMAIL
  printf("$|Contact Email: ");
  if(fgets(email, 100, stdin)  != NULL){
   // printf("\n");

    email[strcspn(email, "\n")] = '\0';
    strcat(email, "\n");

    if(!is_valid_email(email)){
      printf("Email must end with @gmail.com\n");
      clear_input_buffer();
      return 1;
    }

  }else{
    printf("Error reading input.\n");
    clear_input_buffer();
    return 1;
  }

  return 0;
}

//void get_user_input_for_adding_contacts(char* name, char* phoneNumber, char* email){}

int store_contact_info(Contact* contact){
  if(get_user_input_contact_name         (contact -> name) == 1){
    return 1;
  }
  if(get_user_input_contact_phone_number (contact -> phoneNumber) == 1){
    return 1;
  }
  if(get_user_input_contact_email        (contact -> email) == 1){
    return 1;
  }

  return 0;
}

int add_contact(){
  Contact contact;
  
  if(store_contact_info(&contact) == 1){
    return 1;
  }
  

  FILE *file = fopen("contacts.txt", "a");

  if (file == NULL){

    printf("Error opening file!\n");
    return 1;
  }

  fprintf(file, "%s%s",   "Name: ",          contact.name);
  fprintf(file, "%s%s",   "Phone Number: " , contact.phoneNumber);
  fprintf(file, "%s%s\n", "Email: ",         contact.email);

  fclose(file);
    
  return 0;
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
      if(add_contact() == 1){
        main_menu();
      }
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
