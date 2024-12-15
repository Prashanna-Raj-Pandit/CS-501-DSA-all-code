// Blind Search Example - 8 puzzle

#include <iostream>
#include <string>
#include <string.h>
#include <fstream>
#include <time.h>
#include <stack>	// dfs
#include <queue>	// bfs
#include <set>		// close
#include <chrono>	



using namespace std;
const long goal = 123804765;  // or 123804765

struct node
{
	int m[3][3]; // board represented as a 3x3 2d array
	node *parent;
	node *next; // the next node in the solution path
	node(int sm[][3], node* p = nullptr, node* n = nullptr)
	{
		for (int r = 0; r < 3; r++)
			for (int c = 0; c < 3; c++)
				m[r][c] = sm[r][c];
		parent = p;
		next = n;
	}
};

typedef node* nodeP;

long getnumber(int m[][3])
{
	long result = 0;
	for (int r = 0; r < 3; r++)
		for (int c = 0; c < 3; c++)
			result = result * 10 + m[r][c];

	return result;
}

void printsolution(node* n)
{
	// set up next for printing
	while (n->parent)
	{
		n->parent->next = n;
		n = n->parent;
	}

	int count = -1;
	while (n)
	{
		count++;
		cout << endl;
		for (int r = 0; r < 3; r++)
		{
			for (int c = 0; c < 3; c++)
				if (n->m[r][c])
					cout << n->m[r][c] << " ";
				else
					cout << "  ";
			cout << endl;
		}
		n = n->next;
	}
	cout << "This solution has " << count << " steps.\n";
}

void swap(int &a, int &b)
{
	int tmp = a;
	a = b;
	b = tmp;
}

//Movement operations that takes an input of a string for the movement operation
int makeMove(int m[][3], int n[][3], string position) {
	int r0, c0;
	if (position == "up") {
		for (int r = 0; r < 3; r++)
			for (int c = 0; c < 3; c++)
			{
				if (m[r][c] == 0)
				{
					r0 = r; c0 = c;
				}
				n[r][c] = m[r][c];
			}
		if (r0 == 0)
			return 0;
		else
		{
			swap(n[r0][c0], n[r0 - 1][c0]);
			return 1;
		}
	}
	else if (position == "down") {
		for (int r = 0; r < 3; r++)
			for (int c = 0; c < 3; c++)
			{
				if (m[r][c] == 0)
				{
					r0 = r; c0 = c;
				}
				n[r][c] = m[r][c];
			}

		if (r0 == 2)
			return 0;
		else
		{
			swap(n[r0][c0], n[r0 + 1][c0]);
			return 1;
		}
	}
	else if (position == "left") {
		for (int r = 0; r < 3; r++)
			for (int c = 0; c < 3; c++)
			{
				if (m[r][c] == 0)
				{
					r0 = r; c0 = c;
				}
				n[r][c] = m[r][c];
			}
		if (c0 == 0)
			return 0;
		else
		{
			swap(n[r0][c0], n[r0][c0 - 1]);
			return 1;
		}
	}
	else if (position == "right") {
		for (int r = 0; r < 3; r++)
			for (int c = 0; c < 3; c++)
			{
				if (m[r][c] == 0)
				{
					r0 = r; c0 = c;
				}
				n[r][c] = m[r][c];
			}
		if (c0 == 2)
			return 0;
		else
		{
			swap(n[r0][c0], n[r0][c0 + 1]);
			return 1;
		}
	}
	else
		return 0;
}


