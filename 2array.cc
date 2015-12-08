#include <cmath>
#include <cstdio>
#include <vector>
#include <iostream>
#include <algorithm>

using namespace std;

int hour_glass(int i,int j ,vector< vector<int> >*v){
	  int r = (*v)[i][j] ;
	      r +=  (*v)[i][j+1] + (*v)[i][j+2];
		  r +=		(*v)[i+1][j+1];
		  r +=(*v)[i+2][j]+(*v)[i+2][j+1]+(*v)[i+2][j+2];
		  return r;
	}

int main() {
    /* Enter your code here. Read input from STDIN. Print output to STDOUT */   
    
   vector< std::vector<int> > v;
    int n=6;
    int inp;
    int max=-100;
    int curr;
    v.resize(n , vector<int>(n , 0 ) );
    for(int i=0;i<n;++i){
		for(int j=0;j<n;++j){
			cin>>inp;
			v[i][j] = inp;	
		}
	}
	cout<<"DObe";
	 for(int i=0;i<n-2;++i){
		for(int j=0;j<n-2;++j){
			curr = hour_glass(i,j,&v);
			if(curr>max)max=curr;
		}
	}
	cout<<max;
	
    return 0;
}
