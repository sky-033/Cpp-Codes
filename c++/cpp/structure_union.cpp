#include<iostream>
using namespace std;
struct employee{
    int empID;
    char favChar;
    float salary;
};
union money{
    int rice;
    char car;
    float pounds;
};
int main(){
    struct employee sky;
    sky.empID=1;
    sky.favChar='A';
    sky.salary=1000000;
    cout<<"Employee ID is : "<<sky.empID<<endl;
    cout<<"Favourite character is : "<<sky.favChar<<endl;
    cout<<"Salary is : "<<sky.salary<<endl;
    return 0;
}