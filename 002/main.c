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
  printf("$|Contact Name: ");
  if(fgets(name, 50, stdin)  == NULL){
    printf("\nError reading name input\n");
    return 1;
  }

  name[strcspn(name, "\n")] = '\0';
  
  for (size_t i = 0; i < strlen(name); i++){
    if(!isalpha(name[i]) && name[i] != ' '){
      printf("\nName must contain only letters and spaces\n");
      return 1;
    }
  }

  strcat(name, "\n");
  return 0;
}



int get_user_input_contact_phone_number(char* phoneNumber){
  printf("$|Contact Phone Number: ");
  if(fgets(phoneNumber, 50, stdin)  == NULL){
    printf("\nError reading phone number input\n");
    return 1;
  }

  phoneNumber[strcspn(phoneNumber, "\n")] = '\0';

  if(!is_all_digits(phoneNumber)){
    printf("\nPhone number must contain only digits\n");
    return 1;
  }

  strcat(phoneNumber, "\n");
  return 0;
}



int get_user_input_contact_email(char* email){
  printf("$|Contact Email: ");
  if(fgets(email, 100, stdin)  == NULL){
    printf("\nError reading email input\n");
  }

  email[strcspn(email, "\n")] = '\0';

  if(!is_valid_email(email)){
    printf("\nEmail must end with @gmail.com\n");
    return 1;
  }

  strcat(email, "\n");
  return 0;
}


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

  if(strlen(contact.name) > 0 && is_all_digits(contact.phoneNumber) && is_valid_email(contact.email)){
    fprintf(file, "%s%s",   "Name: ",          contact.name);
    fprintf(file, "%s%s",   "Phone Number: " , contact.phoneNumber);
    fprintf(file, "%s%s\n", "Email: ",         contact.email);
  }else{
    printf("One or more input fields are invalid. Contact not saved\n");
  }

  fclose(file);
    
  return 0;
}


void main_menu(){
  int choice = 10;
  while(1){ 
    printf("\n1|Add Contact\n");
    printf("2|View Contacts\n");
    printf("3|Delete Contact\n");
    printf("0|Exit\n");
    printf("\n$|Please input a  number from the list on screen.\n");

    printf("\n");
    printf("$|Choice: ");
    scanf("%d", &choice); 
    printf("\n");
    clear_input_buffer();

    switch(choice){
      case 0:
        printf("\n");
        printf("$|Exiting-x\n");
        return;
      case 1:
        printf("$|Add Contact-x\n");
        add_contact();
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
        break;
            
    }
  }
}



int main(){
  main_menu();
  return 0;
}
