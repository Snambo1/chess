#include "move.h"

#include <stdlib.h>

#include "square.h"

//creates a new list to store the moves
movelist_t* movelist_new(void) {
    movelist_t* moves = malloc(sizeof(movelist_t));
    moves->head = NULL;

    return moves;
}

//frees all the moves
void move_free(move_t* move) {
    if (move == NULL)
        return;

    move_free(move->next);
    free(move);
}

//creates a new move
move_t* move_new(square_t from, square_t to) {
    move_t* move = malloc(sizeof(move_t));

    move->next = NULL;

    move->from = from;
    move->to = to;
    move->capture = false;

    return move;
}

//frees the whole movelist
void movelist_free(movelist_t* moves) {
    move_free(moves->head);
    free(moves);
}

//inserts a move at the end of the list
void movelist_insert_end(movelist_t* moves, move_t* move) {
    if (moves->head == NULL) {
        moves->head = move;
        moves->tail = move;
    }

    moves->tail->next = move;
    moves->tail = move;
}

//returns the total amount of moves
size_t movelist_count(movelist_t* moves) {
    size_t count = 0;
    for (move_t* move = moves->head; move != NULL; move = move->next)
        count++;

    return count;
}

//removes the start of the movelist
void movelist_remove_start(movelist_t* moves) {
    if (moves->head == NULL)
        return;

    if (moves->head == moves->tail) {
        move_free(moves->head);
        moves->head = NULL;
        moves->tail = NULL;

        return;
    }

    move_t* old_head = moves->head;
    move_t* head = old_head->next;

    old_head->next = NULL;
    move_free(old_head);

    if (head->next == NULL)
        moves->tail = head;

    moves->head = head;
}
