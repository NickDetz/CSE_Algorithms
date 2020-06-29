//Collaborated with Tristan Fong
#include <iostream>
#include <limits.h>
#include <math.h>

using namespace std;

class Edges {

public:
  //Public Values given as start and finish then the values of the shortest path
    int start, finish, values;
  };

class Graph {

public:
// Making a class called graph to store the values help with rotation
    int Vals, E;
    Edges *e;
};

int main() {
  //Graphing the verticies to the code is the
    Graph g;
    int vert, e;
    cin >> vert;
    cin >> e;
    g.Vals = vert;
    g.E = e;
    g.e = new Edges[g.E];
    for (int i = 0; i < g.E; i++)
    {
      // inpute the start, end and am with integers
        int start;
        int end;
        int am;
        cin >> start >> end >> am;

        g.e[i].start = start;
        g.e[i].finish = end;
        g.e[i].values = am;
    }
    //Get Values into an array
    int Dis[g.Vals];
    // for getting values in the ammounts
    for (int j = 0; j < g.Vals; j++)
    {
      // array for storing the values of distance being counted
        Dis[j] = INT_MAX;
    }
    //Pyramid of Death Check for values of the 3 arrays tried to condense
    Dis[0] = 0;
    for (int i = 0; i < g.Vals; i++)
    {
        for (int j = 0; j < g.E; j++)
        {
            // int a = g.e[j].am
            int a = g.e[j].start;
            int b = g.e[j].finish;
            if (Dis[a] + g.e[j].values < Dis[b] && Dis[a] != INT_MAX)
                Dis[b] = Dis[a] + g.e[j].values;
        }}
    for (int k = 0; k < g.E; k++)
    {
        int a = g.e[k].start, b = g.e[k].finish;
        if (Dis[a] + g.e[k].values < Dis[b] && Dis[a] != INT_MAX)
        {
            cout << "FALSE" << endl;
            return 0;}}
    cout << "TRUE" << endl;
    for (int l = 0; l < g.Vals; l++)
    {
// check for logical errors
        if (Dis[l] == INT_MAX)
        {
          cout << "INFINITY" << endl;
        }
        else
        {
            cout << Dis[l] << endl;
        }
    }
    return 0;
}
