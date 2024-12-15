// Testing algorithms discussed in MAW chapter 7
#include <iostream>
#include <fstream>
#include <algorithm>
#include <string>
#include <ctype.h>
#include <iomanip>
#include "graph.h"

using namespace std;

int main ()
{

	ifstream fin1, fin2;
	ofstream fout;
	string s, t, d, n1, n2;

   // testing bfs and dfs
	graph stateG;
//	cout << "FLT_MAX is " << FLT_MAX << endl;

	cout << "\n\nTesting BFS and DFS ....\n";
	fin1.open("city.dat");
	fin2.open("distance.dat");

	stateG.read_nodes (fin1);
	stateG.initEdge();
	stateG.read_edges (fin2, true);	
	
	fin1.close();
	fin2.close();

	fout.open("EdgeEdges.dat");
	stateG.printEdgeMatrix(fout);
	
	do
	{
		cout << "Enter a city name to start a traversal, End to quit: \n";
		getline(cin, n1);
		transform(n1.cbegin(), n1.cend(), n1.begin(),::tolower); 
		// write to the same location
			//	[](unsigned char c) { return tolower(c); });
		
		if (n1 == "end")
			break;
		cout << endl << endl;
		int id = stateG.findIndex(n1);
		if (id >= 0)
		{
			int choice;
			cout << "Enter 1 for bfs, 2 for dfs:\t";
			cin >> choice;
			if (choice == 1)
				stateG.bfs(id);
			else
				stateG.dfs(id);
		}
		else
			cout << "City name " << n1 << " not found.\n";
		cout << endl << endl;
	} while (1);

/*
	// topsort
	cout << "\n\nTesting Topological Sort......\n";
	graph CSPreReq;

	fin1.open("courses.dat");
	fin2.open("prereqs.dat");

	CSPreReq.read_nodes (fin1);
	CSPreReq.initEdge();
	CSPreReq.read_edges (fin2, false);	// not un-directed, i.e, digraph
	
	fin1.close();
	fin2.close();


	CSPreReq.topsort(cout);
	fout.close();


	// test dijkstra's algorithm
	cout << "\n\nTesting Dijkstra's algorithm....\n";
	graph Fig920;

	fin1.open("Figure920Nodes.dat");
	fin2.open("Figure920Edges.dat");

	Fig920.read_nodes (fin1);
	Fig920.initEdge();
	Fig920.read_edges (fin2, false);	
	
	fin1.close();
	fin2.close();


	
	cout << "please enter the start node: ";
   
	cin >> s;
	int SI = Fig920.findIndex(s);	// start node Index
	Fig920.dijkstra(SI);
	cout << "please enter the destination node: ";
	cin >> d;
	int DI = Fig920.findIndex(d);	// destination node Index
//	cout << SI << "->" << DI << endl;
	Fig920.printShortestPathDijkstra(DI);


	

	// test max flow

    graph f940, Gf;
	
	fin1.open("Figure940Nodes.dat");
	fin2.open("Figure940Edges.dat");

	f940.read_nodes (fin1);
	f940.initEdge();
	f940.read_edges (fin2, false);	// not bidirectional
	
	fin1.close();
	fin2.close();

	cout << "\n\nTesting max flow....\n";
	cout << "Please enter the name of start and sink node:\t";
	cin >> s >> t;
	Gf=f940.maxFlow(f940.findIndex(s), f940.findIndex(t));
	Gf.print_edges(cout);




	// test prim's algorithm using figure 9.48
	fin1.open("Figure948Nodes.dat");
	fin2.open("Figure948Edges.dat");

	graph f948, MST;
	f948.read_nodes (fin1);
	f948.initEdge();
	f948.read_edges (fin2, true);	//  bidirectional


	fin1.close();
	fin2.close();

	MST=f948.primMST(0);
	MST.print_edges(cout);
*/

	// test Kruskal's algorithm using figure 9.48
	fin1.open("Figure948Nodes.dat");
	fin2.open("Figure948Edges.dat");

	graph f948, MST;
	f948.read_nodes (fin1);
	f948.initEdge();
	f948.read_edges (fin2, true);	//  bidirectional

	fin1.close();
	fin2.close();

	MST=f948.kruskalMST(cout);
	MST.printEdgeMatrix(cout);

	

	

	system("pause");
	return 0;
}

/*

void tolowers(char *s)
{
	for (unsigned k=0;k<strlen(s);k++)
		s[k]=tolower(s[k]);
}
*/

