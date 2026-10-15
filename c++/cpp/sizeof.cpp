#include<iostream>
using namespace std;
int main(){
    float f=34.5;
    long double d=34.5;
    cout<<"Size of float = "<<sizeof(float)<<endl;
    cout<<"Size of float = "<<sizeof(34.5f)<<endl; 
    cout<<"Size of long double = "<<sizeof(34.5l)<<endl; 
    cout<<"Size of double = "<<sizeof(34.5)<<endl; 
    return 0; 

}