#include <stdio.h>
#include <cs50.h>
#include <math.h>

// Credit
// ZunRenYao
// 16 April 2019
// Problem Set 1

// Doing log plus 1
int mylog10(long number)
{
    long temp = number;
    int pow = 0;
    while(temp != 0)
    {
        temp = temp/10;
        pow++;
    }
    return pow;
}

// Read the Digit
int readDigit(long number, int digit_num)
{
    return ((number/((long)pow(10,digit_num)))%10);
}

// Luhn's Algorithm
bool isLuhns(long number)
{
    int odd_sum = 0;
    int even_sum = 0;
    int sum = 0;
    int digit = mylog10(number);
    for( int i = 0; i < digit ; i ++)
    {
        if( i % 2 == 0)
            odd_sum += readDigit(number, i);
        else
        {
            int m2 = 0;
            m2 = readDigit(number, i) * 2;
            if(m2 > 9)
                even_sum +=(m2/10 + m2%10);
            else
                even_sum += m2;
        }
    }
    sum = odd_sum + even_sum;
    if (sum % 10 ==0)
        return true;
    else
        return false;
}

// Check Credit is Valid or not
void check(long number)
{
    int digit = mylog10(number);
    int lastTwo = 0;
    if(digit != 13 && digit != 15 && digit != 16)
        printf("INVALID\n");
    else
    {
        if(isLuhns(number))
        {
            if(digit == 13)
            {
                if ((int)(number / pow(10, 10)) != 4)
                    printf("INVALID\n");
                else
                    printf("VISA\n"); 
            }
            else if (digit == 15)
            {
                lastTwo = (int)(number / pow(10, 13));
                if (lastTwo == 34 || lastTwo == 37)
                    printf("AMEX\n");
                else
                    printf("INVALID\n"); 
            }
            else if (digit == 16)
            {
                lastTwo = (int)(number / pow(10,14));
                if(lastTwo >=51 && lastTwo <=55)
                    printf("MASTERCARD\n");
                else if ((int)(number / pow(10,15)) == 4)
                    printf("VISA\n");
                else
                    printf("INVALID\n");
            }
            else
                printf("INVALID\n");
        }
        else
            printf("INVALID\n");        
    } 
}
// Main function
int main(void)
{
    long number = -1;
    
    while(number < 0)
    {
        number = get_long("Number:");
    }
    check(number);
}
