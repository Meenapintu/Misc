#include <cmath>
#include <cstdio>
#include <vector>
#include <iostream>
#include <algorithm>
#include <string>
using namespace std;

int ispre(vector<string> *s,int i,int n){
	 string str,temp;
	 str= s->at(i);
	 int size = str.size(),ts;
	 for(int j=0;j<i;++j){
		if(i==j)continue;
		 temp = s->at(j);
		 ts= temp.size();
		 if(ts <= size){
				if(temp.substr(0,size) == str){
					return i;
				}
			}
		}
		return -1;			 
	}
int main() {
    /* Enter your code here. Read input from STDIN. Print output to STDOUT */  
    int n;
    vector<string>strs;
    string str;
    cin>>n;
    for(int i =0;i<n;++i){
		cin>>str;
		strs.push_back(str);
	}
	int temp;
	 for(int i =0;i<n;++i){
		 temp = ispre(&strs,i,n);
		if( temp > -1){
			cout<<"BAD SET\n"<<strs[temp]<<"\n";
			return 0;
		}
	}
	cout<<"GOOD SET\n";
    return 0;
}
