#include<iostream>
#include<vector>
#include<unordered_map>
#include<string>
#include<unordered_set>
#include<queue>
using namespace std;

struct graph {
  unordered_map<string,vector<string>> adjList;  
};
void addEdge(graph& g,const string& src,const string& dest){
    g.adjList[src].push_back(dest);
}
void printGraph(const graph& g){
    for(const auto& pair : g.adjList){
        cout<<pair.first<<"->";
        for (const auto& n : pair.second) {
            cout<<n<<" ";
        }
        cout<<endl;
    }
}
void dfs(const graph& g,const string& node, unordered_set<string>& visited){ // took a graph(reference variable) starting node which is also referenced and then visited set to avoid cycle
    visited.insert(node);// insert out current node in visited 
    cout<<node<<" "; // print node
    for(const string& neighbour : g.adjList.at(node)){// traverse 
        if (visited.find(neighbour)==visited.end()){
            dfs(g,neighbour,visited);
        }
    }
}

void bfs(const graph& g, const string& startNode) {
    unordered_set<string> visited;
    queue<string> q;
    visited.insert(startNode);
    q.push(startNode);
    while(!q.empty()){
        string node = q.front();
        q.pop();
        cout << node <<" ";

        if (g.adjList.find(node) != g.adjList.end()) {
            for (const string& neighbour : g.adjList.at(node)) {
                if (visited.find(neighbour)==visited.end()){
                    visited.insert(neighbour);
                    q.push(neighbour);
                }
            }
        }
    }

}
int main(){
    graph g;
    addEdge(g,"A","B");
    addEdge(g,"B","A");
    addEdge(g,"D","A");
    addEdge(g,"D","B");
    addEdge(g,"D","C");
    printGraph(g);
}