#include <bits/stdc++.h>
using namespace std;

void swap(vector<int>*v,int i,int j){ int temp = v->at(j);v->at(j) = v->at(i);v->at(i)=temp;}
void quick_sort(vector<int>*v,int i,int j);
int pivote(vector<int>*v,int i,int j);
void print(vector<int>*v,int n){ cout<<"\n";for(int i=0;i<=n;i++)cout<<v->at(i)<<"  ";cout<<"\n";}
int main(){
	int n,x;
	vector<int> v;
	while(true){
		cin>>x;
		if(x ==-1)break;
		v.push_back(x);
	}
	n= v.size();
	quick_sort(&v,0,n-1);
	print(&v,n-1);
	}
void debug(int  i){cout<<i<<" ___Im HERE\n";}
void quick_sort(vector<int>*v,int i,int j){
	if(i<j){
		int temp = pivote(v,i,j);
		quick_sort(v,i,temp-1);
		quick_sort(v,temp+1,j);
	}
}
int pivote(vector<int>*v,int i,int j){
	//default i<j
	int tp = v->at(j);
	int ti,tj=i-1;
	for(ti=i;ti<j;ti++){
		if(v->at(ti) < tp){tj++;swap(v,tj,ti);}
		
	}
	tj++;
	swap(v,tj,ti);
	return tj;
}
	
