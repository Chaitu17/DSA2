#include<bits/stdc++.h>
using namespace std;

class Node {
	public:
		int data;
		Node* next;
		
	Node() {
		data = 0;
		next = NULL;
	}
	Node(int data) {
		this->data = data;
		this->next = NULL;
	}
};

class Linkedlist {
	Node* head;
	public:
		Linkedlist() {
			head = NULL;
		}
		
		void insertNode(int);
		void printList();
		void deleteNode(int);
};

void Linkedlist :: insertNode(int data) {
	Node* newNode = new Node(data);
	if(head == NULL) {
		head = newNode;
		return;
	}
	Node* temp = head;
	while(temp->next != NULL) {
		temp = temp->next;
	}
	temp->next = newNode;
}

void Linkedlist :: printList() {
	Node* temp = head;
	if(head == NULL) {
		cout << "List is empty\n";
		return;
	}
	while(temp != NULL) {
		cout << temp->data << " ";
		temp = temp->next;
	}
}

void Linkedlist :: deleteNode(int nodeIndex) {
	Node* temp1 = head, temp2 = NULL;
	int listLen = 0;
	if(head == NULL) {
		cout << "List is empty\n";
		return;
	}
	while(temp1 != NULL) {
		temp1 = temp1->next;
		listLen++;
	}
	if(listLen < nodeIndex) {
		cout << "Index is out of range\n";
		return;
	}
	temp1 = head;
	if(nodeIndex == 1) {
		head = head->next;
		delete temp1;
		return;
	}
	while(nodeIndex-- > 1) {
		temp2 = temp1;
		temp1 = temp1->next;
	}
	
	temp2->next = temp1->next;
	delete temp1;
}

void printMiddle(class Node* head) {
	if(head) {
		int len = 0;
		Node* temp = head;
		while(temp != NULL) {
			len++;
			temp = temp->next;
		}
		temp = head;
		int midIndex = len/2;
		while(midIndex--) {
			temp = temp->next;
		}
		cout << "The middle value of the ll is " << temp->data << "\n"; 
	}
}

Node* reverse(Node* head) {
	if(head == NULL || head->next == NULL) return head;
	Node* rest = reverse(head->next);
	head->next->next = head;
	head->next = NULL;
	return rest;
}

int main() {
	Linkedlist ll;
	// Should write the insertion, deletion and printing of linkedlist
}

