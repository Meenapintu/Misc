#include <cmath>
#include <cstdio>
#include <vector>
#include <iostream>
#include <algorithm>
#include <string>
using namespace std;

struct Node
{
int value;
struct Node *left,*right;
};
	

struct Node* get_node(int value){
	struct Node *temp = new Node;
	temp->value = value;
	temp->left = temp->right =NULL;

	return temp;
	}
struct Node* insert(struct Node* root,int val){
	
	 if(root == NULL)return get_node(val);
	 else if (root->value > val)root->left= insert(root->left,val);
	 else if (root->value < val)root->right= insert(root->right,val);
	 cout<<"INSERTED\n";
	 return root;
	}
void print(int n){
	cout<<n<<" ";
	}
void preorder(Node *root){
	if(root != NULL){
		print(root->value);
		preorder(root->left);
		preorder(root->right);
	}
	}
void postorder( struct Node *root){
	if(root != NULL){
		preorder(root->left);
		preorder(root->right);
		print(root->value);
	}
	}
void inorder(struct Node *root){
	cout<<"LOO   ";
	if(root != NULL){
		preorder(root->left);
		print(root->value);
		preorder(root->right);
	}
	}
	
int main(){
	//int n;
	//string str;
	
	Node *bst = NULL;
	bst = insert(bst,6);
	bst = insert(bst,8);
	bst = insert(bst,9);
	/*while(cin>>str && str!="EXIT"){
		cout<<"INT N";
		cin>>n;
		if(str =="in") Node = insert(Node,n);
		else if(str =="d"){}
		else if(str =="s"){}
		else if(str =="p"){}
		else if(str =="pre")preorder(bst);
		else if(str =="post")postorder(bst);
		else if(str =="inor")inorder(bst);
	}*/
	
	return 0;
	}
