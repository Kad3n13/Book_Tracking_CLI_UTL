#include <stdio.h>
#include <time.h>
#include <string.h>
#include "session.h"
#include <stdlib.h>

void wait_for_enter() {
    int c;
    while ((c = getchar()) != '\n' && c != EOF);
    printf("Press Enter to continue...");
    while ((c = getchar()) != '\n' && c != EOF);
}

void start_session() {
    time_t start, end;
    char book[128];
    int pages;
    char notes[256];

    wait_for_enter();
    start = time(NULL);

    printf("Reading session started! Press ENTER to end session..\n");
    wait_for_enter();
    end = time(NULL);

    int duration = (int)((end - start) / 60);
    if (duration <= 0) duration = 1;

    printf("You read for %d minute(s).\n", duration);

    printf("Enter book name: ");
    fgets(book, sizeof(book), stdin);
    book[strcspn(book, "\n")] = 0;

    printf("Pages read: ");
    scanf("%d", &pages);
    while (getchar() != '\n');

    printf("How was your reading experience? ");
    fgets(notes, sizeof(notes), stdin);
    notes[strcspn(notes, "\n")] = 0;

    printf("\nSession Summary:\n");
    printf("Book: %s\nPages: %d\nNotes: %s\nDuration: %d minutes\n",
           book, pages, notes, duration);

    FILE *fp = fopen("sessions.txt", "a");
    if (fp) {
        fprintf(fp, "%s|%d|%d|%s\n", book, pages, duration, notes);
        fclose(fp);
    } else {
        printf("Error: could not save session data.\n");
    }
}

void view_stats() {
    FILE *fp = fopen("sessions.txt", "r");
    if (!fp) {
        printf("No reading sessions found.\n");
        return;
    }

    char line[512];
    int session_count = 0;
    printf("\n--- Reading Sessions ---\n");

    while (fgets(line, sizeof(line), fp)) {
        char *p_book, *p_pages, *p_duration, *p_notes;
        int pages = 0, duration = 0;

        p_book = line;
        p_pages = strchr(p_book, '|');
        if (!p_pages) continue;
        *p_pages++ = '\0';

        p_duration = strchr(p_pages, '|');
        if (!p_duration) continue;
        *p_duration++ = '\0';

        p_notes = strchr(p_duration, '|');
        if (!p_notes) {
            p_notes = p_duration + strlen(p_duration);
        } else {
            *p_notes++ = '\0';
        }

        char *newline = strchr(p_notes, '\n');
        if (newline) *newline = '\0';

        pages = atoi(p_pages);
        duration = atoi(p_duration);

        printf("Book: %s | Pages: %d | Duration: %d min | Notes: %s\n",
               p_book, pages, duration, p_notes);
        session_count++;
    }

    if (session_count == 0) {
        printf("No valid session data found.\n");
    } else {
        printf("\nTotal sessions: %d\n", session_count);
    }

    fclose(fp);
}

