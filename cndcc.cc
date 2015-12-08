#include <iostream>
#include <string>
using namespace std;
int main()
{
    
	int size = 10;
    char s[size];
	fgets(s,size,stdin);
    //int s1 = s[0]-48;
    printf("there goes %s",s);
    string str;
    cin>>str;
    int s1 = str[0];
    cout<<s1<<'\n';
    return 0;

}
