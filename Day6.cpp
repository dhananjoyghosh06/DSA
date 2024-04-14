// Q1. a^b using Recursion 
// Method used - Recursion
TC - 
#include<bits/stdc++.h>
using namespace std;
`
int power(int a , int b){
    if(b == 0) return 1;
    if(b == 1) return a;
    
    int halfPower = power(a, b/2);
    
    if(b%2 == 0) return halfPower*halfPower;
    else return a*halfPower*halfPower;
}

int main(){
    int a, b;
    a=4, b=2;
    cout<<power(a,b)<<endl;
    
    return 0;
}