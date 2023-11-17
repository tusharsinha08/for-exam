#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

// void onlineJudge(){
// 	#ifndef ONLINE_JUDGE
// 		freopen("input.txt","r",stdin); 
// 		freopen("output.txt","w",stdout);  
// 	#endif
// }

class Node {
public:
	Node* left;
	Node* right;
	int data;

	Node(int data) {
		this->data = data;
		left = nullptr;
		right = nullptr;
	}
};

Node* insertBST(Node* &root, int data) {
	if(root==NULL) {
		root = new Node(data);
		return root;
	}

	if(data>root->data){
		root->right = insertBST(root->right, data);
	}
	else {
		root->left = insertBST(root->left, data);
	}

	return root;
}

Node* minVal (Node* root) {
	Node* temp = root;
	while(temp->left!=NULL) {
		temp = temp->left;
	}

	return temp;
}

Node* deleteFromBST(Node* root, int data){
	if(root==NULL) return root;

	if(root->data == data) {
		if(root->left==NULL and root->right==NULL){
			delete root;
			return NULL;
		}

		if(root->left!=NULL and root->right==NULL) {
			Node* temp = root->left;
			delete root;
			return temp;
		}

		if(root->left==NULL and root->right!=NULL) {
			Node* temp = root->right;
			delete root;
			return temp;
		}

		if(root->left!=NULL and root->right!=NULL) {
			int mini = minVal(root->right) -> data;
			root->data = mini;
			root->right = deleteFromBST(root->right, mini);
			return root;
		}
	}

	else if(root->data > data) {
		root->left = deleteFromBST(root->left, data);
		return root;
	}

	else {
		root->right = deleteFromBST(root->right, data);
		return root;
	}

	return root;

}

void takeInput(Node* &root){
	int data; cin>>data;

	while(data != -1){
		insertBST(root, data);
		cin>>data;
	}
}

vector <int> v;

void isBST() {
	if(is_sorted(v.begin(), v.end())) {
		cout<<"Yes, BST!\n";
	}
	else cout<<"Not BST\n";
}

void inOrder(Node* root) {
	if(root==NULL) return;

	inOrder(root->left);
	cout<<root->data<<" ";
	v.push_back(root->data);
	inOrder(root->right);
}

void preOrder(Node* root) {
	if(root==NULL) return;

	cout<<root->data<<" ";
	preOrder(root->left);
	preOrder(root->right);
}

void postOrder(Node* root) {
	if(root==NULL) return;

	postOrder(root->left);
	postOrder(root->right);
	cout<<root->data<<" ";
}

Node* lowestCommonAn(Node* root, int a, int b) {
	if(root==NULL) return NULL;

	if(root->data <a and root->data <b){
		return lowestCommonAn(root->right, a, b);
	}
	if(root->data > a and root -> data > b) {
		return lowestCommonAn(root->left, a, b);
	}

	return root;
}

int main() {

	// onlineJudge();

	Node* root = NULL;
	takeInput(root);

	deleteFromBST(root, 4);


	cout<<"In-Order : ";
	inOrder(root);
	cout<<endl;

	cout<<"Pre-Order : ";
	preOrder(root);
	cout<<endl;

	cout<<"Post-Order : ";
	postOrder(root);
	cout<<endl;

	isBST();

	Node* temp = lowestCommonAn(root, 5, 9);
	cout<<temp->data<<endl;

	cout<<endl;

}