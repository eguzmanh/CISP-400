
/*Don't forget to #include "RSA.h" so you can use the functions declared above declare unsigned long long variables p, q, n, lambda, d, e, m, and c*/
#include "RSA.h"
#include "std_lib_facilities.h"
#include <climits> // to use UCHAR_MAX & USHRT_MAX
#include <ctgmath>

unsigned long long MIN = UCHAR_MAX;
unsigned long long MAX = USHRT_MAX;


int main()
{
  unsigned long long c,d,e,lambda,m,n,p,q;
  unsigned long long seed;


/*Declare unsigned int seed
Ask the user to enter a seed
Call srand() ONCE to seed your RNG*/
  cout << "Enter seed: ";
  cin >> seed;

  srand(seed);

/*Use getPrime to assign to p a random number in the range [UCHAR_MAX...USHRT_MAX]
This will assign it to a prime between 255 and 65535
You can access those constants with #include <climits> This means that p is between 8 and 16 bits in length
Do the same for q
Output the values of p and q */

  p = getPrime(MIN, MAX);
  cout << "p: " << p << endl;
  q = getPrime(MIN, MAX);
  cout << "q: " << q << endl;

/*The modulus n is obtained by multiplying the two large prime numbers, p and q:
Assign n = p * q
Output the value of n */
  n = p * q;
  cout << "n: " << n << endl;

/*Assign lambda to the lcm of p - 1 and q - 1
Output the value of lambda
Lambda is a value that we will use to generate e and d */
  lambda = lcm((p-1),(q-1));
  cout << "lambda: " << lambda << endl;

/*In the next step we will generate e
e must be a prime smaller than lambda that does not divide evenly into lambda Call getPrime to assign to e a random prime in the range [2...lambda - 1]
Use a loop to ensure that lambda is not divisible by e:
while lambda is divisible by e, assign to e a new random prime in the range [2...lambda - 1] Output the value of e */
  e = getPrime(2,lambda-1);

  while(e<lambda)
  {
    unsigned long long kappa = gcd(e,lambda);
    
    if(kappa ==1) break;
    else e++;
  }
  cout <<"e: " << e << endl;

/*Assign to d the modInverse of e and lambda Output the value of d*/
  d = modInverse(e,lambda);
  cout << "d: " << d << endl;

/*Output the public key, which is the values of n and e
Output the private key, which is the values of n and d */
  cout << "Public key: n = " << n <<" e = " << e << endl;
  cout << "Private key: n = " << n <<" d = "<< d << endl;


/*Prompt the user to enter the plain message m, which must be a positive number less than the value of n
input m*/
  cout << "Enter a positive number less than " << n << ":" << endl;
  cin >> m;


/*Use modExp to assign to cipher c the modular exponent (m^e)% n
This is your encrypted value, which is what a client would send to a server
Output the value of the cipher */
  c = modExp(m,e,n);
  cout << "Cipher: " << c << endl;


/*Decrypt and output the cipher c by calculating the modular exponent (c^d) % n
You should get the original message m
This is what the server, having the private key d and n, would do to decrypt the client's message */
  m = modExp(c,d,n);
  cout << "Decrypted cipher: " << m << endl;

  return 0;
}
