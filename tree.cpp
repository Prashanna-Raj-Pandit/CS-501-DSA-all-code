#include<iostream>
#include<stdlib.h>
using namespace std;

struct bstnode
{
    int data;
    bstnode* right,*left;
};

bstnode* getnode(int x)
{
    bstnode*newnode=new bstnode;
    newnode->data=x;
    newnode->right=NULL;
    newnode->left=NULL;
    return newnode;
}
bstnode* insert_data(bstnode*root,int x)//the node named root is NULL every time the function is called so that new node is created
                                        //every time the function is called
{
    if(root==NULL)
    {
        root=getnode(x);
    }
    else if(x<=root->data)
    {
    root->left=insert_data(root->left,x);//root->left is NULL which is passed into function recursively to create new node at left

    }
    else
    {
        root->right=insert_data(root->right,x);// same for the right node
    }
    return root;
}
// bstnode* findmin(bstnode* root)
// {
// 	while(root->left != NULL) root = root->left;
// 	return root;
// }
// bstnode* delet(bstnode*root,int x)  
// {
//     if(root==NULL)
//     {
//         return 0;
//     }
//     else if(x<root->data) return root->left=delet(root->left,x);
//     else if(x>root->data) return root->right=delet(root->right,x);
//     else
//     {
//         if(root->left==NULL&&root->right==NULL)
//         {
//             delete root;
//             root=NULL;

//         }
//         else if(root->left==NULL)
//         {
//             bstnode*temp=root;
//             root=root->right;
//             delete temp;

//         }
//         else if(root->right==NULL)
//         {
//             bstnode*temp=root;
//             root=root->left;
//             delete temp;
//         }
//         else
//         {
//             bstnode*temp=findmin(root->right);
//             root->data=temp->data;
//             root->right=delet(root->right,temp->data);
//         }
//     }
//     return root;
// }
bstnode* findmin(bstnode* root) {
    while (root->left != NULL) 
        root = root->left;
    return root;
}

bstnode* delet(bstnode* root, int x) {
    if (root == NULL) {
        return NULL;  // Corrected: Returning NULL instead of 0 when the tree is empty.
    }

    if (x < root->data) {
        root->left = delet(root->left, x);  // Fixed: No need to return root->left here, just update the pointer.
    } else if (x > root->data) {
        root->right = delet(root->right, x);  // Fixed: Same as above.
    } else {
        // Node to be deleted found

        // Case 1: No child (Leaf node)
        if (root->left == NULL && root->right == NULL) {
            delete root;
            root = NULL;
        } 
        // Case 2: One child (Right child exists)
        else if (root->left == NULL) {
            bstnode* temp = root;
            root = root->right;
            delete temp;
        } 
        // Case 2: One child (Left child exists)
        else if (root->right == NULL) {
            bstnode* temp = root;
            root = root->left;
            delete temp;
        } 
        // Case 3: Two children
        else {
            bstnode* temp = findmin(root->right);  // Find the minimum node in the right subtree.
            root->data = temp->data;  // Replace the data with the minimum value.
            root->right = delet(root->right, temp->data);  // Delete the minimum node in the right subtree.
        }
    }

    return root;  // Return the root to maintain the tree structure.
}


bool search(bstnode*root,int x)
{
    if(root==NULL)
    {
        return false;
    }
    else if(root->data==x)
    {
        return true;
    }
    else if(x<=root->data)
        return search(root->left,x);
    else
        return search(root->right,x);
}
void preorder(bstnode* root)
{
   if(root!=NULL){ cout<<root->data<<"\t";
            preorder(root->left);
            preorder(root->right);
   }

}
void postorder(bstnode*root)
{
    if(root!=NULL)
    {
        postorder(root->left);
        postorder(root->right);
        cout<<root->data<<"\t";
    }
}
void inorder(bstnode*root)
{
    if(root!=NULL)
    {
        inorder(root->left);
        cout<<root->data<<"\t";
        inorder(root->right);
    }
}
int main()
{
    bstnode *root;
    root=NULL;
    int x,y;
    do{
        cout<<"********MENU*******\n 1::INSERT IN TREE\t2:: SEARCH IN BST\t3:: DELETE\t4::EXIT\n 5::PRINT\n";
        cin>>y;
        switch(y)
        {
            case 1: cout<<"enter data:";cin>>x; root=insert_data(root,x);break;
            case 2: cout<<"enter the data to search";cin>>x; if(search(root,x)==true){cout<<"\nfound";}  else cout<<"not found";break;
            case 3: cout<<"\nenter the data to delete";cin>>x; root=delet(root,x);break;
            case 4: exit(0);
            case 5: cout<<"Inorder:";inorder(root);
                cout<<"\nPreorder:";preorder(root);
                cout<<"\nPostorder:";postorder(root);
                    break;
                    
            default:
            break;
        }

    }while(y);

    return 0;
}
