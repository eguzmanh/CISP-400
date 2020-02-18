/* Return the greatest common divisor of x and y.
Use the Basic Euclidean Algorithm for GCD */
#include "RSA.h"
#include "std_lib_facilities.h"
#include <climits>
//#include <ctime>

unsigned long long gcd(unsigned long long x, unsigned long long y)
{

  if (x == 0) return y;
  if (y == 0) return x;
  if (x == y) return x;
  if (x > y) return gcd( x-y,y);

  return gcd(y,x%y);

}

/* Return the least common multiple of x and y
The easiest and fastest way to do this is to return (x*y) / gcd(x,y)  */

unsigned long long lcm( unsigned long long x, unsigned long long y)
{
  unsigned long long ans = (x*y)/ (gcd(x,y));

  return ans;
}


bool isOdd(unsigned long long n)
{
  return ((n % 2 != 0) ? true : false);
}

//Return true if n is prime, false otherwise.
bool isPrime(unsigned long long n)
{
/*  unsigned long long i, temp=1;
  for(i=2; i<= n/2 && temp; i++)
    {if(n%i==0) temp = 0;}
    return temp;
*/

  if(n<=1) return false;
  if(n ==  2) return true;

  if(isOdd(n))
  {
    for(int i = 3; i <= (n / 3); i+= 2)
      {if (n%i == 0) return false;}

    return true;
  }
  else
    return false;
}

/* Return a random prime number in the range of [min...max]
Use rand().
Use a loop:
Generate a random number in the range
while it is not prime, generate a new one */
unsigned long long getPrime(unsigned long long min,unsigned long long max)
{
  //srand(time(0)); // does this need to be in the main.cpp?

  unsigned long long rando = ((rand()%(max - min)) + min);
  //cout << "before while loop" << rando<< endl;

  while(!isPrime(rando))
  {
    rando = (rand()%(max - min)) + min;
    //cout << "inside while loop" << rando << endl;
  }
  return rando;
}

/* Modular exponentiation
The goal is to raise to a power and then mod:
return
Unfortunately, if you try to compute the above expression, the power will get ridiculously large and overflow before the mod operation is done
To work around this, we will multiply the base once per iteration and then mod as we go to keep the number smaller. */


unsigned long long modExp(unsigned long long base, unsigned long long exp, unsigned long long n)
{
  //cout << "base: " << base << " exp: " << exp << " n: " << n << endl;
   unsigned long long ans = 1;
   for(unsigned long long i = 0; i < exp; i++)
    {
      ans = (ans * base) % n;
    //  cout << "In for loop ans: "<< ans << " i == " << i << endl;
    }
   return ans;

}

/* Modular Inverse function.
Given e and lam as parameters, find a number d such that:
There are many fancy ways to do this. We will take a simple, iterative approach:
Use a for loop to test the above equation for every possible value of d, from 1 to lam If the left side of the above equation == 1, then return d  */
unsigned long long modInverse(unsigned long long e, unsigned long long lam)
{
  //unsigned long long kappa;

  for(int i =1; i < lam; i++)
  {
    if(((i*e)%lam) == 1 ) return i;

  }

  return 0;

}
