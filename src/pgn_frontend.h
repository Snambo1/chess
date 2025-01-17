#ifndef PGN_PGN_FRONTEND_H
#define PGN_PGN_FRONTEND_H

#include "board.h"
#include "pgn.h"
#include "symbol.h"
#include "tagspec.h"

/*the pgn list, specs list, list of symbols and the board, personally
I feel as though more verbose and specific variable names would go
a long way here, as these names are a tad too condensed */
typedef struct pgn_frontend_t {
    pgnlist_t* pgns;
    tagspec_t* spec;
    symboltable_t* symbols;
    board_t* board;
} pgn_frontend_t;

/* Allocates a new pgn_frontend */
pgn_frontend_t* pgn_frontend_new(void);

/* Deallocates pgn_frontend */
void pgn_frontend_free(pgn_frontend_t* env);

void pgn_frontend_run(pgn_frontend_t* env);

#endif
