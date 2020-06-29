// Collaborated with Tristan Fong
#include <algorithm>
#include <array>
#include <iostream>
#include <vector>
#include <stdlib.h>
//#include <math>

using namespace std;
const int MAX_N = 101;
bool visit[MAX_N] = {0};
vector<int> Reverse[MAX_N], order, adjac[MAX_N];
vector< vector<int> > STRCON;
// To find the first initial size and the visit everything else
void DFS(vector<int> graph[], vector<int> &res, int i) {
    visit[i] = true;
    for(int j = 0; j < graph[i].size(); j++)
    {
        if(!visit[graph[i][j]])
        {
            DFS(graph, res, graph[i][j]);
        }
    }

    res.push_back(i);
}

int main() {
    // Making the various Variable that will check for edges and verticies
    int i;
    int j;
    int key;
    int u;
    int v;
    int vertices = 0;
    int edges = 0;
    int com = 0;
    cin >> vertices;
    cin >> edges;
    int arr[vertices];
    for(i = 0; i < vertices; i++)
        arr[i] = i;
    for(i = 0; i < edges; i++) {
        cin >> u;
        cin >> v;
        adjac[u].push_back(v);
    }
    for(i = 0; i < vertices; i++)
        visit[i] = false;
    for(i = 0; i < vertices; i++) {
        if (visit[i])
            continue;
        DFS(adjac, order, i);
    }
    //Failed tests 4 and five for double check
    //  for(i = 0; i < vertices; i++)
    //visit[i] = false;
    //for(i = 0; i < vertices; i++) {
      //  if (visit[i])


    //Pushback function made for adjac sorting
    for(i = 0; i < vertices; i++)
        for(j = 0; j < adjac[i].size(); j++)
            Reverse[adjac[i][j]].push_back(i);



    for(i = 0; i < vertices; i++)
        visit[i] = false;
    // Reverseerse order check and the inflection point of the code
    reverse(order.begin(), order.end());
    for(i = 0; i < order.size(); i++)
    {
        if (visit[order[i]])
        {
            continue;
        }
        //vector<int> order;
        vector<int> component;
        DFS(Reverse, component, order[i]);
        STRCON.push_back(component);
    }
// Pyramid of Death is made checking, Tried to condense it down
    for(i = 0; i < STRCON.size(); i++)
    {for(j = 0; j < STRCON[i].size(); j++)
        {com = STRCON[i][j];
for(key = 0; key < vertices; key++)
            {if(arr[key] == com)
                {arr[key] = *min_element(STRCON[i].begin(), STRCON[i].end());
                }}}}

    for(i = 0; i < vertices; i++)
    {
        cout << arr[i] << endl;
    }

    return 0;
}
