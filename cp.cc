#include <iostream>

using namespace std;

// A BST node
struct BST
{
	int value;
	struct BST *left, *right;
};


struct BST* get_node(int value){
	struct BST *temp = new BST;
	temp->value = value;
	temp->left = temp->right =NULL;
	return temp;
	}
	
struct BST* insert(struct BST* root,int val){
	
	 if(root == NULL)return get_node(val);
	 else if (root->value> val)root->left= insert(root->left,val);
	 else if (root->value < val)root->right= insert(root->right,val);
	 return root;
	}


void print(int n){
	cout<<n<<" ";
	}
void preorder(BST *root){
	if(root != NULL){
		print(root->value);
		preorder(root->left);
		preorder(root->right);
	}
	}
void postorder( struct BST *root){
	if(root != NULL){
		preorder(root->left);
		preorder(root->right);
		print(root->value);
	}
	}
void inorder(struct BST *root){
	
	if(root != NULL){
		preorder(root->left);
		print(root->value);
		preorder(root->right);
	}
	}
// Driver program
int main()
{
	// Create first tree as shown in example
	BST *root1 = NULL;
	root1 = insert(root1, 5);
	root1 = insert(root1, 1);
	root1 = insert(root1, 10);
	root1 = insert(root1, 0);
	root1 = insert(root1, 4);
	root1 = insert(root1, 7);
	root1 = insert(root1, 9);

	// Create second tree as shown in example
	BST *root2 = NULL;
	root2 = insert(root2, 10);
	root2 = insert(root2, 7);
	root2 = insert(root2, 79);
	root2 = insert(root2, 70);
	root2 = insert(root2, 20);
	root2 = insert(root2, 4);
	root2 = insert(root2, 9);

	//cout << "Tree 1 : ";
	preorder(root1);
	cout << endl;

	//cout << "Tree 2 : ";
	preorder(root2);

	cout << "\nCommon Nodes: ";
	//printCommon(root1, root2);

	return 0;
}
