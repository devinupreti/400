#include <iostream>
#include <stdlib.h>
#include <typeinfo>
#include <string>
#include "dupreti_op.h"

using namespace std;

int main()
{ 
  float a, b;
  char op;
  string ops;
  cout << "\nHello everyone !!!";
  cout << "\n\nThis is a calculator!\n";
  bool x = 1;
  string input;
  
  while (x){
  
  while(x){
  cout << "\nEnter you operator(+ ,- ,* ,/ or %): ";
  cin >> ops;
  if (ops.length() == 1) { 
  	op = ops[0];	
  	break; }
  else {
  	cout<< "\nInvalid Input, please provide valid input";
  	cin.clear();
  	cin.ignore();
  	   }
  }


  cout << "\nEnter your 1st operand: ";
  cin >> a;
  if (cin.fail()) { 
  cout << "\nInvalid Input";
  cin.clear();
  cin.ignore();
  continue; }
  
  cout << "\nEnter your 2nd operand: ";
  cin >> b;
  if (cin.fail()) { 
  cout << "\nInvalid Input";
  cin.clear();
  cin.ignore();
  continue; }

  switch(op){
    case '+':
      cout << "\nThe result of operation(" << a << op << b << ") is :" << add(a,b) << "\n";
      break;
    case '-':
      cout << "\nThe result of operation(" << a << op << b << ") is :" << substract(a,b) << "\n";
      break;
    case '*':
      cout << "\nThe result of operation(" << a << op << b << ") is :" << multiply(a,b) << "\n" ;
      break;
    case '/':
      cout << "\nThe result of operation(" << a << op << b << ") is :" << divide(a,b) << "\n";
      break;
    case '%':
      if ((a - (int)a == 0) && (b - (int)b == 0)){
      cout << "\nThe result of operation(" << a << op << b << ") is :" << mod(a,b) << '\n';
      break;}
      else { cout << "INVALID INPUT: Cannot take non-int values for modulus operation\n" ;
      		 break; }
    default:
      cout << "INVALID INPUT for Operator!!" << "\n";
	}

  while(x){
  cin.clear();
  cin.ignore();

  cout << "\nDo you want to do more calculation?(Y or N) : ";
  cin >> input;
  if (input == "Y" || input == "y"){ break; }
  else if (input == "N" || input == "n"){ x = 0; }
  else 
  { cout<< "\nInvalid Input, please provide valid input";
  	
  }
    
    }
  
  
  }

}
