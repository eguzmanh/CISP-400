#include "calculator.h"

unsigned long long factorial(int n)
{
    if(n ==0)
      return 1;
    return (n * factorial(n-1));    //recursively calls factorial function to generate the product of n ntimes
}

double factExp(double x, int n)   //exponential divided by factorial function
{
  double total = 1;
  for(int i =1; i<=n; i++)
  {
    total *= (x/i);
  }
  return total;
}

double sin(double x, int nTerms)    //sin function using a Taylor Series
{
    double total=0;
    bool sign = true;

    for(int i = 0; i < nTerms; i++)
    {
        if(sign)                    //If statement to switch between addition and subtraction
        {
          total += factExp(x,(2*i)+1);
          sign = false;
        }
        else                      //else statement executes subtraction
        {
          total -= factExp(x,(2*i)+1);
          sign = true;
        }
    }
    return total;
}


double sqrt(double x, int nTerms)     //square root function
{
    double next = 0;
    double prev = 1;
    for( int i = 0; i  < nTerms; i++)
    {
      next = prev - (((prev * prev) -x)/ (2 * prev));
      prev = next;
    }

    return next;
}

double primary()	// Number or '(' Expression ')' look for fact here
{
    Token t = ts.get();
    switch (t.kind)
    {
    case '(':			       // handle '('expression ')'
    {
      double d = expression();
      t = ts.get();
      if (t.kind != ')') error("')' expected");

      Token t1 = ts.get();
      //return d;///this is fine below here IDK
      if (t1.kind == fact) return factorial(d);
      else ts.putback(t1);
      return d;
      //return d;	// return the number�s value
    }

    case '-':
        return - primary();
/*s
    case fact:
    {
      double d = primary();
      cout << "value of double d assinged to primarty " << d << endl;
      return factorial(d);
    }///don't forget to put the Token back if it is not fact
*/
    case number:	// rather than case '8':
    {   //t = ts.get();
      Token t2= ts.get();
      if(t2.kind == fact) return factorial(t.value);
      else ts.putback(t2);
        return t.value;	// return the number�s value

    }

    ///if the token is of type sine, then
    ///call for a new primary
    ///pass that into the sin function
    ///use nTerms = 1000
    case sine:
    {
      double left = primary();

      return sin(left,1000);
    }

    ///if the token is of type root, then
    ///call for a new primary
    ///pass that into the sqrt function
    ///use nTerms = 1000
    case root:
    {
    return sqrt(primary(),1000);
    }

    default:
        error("primary expected");
        return 0;
    }
}

///The code below this line does not need to be changed at all

double expression()	// read and evaluate: 1   1+2.5   1+2+3.14  etc. look for fact here
{
    double left = term(); 			// get the Term
    Token t = ts.get();
    while (true)
    {
        //**********check **Token t = ts.get();		// get the next token�
        switch (t.kind)  			// � and do the right thing with it
        {
        case '+':
            left += term();
            t=ts.get();
            break;
        case '-':
            left -= term();
            t = ts.get();
            break;
        default:
            ts.putback(t);
            return left;		// return the value of the expression
        }
    }
}
double term()	// exactly like expression(), but for * and  /
{
    double left = primary(); 		// get the Primary
    Token t = ts.get();

    while (true)
    {
        //******check***Token t = ts.get();	// get the next Token
        switch (t.kind)
        {
        case '*':
            left *= primary();
            t=ts.get();
            break;
        case '/':
        {
            double d = primary();
            if  (d==0)
                error("divide by zero");
            left /= d;
            t = ts.get();
            break;
        }
        default:
            ts.putback(t);
            return left;	// return the value
        }
    }
}


void clean_up_mess()
{
    ts.ignore(print);
}


void calculate()
{
    while (cin)
        try
        {
            cout << prompt;
            Token t = ts.get();
            while (t.kind == print)
                t=ts.get();	// first discard all �prints�
            if (t.kind == quit)
                return;		// quit
            ts.putback(t);
            cout << result << expression() << endl;
        }
        catch (exception& e)
        {
            cerr << e.what() << endl;		// write error message
            clean_up_mess();		// <<< The tricky part!
        }
}