//dfs 
void dfs(int sm[][3])
{
	string move[4] = { "up", "down", "left", "right" };

	stack<node*> open;	
	nodeP *np;
	np = new nodeP[200000];
	int npCount = 0;
	set<long> close;
	node *start, *current, *succ;
	long sucnum;
	start = new node(sm); // 
	int temp[3][3], success = 0;
	open.push(start);
	np[npCount++] = start;
	close.insert(getnumber(start->m));
	long gencount = 1;

	while (!open.empty() && !success)
	{
		current = open.top();
		open.pop();
		if (getnumber(current->m) == goal)
		{
			printsolution(current);
			cout << "Total of " << gencount
				<< " nodes examined.\n\n";
			success = 1;
		}
		else
		{
		  for (int m=0;m<4;m++)
			if (makeMove(current->m, temp, move[m])) // move m is ok
			{
				sucnum = getnumber(temp);
				if (close.find(sucnum) == close.end()) // not already in CLOSE
				{
					succ = new node(temp, current);
					close.insert(sucnum);	// add the newly generated successor to CLOSE
					open.push(succ);
					np[npCount++] = succ;
					gencount++;
				}
			}
			
		} // end of else
	} // end of while

	if (!success)
	{
		cout << "No solution.\n";
		cout << "Total of " << gencount
			<< " nodes examined.\n\n";
	}

	for (int j = 0; j < npCount; j++)
		delete np[j];

	delete[] np;
}
//bfs = Breadth First Search
void bfs(int sm[][3])
{
	string move[4] = { "up", "down", "left", "right" };
	queue<node*> open; // store pointers in open to save space.
	
	nodeP *np;		// store all node pointers in an array for memeory recovery
	np = new nodeP[200000];
	int npCount = 0; // keep track of the number of nodes generated 
	set<long> close;
	node *start, *current, *succ;
	long sucnum; // number of successors
	start = new node(sm);
	int temp[3][3], success = 0;

	open.push(start); // enqueue
	np[npCount++] = start;
	close.insert(getnumber(start->m));
	long gencount = 1; // keep track of number of nodes generated
	while (!open.empty() && !success)
	{
		current = open.front();
		open.pop();
		if (getnumber(current->m) == goal)
		{
			printsolution(current);
			cout << "Total of " << gencount
				<< " nodes examined.\n\n";
			success = 1; // set to exit the loop
		}
		else // current is not a goal
		{
		  for (int m=0;m<4;m++) // try all 4 moves
			if (makeMove(current->m, temp, move[m])) // if move[m] is ok
			{
				// here, temp contains the board for a successor
				sucnum = getnumber(temp);
				if (close.find(sucnum) == close.end()) // not already in CLOSE
				{
					succ = new node(temp, current);
					close.insert(sucnum); // add the newly generated successor to CLOSE
					open.push(succ);
					np[npCount++] = succ;
					gencount++;
				}
			}
			

		} // end of else
	} // end of while

	if (!success)
	{
		cout << "No solution.\n";
		cout << "Total of " << gencount
			<< " nodes examined.\n\n";
	}

	for (int j = 0; j < npCount; j++)
		delete np[j];

	delete[] np;
	np = nullptr; 

	return;
}

int main()
{
	int matrix[3][3];
	cout << "please enter the 9 numbers for a puzzle, use 0 for space. -1 to quit.\n";
	cin >> matrix[0][0];
	while (matrix[0][0] != -1)
	{
		cin >> matrix[0][1] >> matrix[0][2]
			>> matrix[1][0] >> matrix[1][1] >> matrix[1][2]
			>> matrix[2][0] >> matrix[2][1] >> matrix[2][2];
		cout << " select a search method: 1 for bfs, otherwise dfs.\n";
		int choice;
		cin >> choice;

		auto start = chrono::steady_clock::now();
		if (choice == 1)
			bfs(matrix);
		else
			dfs(matrix);

		auto elapsed1 = chrono::duration_cast<chrono::milliseconds>(chrono::steady_clock::now() - start);
		auto elapsed2 = chrono::duration_cast<chrono::seconds>(chrono::steady_clock::now() - start);
		cout << "The elapsed run time is: " << elapsed1.count() << " milliseconds" << " or :" << elapsed2.count() << " seconds\n\n";
		
		cout << "please enter the 9 numbers for the next puzzle, -1 to quit.\n";
		cin >> matrix[0][0];
	}
	system("pause");

	return 0;
}
