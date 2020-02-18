#include "Token_stream.h"

Token Token_stream::get()	 // read a Token from the Token_stream
{
    if (full)
    {
        full=false;    // check if we already have a Token ready
        return buffer;
    }

    char ch;
    cin >> ch;	// note that >> skips whitespace (space, newline, tab, etc.)

    switch (ch)
    {
    case '(': case ')': case ';': case 'q': case '+': case '-': case '*': case '/': case fact:
        return Token{ch};		// let each character represent itself
    case '.': case '0': case '1': case '2': case '3': case '4': case '5': case '6': case '7': case '8': case '9':
    {
        cin.putback(ch);		     // put digit back into the input stream
        double val;             //assign to val the character we just put back into input stream
        cin >> val;		     // read a floating-point number
        return Token{number,val}; // rather than Token{'8',val}
    }
/******************
******************
******************
******************/
    ///look for an 's'
    ///if the stream contains 's''i''n', return a sine token
    ///if the stream contains 's''q''r''t', return a root token
    ///else throw a Bad token exception (use error function)

/* cout << prompt
 token t = ts.get();

 */


    /*case '!':
    {
      return Token{fact};
    }
    */
    case 's':               //check to see if the token should be sin or sqrt
      {/*
        cin >> ch;
        if (ch =='i')
        {
          cin >> ch;
          if(ch == 'n')
          {return Token {sine};}

        }
        else if ( ch == 'q')
          {
            cin >> ch;
            if ( ch == 'r')
            {if (ch =='t') return Token{root};}
          }*/
     string inStream;
      inStream += ch;
      while(cin.get(ch) && (isalpha(ch)))
      {
        inStream += ch;
        if(inStream == "sin")
          return Token{sine};
        if(inStream == "sqrt")
          return Token{root};

      }
      cin.putback(ch);
      }
      /*{                     //if the next ch is i look for n



        Token t = ts.get();
        Token t2, t3, t4;                    //else look to see if it is a q
        if(t.kind == 'i')       //else throw an exception
          {
            t3 = ts.get();          // get the next ch to see if it is an n for establishing sin token
            if(t3.kind != 'n') error("Bad token"); // throw error if not n
            else if (t3.kind == 'n') return Token{sine};
          }
        else if(t2.kind=='q')                  // get the next ch to see if it is a q for sqrt token
        {
          t3 = ts.get();
          if(t3.kind != 'r') error("Bad token"); //if the next ch is not an r throw an error
          else if (t3.kind == 'r')
          {
            t4 = ts.get();            //if previous is r then check for t throw error otherwise
            if(t4.kind != 't') error("Bad token");
            else if (t4.kind == 't') return Token{root};
          }*/

    default:
        error("Bad token");
    }
}


void Token_stream::ignore(char c)
// skip characters until we find a c; also discard that c
{
    // first look in buffer:
    if (full && c==buffer.kind)  	// && means and
    {
        full = false;
        return;
    }
    full = false;	// discard the contents of buffer
    // now search input:
    char ch = 0;
    while (cin>>ch)
        if (ch==c)
            return;
}

void Token_stream::putback(Token t)
{
    if (full)
        error("putback() into a full buffer");
    buffer=t;
    full=true;
}
