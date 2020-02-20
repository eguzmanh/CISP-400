#include "Matrices.h"
#include "../std_lib_facilities.h"

//Add each corresponding element construct a local matrix to store
//the result and return it using c = a + b
//if a and b do not have the same number of rows and colomns throw
//an error
double Matrices::operator+(const Matrix& a, const Matrix& b)
{
Matrix sum(a.getRows(),a.getCols())
  try
  {
    if(a.getRows()!= b.getRows()) {error("Matrices must have equal number of rows!\n");}
    if(a.getCols()!= b.getCols()) {error("Matrices must have equal number of columns!\n");}

    for(int r =0; r < a.getRows(); r++)
    {
      for(int c =0; c < a.getCols(); c++)
      {
        sum.operator(r,c)= a.operator(r,c) + b.operator(r,c);
      }
    }
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
double Matrices::operator*(const Matrix& a, const Matrix& b)
{
 Matrix product(a.getRows(),a.getCols());
 int n = a.size();
 int m = a[0].size();
 int p = b[0].size();

 for(int i = 0, i<n; i++)
  {for(int j = 0; j<p; j++)
    for(int k=0; k<m;k++){product.operator(i,j)= a.operator(i,j)*b.operator(i,j);}
  }
}



//if the rows and columns are not equal return false
//if any element (i,j) doesnt match return false otherwise return true
bool Matrices::operator==(const Matrix& a, const Matrix& b)
{
  if(a.getRows()!=b.getRows()) {error("Matrices must have the same number of rows!\n"); return false;}

  if(a.getCols()!=b.getCols())
  {error("Matrices must have the same number of columns!\n"); return false;}

  else return true;

}



//opposite of ==operator
bool Matrices::operator!=(const Matrix& a, const Matrix& b)
{
  if(a.getRows()==b.getRows())
  {return false;}

  if(a.getCols()==b.getCols())
  {return false;}

  else return true;
}


//Output operator will out put matrices in the format with columns separated by ' ' and rows by '\n' you can specify the width of your columns useing setw from <iomanip>
void Matrices::operator<<(ostream& os, const Matrix& a)
{
  setw(11);
  cout << "a:\n";

  for(int r =0; r < a.getRows(); r++)
  {
    for(int c =0; c <a.getCols(); c++)
    {
      cout << a.operator(r,c) const << " "<<;
    } //where do I put const
    cout << "\n";
  }
  cout << "b:\n";
  for(int r =0; r < b.getRows(); r++)
  {
    for(int c =0; c <b.getCols(); c++)
    {
      cout << b.operator(r,c) const << " "<<;
    } //where do I put const
    cout << "\n";
  }
}
