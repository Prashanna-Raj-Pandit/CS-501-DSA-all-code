// Class examples
// Sorting methods

#include <iostream>
#include <fstream>
#include <iomanip>
#include <ctype.h>
#include <string>
#include <vector>
#include <queue>

using namespace std;

struct student_type
{
	string fname, lname;
	int sid;
	float gpa;
};

void readitems(ifstream& fin, vector<student_type> &);	

void display_keymenu();
void display_sortmenu();

// print student list
void printstudent (ostream& output, vector<student_type>);


// Example of functions with argument that are points to other functions
// The sorting function can sort a list in different ways, 
// depending  on argument functions that will be provided by the caller
template <class T> void Swap(T &a, T &b);

template <class T> void shellSort (vector<T> & A, bool (*lessthan) (T, T));
template <class T> void sel_sort  (vector<T> & A, bool(*lessthan) (T, T));
template <class T> void insertionSort(vector<T> & A, bool(*lessthan) (T, T));
template <class T> void bubble_sort(vector<T> & A, bool(*lessthan) (T, T));
template <class T> void merge_sort (vector<T> & A, int F, int L, bool (*lessthan) (T, T));
template <class T> void merge (vector<T> & A, int F, int M, int L, bool (*lessthan) (T, T));
template <class T> void quick_sort (vector<T> & A, int F, int L, bool(*lessthan) (T, T));
template <class T> void heapsort(vector<T> & A, bool(*lessthan) (T, T));
template <class T> void movedown (vector<T> & A, int F, int L, bool (*lessthan) (T, T));
template <class T> void radix_sort(vector<T> & A, int(*sortkey) (T));

// these function are used to guide the sort
// their names are passed as parameters to the sorting function
bool gpa (student_type a, student_type b);
bool sid (student_type a, student_type b);
bool lname (student_type a, student_type b);
bool name (student_type a, student_type b);

// these functions are only useful to radix sort
int key_sid (student_type);
int key_gpa (student_type);

int main ()
{

//	student_type student[35]; // static array of size 35
	vector<student_type> student; // member functions: size, resize, push_back
	

	ifstream sfin("student.dat");
//	ofstream sfout("student.out");
	
	readitems(sfin, student);
//	int studentNum = student.size();
		
	while (1)
	{
	  int key=100, method;
	  do 
	  {
		  display_keymenu();
		  cin >> key;
	  } while (key < 1 || key >6);
	  if (key==5)
	  {
		printstudent(cout, student);
	  }
	  else if (key==6)
		  break;
	  else 
	  {	
		display_sortmenu();
		cin >> method;

		switch (method)
		{
		case 1:		
		  switch (key) 
		  {
			case 1:	sel_sort<student_type>(student, lname); break;
			case 2:	sel_sort<student_type>(student, name); break;
			case 3:	sel_sort<student_type>(student, gpa); break;
			case 4:	sel_sort<student_type>(student, sid); break;
		  }
		 break;
		case 2:
		  switch (key) 
		  {
			case 1:	insertionSort<student_type>(student, lname); break;
			case 2:	insertionSort<student_type>(student, name); break;
			case 3:	insertionSort<student_type>(student, gpa); break;
			case 4:	insertionSort<student_type>(student, sid); break;
		  }
		    break;
		case 3:
		  switch (key) 
		  {
			case 1:	bubble_sort<student_type>(student, lname); break;
			case 2:	bubble_sort<student_type>(student, name); break;
			case 3:	bubble_sort<student_type>(student, gpa); break;
			case 4:	bubble_sort<student_type>(student, sid); break;
		  }
		 	break;
		case 4:
		  switch (key) 
		  {
			case 1:	merge_sort<student_type>(student, 0, student.size()-1, lname); break;
			case 2:	merge_sort<student_type>(student, 0, student.size()-1, name); break;
			case 3:	merge_sort<student_type>(student, 0, student.size()-1, gpa); break;
			case 4:	merge_sort<student_type>(student, 0, student.size()-1, sid); break;
		  }
		  	break;
		case 5:
		  switch (key) 
		  {
			case 1:	quick_sort<student_type>(student, 0, student.size()-1, lname); break;
			case 2:	quick_sort<student_type>(student, 0, student.size()-1, name); break;
			case 3:	quick_sort<student_type>(student, 0, student.size()-1, gpa); break;
			case 4:	quick_sort<student_type>(student, 0, student.size()-1, sid); break;
		  }
		  	break;
		case 6:
		  switch (key) 
		  {
			case 1:	cout << " I am afraid I can't do that, Dave.\n\n"; break;
			case 2:	cout << " I am afraid I can't do that, Dave.\n\n"; break;
			case 3:	radix_sort<student_type>(student, key_gpa);break;
			case 4:	radix_sort<student_type>(student, key_sid); break;
		  }
		  	break;
		case 7:
		  switch (key) 
		  {
			case 1:	heapsort<student_type>(student, lname); break;
			case 2:	heapsort<student_type>(student, name); break;
			case 3:	heapsort<student_type>(student, gpa); break;
			case 4:	heapsort<student_type>(student, sid); break;
		  }
				break;
		case 8:
		  switch (key) 
		  {
			case 1:	shellSort<student_type>(student, lname); break;
			case 2:	shellSort<student_type>(student, name); break;
			case 3:	shellSort<student_type>(student, gpa); break;
			case 4:	shellSort<student_type>(student, sid); break;
		  }
				break;
		default:	cout << "Incorrect sorting method. Starting over.\n";
		} // end of switch
		printstudent(cout, student);
	  } // end of if
	} // end of while
	cout << "\nYou come back to see us, You hear. \n\n";
	system("pause");
	return 0;
}

