#include <iostream>
using namespace std;

int fibonacci(int n) { //this will return the fibonacci number at index n starting from n=0;
    if (n == 0)
        return 0;
    else if (n == 1)
        return 1;
    else
        return fibonacci(n - 1) + fibonacci(n - 2);
}

int main() {
    int n = 0;
    int fib = 0;
    cout << "Fibonacci numbers less than 100: " << endl;

    // Keep calculating Fibonacci numbers until it exceeds 100
    // while (fib < 100) {
    //     fib = fibonacci(n);  // here i am generating the fib sequence starting from index 0. and incrementing the count n. 
    //     if (fib >= 100)
    //         break;
    //     cout << fib << " ";
    //     n++;
    // }
    for(int i=9;i<19;i++){
        cout<<"\t"<<fibonacci(i);
    }
    // cout<<fibonacci(10); // this will give the output 55. (0,1,1,2,3,5,8,13,21,34,55) which is 11th number actually.
    return 0;
}
