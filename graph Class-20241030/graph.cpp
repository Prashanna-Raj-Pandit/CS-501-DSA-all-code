// this is the header file for a weighted graph class

#include <iostream>
#include <fstream>
#include <string>
#include <iomanip>
#include <algorithm>
#include <queue>
#include <limits.h>
#include <float.h>
#include "graph.h"
#include "disjsets.h"

using namespace std;



graph::graph ()
  {
	edgeNum=0;
  }
graph::graph(const graph & g)
{
	//vertexNum = g.vertexNum;
	for (int k = 0; k < g.vertex.size(); k++)
		vertex.push_back(g.vertex[k]);
	initEdge(); // allocate space
	for (int r = 0; r < vertex.size(); r++)
		for (int c = 0; c < vertex.size(); c++)
			edge[r][c] = g.edge[r][c];
}
   
 void graph::printEdgeMatrix (ostream &out)
  {
	out << setiosflags (ios::fixed);
	out << setprecision(0);
	
	out << endl << "The adjacency matrix:\n\n\n";
	int i;
	out << setw(6) << " ";
	for (i=0;i<vertex.size(); i++)
	  out << setw(5) << i;
	out << endl;
	out << setw(6) << " ";
	for (i=0;i<5*vertex.size(); i++)
	  out << "-";
	out << endl;


	for (i=0;i<vertex.size(); i++)
	{
  	  out << setw(4) << i << " |";
	  for (int j=0;j<vertex.size(); j++)
	  {
	    if (edge[i][j]<FLT_MAX)
	      out << setw(5) << edge[i][j];
		else
		  out << setw(5) << "MAX";
	  }
	  out << endl;
	}
  	out << endl << endl;	
  }

void graph::read_nodes (istream &fin) // read node info of a graph
{
	string tmp1, tmp;	
	int id=0;
	while (getline(fin,tmp))
	{
	  if (tmp!="")
	  {	  
		  transform(tmp.cbegin(), tmp.cend(), tmp.begin(), // write to the same location
			  [](unsigned char c) { return tolower(c); });
	    vertexType node(tmp); 
	    add_vertex(node);
	  }

	}
}
// read edge info and add the edges to
// the graph.  Each edge  is of the form i j w
// indicating there is an edge from node (id=i) to node (id=j) with weight w
//

void graph::read_edges (istream &in, bool undirected)
{
	string tmp;
	int index1,index2;
	float weight;
	while (getline(in,tmp))
	{
		transform(tmp.cbegin(), tmp.cend(), tmp.begin(), // write to the same location
			[](unsigned char c) { return tolower(c); });
	//	cout << tmp << endl;
	  index1 = findIndex(tmp);
	  if (index1==-1)
	  {
		  cout << "No such node: " << tmp << endl;
		  cout << "terminating program from read_edges\n";
		  exit(1);
	  }

	  getline(in,tmp);
	  transform(tmp.cbegin(), tmp.cend(), tmp.begin(), // write to the same location
		  [](unsigned char c) { return tolower(c); });
	  index2 = findIndex(tmp);
	  if (index2==-1)
	  {
		  cout << "No such node: " << tmp << " exit from read nodes\n\n";
		  exit(1);
	  }
	  in >> weight;
	  in.ignore();
	  add_edge(index1,index2,weight); 
	  if (undirected) // add edge in both directions
		//  edge[index2][index1] = weight;0
	     add_edge(index2, index1, weight);
	}
}	

 
void graph::display_nodes() 
{ 
 	cout << setiosflags (ios::fixed);
	cout << setprecision(0);
    for (int k=0;k<vertex.size(); k++)
	 cout << setw(25) << vertex[k].name << endl;
    cout << endl;
}

 
void graph::clean_mark() 
{	
	for (int k=0;k<vertex.size(); k++)
	 vertex[k].mark = 0;
}
	

// bfs = breadth-first search (or traversal) 
// disregard edge weight, 
// nodes are visted in the order of their distances (in terms of # of edgess) from start node
// tie-breaker: node Index number
// implemention: use a queue to keep track of nodes yet to be processed
void graph::bfs (int id) // id contains the index of start node for bfs
{
  int cur_id;
  clean_mark();
  queue<int> nodeQ; 
		 
 vertex[id].mark=true; // Mark first node, whose ID is passed as argument
 nodeQ.push(id);
 while (!nodeQ.empty()) // this is a traversal since there is no goal
 {
	cur_id = nodeQ.front();
	nodeQ.pop();
	cout << vertex[cur_id].name << endl; // we could perform other ops if necessary 
	for (int k=0;k<vertex.size(); k++) // check all neighbors
	  if (!vertex[k].mark && edge[cur_id][k]<FLT_MAX)
	  {
		  vertex[k].mark=true;
		  nodeQ.push(k);
	  }
  }
  cout << endl;
  clean_mark();
}

