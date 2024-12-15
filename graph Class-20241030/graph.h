// this is the header file for a weighted graph class

#ifndef GRAPH_H
#define GRAPH_H

#include <iostream>
#include <fstream>
#include <string>
#include <iomanip>
#include <limits.h>
#include <float.h>
#include <vector>

using namespace std;

struct vertexType
{
	string name; // name of node, 	
	int indegree, outdegree; 
	float dist; // shortest distance to this node from the starting node, used for dijkstra, 
				// later on extended to others algorithms such as maxFlow
	int pred;   // store the id number of the predecessor of current node in a solution path, used in dijkstra, maxFlow
	bool mark;	// used to mark a node during bfs, dfs, dijkstra, etc, also called visited

	vertexType (string n=" ", int in=0, int out=0, bool m=false, 
				float d=FLT_MAX, int pre=-1)
	{ name = n; 	 
	  indegree = in;
	  outdegree = out;
	  mark=m;
	  dist=d;
	  pred=pre;
	}
};

class graph
{
protected:

  vector<vertexType> vertex;

  int edgeNum;		// actual number of edges in the graph

  // edge is an adjacency matrix that store the edges in the weighted graph.
  // edge[i][j] = FLT_MAX if there is no edge from vertex i to vertex j
  // edge[i][j] = w if there is an edge from i to j, with weight w
  // note that i and j are id of the vertices. 
  vector<vector<float>> edge;	 
  void dfs1(int id);
  bool findOneMax(int s, int t);

public:
  graph ();
  graph(const graph& g); // copy constructor to support deep copy
  int graph_node_count () {return edge.size(); }

  // add_vertex: add a vertex with value vt to the network
  void add_vertex(vertexType vt)
  {
	  vertex.push_back(vt);
  }

  void initEdge()
  {
	  edge.resize(vertex.size());
	  for (int j = 0; j < vertex.size(); j++)
		  edge[j].resize(vertex.size());
	  for (int r = 0; r < vertex.size(); r++)
		  for (int c = 0; c < vertex.size(); c++)
			  edge[r][c] = FLT_MAX;
  }
  // add_edge: add an edge from vertex i to vertex j with weight w
  void add_edge (int i, int j, float w) 
  {
	  edge[i][j] = w;
	  vertex[j].indegree++;
	  vertex[i].outdegree++;
	  edgeNum++; // increment edge count
  }

  // has_edge check to see if there is an edge between vertex i and j
  // return True if yes, False otherwise
  bool has_edge (int i, int j) {return edge[i][j] < FLT_MAX;}
  void printEdgeMatrix (ostream &out);     // print all edges
  void display_nodes();					// print all nodes
  void clean_mark();					// reset all mark to false 
  void bfs (int id); // breadth first search with start node at index id
  void dfs(int id);   // depth-first search
  int findIndex (string n); // find the index of the node given its string name
  float get_distance (string n1, string n2); 
  void read_nodes (istream &in);  // read all node info from an input stream
  void read_edges (istream &in, bool biDirectional);  // read all edges from an input stream
    
  void topsort(ostream&);		// topological sort
  void dijkstra (int s);		// find shortest distance from s, store in dis field of each

  void printShortestPathDijkstra(int d);

  // find max flow using method 2: 
  // always choose augmenting path which allows the largest increase in the flow, 
  // i.e. choose a path with max flow in the residual graph
  // this function returns the flow graph when called from a graph object
  graph maxFlow(int s, int t);

  // this function use kruskal's algorithm to find and return a MST
  // IT uses disjointSet class
  graph kruskalMST (ostream &);

  // this function use prim's algorithm to find 
  // and return a MST
  // IT 's similar to Dijkstra's algorithm
  graph primMST (int);

}; // end of class




#endif

