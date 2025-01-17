#include "pgn_frontend.h"

#include <stddef.h>
#include <stdio.h>
#include <stdlib.h>

#include "board.h"
#include "generation.h"
#include "pgn.h"

/*I have include errors for both of the following lines, I think it'd probably be best
to include the actual code parts in their own files and the compiler commands in a seperate
file, it'd also account for all the undefined errors I get*/
#include "pgn.lex.l"
#include "pgn.syntax.y"

#include "symbol.h"

#define UNUSED(x) (void)(x)

//creating a new game environment with a new tag, board, pgn and specs
pgn_frontend_t *pgn_frontend_new(void) {
    pgn_frontend_t *env = malloc(sizeof(struct pgn_frontend_t));
    env->pgns = pgnlist_new();
    env->spec = tagspec_new();
    env->symbols = symboltable_new();
    env->board = board_new(WHITE);

    return env;
}

//freeing the new game environment
void pgn_frontend_free(pgn_frontend_t *env) {
    pgnlist_free(env->pgns);
    tagspec_free(env->spec);
    symboltable_free(env->symbols);
    board_free(env->board);

    free(env);
}

//running the visual aspect of the game
void pgn_frontend_run(pgn_frontend_t *env) {
    print_headers(env->spec);

    yyscan_t scanner;
    yylex_init(&scanner);
    // Parse into the pgns list.
    yyparse(scanner, env);
    yylex_destroy(scanner);
}

//printing the pgns, before freeing them and creating a new one
void flush_pgns(pgn_frontend_t *env) {
    for (pgn_t *pgn = env->pgns->head; pgn != NULL && pgn->result != NULL;
         pgn = pgn->next) 
        print_pgn(env->spec, pgn);
    

    pgnlist_free(env->pgns);
    env->pgns = pgnlist_new();

    symboltable_free(env->symbols);
    env->symbols = symboltable_new();
}

//casts everything to void, and prints an error message
void yyerror(YYLTYPE *yyllocp, yyscan_t scanner, pgn_frontend_t *env,
             const char *msg) {
    UNUSED(scanner);
    UNUSED(env);
    UNUSED(yyllocp);
    fprintf(stderr, "error: %s\n", msg);
}