// depth-first 
void graph::dfs(int id) 
{
  clean_mark(); 
  dfs1(id);
  clean_mark();
}
// visit ID, then its 1st neighbor, and then 1st neighbor of 1st neightbor of ID
// ... backtrack to other neighbors (deepest first) when it gets to a deadend
void graph::dfs1(int id)
{
	cout << vertex[id].name << endl; // print current node
	vertex[id].mark=true; // mark current node as visited
	for (int k=0;k<vertex.size(); k++) // continue dfs with the first unmarked neighbor
	  if (!vertex[k].mark && edge[id][k]<FLT_MAX)
		dfs1(k);
}

int graph::findIndex (string n)
{
	for (int k=0;k<vertex.size(); k++)
	  if (vertex[k].name== n) // found the node
        return k;
	return -1;
}

 
float graph::get_distance (string n1, string n2)
{
	return edge[ findIndex(n1)][ findIndex(n2)];
}


void graph::topsort(ostream &out)
{
	vertexType v, w;
	vector<vertexType> tempV; // a temp array to work with 
					    //so that indegree are not change in the graph
	queue<int> vertexQ; // a queue of vertex indices
	int count=0; // count the number of nodes that we have processed
	// copy vertices to tempV array and look for indegreeZero nodes 
	for (int j = 0; j < vertex.size(); j++)
	{
		tempV.push_back(vertex[j]);
		if (tempV[j].indegree==0)
			vertexQ.push(j);
	}
	if (vertexQ.empty()) // has cycle
	{
		cout << "Cycle found in graph, topsort will terminate the program\n\n";
		exit(1);
	}

	int curIndex;
	while (!vertexQ.empty()) // N
	{
		curIndex = vertexQ.front();
		vertexQ.pop();
		count++;
		out << tempV[curIndex].name << endl;
		for (int k=0;k<vertex.size(); k++) // updating the indegree of its neighbors
			if (has_edge(curIndex, k)) // edge curINdex to k
			{
				tempV[k].indegree--;
				if (tempV[k].indegree==0)
					vertexQ.push(k);

			}
	}
	out << endl;
	if (count<vertex.size()) // did not process all nodes, 
						// there must be a cycle
	{
		cout << "Cycle found in graph. Only " << count << " nodes processed, topsort will terminate the program\n\n";
		return;
	}
}

void graph::dijkstra(int s)
{
	int j;
	// initialize the table, which is made of existing fields in vertex_t
	for (j=0;j<vertex.size(); j++)
	{
	  vertex[j].mark=false;
	  vertex[j].pred=-1;
  	  vertex[j].dist=FLT_MAX; // infinity 
	}

	vertex[s].dist=0; // set s.dist = 0

	for (int phase=0; phase<vertex.size(); phase++) // go through vertexNum phases, O(N)
	{	// finalize the dist for one node during each phase
		// find the node with the smallest dist value, which is marked false
		// first time, it's abviously s
		int smIndex;
		float smDist=FLT_MAX; // smallest dist, etc
		// we could use a min heap to reduce this to LogN
		for (int j=0;j<vertex.size(); j++) // O(N)
		{
			if (!vertex[j].mark && vertex[j].dist < smDist)
			{
				smDist = vertex[j].dist;
				smIndex = j;
			}
		}
		if (smDist==FLT_MAX)
		{
			cout << "could not complete for all nodes. Some nodes are not connected to " << vertex[s].name << endl;
			break; //exit for loop, this deals wih graph that is not connected
		}

		// smIndex is found
		vertex[smIndex].mark=true; // mark it as shortet path found
		// update its neighbors 
		// we could reduce this to O(M) total with adjacency list
		for (int j=0;j<vertex.size(); j++) // O(N)
		{   // if j is a neighbor && new path through smIndex to J is shorter
			if (!vertex[j].mark && has_edge(smIndex, j) && 
			     (vertex[j].dist > vertex[smIndex].dist + edge[smIndex][j]) )  
			{
				// update dist
				vertex[j].dist = vertex[smIndex].dist + edge[smIndex][j];
				// make smIndex pred of j in the solution path
				vertex[j].pred = smIndex;
			}
		}

	}
}

// should be called after dijkstra's function
// this prints the shortest distance from s to d
// where s was the node which we called Dijkstra
void graph::printShortestPathDijkstra(int d)
{
	if (vertex[d].dist==FLT_MAX) // no path
	{
		cout << "NO PATH found\n";
		return;
	}
	// copy path to an array
	vector<int> path;
	int curIndex = d;
	while(curIndex>=0) // have not got to start node yet
	{
		path.push_back(curIndex);
		curIndex = vertex[curIndex].pred;
	}

	// print the path
	   for (int j = path.size()-1; j >= 0; j--)
	   {
		   int curNode = path[j];
		   cout << vertex[curNode].name << " ";
		}

	cout << endl;
	cout << "Path total distance is " << vertex[d].dist << endl;
}

