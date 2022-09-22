
#include "headers.h"

// --------------------------------------------- **** ------------------------------------------

// 1-indexed node 
void DFS(int start, vector<int> v[],vector<int> &visited) {
    visited[start] = 1;
    for(int i= 0; i<v[start].size(); ++i) {        
        if(visited[v[start][i]] == 0)
            DFS(v[start][i], v, visited);        
    }    
}

void solve1(int case_num){
    int connected=0, temp1, temp2,n, p;
    cin>>n>>p; // number of vertices and edges
    vector<int> v[n+1], visited(n+1,0);
    for(int i=0; i<p; ++i) {
        cin>>temp1>>temp2;
        v[temp1].push_back(temp2);
        v[temp2].push_back(temp1);
    }     
    connected = 0;
    for(int i=1;i<=n;++i) {
        if(visited[i] == 0 ) {
            connected++;
            DFS(i,v,visited);
        }        
    }
    cout<<connected<<endl; // total no of connected components
}

// --------------------------------------------------------------------------------------------
// connected components using dsu using 0-indexed node naming
// use edges directly donot create adjacency list
// --------------------------------------------------------------------------------------------

int parent[1000000];
 
// Function to find the topmost
// parent of vertex a
int root(int a)
{
    // If current vertex is
    // the topmost vertex
    if (a == parent[a]) {
        return a;
    }
 
    // Otherwise, set topmost vertex of
    // its parent as its topmost vertex
    return parent[a] = root(parent[a]);
}
 
// Function to connect the component
// having vertex a with the component
// having vertex b
void connect(int a, int b)
{
    // Connect edges
    a = root(a);
    b = root(b);
 
    if (a != b) {
        parent[b] = a;
    }
}
 
// Function to find unique top most parents
void connectedComponents(int n)
{
    set<int> s;
 
    // Traverse all vertices
    for (int i = 0; i < n; i++) {
 
        // Insert all topmost
        // vertices obtained
        s.insert(root(parent[i]));
    }
 
    // Print count of connected components
    cout << s.size() << '\n';
}
 
// Function to print answer
void printAnswer(int N, vector< vector < int > > edges)
{
 
    // Setting parent to itself
    for (int i = 0; i <= N; i++) {
        parent[i] = i;
    }
 
    // Traverse all edges
    for (int i = 0; i < edges.size(); i++) {
        connect(edges[i][0], edges[i][1]);
    }
 
    // Print answer
    connectedComponents(N);
}
 


