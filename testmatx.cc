#include <cmath>
#include <cstdio>
#include <vector>
#include <iostream>
#include <algorithm>
using namespace std;

void rfill(char *c,vector<char[1]> *v,int n){
    for(int i=0;i<n;++i){
        v->at(i)[0] = c[i];
    }
}
//from matrix get the friend 
//to do this first check row wise 
bool unique_insert(bool *arr,int pos){
    if(!arr[pos]){arr[pos] =true;return true;}
    return false;
}
void check_row(int i,bool *col,vector<vector<char[1]>> *m ,int size,vector<int>*temp,bool rval){ 
            for(int j=0;j<size;++j){//row
                if(m->at(j)[i][0] =='Y')if(unique_insert(col,j)){temp->push_back(i); rval = true;}
            }  
}
void check_col(int i,bool *row,vector<vector<char[1]>> *m,int size,vector<int>*temp,bool rval){
    
            for(int j=0;j<size;++j){ //column 
                if(m->at(i)[j][0] =='Y')if(unique_insert(row,j)){temp->push_back(j);rval=true;cout<<"found  ";}
            }  
}

void arr_init(bool *arr ,int n){ for(int i=0;i<n;++i)arr[i] = false;}
int __get(bool *row,bool *col,vector<vector<char[1]>> *m,int fg,vector<int>temp_row){
     
    vector<int>temp;
    vector<int>temp1;
    int n = temp_row.size();
     for(int i=0;i<n;++i){
		 bool rval = false;
        if(!row[temp_row.at(i)]){
            check_row(i,col,m,n,&temp,rval);
           
        }   
         if(rval)fg++;
           int tn = temp.size();
            for(int j=0;j<tn;++j){
                if(!col[temp.at(j)]){
                    check_col(temp.at(j),row,m,n,&temp1,rval);
                    }
            }
     }
    free(&temp_row);
    fg = __get(row,col,m,fg,temp1);
    return fg;
}
int get_(bool *row,bool *col,vector<vector<char[1]>> *m,int n,int i,int fg){
    vector<int>temp_row;
    vector<int>temp;
    cout<<"first function call";
     for(i =i;i<n;++i){
		bool rval = false;
        if(!row[i]){
            
            check_row(i,col,m,n,&temp,rval);
            
        }   
        if(rval)fg++;
           int tn = temp.size();
            for(int j=0;j<tn;++j){
                if(!col[temp.at(j)]){
                    check_col(temp.at(j),row,m,n,&temp_row,rval);
                    }
            }
		}
      
         fg = __get(row,col,m,fg,temp_row);
    return fg;
}

int main() {
    /* Enter your code here. Read input from STDIN. Print output to STDOUT */   
    int n;
    cin>>n;
    cout<<"nnnn\n";
    typedef std::vector <char[1]> row_t;
	std::vector <row_t>t;
    //vector<vector<char[1]>>t;
    char c[n];
    cout<<"first loop in";
    for(int i=0;i<n;++i){
        fgets(c,n,stdin);
        cout<<"first loop in";
         rfill(c,&t[i],n);
        cout<<"first loop 1";
    }
    cout<<"first loop complete";
    vector<bool>trow;
    vector<bool>tcol;
    bool row[n];bool col[n];
    arr_init(row,n);
    arr_init(col,n);
    int fg=get_(row,col,&t,n,0,0);
    cout<<fg;
    return 0;
}
