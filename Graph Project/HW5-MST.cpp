/*
Author Name: Prashanna Raj Pandit
--------------------------------------------------------------------------------------------------------
Program Information: a C++ program thatprogram that reads a sequence of undirected graphs, build an MST 
and print the edges for each graph in a specific form as described in document .doc. my program will continue to 
loop until the user enters done for filename (All lower case). 
---------------------------------------------------------------------------------------------------------
Submitted on: November 13, 2024
---------------------------------------------------------------------------------------------------------
Deadline: November 13, 2024, 10:10 PM
---------------------------------------------------------------------------------------------------------
Instruction for grader: the time delay is maximum 1 sec while running in my PC. (MACbook M1 processor)
*/

#include <iostream>
#include <fstream>
#include <algorithm>
#include <string>
#include <vector>
#include <unordered_map>

using namespace std;

// Union-Find class for managing connected components in Kruskal's algorithm
class UnionFind {
public:
    unordered_map<string, string> parent;
    unordered_map<string, int> rank;

    UnionFind(const vector<string>& vertices);
    string find(const string& vertex);
    void unite(const string& vertex1, const string& vertex2);
};

// Structure to represent an edge in the graph
struct Edge {
    string node1, node2;
    int weight;

    bool operator<(const Edge& other) const;  // Overload < operator for sorting
};

// Function declarations
pair<int, vector<Edge> > kruskalMST(const vector<string>& vertices, vector<Edge>& edges);
void readGraph(const string& filename, vector<string>& vertices, vector<Edge>& edges);
void writeMST(const string& filename, int totalWeight, const vector<Edge>& mstEdges);

// UnionFind constructor
UnionFind::UnionFind(const vector<string>& vertices) {
    for (size_t i = 0; i < vertices.size(); i++) {
        parent[vertices[i]] = vertices[i];
        rank[vertices[i]] = 0;
    }
}

// Path-compressed find function
string UnionFind::find(const string& vertex) {
    if (parent[vertex] != vertex) {
        parent[vertex] = find(parent[vertex]);
    }
    return parent[vertex];
}

// Union by rank function
void UnionFind::unite(const string& vertex1, const string& vertex2) {
    string root1 = find(vertex1);
    string root2 = find(vertex2);

    if (root1 != root2) {
        if (rank[root1] > rank[root2]) {
            parent[root2] = root1;
        } else if (rank[root1] < rank[root2]) {
            parent[root1] = root2;
        } else {
            parent[root2] = root1;
            rank[root1]++;
        }
    }
}

// Overload < operator to compare edges by weight
bool Edge::operator<(const Edge& other) const {
    return weight < other.weight;
}

// Kruskal's MST function
pair<int, vector<Edge> > kruskalMST(const vector<string>& vertices, vector<Edge>& edges) {
    sort(edges.begin(), edges.end());  // Sort edges by weight
    UnionFind uf(vertices);

    vector<Edge> mstEdges;
    int totalWeight = 0;

    for (size_t i = 0; i < edges.size(); i++) {
        if (uf.find(edges[i].node1) != uf.find(edges[i].node2)) {
            uf.unite(edges[i].node1, edges[i].node2);
            mstEdges.push_back(edges[i]);
            totalWeight += edges[i].weight;

            if (mstEdges.size() == vertices.size() - 1) break;
        }
    }

    if (mstEdges.size() != vertices.size() - 1) {
        cerr << "Error: The graph is not connected, so an MST cannot be formed." << endl;
        return make_pair(-1, vector<Edge>());  // Return error code and empty MST if graph is disconnected
    }

    return make_pair(totalWeight, mstEdges);
}

// Reads the graph from a file
void readGraph(const string& filename, vector<string>& vertices, vector<Edge>& edges) {
    ifstream infile(filename.c_str());
    if (!infile) {
        cerr << "Error opening file: " << filename << endl;
        return;
    }

    unordered_map<string, bool> vertexMap;
    int numEdges;
    infile >> numEdges;

    for (int i = 0; i < numEdges; i++) {
        string node1, node2;
        int weight;
        infile >> node1 >> node2 >> weight;
        edges.push_back((Edge){ node1, node2, weight });  // Use traditional C++98 style initialization

        if (vertexMap.find(node1) == vertexMap.end()) {
            vertices.push_back(node1);
            vertexMap[node1] = true;
        }
        if (vertexMap.find(node2) == vertexMap.end()) {
            vertices.push_back(node2);
            vertexMap[node2] = true;
        }
    }
    infile.close();
}

// Comparator function for sorting edges by node names
bool compareEdges(const Edge& a, const Edge& b) {
    if (a.node1 == b.node1) {
        return a.node2 < b.node2;
    }
    return a.node1 < b.node1;
}

// Writes the MST to a file
void writeMST(const string& filename, int totalWeight, const vector<Edge>& mstEdges) {
    ofstream outfile(filename.c_str());
    if (!outfile) {
        cerr << "Error opening file for writing: " << filename << endl;
        return;
    }

    outfile << "Total weight of MST: " << totalWeight << endl;

    vector<Edge> sortedEdges = mstEdges;
    for (size_t i = 0; i < sortedEdges.size(); i++) {
        if (sortedEdges[i].node1 > sortedEdges[i].node2) {
            swap(sortedEdges[i].node1, sortedEdges[i].node2);
        }
    }

    // Sort edges using compareEdges function
    sort(sortedEdges.begin(), sortedEdges.end(), compareEdges);

    for (size_t i = 0; i < sortedEdges.size(); i++) {
        outfile << sortedEdges[i].node1 << " " << sortedEdges[i].node2 << " " << sortedEdges[i].weight << endl;
    }
    outfile.close();
}

// Main function
int main() {
    string filename;
    cout << "Enter the filename (without extension): ";
    cin >> filename;

    while (filename != "done") {
        vector<string> vertices;
        vector<Edge> edges;

        readGraph(filename + ".in", vertices, edges);

        pair<int, vector<Edge> > result = kruskalMST(vertices, edges);
        int totalWeight = result.first;
        vector<Edge> mstEdges = result.second;

        if (totalWeight != -1) {
            writeMST(filename + ".out", totalWeight, mstEdges);
            cout << "MST written to " << filename + ".out" << endl;
        }

        cout << "Enter another filename or 'done' to quit: ";
        cin >> filename;
    }

    return 0;
}
