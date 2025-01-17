#ifndef DOT_H
#define DOT_H

#include <stdio.h>

//stores node's square,label, row and column
/*
I'd probably advise renaming id and label to more practical variable names
as someone else looking at them might have to go digging to find what they are*/
typedef struct dot_node {
    const char* id;
    const char* label;
    int pos_x;
    int pos_y;
} dot_node_t;

//specifies where edge started and where it ended up, and square's color
/*a and b represent where the piece is going and where its from but
this isn't immediately understandable without reading the rest of the code,
renaming them might also be beneficial to code readability
*/
typedef struct dot_edge {
    const char* a;
    const char* b;
    const char* color;
} dot_edge_t;

void dot_fprint_edge(FILE* out_fp, dot_edge_t edge);

void dot_fprint_node(FILE* out_fp, dot_node_t node);

void dot_fprint_start(FILE* out_fp);

void dot_fprint_end(FILE* out_fp);

#endif
