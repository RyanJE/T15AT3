typedef struct _Edge {
    int from;
    int to;
} Edge;

typedef struct _Graph {
    int nE;
    int** e_matrix; // 0 for no edge, 1 otherwise
} Graph;

bool isEulerPath(Graph g, Edge e[], int nE) {
    /*
    if nE != g->nE return false
    all edges in e must be in graph
    end node of each edge equal to beginning node of succeeding edge
      n       n+1
    m -> k   k -> a 
    Each edge is not repeated
    */
   if (g->nE != nE) return false;
   for (int i = 0 ; i < nE;++i) {
       if (g->edges[e[i].from][e[i].to] != 1) {
           return false;
       }
   }
   for (int i = 0 ; i < nE-1;++i) {
       if (e[i].to != e[i+1].from) {
           return false;
       }
   }
   for (int i = 0; i < nE;++i) {
       for (int j = i+1; i < nE;++i) {
           if (edges[i].from == edges[j].from
           && edges[i].to == edges[j].from) {
               return false;
           }
           if (edges[i].from == edges[j].to
           && edges[i].to == edges[j].from) {
               return false;
           }
       }
   }
   return true;
}