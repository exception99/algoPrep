#include <bits/stdc++.h>

using namespace std;

class node {
public:
	int data;
	node* left;
	node* right;
};

node* createNode(int data) {
	node* newNode = new node();

	newNode->data = data;
	newNode->left = newNode->right = NULL;
	return newNode;
}

void leftView(node* root) {
	if(!root) return;
	node* specialNode = createNode(99999);
	queue<node*> q;
	q.push(specialNode);
	q.push(root);

	while(!q.empty()) {
		int flag = 0;
		node* temp = q.front();
		q.pop();

		if(temp->data == 99999){
			if(q.empty()) break;
			temp = q.front();
			q.pop();
			cout << temp->data << " ";
			flag = 1;
			
		}
		if(flag) q.push(specialNode);
		if(temp->left) q.push(temp->left);
		if(temp->right)  q.push(temp->right);	
	}
}

int main() {
	node* root = createNode(23);
	root->left = createNode(34);
	root->right = createNode(45);
	root->left->left = createNode(56);
	root->left->right = createNode(67);
	root->right->left = createNode(78);
	root->right->right = createNode(89);
	
	leftView(root);
	cout << endl;
	return 0;
}