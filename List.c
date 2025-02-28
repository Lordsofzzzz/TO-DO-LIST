#include <stdio.h>
#include <string.h>

struct todo {
    char description[100];
};

int taskcount = 0;
struct todo task[100];

void addTask() {
    if (taskcount >= 100) {
        printf("The list is full.\n");
        return;
    }

    printf("Enter the task description: ");
    getchar();
    fgets(task[taskcount].description, 100, stdin);
    task[taskcount].description[strcspn(task[taskcount].description, "\n")] = 0;
    
    taskcount++;
    printf("The task has been added successfully.\n");
}

void viewTasks() {
    int i;
    if (taskcount == 0) {
        printf("No tasks available.\n");
        return;
    }

    printf("\nTo-Do List:\n");
    for (i = 0; i < taskcount; i++) {
        printf("%d: %s\n", i + 1, task[i].description);
    }
}

void deleteTask() {
    int i, index;
    if (taskcount == 0) {
        printf("No tasks to delete.\n");
        return;
    }

    printf("Enter the task number to delete: ");
    scanf("%d", &index);

    if (index < 1 || index > taskcount) {
        printf("Invalid task number.\n");
        return;
    }

    for (i = index - 1; i < taskcount - 1; i++) {
        task[i] = task[i + 1];
    }

    taskcount--;
    printf("Task deleted successfully.\n");
}

int main() {
    int choice;
    
    while (1) {
        printf("\nTo-Do List Menu:\n");
        printf("1. Add Task\n");
        printf("2. View Tasks\n");
        printf("3. Delete Task\n");
        printf("4. Exit\n");
        printf("Choose an option: ");
        scanf("%d", &choice);

        switch (choice) {
            case 1: addTask(); break;
            case 2: viewTasks(); break;
            case 3: deleteTask(); break;
            case 4: return 0;
            default: printf("Invalid choice! Try again.\n");
        }
    }

    return 0;
}
