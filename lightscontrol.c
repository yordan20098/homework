#include <stdio.h>

void switchLights(unsigned char *state, int roomNumber) 
{
    *state ^= (1 << (roomNumber - 1));
}

void printState(unsigned char state) 
{
    printf("The light is on in rooms:");

    for (int i = 0; i < 8; i++) 
    {
        if ((state & (1 << i)) != 0) 
        {
            printf(" %d", i + 1);
        }
    }

    printf("\n");
}

int main() 
{
    unsigned char lightState = 0;

    int choice, roomNumber;

    do 
    {
        printf("\nMenu:\n");
        printf("1. Switch lights\n");
        printf("2. Print state\n");
        printf("0. Exit\n");
        printf("Enter your choice: ");
        scanf("%d", &choice);

        switch (choice) 
        {
            case 1:
                printf("Enter room number (1-8): ");
                scanf("%d", &roomNumber);

                if (roomNumber >= 1 && roomNumber <= 8) 
                {
                    switchLights(&lightState, roomNumber);
                    printf("Lights in room %d toggled.\n", roomNumber);
                } else 
                {
                    printf("Invalid room number. Please enter a number between 1 and 8.\n");
                }

                break;
            case 2:
                printState(lightState);
                break;
            case 0:
                printf("Exiting program.\n");
                break;
            default:
                printf("Invalid choice. Please enter a valid option.\n");
        }
    } while (choice != 0);

    return 0;
}
