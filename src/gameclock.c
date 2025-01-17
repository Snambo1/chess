#include "gameclock.h"

#include <stdlib.h>
#include <string.h>

//initiates a new chess clock
gameclock_t* gameclock_new(void) {
    gameclock_t* gameclock = malloc(sizeof(gameclock_t));

    gameclock->head = NULL;
    gameclock->tail = NULL;

    return gameclock;
}

//returns the total amount of seconds parsed given the hour, minute, and current seconds
int parse_timestamp(const char* h_m_s) {
    int seconds = 0;

    // For each chunk
    const char* head = h_m_s;
    for (int i = 0; i < 3; i++) {
        int chunk = atoi(head);
        int multiplier = (2 - i) * GAMECLOCK_MINUTE;
        if (multiplier != 0)
            chunk *= multiplier;

        seconds += chunk;

        head = index(head, ':');
        if (head == NULL) 
            break;

        head++;
    }

    return seconds;
}

//shows the time per move and adds it to a linked list
void gameclock_add(gameclock_t* gameclock, const char* h_m_s) {
    timestamp_t* next = malloc(sizeof(timestamp_t));
    next->time = parse_timestamp(h_m_s);
    next->next = NULL;

    if (gameclock->tail == NULL) {
        gameclock->head = next;
        gameclock->tail = next;
    } else {
        gameclock->tail->next = next;
        gameclock->tail = gameclock->tail->next;
    }
}

//frees all the timestamp_ts
void timestamp_free(timestamp_t* time) {
    while (time != NULL) {
        timestamp_t* next = time->next;

        free(time);

        time = next;
    }
}

//frees the gameclock_t
void gameclock_free(gameclock_t* gameclock) {
    timestamp_free(gameclock->head);
    free(gameclock);
}
