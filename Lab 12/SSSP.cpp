#include <iostream>
#define INF 999
#define n 6;

using namespace std;

void printCost(int cost, int start, int end) {
    cout << "time taken from " << start << " to " << end << " --> " << cost << endl;
}

string printPath(int prevNode[], int end) {
    if(prevNode[end] == -1) {
        return to_string(end);
    } else {
        return printPath(prevNode, prevNode[end]) + " --> " + to_string(end);
    }
}

void sssp(int G[6][6], int start) {
    int timeTaken[6];
    fill(begin(timeTaken), end(timeTaken), INF);
    timeTaken[start] = 0;
    int prevNode[6];
    fill(begin(prevNode), end(prevNode), -1);

    bool visited[6];
    fill(begin(visited), end(visited), false);
    int min = start;
    int minTime = 0; 
    while(minTime!=INF) {
        for(int i=0; i<=5; i++) {
            if(!visited[i] && (timeTaken[min] + G[min][i])<timeTaken[i] && i!=min) {
                timeTaken[i] = (timeTaken[min] + G[min][i]);
                prevNode[i] = min;
            }
        }
        visited[min] = true;
        minTime = INF;
        for(int j=0; j<=5; j++) {
            if(!visited[j] && minTime>timeTaken[j]) {
                minTime = timeTaken[j];
                min = j;
            }
        }
    }
    for(int i=0; i<=5; i++) {
        if(i!=start) {
            printCost(timeTaken[i], start, i);
            string s = printPath(prevNode, i);
            cout << s << endl;
        }
    }
}

int main() {
    int G[6][6]={
        {0,10,INF,INF,15,5},
        {10,0,10,30,INF,INF},
        {INF,10,0,12,5,INF},
        {INF,30,12,0,INF,20},
        {15,INF,5,INF,0,INF},
        {5,INF,INF,20,INF,0}
    };
    cout << "Start node 0 " << endl;
    sssp(G, 0);
    cout << endl << "Start node 1 " << endl;
    sssp(G, 1);
    cout << endl << "Start node 2 " << endl;
    sssp(G, 2);
    cout << endl << "Start node 3 " << endl;
    sssp(G, 3);
    cout << endl << "Start node 4 " << endl;
    sssp(G, 4);
    cout << endl << "Start node 5 " << endl;
    sssp(G, 5);
}