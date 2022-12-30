#include <iostream>
using namespace std;
#include <math.h>

int fact(int n)
{
    if (n == 1)
    {
        return 1;
    }
    else
    {
        return n * fact(n - 1);
    }
};

int main()
{
    // ----------------------------program to find factorial of a number------------------
    // int n;
    // cout<<"Enter your number : ";
    // cin>>n;

    // for (int i = n-1; i > 0; i--)
    // {
    //     n = n*i;
    // }
    // cout<<"The fctorial of number is : "<<n;

    // ----------------------------program to find perfect number---------------------
    // int n, sum = 0 ;
    // cout<<"Enter your number: ";
    // cin>>n;

    // for (int i = 1; i < n; i++)
    // {
    //     if (n%i == 0)
    //     {
    //         sum = sum + i;
    //     }
    // };
    // if (sum == n){
    //     cout<<"This is a perfect number";
    // }else{
    //     cout<<"This is not a perfect number";
    // };
    //------------------------------------------------ Perfect number :: sum of factors should be equal to number

    // -------------------------------Program to find prime number ---------------------
    // int n, factors = 0 ;
    // cout<<"Enter your number : ";
    // cin>>n;
    // for (int i = 1; i < n; i++)
    // {
    //     if (n%i == 0)
    //     {
    //         ++factors;
    //     }
    // };
    // if (factors > 1)
    // {
    //     cout<<"It is not a prime number";
    // }else{
    //     cout<<"It is a prime number";
    // }

    // --------------------------Strong number------------------------
    // int n, m, digit ,sum = 0;
    // cout<<"Enter your number: ";
    // cin>>n;

    // for (int i = 0; i < number_of_digits(n); i++)
    // {
    //     m = n/(pow(10, i));

    //     digit = (int(m))%10;

    //     sum = sum + (digit*digit*digit);

    // }
    // cout<<sum;

    // Strong number: sum of factorial of digits of number is equal to number
    // Armstrong number:: sum of cubes of digits of number is equal to number
    // Palimdrome number: reverse of number is same as number
    // Perfect number : sum of factors of number is equal to number

    // ---------------------------------------------------------------------------------------------------------------

    // ------------------------------Printing perfect numbers in a given range--------------------------------------
    // int start, end, sum = 0;
    // cout << "Where you want to start with : ";
    // cin >> start;
    // cout << "Where you want to end : ";
    // cin >> end;

    // for (int i = start; i < end + 1; i++)
    // {
    //     for (int j = 1; j < i; j++)
    //     {
    //         if (i % j == 0)
    //         {
    //             sum = sum + j;
    //         }
    //     };
    //     if (sum == i)
    //     {
    //         cout << i << "is a perfect number"<<endl;
    //     }
    //     else{};
    //     sum = 0;
    // }

    // -------------------------printing armstrong number in a given range----------------------
    // int start, end,n , m, digit, sum = 0;
    // cout << "Where you want to start with : ";
    // cin >> start;
    // cout << "Where you want to end : ";
    // cin >> end;

    // for (int i = start; i < end + 1; i++)
    // {

    //     for (int j = 0; j < number_of_digits(i); j++)
    //     {
    //         m = i / (pow(10, j));

    //         digit = (int(m)) % 10;

    //         sum = sum + (digit * digit * digit);
    //     }
    //     if (sum == i)
    //     {
    //         cout<<i<<" is a Armstrong number"<<endl;
    //     }else{}
    //     sum = 0;
        
    // }

    return 0;
}
