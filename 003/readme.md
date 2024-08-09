# Command-line Todo List Application

Task made by Claude.
This project assignment is designed to practice key programming concepts including pointers, dynamic memory allocation, data structures, and file I/O.

## Project: Command-line Todo List Manager

### Objective:
Create a comprehensive command-line application to manage a todo list, allowing users to add, view, update, and delete tasks, while implementing various programming concepts.

### Instructions:

1. **Define Task Structure:**
   - Create a structure to hold task information. Include fields such as task description, due date, and priority level.

2. **Implement a Linked List:**
   - Use a linked list to store the tasks. This will require understanding of pointers and dynamic memory allocation.

3. **Main Menu:**
   - Implement a menu that allows users to select options such as "Add Task," "View Tasks," "Update Task," "Delete Task," "Save to File," and "Load from File."

4. **Add Task:**
   - Implement functionality to add a new task to the list. Collect user input for task details.
   - Allocate memory dynamically for each new task.

5. **View Tasks:**
   - Implement functionality to display all tasks in the list.
   - Include an option to sort tasks by due date or priority using a simple sorting algorithm.

6. **Update Task:**
   - Allow users to update the details of an existing task.

7. **Delete Task:**
   - Implement functionality to delete a task from the list based on user input.
   - Ensure proper deallocation of memory when a task is deleted.

8. **File I/O:**
   - Implement "Save to File" functionality to write the current task list to a file.
   - Implement "Load from File" functionality to read tasks from a file into the program.

9. **Undo/Redo Functionality:**
   - Implement a stack to keep track of operations, allowing users to undo or redo actions.

10. **Error Handling:**
    - Add robust error handling for cases such as attempting to view tasks when none have been added, trying to delete a task that doesn't exist, file I/O errors, etc.

### Advanced Features (Optional):

11. **Task Categories:**
    - Implement a way to categorize tasks and filter view by category.

12. **Recurring Tasks:**
    - Allow users to set tasks as recurring (daily, weekly, monthly).

13. **Command-line Arguments:**
    - Implement functionality to add or complete tasks directly via command-line arguments.

### Tips:

- Use functions to keep your code organized and readable.
- Comment your code thoroughly to explain your implementation choices.
- Test your program extensively, including edge cases.
- Consider using typedef to create aliases for your structures for cleaner code.
- Remember to free any dynamically allocated memory to avoid memory leaks.

### Compilation and Execution:

Provide clear instructions on how to compile and run the program, including any necessary compiler flags.

Example:
```
gcc -o todo_list todo_list.c
./todo_list
```

This project will give you hands-on experience with:
- Pointers and dynamic memory allocation
- Implementing and manipulating linked lists
- Basic file I/O operations
- Structuring a larger program with multiple functionalities
- Error handling and input validation

Good luck, and happy coding!
