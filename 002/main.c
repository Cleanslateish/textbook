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

void press_any_key_to_continue(){
  printf("$|Press any key to return to the main menu: ");
  getchar();
  printf("\n");
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
    printf("\n$|Error reading name input.\n");
    press_any_key_to_continue();
    return 1;
  }

  name[strcspn(name, "\n")] = '\0';
  
  for (size_t i = 0; i < strlen(name); i++){
    if(!isalpha(name[i]) && name[i] != ' '){
      printf("\n$|Name must contain only letters and spaces.\n");
      press_any_key_to_continue(); 
      return 1;
    }
  }

  strcat(name, "\n");
  return 0;
}



int get_user_input_contact_phone_number(char* phoneNumber){
  printf("$|Contact Phone Number: ");
  if(fgets(phoneNumber, 50, stdin)  == NULL){
    printf("\n$|Error reading phone number input.\n");
    press_any_key_to_continue();
    return 1;
  }

  phoneNumber[strcspn(phoneNumber, "\n")] = '\0';

  if(!is_all_digits(phoneNumber)){
    printf("\n$|Phone number must contain only digits.\n");
    press_any_key_to_continue();
    return 1;
  }

  strcat(phoneNumber, "\n");
  return 0;
}



int get_user_input_contact_email(char* email){
  printf("$|Contact Email: ");
  if(fgets(email, 100, stdin)  == NULL){
    printf("\n$|Error reading email input.\n");
    press_any_key_to_continue();
  }

  email[strcspn(email, "\n")] = '\0';

  if(!is_valid_email(email)){
    printf("\n$|Email must end with @gmail.com.\n");
    press_any_key_to_continue();
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
  

  FILE* file = fopen("contacts.txt", "a");

  if (file == NULL){

    printf("$|Error opening file!\n");
    return 1;
  }

  if(strlen(contact.name) > 0 && is_all_digits(contact.phoneNumber) && is_valid_email(contact.email)){
    fprintf(file, "%s%s",   "Name: ",          contact.name);
    fprintf(file, "%s%s",   "Phone Number: " , contact.phoneNumber);
    fprintf(file, "%s%s\n", "Email: ",         contact.email);
  }else{
    printf("$|One or more input fields are invalid. Contact not saved.\n");
  }

  fclose(file);
  return 0;
}

int view_contacts(){
  FILE* file = fopen("contacts.txt", "r");
  char fileBuffer[256];
  

  if(file == NULL){
    printf("$|Error opening file!\n");
    return 1;
  }


  while(fgets(fileBuffer, sizeof(fileBuffer), file) != NULL){
    printf("%s", fileBuffer);
  }

  fclose(file);

  return 0;
}

int delete_contact(){
  char delete_contact_buffer[256];
  view_contacts();
  printf("\n0|Cancel");
  printf("\n$|Please input the name of the contact you wish to delete: ");
  
  if(fgets(delete_contact_buffer, 256, stdin)  == NULL){
    printf("\n$|Error reading delete contact input.\n");
    press_any_key_to_continue();
  }

  FILE* file = fopen("contacts.txt", "r");
  if(file == NULL){
    printf("$|Error opening file.");
    return 1;
  }

  FILE* tempFile = fopen("temp.txt", "w");
  if(tempFile == NULL){
    printf("$|Error creating temporary file.");
    fclose(file);
    return 1;
  }

  char line[256];
  int found = 0;
  int lineSkip = 0;
  while(fgets(line, sizeof(line), file)){
    if(strcmp(delete_contact_buffer, "0") == 0){
      printf("\n$|Cancel-x \n");
      press_any_key_to_continue();
      return 0;
    }
    if(!found && strstr(line, delete_contact_buffer)){
      found = 1;
      lineSkip = 3;
      continue;
    } 

    if(lineSkip > 0){
      lineSkip--;
    }else{
      fputs(line, tempFile);
    }
  }


  fclose(file);
  fclose(tempFile);

  if(remove("contacts.txt") != 0){
      printf("Error deleting the original file.");
      return 1;
  }

  if(rename("temp.txt", "contacts.txt") != 0){
    printf("Error renaming the temporary file.");
    return 1;
  }


  return 0;
}

void main_menu(){
  int choice = 10;
  while(1){ 
    printf("\n1|Add Contact\n");
    printf("2|View Contacts\n");
    printf("3|Delete Contact\n");
    printf("0|Exit\n");
    printf("\n$|Please input a number from the list on screen.\n");

    printf("$|Choice: ");
    scanf("%d", &choice); 
    printf("\n");
    clear_input_buffer();

    switch(choice){
      case 0:
        printf("\n$|Exit-x\n");
        return;
      case 1:
        printf("$|Add Contact-x\n");
        add_contact();
        break;

      case 2:
        printf("$|View Contacts-x\n");
        view_contacts();
        press_any_key_to_continue();
        break;

      case 3:
        printf("$|Delete Contact-x\n");
        delete_contact();
        break;

      default: 
        printf("\n");
        printf("\n$|Please input a number from the list on screen.\n");
        while((choice = getchar() != '\n' && choice != EOF)){}
        break;
            
    }
  }
}



int main(){
  main_menu();
  return 0;
}
