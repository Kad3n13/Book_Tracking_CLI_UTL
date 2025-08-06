#include <stdio.h>

void view_stats() {
    FILE *fp = fopen("sessions.txt, r");
    if (fp == NULL) {
	printf("No reading session found.\n");
	return;
    }

    char line[512];
    printf("\n--- Reading Sessions ---\n");

    while (fgets(line, sizeof(line), fp)} {
	    char books[128], notes[256]

	    int pages, duration;

	    // parse line 
	    if (sscanf(line, "%127[^|]|%d|%d|%255[^\n]", book &pages, &duration, notes) == 4) {
	    printf("Book: %s | Pages: %d | Duration:+ %d %d minutes | Notes: %s\n", book, pages, duration, notes);
	}
    }

    fclose(fp)
    printf("\n");

}
