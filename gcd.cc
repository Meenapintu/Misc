#include <cmath>
#include <cstdio>
#include <vector>
#include <iostream>
#include <algorithm>
#include <string>
using namespace std;

void gcd(int m,int n){
	 if(n==0)cout<<m;
	 else gcd(n,m%n);
	}

int main() {
    /* Enter your code here. Read input from STDIN. Print output to STDOUT */
    int m,n;
    cin>>m>>n;
      gcd(m,n);
    
    return 0;
}
