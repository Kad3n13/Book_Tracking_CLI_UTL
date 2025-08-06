#include <stdio.h>
#include <stdlib.h>
#include <string.h>

void clear_screen(void) {
#ifdef _WIN32
    system("cls");
#else
    system("clear")
#endif
    }


int get_menu_choice() {
    char input[100];
    int choice;

    while (1) {
        printf("Choose: ");
        if (!fgets(input, sizeof(input), stdin)) {
            printf("Input error. Please try again.\n");
            continue;
        }

        input[strcspn(input, "\n")] = 0;

        char *endptr;
        choice = (int)strtol(input, &endptr, 10);
        if (endptr == input || *endptr != '\0') {
            printf("Invalid input, please enter a number.\n");
            continue;
        }

        return choice;
    }
}

// Clear the entire session file by trunacating it 
void clear_sessions() {
    FILE *fp = fopen("sessions.txt", "w"); // open in write mode to trunacte
    if (fp) {
	fclose(fp);
	printf("All sessions cleared.\n");
    } else {
	printf("Error: Unable to clear sessions.\n");
    }
}
