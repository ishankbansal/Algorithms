#include<iostream>
#include<vector>
#include<climits>
using namespace std;

class node{
public:
	node* left;
	node* right;
	int data;

	node(int data){
		left = NULL;
		right = NULL;
		this->data = data;
	}
};

node* buildTree(){
	int d;
	cin >> d;
	if(d == -1){
		return NULL;
	}

	node* root = new node(d);
	root->left = buildTree();
	root->right = buildTree();
	return root;
}

void morris_Inorder(node* root){
	node* curr = root;
	node* prev = NULL;

	while(curr){
		if(!curr->left){
			cout << curr->data << " ";
			curr = curr->right;
		}
		else{
			prev = curr->left;

			while(prev->right && prev->right != curr){
				prev = prev->right;
			}

			if(!prev->right){
				prev->right = curr;
				curr = curr->left;
			}
			else{
				cout << curr->data << " ";
				prev->right = NULL;
				curr = curr->right;
			}
		}
	}

	cout << endl;
}

int main(){
	node* root = buildTree();
	morris_Inorder(root);
}