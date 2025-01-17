#include "dot.h"

#include <stdio.h>

/*prints out the edge's old square, its new square, and the square color
to specified file output stream*/
void dot_fprint_edge(FILE* out_fp, dot_edge_t edge) {
    fprintf(out_fp, "\t%s->%s [color=%s]\n", edge.a, edge.b, edge.color);
}

/*prints out the node's square, its label, then its row and column
to the specified file output stream
*/
void dot_fprint_node(FILE* out_fp, dot_node_t node) {
    fprintf(out_fp,
            "\t%s [shape=circle label=\"%s\" "
            "pos=\"%d,%d\" "
            "]\n",
            node.id, node.label, node.pos_x, node.pos_y);
}

//prints start of file
void dot_fprint_start(FILE* out_fp) {
    fprintf(out_fp, "digraph {\noverlap=false;\nscale=true;\n");
}

//print end of file
void dot_fprint_end(FILE* out_fp) { 
    fprintf(out_fp, "}\n"); 
}
