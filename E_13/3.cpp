
#include<iostream>
using namespace std;

void rec(int *mat,int *cost,int m,int n,int i,int j,int val,int prev){
    if(i>=m || i<0 || j<0 || j>=n)  return;
    if(*(mat+i*n+j)==0) return;
    if(*(cost+i*n+j)==-1 || val<*(cost+i*n+j)){
        *(cost+i*n+j)=val;
        val = *(cost+i*n+j);
    }else{
        return;
    }
    if(prev!=4) rec(mat,cost,m,n,i,j+1,val+2,2);
    if(prev!=2) rec(mat,cost,m,n,i,j-1,val+2,4);
    if(prev!=3) rec(mat,cost,m,n,i-1,j,val+4,1);
    if(prev!=1) rec(mat,cost,m,n,i+1,j,val+1,3);
}


int main(){
    int m,n,i,j;
    cout<<"Enter the dimension of the hill matrix: ";
    cin>>m>>n;
    int *matrix= (int *)malloc(sizeof(int)*n*m);
    int *cost= (int *)malloc(sizeof(int)*n*m);
    cout<<"Enter the hill matrix:\n";
    for(i=0;i<m;i++){
        for(j=0;j<n;j++){
            cin>>*(matrix+i*n+j);
        }
    }
    for(i=0;i<m;i++){
        for(j=0;j<n;j++){
            *(cost+i*n+j)=-1;
        }
    }

    rec(matrix,cost,m,n,m-1,0,0,0);
    int val;
    bool flag=true;
    for(i=0;i<m;i++){
        for(j=0;j<n;j++){
            if(*(cost+i*n+j)!=-1){
                if(flag){
                    val = *(cost+i*n+j);
                    flag=false;
                }else if(val>*(cost+i*n+j)){
                    val=*(cost+i*n+j);
                }
            }
        }
        if(!flag) break;
    }
    cout<<"Maximum reachable height: "<<m-i-1<<endl;
    cout<<"Minimum cost to reach the maximum reachable height: "<<val<<endl;
    return 0;
}