#include "Graph.h"
#include "Set.h"
#include "Queue.h"
#include "math.h"
//INFINITY is found in math.h

// We can use bfs
// We can also use dfs

// BFS
Set reachable(Graph g, Vertex src) {
    Set seenSet = newSet();
    Set bfsQueue = QueueNew();
    QueueEnqueue(bfsQueue, src);
    while (!QueueuIsEmpty(bfsQueue)) {
        Vertex nextIt = QueueDequeue(bfsQueue);
        if (SetMember(seenSet,nextIt)) {
            continue;
        }
        SetInsert(seenSet,nextIt);
        for (Vertex n = 0; n < GraphNumVertices(g);++n) {
            if (GraphIsAdjacent(g,nextIt,n) 
            && !SetMember(seenSet,n)) {
                QueueEnqueue(bfsQueue,n);
            }
        }
    }
    QueueFree(bfsQueue);
    return seenSet;
}


// DFS
/*
Start at node 1
Add node 1 to the seenset
Recursively call the dfs function on all neighbours of 1 
that arent in seenset
*/
Set reachableDFS(Graph g, Vertex src) {
    Set seenSet = newSet();
    dfsRecurse(g,src,seenSet);
    return seenSet;
}
// Recursive algorithm
void dfsRecurse(Graph g, Vertex src, Set seen) {
    SetInsert(seen,src);
    for (Vertex n = 0; n < GraphNumVertices(g);++n) {
        if (GraphIsAdjacent(g,src,n)
        && !SetMember(seen,n)) {
            dfsRecurse(g,n,seen);
        }
    }
}