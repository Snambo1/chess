#include "board.h"

#include <assert.h>
#include <stdio.h>
#include <stdlib.h>

#include "square.h"

//returns a pointer to newly created board with all its squares set to empty and the current turn
board_t *board_new(board_turn_t turn) {
    board_t *board = malloc(sizeof(board_t));
    for (size_t i = 0; i < SQUARE_COUNT; i++) {
        board->squares[i] = SQUARE_EMPTY;
    }

    board->turn = turn;

    return board;
}

//frees the board
void board_free(board_t *board) { 
    free(board); 
}

//places a piece on the given board square
void board_set_piece(board_t *board, square_t square, square_piece_t piece) {
    board->squares[square] = piece;
}

//gets the board rank of a given piece, or returns the rank count if the piece is not found
square_rank_t board_get_rank(board_t *board, square_piece_t piece,
                             square_file_t file) {
    for (int rank = 0; rank < SQUARE_RANK_COUNT; rank++) 
        if (board->squares[square_from(file, rank)] == piece) 
            return rank;    

    return SQUARE_RANK_OOB;
}

//gets the board file of a given piece, or returns the file count if the piece is not found
square_file_t board_get_file(board_t *board, square_piece_t piece,
                             square_rank_t rank) {
    for (int file = 0; file < SQUARE_FILE_COUNT; file++) 
        if (board->squares[square_from(file, rank)] == piece) 
            return file;

    return SQUARE_FILE_OOB;
}

//returns the piece on the board square, or SQUARE_EMPTY if one is not found
square_piece_t board_get_piece(board_t *board, square_t square) {
    return board->squares[square];
}
