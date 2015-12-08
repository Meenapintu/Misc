#include <cmath>
#include <cstdio>
#include <vector>
#include <iostream>
#include <algorithm>
using namespace std;

void YN(){
    int n,k,a;
    cin>>n>>k;
    for(int i=0;i<n;i++){
        cin>>a;
        if(a<=0)k--;
    }
    if(k<=0)cout<<"NO\n";
    else cout<<"YES\n";
}
int main() {
    /* Enter your code here. Read input from STDIN. Print output to STDOUT */  
    int t,a,n,k;
    cin>>t;
    for(int i=0;i<t;i++){
        YN();
    
    }
   
    return 0;
}

//https://www.hackerrank.com/challenges/angry-professor
