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

void bfs(node* root) {
	if(root == NULL) return;

	queue<node*> q;
	q.push(root);

	while(!q.empty()) {
		node* temp = q.front();
		q.pop();

		if(temp->left) q.push(temp->left);
		if(temp->right) q.push(temp->right);
		cout << temp->data << " ";		
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
	
	bfs(root);
	cout << endl;
	return 0;
}