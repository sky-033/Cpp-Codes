#include<iostream>
using namespace std;

int main(){
    enum meal{breakfast,lunch,dinner};//breakfast=0   lunch=1   dinner=2
    meal m1=lunch;
    cout<<(m1==1);
    return 0;
}