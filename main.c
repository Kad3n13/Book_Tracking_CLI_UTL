#include <stdio.h>
#include "session.h"
#include "utils.h"   // Include the declaration of get_menu_choice()

int main() {
    int choice;

    while (1) {
	clear_screen();		// CLear screen before showing menu 
	
        printf("\n--- Reading Tracker ---\n");
        printf("1. Start Reading Session\n");
        printf("2. View Stats\n");
	printf("3. Clear all sessions\n");
        printf("4. Exit\n");
	

	
	 choice = get_menu_choice();

        if (choice == 1) {
            start_session();
            printf("\nPress Enter to return to menu...");
            getchar();  // wait for user to see summary
        }
        else if (choice == 2) {
            view_stats();
            printf("\nPress Enter to return to menu...");
            getchar();
        }
        else if (choice == 3) {
            clear_sessions();
            printf("\nPress Enter to return to menu...");
            getchar();
        }
        else if (choice == 4) {
            printf("Goodbye!\n");
            break;
        }
        else {
            printf("Invalid choice.\n");
            printf("\nPress Enter to try again...");
            getchar();
        }
    }

    return 0;
}

