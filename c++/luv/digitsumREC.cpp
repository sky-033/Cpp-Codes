// #include<bits/stdc++.h>
// using namespace std;
// int superDigit(int n){
//     if(n==0) return 0;
//     return superDigit(n/10)+n%10;
// }

// int main(){
//     string n,N;
//     cin>>n;
//     int k;
//     cin>>k;
    
//     for(int i=0;i<k;i++){
//         N+=n;
//     }
//     long long int a=superDigit(stoi(N));
//     while(true){
//         if(a<10){
//         cout<<a;
//         }
//         else{
//         a=superDigit(a);
//         }
//     }
// }

#include <bits/stdc++.h>
using namespace std;

// Recursive function to compute the super digit
int superDigit(int n) {
    if (n < 10) return n; // Base case: single digit
    int sum = 0;
    while (n > 0) {
        sum += n % 10; // Add the last digit
        n /= 10;       // Remove the last digit
    }
    return superDigit(sum); // Recurse on the sum
}

int main() {
    string n;
    int k;
    cin >> n >> k;

    // Calculate the initial sum of digits in the string `n`
    long long digitSum = 0;
    for (char c : n) {
        digitSum += c - '0'; // Convert character to integer and add
    }

    // Multiply the sum by `k` to account for the repetition
    long long totalSum = digitSum * k;

    // Compute the super digit of the resulting sum
    cout << superDigit(totalSum) << endl;

    return 0;
}
