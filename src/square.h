#ifndef SQUARE_H
#define SQUARE_H

#define SQUARE_RANK_COUNT 8
#define SQUARE_FILE_COUNT 8
#define SQUARE_COUNT 64

extern const char* SQUARE_NAMES[SQUARE_COUNT];

typedef enum square_rank {
    SQUARE_RANK_1 = 0,
    SQUARE_RANK_2,
    SQUARE_RANK_3,
    SQUARE_RANK_4,
    SQUARE_RANK_5,
    SQUARE_RANK_6,
    SQUARE_RANK_7,
    SQUARE_RANK_8,
    SQUARE_RANK_OOB,
} square_rank_t;

typedef enum square_file {
    SQUARE_FILE_A = 0,
    SQUARE_FILE_B,
    SQUARE_FILE_C,
    SQUARE_FILE_D,
    SQUARE_FILE_E,
    SQUARE_FILE_F,
    SQUARE_FILE_G,
    SQUARE_FILE_H,
    SQUARE_FILE_OOB,
} square_file_t;

/*defines a square, a suggestion could be having a 2d array of pointers,
it would probably allow for more pointer access rather than subscripting which could improve
the speed of the codebase as a whole, although that's a BIG change and it's up to you if you want to commit to that*/
typedef enum square {
    SQUARE_A1 = 0 + (0 * SQUARE_RANK_COUNT),
    SQUARE_A2 = 0 + (1 * SQUARE_RANK_COUNT),
    SQUARE_A3 = 0 + (2 * SQUARE_RANK_COUNT),
    SQUARE_A4 = 0 + (3 * SQUARE_RANK_COUNT),
    SQUARE_A5 = 0 + (4 * SQUARE_RANK_COUNT),
    SQUARE_A6 = 0 + (5 * SQUARE_RANK_COUNT),
    SQUARE_A7 = 0 + (6 * SQUARE_RANK_COUNT),
    SQUARE_A8 = 0 + (7 * SQUARE_RANK_COUNT),

    SQUARE_B1 = 1 + (0 * SQUARE_RANK_COUNT),
    SQUARE_B2 = 1 + (1 * SQUARE_RANK_COUNT),
    SQUARE_B3 = 1 + (2 * SQUARE_RANK_COUNT),
    SQUARE_B4 = 1 + (3 * SQUARE_RANK_COUNT),
    SQUARE_B5 = 1 + (4 * SQUARE_RANK_COUNT),
    SQUARE_B6 = 1 + (5 * SQUARE_RANK_COUNT),
    SQUARE_B7 = 1 + (6 * SQUARE_RANK_COUNT),
    SQUARE_B8 = 1 + (7 * SQUARE_RANK_COUNT),

    SQUARE_C1 = 2 + (0 * SQUARE_RANK_COUNT),
    SQUARE_C2 = 2 + (1 * SQUARE_RANK_COUNT),
    SQUARE_C3 = 2 + (2 * SQUARE_RANK_COUNT),
    SQUARE_C4 = 2 + (3 * SQUARE_RANK_COUNT),
    SQUARE_C5 = 2 + (4 * SQUARE_RANK_COUNT),
    SQUARE_C6 = 2 + (5 * SQUARE_RANK_COUNT),
    SQUARE_C7 = 2 + (6 * SQUARE_RANK_COUNT),
    SQUARE_C8 = 2 + (7 * SQUARE_RANK_COUNT),

    SQUARE_D1 = 3 + (0 * SQUARE_RANK_COUNT),
    SQUARE_D2 = 3 + (1 * SQUARE_RANK_COUNT),
    SQUARE_D3 = 3 + (2 * SQUARE_RANK_COUNT),
    SQUARE_D4 = 3 + (3 * SQUARE_RANK_COUNT),
    SQUARE_D5 = 3 + (4 * SQUARE_RANK_COUNT),
    SQUARE_D6 = 3 + (5 * SQUARE_RANK_COUNT),
    SQUARE_D7 = 3 + (6 * SQUARE_RANK_COUNT),
    SQUARE_D8 = 3 + (7 * SQUARE_RANK_COUNT),

    SQUARE_E1 = 4 + (0 * SQUARE_RANK_COUNT),
    SQUARE_E2 = 4 + (1 * SQUARE_RANK_COUNT),
    SQUARE_E3 = 4 + (2 * SQUARE_RANK_COUNT),
    SQUARE_E4 = 4 + (3 * SQUARE_RANK_COUNT),
    SQUARE_E5 = 4 + (4 * SQUARE_RANK_COUNT),
    SQUARE_E6 = 4 + (5 * SQUARE_RANK_COUNT),
    SQUARE_E7 = 4 + (6 * SQUARE_RANK_COUNT),
    SQUARE_E8 = 4 + (7 * SQUARE_RANK_COUNT),

    SQUARE_F1 = 5 + (0 * SQUARE_RANK_COUNT),
    SQUARE_F2 = 5 + (1 * SQUARE_RANK_COUNT),
    SQUARE_F3 = 5 + (2 * SQUARE_RANK_COUNT),
    SQUARE_F4 = 5 + (3 * SQUARE_RANK_COUNT),
    SQUARE_F5 = 5 + (4 * SQUARE_RANK_COUNT),
    SQUARE_F6 = 5 + (5 * SQUARE_RANK_COUNT),
    SQUARE_F7 = 5 + (6 * SQUARE_RANK_COUNT),
    SQUARE_F8 = 5 + (7 * SQUARE_RANK_COUNT),

    SQUARE_G1 = 6 + (0 * SQUARE_RANK_COUNT),
    SQUARE_G2 = 6 + (1 * SQUARE_RANK_COUNT),
    SQUARE_G3 = 6 + (2 * SQUARE_RANK_COUNT),
    SQUARE_G4 = 6 + (3 * SQUARE_RANK_COUNT),
    SQUARE_G5 = 6 + (4 * SQUARE_RANK_COUNT),
    SQUARE_G6 = 6 + (5 * SQUARE_RANK_COUNT),
    SQUARE_G7 = 6 + (6 * SQUARE_RANK_COUNT),
    SQUARE_G8 = 6 + (7 * SQUARE_RANK_COUNT),

    SQUARE_H1 = 7 + (0 * SQUARE_RANK_COUNT),
    SQUARE_H2 = 7 + (1 * SQUARE_RANK_COUNT),
    SQUARE_H3 = 7 + (2 * SQUARE_RANK_COUNT),
    SQUARE_H4 = 7 + (3 * SQUARE_RANK_COUNT),
    SQUARE_H5 = 7 + (4 * SQUARE_RANK_COUNT),
    SQUARE_H6 = 7 + (5 * SQUARE_RANK_COUNT),
    SQUARE_H7 = 7 + (6 * SQUARE_RANK_COUNT),
    SQUARE_H8 = 7 + (7 * SQUARE_RANK_COUNT),
    SQUARE_OOB = 404,
} square_t;

typedef enum square_piece {
    SQUARE_EMPTY = 0,
    SQUARE_PAWN_WHITE,
    SQUARE_PAWN_BLACK,
    SQUARE_KNIGHT_WHITE,
    SQUARE_KNIGHT_BLACK,
    SQUARE_BISHOP_WHITE,
    SQUARE_BISHOP_BLACK,
    SQUARE_ROOK_WHITE,
    SQUARE_ROOK_BLACK,
    SQUARE_QUEEN_WHITE,
    SQUARE_QUEEN_BLACK,
    SQUARE_KING_WHITE,
    SQUARE_KING_BLACK,
    SQUARE_PIECE_COUNT
} square_piece_t;

extern const char* PIECE_NAMES[SQUARE_PIECE_COUNT];

typedef square_piece_t squares_t[SQUARE_COUNT];

square_t square_from(int file, int rank);

square_rank_t square_get_rank(square_t square);

square_file_t square_get_file(square_t square);

#endif
