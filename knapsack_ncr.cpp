/*knapsack problem Input: n,C,W[1..n],V[1..n].  
where n = number of packet , c is the limit of pack weight ,
and w[i] is weight of i pack and v[i] value simillary

aim => maximize the value on given weight limit c
* brute force approch t(n)=2^n   (NCR) 
* 
 */

#include <iostream>
#include <vector>
using namespace std;

int ks_ncr(int n,int c,vector<int>*w,vector<int>*v){
	if (c==0||n == 0)
		return 0;
   if (w->at(n-1) > c)
       return  ks_ncr(n-1,c,w,v);
   int t1,t2;
   t1 = v->at(n-1) + ks_ncr( n-1,c-w->at(n-1),w,v);
   t2 = ks_ncr(n-1,c,w,v);
   if(t1<t2) return t2;
   else return t1;
}

int main(int argc, char** argv) {
 	int n,c;
 	//cout<<"INPUT ORDER  w=>weight vector ,v=> value vector =   n ,c w ,v\n";
 	cin>>n>>c;
 	vector<int> w = vector<int>(n);
 	vector<int> v = vector<int>(n);
 	for(int i=0;i<n;++i){
 		cin>>w.at(i);
	 }
	 for(int i=0;i<n;++i){
 		cin>>v.at(i);
	 }
	cout<< ks_ncr(n,c,&w,&v)<<endl;
	return 0;
}

