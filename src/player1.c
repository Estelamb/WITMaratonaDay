// Autora, Estela Miranda Batista
// UFV - Campus Florestal

#include <stdlib.h>
#include <stdio.h>
#include "player1.h"

//retorna o movimento válido que vira mais peças
pos player1(game* g){
    unsigned i, j;

    // tecnica que ira comparar qual das tres estrategias é melhor
    pos p1, p2, p3;
    unsigned x = 0, y=0, z=0;
    int melhor;

    for(i = 0; i < g->b->nrows; i++){
        for(j = 0; j < g->b->ncols; j++){
            p1 = make_pos(i, j);
            p2 = make_pos(i,j);
            p3 = make_pos(i,j);

            melhor_interior(g, &x, &p1);
            melhor_canto(g, &y, &p2);
            melhor_lado(g, &z, &p3);

            if(x >= y && x >= z) melhor = 1;
            else if(y > x && y > z) melhor = 2;
            else melhor = 3;

            if(flanqueia(g, p1) && melhor == 1) return p1;
            if(flanqueia(g, p2) && melhor == 2) return p2;
            if(flanqueia(g, p3) && melhor == 3) return p3;
        }
    }
}