//void readitems(ifstream& sfin, student_type s[], int &num_of_s)

void readitems(ifstream& sfin, vector<student_type> & s)
{

	// read student records
	sfin.ignore(100, '\n');			// read and discard the 1st line
	student_type temp;
	sfin >> temp.fname;
	while(!sfin.eof())
	{
		sfin >> temp.lname >> temp.sid >> temp.gpa;
		s.push_back(temp); // add this new record at the end of temp
		sfin >> temp.fname; // read the next fname
	}// end of while
}

void display_keymenu()
{
	cout << "\n    Please select a field as the sorting key:\n"
		 << "\t1. Lastname\n"
		 << "\t2. Lastname, Firstname\n"
		 << "\t3. GPA\n"
		 << "\t4. Student ID\n"
		 << "\t5. Just print\n"
		 << "\t6. Exit\n\n";
}

void display_sortmenu()
{
cout << "\n    Please select an a sorting method:\n"
	 << "\t1. Selection Sort\n"
	 << "\t2. Insertion Sort\n"
	 << "\t3. Bubble Sort\n"
	 << "\t4. Merge Sort\n"
	 << "\t5. Quick Sort\n"
	 << "\t6. Radix Sort\n"	 
	 << "\t7. Heap Sort\n"
	 << "\t8. Shell Sort\n\n";
}


void printstudent (ostream& output, vector<student_type> s)
{
	// print the heading
	output << setw(14) << "Fname(10)"	
			<< setw(14)  << "Lname(10)"
			<< setw(7) << "ID(4)"
			<< setw(5) << "GPA(4)" << endl; 

	for (int k=0;k<s.size();k++)
		output << setw(14) << s[k].fname 
				<< setw(14) << s[k].lname 
				<< setw(7) << s[k].sid 
				<< setw(5) << s[k].gpa << endl;
}

// this is a template function which allows the user to 
// swap values of two variables of Any TYPE
template <class T> 
void Swap(T &a, T &b)
{
	T	temp=a;
		a=b;
		b=temp;
}


