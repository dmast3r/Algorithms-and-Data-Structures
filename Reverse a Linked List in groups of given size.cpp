/*
	Reverse a Linked List in groups of given size. 
	Given a linked list of size N. The task is to reverse every k nodes (where k is an input to the function) in the linked list.

	Input:
	First line of input contains number of testcases T. For each testcase, first line contains length of linked list and next line contains the linked list elements.

	Output:
	For each testcase, there will be a single line of output which contains the linked list with every k group elements reversed.

	Example:
	Input:
	1
	8
	1 2 2 4 5 6 7 8
	4

	Output:
	4 2 2 1 8 7 6 5

	Solution-
	The idea is simple. Recursively call the next group to reverse itself and return reference to the new head obtained after reversing itself.
	The current group will then reverse itself and attach it's new tail obtained after reversing itself to the new head of the next group.
*/

#include <bits/stdc++.h>
using namespace std;

struct node {
	int data;
	struct node *next;
};

node *reverseList(node *head, node *next_head, int k) {
	if(head == nullptr)
		return nullptr;
	
	node *temp_head = head, *prev = nullptr;
	int count = 0;
	while(head != nullptr and count != k) {
		node *temp = head -> next;
		head -> next = prev;
		prev = head;
		head = temp;
		++count;
	}

	temp_head -> next = next_head;
	return prev; // new head
}

node *findNextHead(node *head, int k) {
	if(head == nullptr)
		return nullptr;
	
	int count = 0;
	while(head != nullptr and count != k) {
		head = head -> next;
		++count;
	}

	return head;
}

node *reverseUtil(node *head, int k) {
	if(head == nullptr)
		return head;
	node *next_head = findNextHead(head, k);
	next_head = reverseUtil(next_head, k);
	head = reverseList(head, next_head, k);
	return head;
}

struct node *reverse(node *head, int k) { 
	if(head == nullptr or k == 0)
		return head;
	return reverseUtil(head, k);
}

int main() {
	// count = number of nodes in your list, num for scanning node data, k = group size to be reversed.
	int count, num, k; 
	cin >> count; 
	count--;	

	cin >> num;
	node *head = new node{num, nullptr}, *temp_head = head;

	while(count--) {
		cin >> num;
		head -> next = new node{num, nullptr};
		head = head -> next;
	}	

	cin >> k;
	head = temp_head;
	head = reverse(head, k);
	while(head != nullptr) {
		cout << head -> data << " ";
		head =  head -> next;
	}
}
