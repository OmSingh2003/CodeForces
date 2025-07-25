#include<iostream>
#include<vector>
#include<unordered_map>
#include<string>
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

int main(){
    graph g;
    addEdge(g,"A","B");
    addEdge(g,"B","A");
    addEdge(g,"D","A");
    addEdge(g,"D","B");
    addEdge(g,"D","C");
    printGraph(g);
}