template <class T> 
void shellSort (vector<T> & A, bool (*lessthan) (T, T))
{
	int N = A.size();
    for (int increment = N/2; increment > 0; increment /= 2) // shell's increment
      for (int index = increment; index < N; index++)  // perform increment insertion sort 
      {
         T copy = A[index];
		 int k=index;
		 while(k>=increment && lessthan(copy, A[k-increment]))
		 {
			A[k]=A[k-increment]; // move A[k-increment] to k
			k -= increment;
		 }
         A[k] = copy;
      }

}

template <class T> 
void sel_sort (vector<T> & A, bool (*lessthan) (T, T))
{

	int si, N=A.size();
	for (int index = 0; index < N; index++)
	{
		si = index;
		for (int k = si + 1; k < N; k++)
			if (lessthan(A[k], A[si]))
				si = k;
		Swap<T>(A[si], A[index]);
	}
}

template <class T> 
void insertionSort (vector<T> & A, bool (*lessthan) (T, T))
{
	int N = A.size();
	for (int index =0; index < N; index++)
	{
		T copy=A[index];
		int k=index;
		while(k>=1 && lessthan(copy, A[k-1]))
		{
			A[k]=A[k-1]; // move A[k-1] to the right
			k--;
		}
		A[k] = copy; // put A[index] in the desired place
     }

}

template <class T> 
void bubble_sort (vector<T> & A, bool (*lessthan) (T, T))
{
	int N = A.size();
	bool sorted=false;
	for (int pass=1; (pass<N) && !sorted; pass++)
	{
		sorted = true;
		for (int k=0; k<N-pass;k++)
			if (lessthan(A[k+1], A[k])) 
			{
	   			Swap<T>(A[k], A[k+1]);
				sorted = false;
			}
	}
}

template <class T> 
void merge_sort (vector<T> & A, int F, int L, bool (*lessthan) (T, T))
{
	if (F<L) // recursive case - at least 2 elements
	{
		int M = (F+L)/2;
		merge_sort(A, F, M, lessthan);
		merge_sort(A, M+1, L, lessthan);
		merge(A, F, M, L, lessthan);
	}
}

// merge two halves of array A
template <class T> 
void merge (vector<T> & A, int F, int M, int L, bool (*lessthan) (T, T))
{
	T *tmp;
	tmp = new T[L+1];
	int p1=F, p2=M+1, p=F;
	while ( (p1<=M) && (p2<=L))
	{ 
	  if (lessthan (A[p1], A[p2]))
	    tmp[p++] = A[p1++];
	  else
	    tmp[p++] = A[p2++];
	}
	
	while ( p1 <=M )
	  tmp[p++] = A[p1++];

	while (p2 <=L)
	  tmp[p++] = A[p2++];

	for (int i=F; i<=L; i++)
	  A[i]=tmp[i];

	delete [] tmp;
}

template <class T> 
void quick_sort (vector<T> & A, int F, int L, bool (*lessthan) (T, T))
{	
	if (F>=L) return; // base case
	
	// recursive case
	int LastS1=F, FirstS2=L;
	T P = A[F];

	// 1. partition
	while (LastS1<=FirstS2)
	{
	  while (LastS1<=FirstS2 && lessthan(A[LastS1],P))
		LastS1++;
	  while (LastS1<=FirstS2 && !lessthan(A[FirstS2], P))
		FirstS2--;
	  if (LastS1 < FirstS2)
		Swap<T>(A[FirstS2--], A[LastS1++]);
	  if (LastS1==F) // 
		  LastS1++;
	} // end of while

	// 2. recursive calls
	quick_sort(A, F, LastS1-1, lessthan);
	quick_sort(A,LastS1, L, lessthan);
} // end of quicksort

