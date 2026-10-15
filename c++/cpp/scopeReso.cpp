#include<iostream>
using namespace std;
int global=8;
int main(){
    int a=5,b=9,global;
    global=a+b;
    cout<<"Value of a+b= "<<global<<endl;
    cout<<"Global value= "<<::global;
    return 0;
}