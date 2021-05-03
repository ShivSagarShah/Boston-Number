/*
A Boston number is a composite number, the sum of whose digits is the sum of the digits of its prime factors obtained as a result of prime factorization (excluding 1 ). 
The first few such numbers are 4,22 ,27 ,58 ,85 ,94 and 121 . 
For example, 378 = 2 × 3 × 3 × 3 × 7 is a Boston number since 3 + 7 + 8 = 2 + 3 + 3 + 3 + 7. 
Write a program to check whether a given integer is a Boston number.

Input Format
There will be only one line of input:N , the number which needs to be checked.

Constraints
1 < N < 2,147,483,647 (max value of an integer of the size of 4 bytes)

Output Format
1 if the number is a Boston number. 0 if the number is a not Boston number.

Sample Input
378

Sample Output
1
*/

// prime factors of a number are always less than square root of a number 
#include<iostream>
#include<cmath>
using namespace std;
int main()
{
    int n, sum_n=0, sump=0;
    cin>>n;
    int temp1 = n;
    // calculating sum of digits
    while (temp1 > 0)
    {
        sum_n = sum_n + temp1%10;
        temp1 = temp1/10;
    }
    // we will handle odd and even prime factors separately 
    while (n%2 == 0)
    {
        sump = sump + 2;
        n = n/2;
    }
    for (int i = 3; i <= sqrt(n); i=i+2)
    {
        while (n%i == 0)
        {
            int temp = i;
            while (temp>0)
            {
                sump = sump + temp%10;
                temp = temp/10;
            }
            n = n/i;
        }  
    }
    if (n>2)
    {
        while (n>0)
        {
            sump = sump + n%10;
            n = n/10;
        }
    }
    if (sum_n == sump)
    {
        cout<<1;
    }
    else
    {
        cout<<0;
    }
    return 0;
}
