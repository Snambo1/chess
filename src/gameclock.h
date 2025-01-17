#ifndef gameclock_H
#define gameclock_H

#define GAMECLOCK_MINUTE 60

//stores the time, and a linked list keeping track of the times
typedef struct timestamp {
    int time;
    struct timestamp* next;
} timestamp_t;

//stores the linked lists of the times
typedef struct gameclock {
    timestamp_t* head;
    timestamp_t* tail;
} gameclock_t;

gameclock_t* gameclock_new(void);

void gameclock_add(gameclock_t* gameclock, const char* h_m_s);

void gameclock_free(gameclock_t* gameclock);

#endif
