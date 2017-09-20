#include <iostream>
#include <stdlib.h>
#include "dupreti_op.h"

using namespace std;

float add(float a, float b){ return a+b; }

float substract(float a, float b){ return a-b; }

float multiply(float a, float b){ return a*b; }

float divide(float a, float b)
{
  if (b == 0.00) { 
      cout << "\nDivide by zero error\n";
      cout << "Denominator cannot be zero";
      return 0; }
  else 
    return a/b;
}

int mod(int a, int b){ 
  if (b != 0) {return a%b;} 
  else {
    cout << "\nDivide by zero error;\n" ;
    cout << "Denominator cannot be zero";
    return 0;
}
}

