#include <iostream>
#include <vector>

#define N 6
#define INF 999
using namespace std;

void prims(int G[N][N], int start){
    bool visited[N];
    fill(begin(visited),end(visited),false);
    int edgeSet[6];
    fill(begin(edgeSet),end(edgeSet),INF);
    int currNode = start;
    int weight = 0;
    string weightEdges;
    for(int j=0; j<N-1; j++){
        for(int i=0; i<N; i++){
            if(!visited[i] && G[currNode][i]!=INF && G[currNode][i]!=0 && edgeSet[i]>G[currNode][i]){
                edgeSet[i] = currNode;
            }
        }
        int min = INF;
        int minIndex;
        for(int i=0; i<N; i++){
            if(edgeSet[i] != INF && min>G[edgeSet[i]][i]) {
                min = G[edgeSet[i]][i];
                minIndex = i;
            }
        }
        weight+=min;
        weightEdges+= to_string(edgeSet[minIndex])+" --> "+ to_string(minIndex)+"\n";
        edgeSet[minIndex] = INF;
        visited[currNode] = true;
        currNode = minIndex;
    }
    cout << "Weight : " << weight << endl;
    cout << "Weight edges : \n" << weightEdges;
}

int main() {
    int G[N][N] = {
            {0, 3, INF, INF, INF, 1},
            {3, 0, 2, 1, 10, INF},
            {INF, 2, 0, 3, INF, 5},
            {INF, 1, 3, 0, 5, INF},
            {INF, 10, INF, 5, 0, 4},
            {1, INF, 5, INF, 4, 0}
    };
    prims(G, 0);
    return 0;
}
