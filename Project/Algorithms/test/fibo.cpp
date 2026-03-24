#include<iostream>
#include <iomanip>
using namespace std;
int fibo(int n);
int Arithmetic_sequence(int a1, int d, int n);
int Geometric_sequence(int a1,int q,int n);
int Factorial(int n);
double calculateSum(int n);

int main()
{
    int n,a1,d,q=0;
    /*cin>>a1;
    cin>>q;
    */
    cin>>n;
    double k = calculateSum(n);;

    cout << fixed << setprecision(3) << k << endl;

    return 0;

    // return Geometric_sequence(a1,q,n);
}

int fibo(int n) {
    if(n==2) {
        return 1;
    }
    else if (n==1) {
        return 1;
    }
    else {
        return fibo(n-1) + fibo(n-2);
    }
}

int Arithmetic_sequence(int a1,int d, int n) {
    if (n<=0) {
        cout<<"不能這樣喔"<<endl;
        return 0;
    }
    else if (n==1) {
        return a1;
    }
    else {
        return Arithmetic_sequence(a1,d,n-1)+d;
    }
}

int Geometric_sequence(int a1,int q, int n) {
    if (n<=0) {
        cout<<"不能這樣喔"<<endl;
        return 0;
    }
    else if (n==1) {
        return a1;
    }
    else {
        return Geometric_sequence(a1,q,n-1)*q;
    }
}

int Factorial(int n) {
    if (n<=0) {
        return 0;
    }
    else if (n==1) {
        return 1;
    }
    else {
        return Factorial(n-1)*n;
    }
}

double calculateSum(int n) {
    double sum = 0.0;
    for(int i = 1; i <= n; i++) {
        // 第i项 = fibo(i) / fibo(i+1)
        sum += (double)fibo(i) / fibo(i+1);
    }
    return sum;
}