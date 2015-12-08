#include <cmath>
#include <cstdio>
#include <vector>
#include <iostream>
#include <algorithm>
#include <stdio.h>
#include <string.h>

using namespace std;

bool binarys(char a, string b){
   
    if(b.length()==0){return false;}
    else if(b[b.length()/2] == a){return true;}
    else if(b[b.length()/2] < a){ binarys(a, b.substr(b.length()/2,b.length()-1));}
    else if(b[b.length()/2] > a){binarys(a,b.substr(0, b.length()/2));}
    return false;
}
void is_substr(string a ,string b){
    sort(a.begin(),a.end());
    sort(b.begin(),b.end());
    bool yes = false;
    for(int i=0; i<a.length();i++){
          if(binarys(a[i],b)){yes=true;break;}
    }
    if(yes)cout<<"YES\n";
    else cout<<"NO\n";
}
int main() {
    /* Enter your code here. Read input from STDIN. Print output to STDOUT */ 
    int t;
    string a,b;
    cin>>t;
    for(int i=0;i<t;i++){
        cin>>a>>b;
        is_substr(a,b);
    }
    return 0;
    
}
