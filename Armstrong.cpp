#include<iostream>
#include<cmath>
using namespace std;
int main(){

    int n ;
    cout<<"Enter the number:";
    cin>>n;

    int copynum = n ;

    int sum = 0 ; 
    while(n!=0){
        int digit = n%10;
        sum = sum + pow(digit,3);
        n = n/10;
    }

    if(copynum == sum){
        cout<<copynum<<" is an Armstrong Number";
    }

    else{
        cout<<copynum<<" is not a Armstrong Number";
    }
    
}