template <class T> 
void radix_sort (vector<T> & A, int (*sortkey) (T))
{
	int N = A.size();
	int digit=1, k, j;
	bool done=false;
//	ArrayQueue<T> Q[10];
	queue<T> Q[10];
	while(!done)
	{
		done=true;
		for (j=0;j<N;j++)
		{
			int cur_digit = sortkey(A[j])%(digit*10)/digit;
			if (cur_digit > 0)
				done= false;
			Q[cur_digit]. push(A[j]);
		}
		
		for (k=0, j=0;k<10;k++)
			while (!Q[k].empty()) {
				A[j++] = Q[k].front();
				Q[k].pop();
		   }
		//	  Q[k].dequeue(A[j++]);

		digit *=10;
	}
}

int key_sid (student_type a)
{
	return a.sid;
}


int key_gpa (student_type a)
{
	return int (a.gpa*100);
}

// template <class T> 
// void movedown(vector<T> & A, int F, int L, bool (*lessthan) (T, T))
// {
// 	int GI = 2*F+1;  // store the index of the child with the greater value
// 	// Initialize to left child
// 	int P = F;		// store index of a parent node, beginning with the root.

// 	while (GI <= L) // continue to move down until end of array
// 	{ 
// 		if (GI < L && lessthan(A[GI], A[GI+1])) 
// 		GI++; // set GI to index of the child with the greater value
  
// 		// Swap F with GI and move down, if necessary
// 		if (lessthan(A[P], A[GI]))
// 		{
// 			Swap<T> (A[P], A[GI]);
// 			P = GI;  // the guy is now the new parent node
// 			GI = 2*GI+1; // GI is now set to its own left child
// 		}
// 		else 
// 			GI = L+1; // set largest to exit;
// 	}
// }
template <class T>
void movedown(vector<T>& A, int parent, int end, bool (*lessthan)(T, T)) {
    int child = 2 * parent + 1;  // Index of the left child

    while (child <= end) {  // Loop until we reach the end of the heap
        // If the right child exists and is larger, move to the right child
        if (child < end && lessthan(A[child], A[child + 1])) {
            child++;
        }

        // If the parent is smaller than the larger child, swap them
        if (lessthan(A[parent], A[child])) {
            Swap<T>(A[parent], A[child]);

            // Update the parent and child to move down the heap
            parent = child;
            child = 2 * parent + 1;  // Update to left child of the new parent
        } else {
            break;  // Exit if heap property is satisfied
        }
    }
}


template <class T> 
void heapsort (vector<T> & A, bool (*lessthan) (T, T))
{
	int i, N=A.size();

	// create a heap
	for (i=N-1; i>=0; i--)
		movedown(A, i, N-1, lessthan);

	for (i=N-1; i> 1; i--)
	{
		Swap<T>(A[0], A[i]);			 // move root item to the end of array
		movedown(A, 0, i-1, lessthan);	// restore the heap property
	}
	if (lessthan(A[1], A[0]))
		Swap<T>(A[0], A[1]);
}

bool gpa (student_type a, student_type b)
{
	return a.gpa<b.gpa;
}

bool sid (student_type a, student_type b)
{
	return a.sid<b.sid;
}

bool lname (student_type a, student_type b)
{
	return a.lname<b.lname;

}

bool name (student_type a, student_type b) // 
{
	return (a.lname<b.lname) || 
			(a.lname==b.lname && a.fname<b.fname);
}

/* student.dat
Fname(10)	Lname(10)	ID(4)	gpa(3)
Merla		Black		9284	3.8
Bonita		Hill		9813	3.5
Chris		Smith		6299	3.1
Byung		Park		8714	2.9
Robert		Pickford	1148	2.4
Richard		Poirier		9798	2.6
Michael		Rhoden		2174	3.4
Jean		Roehl		9436	3.5
Eric		Salyer		5807	3.8
Young		Shin		9476	3.7
Patrick		Smith		1974	3.2
Laura		Snow		4201	3.4
Bretton		Wendel		4979	2.8
Larry		Smith		2661	2.2
David		Letterman	1045	0.1
Jay			Lano		7201	0.1
Black		Smith		2502	2.7
Doug		Fisher		5841	3.5
*/