#include <cmath>
#include <cstdio>
#include <vector>
#include <iostream>
#include <algorithm>
#include <string>
using namespace std;

int gcd(int m,int n){
	 if(n==0)return m;
	 else return gcd(n,m%n);
	
	}

int main() {
    /* Enter your code here. Read input from STDIN. Print output to STDOUT */
    int m,n;
    cin>>m>>n;
    cout <<(m*n)/gcd(m,n);
    return 0;
}