graph graph::maxFlow(int s, int t)
  {
	  graph Gf(*this), Gr(*this);
//	  Gr = (*this); // copy original graph to residual graph
	  int r,c;
	  // copy graph to flow graph then initializ all flow to 0
//	  Gf = *this;
	  for (r=0; r<vertex.size(); r++)
	    for (c=0;c<vertex.size(); c++)
			Gf.edge[r][c] = 0;
/*
	  cout << " initial flow graph\n";
	  Gf.print_edges();
	  cout << endl;
	  cout << " initial residual graph\n";
	  Gr.print_edges();
	  cout << endl;
*/
	  while (Gr.findOneMax(s, t)) // repeatedly find one path with max flow
	  {
		  // update Gf, Gr
		  int k=t, j=Gr.vertex[t].pred;
		  float curFlow=Gr.vertex[t].dist; // dist is the actual flow  found
		  // call print one flow 
		  while (j>=0) // path is not completed yet, update j->k of curFlow on the graphs
		  {
		      // copy curFlow on edge j->k to Gf
			  if (Gf.edge[k][j]==0) // reverse edge does not exist
                Gf.edge[j][k] += curFlow; // add currrent flow
			  else if (edge[k][j] > curFlow)// reverse is bigger
			    Gf.edge[k][j] -= curFlow;
			  else // reverse is smaller
			  {			
				Gf.edge[j][k] = curFlow - Gf.edge[k][j];
			    Gf.edge[k][j] = 0;
			  }
			  
			  // reduce edge j->k from Gr, add edge[k][j]
			  Gr.edge[j][k] -= curFlow;
			  if (has_edge(k,j))
			     Gr.edge[k][j] += curFlow;
			  else
			     Gr.edge[k][j] = curFlow; // change from FLT_MAX to curFlow
			
			  // update j, k
			  k=j;
			  j=Gr.vertex[k].pred;
		  }
	  } // end of while
	  return Gf;
  }

// find A path with max increase of flow 
bool graph::findOneMax(int s, int t)
{
	int j;
	// initialize the table, which is made of existing fields in vertex_t
	for (j=0;j<vertex.size(); j++)
	{
	  if (j==s)
	  {
		  vertex[j].mark=false;
		  vertex[j].dist=FLT_MAX-1; // since we're looking for max flow, we replace dist with
							// flow, initialized s to FLT_MAX, others to 0
		  vertex[j].pred=-1;
	  }
	  else
	  {
		vertex[j].dist=0; // 
		vertex[j].mark=false; // distance set to unknown
		vertex[j].pred=-1; // no predecessor yet
	  }
	}

	for (int phase=0; phase<vertex.size(); phase++)
		// go through vertexNum phases, 
	{							// find the dist for one node during each phase
		// find the node with the max flow, and marked false
		// first time, it's abviously s
		int lgIndex;
		float lgDist=0; // 
		for (int j=0;j<vertex.size(); j++)
		{
			// this node has a larger (and >0) flow, 
			if (!vertex[j].mark && vertex[j].dist > lgDist)
			{
				lgDist = vertex[j].dist; // remember dist is flow
				lgIndex = j;
			}
		}
		if (lgDist==0) // no more node to go, quit
			break;
		vertex[lgIndex].mark=true; // another one found, mark it true to finalize it's flow value
		// update its neighbors
		for (int j=0;j<vertex.size(); j++)
		{   // if j is a neighbor && new path through lgIndex to J has bigger flow
			if (!vertex[j].mark && has_edge(lgIndex, j) && 
			     (vertex[j].dist < min(vertex[lgIndex].dist, edge[lgIndex][j])) )  
			{
				vertex[j].dist = min(vertex[lgIndex].dist, edge[lgIndex][j]);
				vertex[j].pred = lgIndex;
			}
		}
	} // end of for
	if (vertex[t].pred==-1) // no more flow to t
	  return false;
	else 
		return true;
}

