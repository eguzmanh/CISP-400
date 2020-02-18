#include "Matrices-3.h"


//function for getting columns and setting private member
Matrix Matrices-3.h::getCols(int cols)
{
 try
 {
   cout << "Please enter a number of columns for your matrix: ";
   cint >> cols;

   if(isdigit(cols)) return cols;
   else error("\nYou must enter a number!")
 }
 catch(...)
 {
   cerr << "exception \n";
   keep_window_open();
 }
}

//function for getting rows and seeting private member
Matrix Matrices-3.h::getRows(int rows)
{
  try
  {
    cout << "Please enter a number of rows for your matrix: ";
    cint >> rows;

    if(isdigit(rows)) return rows;
    else error("\nYou must enter a number!")
  }
  catch(...)
  {
    cerr << "exception \n";
    keep_window_open();
  }
}


///set up constructor to use getRows() and getCols() to build vector
///Initialize each element to zero using vector resize function
Matrix Matrices-3.h::Matrix()
  //option1 :rows = getRows();, cols = getCols();

//option2
//Matrix Matrices-3.h::Matrix[rows][cols];
//option3
//Matrix Matrices-3.h::Matrix[getRows][getCols];


//Add each corresponding element construct a local matrix to store
//the result and return it using c = a + b
//if a and b do not have the same number of rows and colomns throw
//an error
Matrix Matrix-3.h::operator+(const Matrix& a, const Matrix& b)
{
  try
  {
    if(a.size == b.size)      //check to see if maxtrix a has equal rows and cols
    {
      Matrix omega[rows][columns]{{0},{0}};
      for(int r = 0; r < rows; r++)  //traverse rows
      {
        for(int c = 0; c < columns; c++)   //traverse columns
        {
          omega[r][c] = a[r][c] + b[r][c];   //adding elements vector assigning them to omega
        }
      }
    }
    else error("\nMatrices must have equal rows and columns to add.\n")
  }
  catch(...)
  {
    cerr << "exception \n";
    keep_window_open();
  }
}


//Perform matrix multiplication for a matrix a with row i and column j
//and a matrix b with row j and column k the product c of two
//matrices is defined as c(i,k) = a(i,0)*b(o,k) + a(i,2)*b(2,k)+ ...
//elements at row i of are are mulitipled and summed with elements
// in columnn k of b and store the resulting sum in element c(i,k)
//This can be done with a triple nested for loop
//outermost look control k and the collumn index for b
//the next loop control i, the row for a
//the innermost loop will control j, with will determine which column to use from a and with row ot use from b
//create a running sum when the j loops is finished store in c(i,k)
//if the number of columns and rows in a and b dont match throw and error
//construct a local matrix to store the result and return it.
Matrix Matrix-3.h::operator*()
:



//if the rows and columns are not equal return false
//if any element (i,j) doesnt match return false otherwise return true
Matrix Matrix-3.h::operator==()
:



//opposite of ==operator
Matrix Matrix-3.h::operator!=()
:


//Output operator will out put matrices in the format with columns separated by ' ' and rows by '\n' you can specify the width of your columns useing setw from <iomanip>
Matrix Matrix-3.h::operator<<()
:
