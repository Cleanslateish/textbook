
#ifndef UTILS_H
#define UTILS_H

enum PriorityLevel { LOW, MEDIUM, HIGH }; 

struct Task{
  char* description[100];
  char* due_date[20];
  enum PriorityLevel priorityLevel;
};

#endif
