#include<iostream>
using namespace std;
int main(){
    int age;
    cout<<"Enter your age : ";
    cin>>age;
    if(age>=18){
        cout<<"You can drive.";
    }
    else{
        cout<<"You cannot drive.";
    }
    return 0;
}