// s=0 give the s the default value of 0
// this allows the user to call the primMST function either with one argument, 
// graph MST=G.primMST(5);
// or 
// graph MST=G.primMST();
graph graph::primMST (int s=0)
{
	int j;
	// initialize the table, which is made of existing fields in vertex_t
	for (j=0;j<vertex.size(); j++)
	{
	  if (j==s)
	  {
		  vertex[j].mark=false;
		  vertex[j].dist=0;
		  vertex[j].pred=-1;
	  }
	  else
	  {
		vertex[j].dist=FLT_MAX; // 
		vertex[j].mark=false; // distance set to unknown
		vertex[j].pred=-1; // no predecessor yet
	  }
	}

	for (int phase=0; phase<vertex.size(); phase++) // go through vertexNum phases, 
	{	
		// add one node to MST during each phase
		// find the node with the smallest dist, and marked false
		// first time, it's obviously s
		int smIndex;
		float smDist=FLT_MAX; // smallestIndex, etc
		for (int j=0;j<vertex.size(); j++)
		{
			if (!vertex[j].mark && vertex[j].dist < smDist)
			{
				smDist = vertex[j].dist;
				smIndex = j;
			}
		}
		if (smDist==FLT_MAX)
			break; //exit for loop, used when the graph is not connected

		vertex[smIndex].mark=true; // another one found
		// update its neighbors
		for (int j=0;j<vertex.size(); j++)
		{   // if j is a neighbor && 
			// edge from smIndex to J is shorter
			if (!vertex[j].mark && has_edge(smIndex, j) && 
			   (vertex[j].dist > edge[smIndex][j]) )  
			{
				vertex[j].dist = edge[smIndex][j];
				vertex[j].pred = smIndex;
			}
		}

	} // end of for (phase)

	// all the pred and dist are set
	graph MST;
	int k;
	// copy vertices to MST
	for (j=0;j<vertex.size(); j++)
		MST.vertex.push_back(vertex[j]);
	
	// copy the edges
	MST.initEdge();
	for (j = 0; j < vertex.size(); j++)
	{
		if ((k = vertex[j].pred) >= 0) // it has an edge
			MST.add_edge(j, k, edge[j][k]);		
	}


	return MST;
}
struct edge_t
{
	float weight;
	int v1, v2;
	bool inMST;
	edge_t(float w, int u, int v, bool in=false)
	{
		weight = w; v1 = u; v2 = v; inMST = in;
	}
};

// this support sort by weight
bool less1(edge_t& e1, edge_t& e2) { return (e1.weight < e2.weight); }

// this support sort by node names for output
// This assumes the nodes are sorted in alpha-numeric order of their name before edges are read
// if not, we could fix the edges after MST is created by
// (1) swap v1 and v2 if vertex[v1].name > vertex[v2].name
// (2) change less2 to sort edges vector by vertex names, ex.,
// vertex[e1.v1],name < vertex[e2.v1].name etc
bool less2(edge_t& e1, edge_t& e2)
{
	return  (e1.v1 < e2.v1) || ((e1.v1 == e2.v1) && (e1.v2 < e2.v2));
}

// 3/29: updated to make it more straightforward
graph graph::kruskalMST(ostream& out=cout)
{
	DisjSets ds(vertex.size()); 
	// internally, we get an array s[vertex_size()], all initialized to -1
	// create a MST graph with nodes and no edge
	graph MST;

	// copy vertices from default graph obj to the MST graph we are creating
	for (int j = 0; j < vertex.size(); j++)
		MST.vertex.push_back(vertex[j]);

	MST.initEdge(); // allocate space for the edge matrix

	// create an edge vector to store all edges 
	vector<edge_t> edges;
	// since it's undirect, for each edge u-v there are two entries in matrix, edge[u][v] and edge[v][u]
	// we only copy edge[u][v] where u < v
	for (int u = 0; u < vertex.size(); u++) 
		for (int v = u + 1; v < vertex.size(); v++)
		{
			if (has_edge(u, v)) // find another edge
			{
				edge_t temp(edge[u][v], u, v, true); 
				edges.push_back(temp);
			}
		} // end of for

	// sort the edges based on weight
	sort(edges.begin(), edges.end(), less1);

	// at this point, the edge array has all the edges, already sorted by weight
	int count = 0, // count number of edges added, stop when count == vertex.size()-1
		set1, set2; // var for set
	for (int j = 0; j < edges.size() && count<vertex.size()-1; j = j++) // try to add an edge in each iteration
	{
		set1 = ds.find(edges[j].v1);
		set2 = ds.find(edges[j].v2);
		if (set1 != set2)			// not in the same set, found one
		{
			edges[j].inMST = true;
			MST.add_edge(edges[j].v1, edges[j].v2, edges[j].weight); // add edge to MST edge matrix
			ds.unionSets(set1, set2);
			count++;
			
		}
	} // end of for with j
	if (count < vertex.size()-1) // need to add exception handling here
	{
		cout << "Error in KruskalMST: graph not connected, exiting.\n";
			exit(1);
	}
	// for HW6, add code here to sort the edges vector by less2 or similar,
	// then print to file all edges from edges vector where inMST=true 

	return MST;
}
