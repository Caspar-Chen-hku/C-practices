#include<iostream>
#include<string>
#include<algorithm>
#include<map>
#include<vector>
#include<queue>
using namespace std;

class Node{
 public:
 Node(){
 id=0;
 name="";}
 Node(int i,string n){
     id=i;
     name=n;
 }
 int id;
 string name;
};

struct Edge{
int s,e;
Edge(int q,int w){
s=q;
e=w;}};
typedef struct Edge Edge;
bool operator<(Edge a,Edge b){
if (a.s<b.s) return true;
else if(a.s>b.s) return false;
else return (a.e<b.e);
}
class Graph{
 public:
 void InsertNode( Node x ){
     if (nodes.count(x.id)==1){
        cout << "ID exists.\n";
        return;
     }
  nodes[x.id]=x;}
 void InsertEdge( int x, int y){
     if (nodes.count(x)==0||nodes.count(y)==0){
        cout << "No such node.\n";
        return;
     }
     Edge edge(x,y);
     edges.push_back(edge);
     sort(edges.begin(),edges.end());
 }
 void CommonNeighbor( int x, int y ){
     if (nodes.count(x)==0||nodes.count(y)==0){
        cout << "No such node.\n";
        return;
     }
     vector<int> xn,yn;
     for (int i=0; i<edges.size(); i++){
        if (edges[i].s==x) xn.push_back(edges[i].e);
        if (edges[i].s==y) yn.push_back(edges[i].e);
     }
     sort(xn.begin(),xn.end());
     sort(yn.begin(),yn.end());
     /*for (int i=0; i<xn.size(); i++){
        cout << xn[i] << " ";
     }
     cout << endl;
     for (int i=0; i<yn.size(); i++){
        cout << yn[i] << " ";
     }
     cout << endl;*/
     vector<int> v(minimum(xn.size(),yn.size()));
//cout << minimum(xn.size(),yn.size()) << endl;
     vector<int>::iterator itr=set_intersection(xn.begin(),xn.end(),yn.begin(),yn.end(),v.begin());
     v.resize(itr-v.begin());                      // 10 20
  if (v.size()==0) {cout << "No common neighbor.\n";
  return;}
  //cout << "The intersection has " << (v.size()) << " elements:\n";
  for (itr=v.begin(); itr!=v.end(); ++itr)
    cout << *itr << ' ' << nodes[(*itr)].name << endl;

 }
int minimum(int a,int b){
return (a<b ? a : b);}

 void ShortestPath(int source, int destination){
if (nodes.count(destination)==0||nodes.count(source)==0){
cout << "No such node.\n";
return;}
if (source==destination){
cout << source << " " << nodes[source].name << endl;
return;}
 queue<int> q;
 map<int,int> previous;
 map<int,bool> visited;
 map<int,Node>::iterator i;
 for (i=nodes.begin(); i!=nodes.end(); i++){
    visited[(*i).first]=false;
    previous[(*i).first]=-1;
 }
  q.push(source);
  visited[source]=true;
  previous[source]=-1;
  while (q.empty() == false && !visited[destination]){
    int current = q.front();
    q.pop();
  for (int i=0; i<edges.size(); i++){
    if (edges[i].s==current&&!visited[edges[i].e]){
        q.push(edges[i].e);
        visited[edges[i].e]=true;
        previous[edges[i].e]=current;
    }
 }

}
if (!visited[destination]){
    cout << "No path found.\n";
    return;
}
vector<int> path;
int start=destination;
 //cout << source << " " << nodes[source].name << endl;
 path.push_back(start);
 while(previous[start]!=source){
    start=previous[start];
     path.push_back(start);
 }
 path.push_back(source);
 //cout << start << " " << nodes[start].name << endl;
 for (int i=path.size()-1; i>=0; i--){
    cout << path[i] << ' ' << nodes[path[i]].name << endl;
 }
 }
 /*while (start!=destination){
    start=findafter(previous,start);
 }


 int findafter(map<int,int> previous, int start){
    map<int,int>::iterator i;
 for (i=previous.begin(); i!=previous.end(); i++){
    if ((*i).second==start){
        cout << (*i).first << " " << nodes[(*i).first].name <<endl;
        return (*i).first;
    }
 }
 }*/
 // You can add more member functions to help your
 //implementation.
 void printNode(){
     map<int,Node>::iterator i;
 for (i=nodes.begin(); i!=nodes.end(); i++){
    cout << (*i).first << " " << (*i).second.name << endl;
 }}
 void printEdge(){
 for (int i=0; i<edges.size(); i++){
    cout << edges[i].s << " to " << edges[i].e << endl;
 }}
 private:
 map<int,Node> nodes;
 vector<Edge> edges;
};


int main(){
 Graph g;
 string command;
 int id1, id2;
 string name;
 while (cin >> command ){
 if (command == "InsertNode"){
 cin >> id1 >> name;
 Node n(id1,name);
 g.InsertNode(n);
 }else if (command == "InsertEdge"){
 cin >> id1 >> id2;
 g.InsertEdge(id1,id2);
 }else if (command == "CommonNeighbor"){
 cin >> id1 >> id2;
 g.CommonNeighbor(id1, id2);
 }else if (command == "ShortestPath"){
 cin >> id1 >> id2;
 g.ShortestPath(id1, id2);
 }else if (command == "Exit"){
 return 0;
 }
 }
}