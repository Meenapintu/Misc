#include <bits/stdc++.h>
using namespace std;

struct node {
 int val;
 node *next;
 };
 
 node *rev_link(node *head){
     node * prev=NULL;
     //node * curr;
     node * next;
     while(head!=NULL){
     next = head->next;
     head->next = prev;
     prev = head;
     head = next;
     }
     return prev;
 }
 void push_f(node **head,int n){
	 node * temp = new node;
		temp->val = n;
		temp->next = *head;
		*head = temp;	
	 }
void print_l(node *head){
	 while(head !=NULL){
	 cout<< head->val<<"->";
	 head = head->next;
		}
	 cout<<"\n";
	}
int main(){
	int n;
	node *head = NULL;
	while(cin>>n){
		if(n >1)
			push_f(&head,n);
		else if(n==-2)
		   print_l(head);
		else if(n==0)
		   head = rev_link(head);
	}
}
