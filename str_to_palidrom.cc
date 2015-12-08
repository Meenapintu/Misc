#include <cmath>
#include <cstdio>
#include <vector>
#include <iostream>
#include <algorithm>
#include <string>
using namespace std;
struct findmap{
	int index;
	bool front;
	bool next;
	};
	
bool palidrom(string str,int l){
	int i=0;
	while(i<=l){
		if(str[i]!=str[l])return false;
		++i;--l;
	}
	return true;
}

findmap find(string *s ,char vfrom,char vend,int from ,int end){
	//int f= from;e= end;
	findmap m;
	int isloop = end-from;
	
	while(isloop >0){
		
		if(s->at(from) ==vend){m.index = from ; m.front=true;m.next=true;return m;}
		if(s->at(end) ==vfrom){m.index = end ; m.front=false;m.next=true;return m;}
		++from;--end;
		--isloop;
	}
	if((from+end)%2 !=0){cout<<"YOU CAN'T GET IT";exit(4);}
	m.index = (from+end)/2 ; m.front=true;
	m.next=false;
	return m;
	}
	
int swap(string *s ,int i ,int j){  // i t0 j replace .really? yes
	
	  char temp = s->at(j);
	
	  for(int k=j;k<i;++k){
		  s->at(k) = s->at(k+1);
	  }
	  s->at(i) = temp;
	  
	 
	return i-j;
	}
int swap_f(string *s ,int i ,int j){  // i t0 j replace .really? yes
	  char temp = s->at(i);
	 
	  for(int k=i;k>j;--k){
		  s->at(k) = s->at(k-1);
	  }
	  s->at(j) = temp;
	return i-j;
	}
	
void st_(string *s,int l){
	int i=0;
	int sc=0;
	bool sig = false;
	findmap m;
	
	while(i<=l){
		m = find(s,s->at(i),s->at(l),i,l);
		
		if(m.front)
		sc += swap_f(s,m.index,i);
		else sc +=swap(s,l,m.index);
		if(!m.next){
			if(i==l){++i; --l;continue;}
			else if(sig){cout<<"YOU CAN'T GET IT ";exit(5);}
			else{sig=true;
				continue;}
			}
		++i; --l;
		
	}
	cout<<"TOTOAL SWAP__"<<sc<<"__"<<*s<<endl;
	}



int main() {
    /* Enter your code here. Read input from STDIN. Print output to STDOUT */
    string str;
    cin>> str;
    int size = str.size();
    if(palidrom(str,size-1))cout<<"0 SWAP";
    else st_(&str,size-1);
    
    return 0;
}
