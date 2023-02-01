
#include<iostream>
#include<string>
using namespace std;

class BigInteger{
    string number="";
    public:
        BigInteger(string number){
            this->number = number;
        }
        BigInteger(int arr[],int n){
            for(int i=0;i<n;i++){
                number.push_back(arr[i]+'0');
            }
        }
        friend BigInteger operator*(BigInteger &b1,BigInteger &b2);
        friend ostream& operator<<(ostream &o,BigInteger &b);
};

BigInteger operator*(BigInteger& b1,BigInteger& b2){
    int i,j,m = b1.number.length(),n = b2.number.length(),carry=0,shift=0;
    int partialProduct[m+n]={0};
    for(i=n-1;i>=0;i--){
        for(j=m-1;j>=0;j--){
            partialProduct[m+n-1-shift-(m-j-1)]+= ((int)(b2.number[i])-(int)'0') * ((int)(b1.number[j])-(int)'0') + carry;
            carry = partialProduct[m+n-1-shift-(m-j-1)]/10;
            partialProduct[m+n-1-shift-(m-j-1)] %= 10;
        }
        partialProduct[m+n-1-shift-(m-j-1)]+=carry;
        carry=0;
        shift++;
    }
    return BigInteger(partialProduct,m+n);
}

ostream& operator<<(ostream& o,BigInteger& b){
    bool flag = true;
    for(int i=0;i<b.number.length();i++){
        if(flag && b.number[i]=='0'){
            continue;
        }else{
            flag = false;
            o<<b.number[i];
        }
    }
    o<<endl;
    return o;
}


int main(){
    BigInteger b1("2049874329569346590314032475981765481654981644659031654916541403247598176548165498465903165491654140324759817654816549049874320498743204987432846590316549165414032475981765481654984659031654916541403247598176548165498404987432049874326590316654916541403247598176548165498164");
    BigInteger b2("549165414032475981765481654981645491654140324759817654816549816454916541403247598176548165498164465903165491654140324759817654816549846590316549165414032475981765481654904987432049874320498743284659031654916541403247598176548165498465903165491654140324759817654816549840498743204987432659031654916541403247598176548165498465903165491654140324759817654816549804987432");
    BigInteger b3=b1*b2;
    cout<<b3;
    return 0;
}