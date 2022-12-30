#include <iostream>
#include<math.h>
using namespace std;

int gcd_number(int a, int b){
    while (a%b != 0)
    {
       int temp = a%b;
       a = b; 
       b = temp; 
    }
    return a;
    
}

int reverse_number(int n)
{
    int reverse = 0;
    while (n > 0)
    {
        int digit = n % 10;
        reverse = reverse * 10 + digit;
        n = n / 10;
    }
    return reverse;
}

int decimal_binary(int n){
    if (n % 2 == 0)
    {
        int binary = 0;
        while (n > 0)
        {
            int digit = n % 2;
            binary = binary * 10 + digit;
            n = n / 2;
        }
        return reverse_number(binary)*10;
    }
    else
    {
        int binary = 0;
        while (n > 0)
        {
            int digit = n % 2;
            binary = binary * 10 + digit;
            n = n / 2;
        }
        return reverse_number(binary);
    }
}

int binary_decimal(int n){
    int sum = 0, i=0;
    while (n>0)
    {
        int digit = n%10;
        sum = sum + digit*pow(2,i);
        n = n/10;
        i++;
    }
    return sum;
};

int get_bit(int n, int pos){
    int mask = 1<<pos;

    int res = n&mask;

    if (res == 0)
    {
        return 0;
    }else{
        return 1;
    }
    
};

int set_bit(int n, int pos){
    int mask = 1<<pos;
    return n|mask;
};

int clear_bit(int n, int pos){
    int mask = ~(1<<pos);
    return n&mask;
}

int hcd_number(int a, int b);

int main()
{
    // program for decimal to binary
    // int a;
    // cout << "Enter your decimal number: ";
    // cin >> a;

    // cout<<decimal_binary(n);

    // cout<<binary_decimal(101);

    int aa = 5;
    int b = 7;

    // Swap two numbers 
    // aa = aa^b;
    // b = aa^b;
    // aa = aa^b;
    // cout<<aa<<"  "<<b;

    // odd/Even
    // if (aa & 1== 0)
    // {
        // cout<<"Number is even";
    // }
    

    // Find the ith bit;

    // int mask = aa>>n;

    // if (aa& mask != 0)
    // {
    //     cout<<1;
    // }
    // else{
    //     cout<<0;
    // }
    

    // cout<<~(aa>>1);

    //   find non repeating element in array 
    // int arr[] = {1, 2, 3, 6, 2, 3, 1};
    // int res = 0;

    // for (int i = 0; i < 7; i++)
    // {
    //     res = res^arr[i];
    // }
    // cout<<res;
    
    // find two non repeating element in a array
    
    // int arr[] = {1, 3, 6, 2, 1, 3};
    // int res = 0;
    // for (int i = 0; i < 6; i++)
    // {
    //     res = res^arr[i];
    // }
    
    // int pos = 0;
    // for (int i = 0; i < 32; i++)
    // {
    //     if (get_bit(res, i) == 1)
    //     {
            
    //         pos = i;
    //         break;
    //     }    
    // }
    // int new_res = 0;
    // for (int i = 0; i < 6; i++)
    // {
    //     if (get_bit(arr[i], pos) == 1)
    //     {
    //         new_res = new_res^arr[i];
    //     }
    // }
    // int ans = new_res^res;
    // int ans2 = ans^res;
    // cout<<ans<<"  "<<ans2;
    

    // int arr[] = {1, 3, 5, 6, 2};
    // int xor = arr[0]^arr[1] ;
    // int first = 0, second = 0;
    // int min_xor = arr[0]^arr[1];

    // for (int i = 0; i < 5; i++)
    // {
    //     for (int j = i; j < 4; j++)
    //     {
    //         xor = arr[i]^arr[j];
    //         if (xor<min_xor)
    //         {
    //             min_xor = xor;
    //             first = i;
    //             second = j;
    //         }   
    //     }  
    // }

    // cout<<min_xor<<endl;
    // cout<<first<<"  "<<second;
    


    // Sieve of eratosthenes
    // how to find prime factors from 0 to given number 
    // int n ;
    // cout<<"Enter your number :";
    // cin>>n;
    // bool arr[n+1];
    // for (int i = 0; i < n+1; i++)
    // {
    //     arr[i] = true;
    // }
    
    // arr[0] = false;
    
    // for (int i = 2; i < n+1; i++)
    // {
    //     for (int j = 2*i; j < n+1; j+=i)
    //     {
    //         arr[j-1]  = false;
    //     }
        
    // }

    // for (int i = 0; i < n; i++)
    // {
    //     cout<<arr[i]<<"  "<<i+1<<endl;
    // }
    
    int arr[] = {1, 3, 4, 6,7};

    cout<<gcd_number(15,27);
    
    
   

    return 0;
}


int hcd_number(int a, int b){
    if (b == 0)
    {
        return a;
    }
    int temp = a%b;
    a = b;
    b = temp;
    hcd_number(a, b);
}