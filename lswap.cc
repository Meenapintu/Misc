#include <bits/stdc++.h>
using namespace std;

struct node{
	int x;
	node *next;
	};
struct pc{
	node *p;
	node *c;
	};
	
pc get_node(int x,node *head,bool root){
	 pc p;
	  if(head->next !=NULL){
	      
			if(root){  // it doesn't have parent node .
				if(head->x == x) {p.p = NULL;p.c = head; return p;}
				else if(head->next->x ==x){p.p = head;p.c = head->next; return p;}
				else return get_node(x,head->next,false);
			}
			else{ //it is a chiled of some other node ,
				if(head->next->x ==x){p.p = head;p.c = head->next; return p;}
				else return get_node(x,head->next,false);
		}
	}
	p.p =p.c = NULL;
	return p;
}
	
void swap(int d1,int d2,node *head){
	//leaving error msg if not available  then just show msg data not found else;
	pc p1 = get_node(d1,head,true);
	pc p2 = get_node(d2,head,true);
	if(p1.c !=NULL && p2.c !=NULL){
		node *tc2;
		
		tc2 = p2.c->next;
		
		cout<<p2.p->x<<" "<<p2.c->x<<"\n";
		
		p1.p->next = p2.c;
		p2.c->next = p1.c->next;
		p2.p->next = p1.c;
		p1.c->next = tc2;
		}
		
	}
	
node* insert(node *head ,int x,node **root){
	node *temp = new node;//(struct node*) malloc(sizeof(struct node));
	temp->x = x;
	temp->next = NULL;
	if(head == NULL){*root=temp;head = temp;return head;}
	else{(head)->next = temp;head =temp;}
	return temp;
	}
	
void print_l(node *head){
	int n=0;
	 while(head !=NULL){
		//if(n==18)break;
	 cout<< head->x<<"->";
	 head = head->next;
	// n++;
		}
	 
	 cout<<"\n";
	}
int main(){
	int n,x,y;
	
	node * head = NULL;
	node *root = NULL;
	
	head =insert(head,1,&root);
	//print_l(head);
	//print_l(root);
	head =insert(head,2,&root);
	head =insert(head,3,&root);
	//print_l(head);
	head =insert(head,4,&root);
	head =insert(head,5,&root);
	head =insert(head,6,&root);
	head =insert(head,7,&root);
	//print_l(root);
	//print_l(head);
	while(true){
		cout<<"PUT N =1 for insert ,2 for swap \n";
		cin>>n;
		if(n==1){
			while(true){
				cin>>n;
				if(n==-1)break;
				head = insert(head,n,&root);
				print_l(root);
			}
		}
		
		if(n==2){
			while(true){
				cout<<"INT X <Y HERE\n";
				cin>>x>>y;
				if(x==-1)break;
				print_l(root);
				swap(x,y,root);
				print_l(root);
			}
		}
	}
	}
