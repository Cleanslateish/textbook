// Stack practice

#include <stdio.h>
#include <string.h>

#define MAX_SIZE 100

struct Stack {
  char top;
  char array[MAX_SIZE];
};

void push(struct Stack* stack, char item){
  if (stack->top >= MAX_SIZE - 1){
    printf("\nStack overflow\n");
    return;
  }
  stack->array[++stack->top] = item;

  printf("\n%c pushed to stack\n", item);
}

char pop(struct Stack* stack){
  if(stack->top < 0){
    printf("\nStack Underflow\n");
    return '\0';
  }
  char item = stack->array[stack->top];
  stack->top--;
  return item;
}

char peek(struct Stack* stack){
  if(stack->top < 0){
    printf("\nStack is empty\n");
    return '\0';
  }
  return stack->array[stack->top];
}

char isEmpty(struct Stack* stack){
  return stack->top == '\0';
}

char* reverseString(char* originalStr, struct Stack* stack){
  printf("\noriginal string: %s\n", originalStr);
  char* revStr = originalStr; 
  char* catStr; 
  
  for (size_t i = 0; i < strlen(originalStr) - 1; i++) {
    //printf("%c\n", originalStr[i]);
    push(stack, originalStr[i]);
  }

  for (size_t i = 0; i < strlen(originalStr) - 1; i++){
    printf("\n%c popped from stack\n", pop(stack));
     
  }


 return revStr;
}

int main(){
  char buffer[150];
  printf("Please input a string to reverse: ");
  if(fgets(buffer, 150, stdin) == NULL){
    return 1;
  }


  struct Stack stack;
  stack.top = '\0';

  reverseString(buffer, &stack);

//  printf("\n%c popped from stack \n", pop(&stack));
//  printf("\nTop element is %c\n", peek(&stack));



  return 0;
}
