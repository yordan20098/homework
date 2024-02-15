#include "processes.h"
#include <stdio.h>
#include <string.h>

struct Process processes[MAX_PROCESSES];
int processescount = 0;

static int generateprocessid(void) {
    static int id_counter = 1;
    if (id_counter > 0 && id_counter <= MAX_PROCESSES) {
        return id_counter++;
    } else {
        return 0; 
    }
}

int nextprocessid(void) {
    return generateprocessid();
}

int createnewprocess(const char *name) {
    if (processescount >= MAX_PROCESSES) {
        printf("Error: The maximum number of running processes has been reached.\n");
        printf("To create a new process, you need to stop one of the workers.\n");
        return 0;
    }

    int processid = generateprocessid();
    if (processid == 0) {
        printf("Error: Unique process numbers are run out.\n");
        return 0;
    }

    struct Process newprocess;
    newprocess.id = processid;
    strncpy(newprocess.name, name, MAX_NAME_LENGTH);
    newprocess.name[MAX_NAME_LENGTH] = '\0';

    processes[processescount++] = newprocess;

    printf("Process #%d created successfully: %s\n", newprocess.id, newprocess.name);

    return processid;
}

void stopprocess(int processid) {
    for (int i = 0; i < processescount; i++) {
        if (processes[i].id == processid) {
            printf("Process #%d stopped successfully: %s\n", processes[i].id, processes[i].name);

            for (int j = i; j < processescount - 1; j++) {
                processes[j] = processes[j + 1];
            }
            processescount--;
            return;
        }
    }

    printf("Error! Processes with number #%d wasn't found.\n", processid);
}
