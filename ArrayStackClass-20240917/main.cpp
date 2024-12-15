// sample main using ArrayStack

#include <iostream>
#include <fstream>
#include <iomanip>
#include <ctype.h>
#include <string>
#include <stdlib.h>
#include <time.h>
#include <cstdlib>

#include "ArrayOnlyStack.h"

using namespace std;

bool recLang(string s);
bool recP(string s);


int main ()
{

	// delcare an char stack
	Stack<char> S;

	// put the letters a through z onto stack S
	for (char ch = 'a'; ch <= 'z'; ch++)
		S.push(ch);

	vector<char> v = S.toVector();
	for (int k = v.size() - 1; k >= 0; k--)
		cout << v[k] << " "; // print in reverse order
	cout << endl;

	//  print everything from stack bottom up without changing the stack
	// for (unsigned k = 0; k <v.size(); k++)
	for(char k:v)
		cout << k << " "; // print in original order
	cout << endl;

	// Testing contain
	char ch;
	cout << "please enter a char to check: ";
	cin >> ch;

	ch = tolower(ch);
	if (S.contain(ch))
		cout << "yes\n ";
	else
		cout << "No\n";
	
	return 0;


}

// this function recognize the L t$t' where t' is reverse of t
// i.e., recog odd palindrome with $ in the middle
bool recLang(string s)
{
	Stack<char> aStack;
	int p = 0;
	while (p<s.length() && s[p]!='$') // push everything until $ or end of s
	{
		aStack.push(s[p]);
		p++;
	}
	// at this point, either s[p]=='$' or s has ended=> false
	if (p >= s.length()) // s has ended, no $
		return false;
	else
		p++;	// move to the char after $

	// compare the rest of s with content of aStack

	bool result = true;

	while ((p < s.length() && !aStack.empty()))
	{
		char ch = aStack.top(); // get top of stack
		if (s[p] == ch) // we are still ok, don't change the result yet
		{
			p++;	// go to the next letter
			aStack.pop();
		}
		else
			return false;
	}
	// here: either s ended or stack is empty, but we need both to accept
	if (p == s.length() && aStack.empty())
		return true;
	else
		return false;
	

}
// this function recognize palindrome
bool recP(string s)
{
	Stack<char> aStack;

	int SL = s.length();
	int p = 0;
	while (p < SL/2) // push everything until $ or end of s
		aStack.push(s[p++]);

	// at midpoint
	if (SL%2>0) 
		p++;	// skip a char if length is odd

	// compare the rest of s with content of aStack

	bool result = true;

	while (p < s.length())
	{
		char ch = aStack.top(); // get top of stack
		if (s[p] == ch) // we are still ok, don't change the result yet
		{
			p++;	// go to the next letter
			aStack.pop();
		}
		else
			return false;
	}

	// here everything matched
	return true;
	
}
