#include "processes.h"
#include <stdio.h>

void printallprocesses(void) {
    printf("List of all processes:\n");
    for (int i = 0; i < processescount; i++) {
        printf("Process #%d: %s\n", processes[i].id, processes[i].name);
    }
}

int main(void) {
    int choice;
    char name[MAX_NAME_LENGTH + 1];

    do {
        printf("\n Menu:\n");
        printf("1. Creation of process.\n");
        printf("2.Printing list with all processes.\n");
        printf("3. Stopping the process.\n");
        printf("4. Exit.\n");
        printf("Choose an option: ");
        scanf("%d", &choice);

        switch (choice) {
            case 1:
                printf("Enter name of the process: ");
                scanf("%s", name);
                createnewprocess(name);
                break;

            case 2:
                printallprocesses();
                break;

            case 3:
                printf("Enter number of the process, that you want to stop: ");
                int processid;
                scanf("%d", &processid);
                stopprocess(processid);
                break;

            case 4:
                printf("Exit of the program.\n");
                break;

            default:
                printf("Wrong choice. Please, enter again.\n");
                break;
        }

    } while (choice != 4);

    return 0;
}
