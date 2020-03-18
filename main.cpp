#include <fstream>
#include <iostream>
#include <list>
#include <queue>
using namespace std;

//Group 29
//Pham Hoang Minh - s1024376
//Sebastian France - s1028982

// Graph class represents a undirected graph
// using adjacency list representation
class Graph
{
    long int V;    // No. of vertices
    // Pointer to an array containing adjacency lists
    list<long int> *adj;
    list<long int> componentsmax;
    
public:
    Graph(long int V);   // Constructor
    void addEdge(long int v, long int w);
    bool checker3 = false; //checker used for checking the 3rd largest components
    pair<long int, long int> connectedComponents();
    pair<long int, long int> bfs(long int u, bool visited[], int trigger); // function returns maximum distant
                                
};

Graph::Graph(long int V)
{
    this->V = V;
    adj = new list<long int>[V];
}
  
// method to add an undirected edge
void Graph::addEdge(long int v, long int w)
{
    adj[v].push_back(w);
    adj[w].push_back(v);
}
////////////////////////////////////////////////////////////////////////////////////////////////
  
// Method to print connected components in an
// undirected graph
pair<long int, long int> Graph::connectedComponents()
{
    // Mark all the vertices as not visited
    bool *visited = new bool[V];
    for(long int v = 0; v < V; v++)
        visited[v] = false;
    
    for (long int v=0; v<V; v++)
    {
        if (visited[v] == false)
        {
            pair<long int, long int> t1, t2;
            t1 = bfs(v, visited, 0); //get the initial farthest nodes id and its distance
            t2 = bfs(t1.first, visited, 1); //get the final farthest nodes id and its distance
            componentsmax.push_back(t2.second); //form a list of longest distance(diameter) of every distinct connected components
            
            //for testing purposes
            //for (long int v=0; v < V; v++)
            //    if (visited[v] == true) cout << v;
            //cout << endl;
        }
    }
    
    //for testing purposes
    //for (long int val : componentsmax)
    //   cout << val <<"-";
    //cout<< endl;
    
    long int max1 = 1; //1st longest diameter
    long int max2 = 1; //2nd longest diameter
    long int remainingv = V; //value used for checking 2nd and 3rd longest diameter
    
    bool checker1 = false; //a signal to tell if we have passed the 1st longest diameter
    bool checker2 = false;//a signal to tell if we have passed the 2nd longest diameter
    
    //find the 1st longest diameter
    for (long int val : componentsmax)
        if (val > max1) max1 = val;
    
    //find the 2nd longest diameter
    remainingv = remainingv - max1;
    
    if (remainingv > 0)
    {
        for (long int val : componentsmax)
            if (val > max2 && val < max1) max2 = val;
            else if (val == max1 && checker1 == false) checker1 = true;
            else if (val == max1 && checker1 == true) max2 = max1;
    }
    else return make_pair(2*max1, (-4));
    
    //determine if the 3rd longest diameter really affects the final (get checker3)
    remainingv = remainingv - max2;
    checker1 = false;
    
    if (remainingv > 0)
    {
    for (long int val : componentsmax)
        if (max1 == max2)
        {
            if (val == max1 && checker1 == false) checker1 = true;
            else if (val == max1 && checker1) checker2 = true;
            else if (val >= (max1 - 1) && checker2)
            {
                checker3 = true;
                break;
            }
        }
        else
            if (max2 == (max1 - 1))
            {
                if (val == max2 && !checker1) checker1 = true;
                else if (val >= (max2 - 1) && checker1)
                {
                    checker3 = true;
                    break;
                }
            }
    }
    
    //for testing purposes
    //cout << max1 <<"--"<<max2<<endl;
    return make_pair(max1,max2);
}
  
pair<long int, long int> Graph::bfs(long int start,bool visited[], int trigger)
{
    //  mark all distance with 0
    long int dis[V];
    for (long int i = 0; i < V; i++) dis[i] = 0;
  
    //intiate the queue with the starting vertex
    queue<long int> q;
    q.push(start);
  
    //  distance of u from u will be 1
    dis[start] = 1;
    //only mark the nodes as visited when the trigger is 1
    if(trigger == 1) visited[start] = true;
  
    while (!q.empty())
    {
        long int t = q.front();       q.pop();
  
        //  loop for all adjacent nodes of node-t
        for (auto it = adj[t].begin(); it != adj[t].end(); it++)
        {
            long int v = *it;
  
            // push node into queue only if
            // it is not visited already
            if (dis[v] == 0)
            {
                q.push(v);
                //only mark the nodes as visited when the trigger is 1
                if(trigger == 1) visited[v] = true;
                // make distance of v, one more than distance of t
                dis[v] = dis[t] + 1;
            }
        }
    }
  
    long int maxDis = 0;
    long int nodeIdx;
  
    //  get farthest node distance and its index
    for (long int i = 0; i < V; i++)
    {
        if (dis[i] > maxDis)
        {
            maxDis = dis[i];
            nodeIdx = i;
        }
    }
    
    //return the farthest node index and its distance
    return make_pair(nodeIdx, maxDis);
}

int main(int argc, char** argv) {
    // The final solution should use std::cin, but you may want to read from
    // a file for testing.
    //ifstream input;
    //input.open("big_8.in", ios::in);
    auto& input = std::cin;

    long int p, l;
    input >> p >> l;
    
    //create graph
    Graph g(p);
    

    for (long int i = 0; i < l; i++) {
       long int a, b;
        input >> a >> b;
        //create edges
        g.addEdge(a, b);
    }
    
    long int valuex; //final output
    pair<long int, long int> pairx; //value got from connectedComponents
    
    if (p <=2) cout << 0 << endl; //Situation: Less than or equal 2 vertices
    else if (l == 0) cout << 1 << endl; // Situation: more than 2 vertices and connections equal 0
    else
    {
        pairx = g.connectedComponents();
        
        //calculate final value based on checker3
        if (g.checker3) valuex = ((pairx.second / 2)*2 +3);
        else valuex = (pairx.first / 2) + 1 + (pairx.second / 2) + 1;
        
        //return final value excluding endpoints
        cout <<valuex-2<<endl;
        
    }
}
