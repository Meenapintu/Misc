#include <cmath>
#include <cstdio>
#include <vector>
#include <iostream>
#include <algorithm>
using namespace std;

vector<int>vs ;
vector<int>temp(2,0);
int pt=0;

void print(vector<int>*v){
 
	for( unsigned i=0; i<v->size(); i++){
		cout<<v->at(i);
      
	}

}
vector<int> num_to_vec(int n){
	vector<int> v;
    while(n >0){
        v.push_back(n%10);
		n=n/10;
    }
    return v;
}
void vector_mul_to_elem(int n,vector<int> *vtomul){  //assuming n is single digit and it should be a single digit
	int k =vtomul->size();
	for(int i=k-1;i >=0;--i){
		temp = num_to_vec((vtomul->at(i)*n) + pt);
		vtomul->at(i) = temp[0];
		pt = temp[1];
		fill(temp.begin(), temp.end(), 0);
	}
	if(pt !=0){
		
		vtomul->insert(vtomul->begin(),pt);
	}
	
	pt=0;
	
}


void vec_add(vector<int>*v1,vector<int>*v2){   //array add order matter
		int sv1 = v1->size();
		int sv2 = v2->size();
		if(sv1 <= sv2){
			
			for(int i =0;i< sv1;++i ){
			temp = num_to_vec((v1->at(i)+v2->at(i))+pt);
			v2->at(i) = temp[0];
			pt = temp[1];
			fill(temp.begin(), temp.end(), 0);	
			}
			for(int i =sv1;i<sv2;++i ){
			temp = num_to_vec(v2->at(i)+pt);
			v2->at(i) = temp[0];
			pt = temp[1];
			fill(temp.begin(), temp.end(), 0);	
			}
		}
		else
		{	
			for(int i =0;i<sv2;++i ){
			temp = num_to_vec((v1->at(i)+v2->at(i))+pt);
			v2->at(i) = temp[0];
			pt = temp[1];
			fill(temp.begin(), temp.end(), 0);	
			}
			for(int i =sv2;i<sv1;++i ){
			temp = num_to_vec(v1->at(i)+pt);
			v2->push_back(temp[0]);
			pt = temp[1];
			fill(temp.begin(), temp.end(), 0);
			}
			
		}	
		if(pt !=0){
		v2->push_back(pt);
		}
		
		pt=0;
		fill(temp.begin(), temp.end(), 0);			
}


void many_to_many(int n,vector<int>*fac){
			vector<int> v = num_to_vec(n);
			vector<int>vprev ,vcurr ;
			vprev.assign(fac->begin(),fac->end());
			int k = v.size();
			fac->clear();
			
			for(signed i=0;i<k;++i){
				vcurr.assign(vprev.begin(),vprev.end());

				vector_mul_to_elem(v[i],&vcurr);
				fac->insert(fac->begin(),0);
		
				vec_add(&vcurr,fac);
				
				
				vcurr.clear();
				
			}
			vprev.clear();
			v.clear();

			if(n>1){
				many_to_many(n-1,fac);
			}	
			else{
			print(fac);	
		}	
	}
int main() {
    /* Enter your code here. Read input from STDIN. Print output to STDOUT */   
    int input;
    cin>>input;
    vs.push_back(1);
    
    many_to_many(input,&vs);
    
    return 0;
}
