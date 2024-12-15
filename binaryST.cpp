
// Binary Search Tree - Implemenation in C++
// Simple program to create a BST of integers and search an element in it
#include<iostream>
using namespace std;
//Definition of Node for Binary search tree
struct BstNode {
	int data;
	BstNode* left;
	BstNode* right;
};

// Function to create a new Node in heap
BstNode* GetNewNode(int data) {
	BstNode* newNode = new BstNode();
	newNode->data = data;
	newNode->left = newNode->right = NULL;
	return newNode;
}

// To insert data in BST, returns address of root node
BstNode* Insert(BstNode* root,int data) {
	if(root == NULL) { // empty tree
		root = GetNewNode(data);
	}
	// if data to be inserted is lesser, insert in left subtree.
	else if(data <= root->data) {
		root->left = Insert(root->left,data);
	}
	// else, insert in right subtree.
	else {
		root->right = Insert(root->right,data);
	}
	return root;
}
//To search an element in BST, returns true if element is found
bool Search(BstNode* root,int data) {
	if(root == NULL) {
		return false;
	}
	else if(root->data == data) {
		return true;
	}
	else if(data <= root->data) {
		return Search(root->left,data);
	}
	else {
		return Search(root->right,data);
	}
}
BstNode* findmin(BstNode* root)
{
	while(root->left != NULL) root = root->left;
	return root;
}
/*BstNode* delet(BstNode*root,int x)
{
    if(root==NULL)
    {
        return 0;
    }
    else if(x<root->data) return root->left=delet(root->left,x);
    else if(x>root->data) return root->right=delet(root->right,x);
    else
    {
        if(root->left==NULL&&root->right==NULL)
        {
            delete root;
            root=NULL;

        }
        else if(root->left==NULL)
        {
            BstNode*temp=root;
            root=root->right;
            delete temp;

        }
        else if(root->right==NULL)
        {
            BstNode*temp=root;
            root=root->left;
            delete temp;
        }
        else
        {
            BstNode*temp=findmin(root->right);
            root->data=temp->data;
            root->right=delet(root->right,temp->data);
        }
    }
    return root;
}*/
int main() {
	BstNode* root = NULL;  // Creating an empty tree
	/*Code to test the logic*/
	  int x,y;
    do{
        cout<<"enter the data:";
        cin>>x;
       Insert(root,x);
        cout<<"continue? 1for yes 0 for no:";
        cin>>y;
    }while(y);
    do{
        cout<<"enter the data to search:";
        cin>>x;
      if(Search(root,x)==true)
      {
          cout<<"found\n";
      }
      else{
        cout<<"not found\n";}
        cout<<"continue? 1for yes 0 for no:";
        cin>>y;
    }while(y);
     