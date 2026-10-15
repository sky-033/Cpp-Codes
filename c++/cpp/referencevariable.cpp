#include<iostream>
using namespace std;
int main(){
    int a=455;
    int & b=a; //no copy of variable
    cout<<a<<endl;
    cout<<b;

    return 0;
}