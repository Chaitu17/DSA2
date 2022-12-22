#include<bits/stdc++.h>
using namespace std;

struct Node {
	int data;
	struct Node* left;
 	struct Node* right;	
};

Node* newNode(int data) {
	Node* child = new Node;
	child->data = data;
	child->left = NULL;
	child->right = NULL;
	return child;
}

void preOrder(Node* root) {
	if(root == NULL) return;
	cout << root->data << " ";
	preOrder(root->left);
	preOrder(root->right);
}

void inOrder(Node* root) {
	if(root == NULL) return;
	inOrder(root->left);
	cout << root->data << " ";
	inOrder(root->right);
}

void postOrder(Node* root) {
	if(root == NULL) return;
	postOrder(root->left);
	postOrder(root->right);
	cout << root->data << " ";
}

void levelOrder(Node* root) {
	vector<vector<int>> ans;
	if(root == NULL) return;
	queue<Node*> q;
	q.push(root);
	while(!q.empty()) {
		vector<int> level;
		int n = q.size();
		for(int i=0; i<n; ++i) {
			Node* num = q.front();
			q.pop();
			if(num->left != NULL) q.push(num->left);
			if(num->right != NULL) q.push(num->right);
			level.push_back(num->data);
		}
		ans.push_back(level);
	}
	for(int i=0; i<ans.size(); ++i) {
		for(int j=0; j<ans[i].size(); ++j) {
			cout << ans[i][j] << " "; 
		}
	}
}

void iterPreOrder(Node* root) {
	if(root == NULL) return;
	stack<Node*> st;
	st.push(root);
	while(!st.empty()) {
		Node* num = st.top();
		st.pop();
		cout << num->data << " ";
		if(num->right != NULL) {
			st.push(num->right);
		}
		if(num->left != NULL) {
			st.push(num->left);
		}
	}
}

void iterInOrder(Node* root) {
	stack<Node*> st;
	Node* node = root;
	while(true) {
		if(node != NULL) {
			st.push(node);
			node = node->left;
		}
		else {
			if(st.empty() == true) break;
			node = st.top();
			st.pop();
			cout << node->data << " ";
			node = node->right;
		}
	}
}

void iterPostOrder(Node* root) {
	if(root == NULL) return;
	stack<Node*> st1, st2;
	st1.push(root);
	while(!st1.empty()) {
		root = st1.top();
		st1.pop();
		st2.push(root);
		if(root->left != NULL) {
			st1.push(root->left);
		}
		if(root->right != NULL) {
			st1.push(root->right);
		}
	}
	while(!st2.empty()) {
		cout << st2.top()->data << " ";
		st2.pop();
	}
}

void iterPostOrderTrav(Node* root) {
	if(root == NULL) return;
	
}


int main() {
	
	struct Node* root = newNode(1);
	root->left = newNode(2);
	root->right = newNode(3);
	root->left->left = newNode(4);
	root->left->right = newNode(5);
	root->right->left = newNode(6);
	root->right->right = newNode(7);
	
	cout << "This is the preOrder traversal of the tree ";
	preOrder(root);
	cout << "\n";
	cout << "This is the inOrder traversal of the tree ";
	inOrder(root);
	cout << "\n";
	cout << "This is the postOrder traversal of the tree ";
	postOrder(root);
	cout << "\n";
	cout << "This is the levelOrder traversal of the tree ";
	levelOrder(root);
	cout << "\n";
	cout << "This is the iterative preOrder traversal of the tree ";
	iterPreOrder(root);
	cout << "\n";
	cout << "This is the iterative inOrder traversal of the tree ";
	iterInOrder(root);
	cout << "\n";
	cout << "This is the iterative postOrder traversal of the tree ";
	iterPostOrder(root);
	cout << "\n";
	return 0;
}


