#include <cmath>
#include <cstdio>
#include <vector>
#include <iostream>
#include <algorithm>
#include <string>
using namespace std;


void print_v(vector<int>*v,int size){
	cout<<"\n";
	for(int i=0;i<size;++i){
		cout<<v->at(i)<<" ";
	}
	cout<<"\n";
}
vector<int> merge(vector<int> v1,vector<int>v2){
	int l=0,r=0;
	int s1 = v1.size(),s2 = v2.size();
	vector<int> temp ;//=  vector<int>(s1+s2);
	while(l<s1 ||r<s2 ){
		if(l<s1 && r<s2){
			if(v1[l] <=v2[r]){
				temp.push_back(v1[l]);
				l++;
			}
			else{
				temp.push_back(v2[r]);
				r++;
			}
		}
		else if(l<s1){
			temp.push_back(v1[l]);
			l++;
		}
		else if(r<s2){
			temp.push_back(v2[r]);
			r++;
		}
	}
	return temp;
	
	}
vector<int> merges(vector<int>*v,int l,int r){
	vector<int> t1,t2;
	if(l<r){
		int mid = (l+r)/2;
		t1 = merges(v,l,mid);
		t2 = merges(v,mid+1,r);
		return merge(t1,t2);
	}
	else{
		t1.push_back(v->at(r));
		return merge(t1,t2);
	}
	
	}


int main(){
	vector<int> t1;
	int t;
	while(cin>>t){
		t1.push_back(t);
	}
	int size = t1.size();
	t1 = merges(&t1,0,size-1);
	print_v(&t1,size);
}
