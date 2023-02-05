#include<stdio.h>
#include<math.h>
int gcd(int a,int b){
    int n;
    if(a>b)
      n=b;
    else
      n=a;
    if(a==0)
        return b;
    else if(b==0){
        return a;
    }
    else if(a==0 && b==0){
        printf("Infinity\n");
    }
    else{
    int ans=0;
    for(int i=1;i<=n;i++){
        if(a%i==0 && b%i==0){
            ans=i;
        }
    }
        return ans;
    }
}
int main()
{
    int m,n;
    printf("Enter the two numbers\n");
    scanf("%d%d",&m,&n);
    printf("Gcd of %d and %d is : %d",m,n,gcd(m,n));
}