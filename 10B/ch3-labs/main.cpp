#include <iostream>

using namespace std;

// Rational Class declaration
class Rational {
   private:
      int numerator;
      int denominator; 
   public:
      Rational();
      explicit Rational(int); 
      Rational(int, int); 
      Rational add(const Rational &) const; 
      Rational subtract(const Rational &) const; 
      Rational multiply(const Rational &) const; 
      Rational divide(const Rational &) const;
      void simplify();
      void display() const;
   private:
      int gcd(int, int) const;
};

// (a/b) + (c/d) = (ad + bc) / (b*d) is the equation for addition
// A = numerator, B = denominator, C = rationalB numerator, D = rationalB denominator
Rational Rational::add(const Rational &rationalB) const {
   Rational result;
   result.numerator = ((numerator * rationalB.denominator) + (denominator * rationalB.numerator));
   result.denominator = (denominator * rationalB.denominator);
   
   return result;
}

// (a/b) - (c/d) = (ad - bc) / (b*d) is the equation for subtraction
// A = numerator, B = denominator, C = rationalB numerator, D = rationalB denominator
Rational Rational::subtract(const Rational &rationalB) const {
   Rational result;
   result.numerator = ((numerator * rationalB.denominator) - (denominator * rationalB.numerator));
   result.denominator = (denominator * rationalB.denominator);

   return result;
}

// (a/b) * (c/d) = (ac) / (bd) is the equation for multiplication
// A = numerator, B = denominator, C = rationalB numerator, D = rationalB denominator
Rational Rational::multiply(const Rational &rationalB) const {
   Rational result;
   result.numerator = (numerator * rationalB.numerator);
   result.denominator = (denominator * rationalB.denominator);

   return result;
}

// (a/b) / (c/d) = (ad) / (cb) is the equation for division
// A = numerator, B = denominator, C = rationalB numerator, D = rationalB denominator
Rational Rational::divide(const Rational &rationalB) const {
   Rational result;
   result.numerator = (numerator * rationalB.denominator);
   result.denominator = (rationalB.numerator * denominator);

   return result;
}

//3 constructors:
//1. a constructor with two parameters (numerator and denominator)
Rational::Rational(int inputNum, int inputDenom) {
   numerator = inputNum;
   denominator = inputDenom;
   return;
}
//2. a constructor with one parameter (denominator set to 1)
Rational::Rational(int input) {
   numerator = input;
   denominator = 1;
   return;
}
//3. a constructor with no parameters (0/1)
Rational::Rational() {
   numerator = 0;
   denominator = 1;
}

//greatest common denominator function 
int Rational::gcd(int num1, int num2) const {
   while (num2 != 0) {
      int temp = num2;
      num2 = num1 % num2;
      num1 = temp;
   }
   return num1;
}

//simplify function
void Rational::simplify() {
   int result = gcd(numerator, denominator);
   numerator = numerator / result;
   denominator = denominator / result;
}

//display function
void Rational::display() const {
   cout << numerator << " / " << denominator;
}

// Do not change any of the code below this line!!

Rational getRational();
void displayResult(const string &, const Rational &, const Rational&, const Rational&);

int main() {
   Rational A, B, result;
   char choice;
   
   cout << "Enter Rational A:" << endl;
   A = getRational();
   cout << endl;
   
   cout << "Enter Rational B:" << endl;
   B = getRational();
   cout << endl;
   
   cout << "Enter Operation:" << endl
      << "a - Addition (A + B)" << endl
      << "s - Subtraction (A - B)" << endl
      << "m - Multiplication (A * B)" << endl
      << "d - Division (A / B)" << endl
      << "y - Simplify A" << endl;
   cin >> choice;
   cout << endl;
   
   if (choice == 'a') {
      result = A.add(B);
      displayResult("+", A, B, result);
   } else if (choice == 's') {
      result = A.subtract(B);
      displayResult("-", A, B, result);
   } else if (choice == 'm') {
      result = A.multiply(B);
      displayResult("*", A, B, result);
   } else if (choice == 'd') {
      result = A.divide(B);
      displayResult("/", A, B, result);
   } else if (choice == 'y') {
      A.simplify();
      A.display();
   } else {
      cout << "Unknown Operation";
   }
   cout << endl;
   
   return 0;
}


Rational getRational() {
   int choice;
   int numer, denom;
   
   cout << "Which Rational constructor? (Enter 2, 1, or 0)" << endl
      << "2 - 2 parameters (numerator & denominator)" << endl
      << "1 - 1 parameter (numerator)" << endl
      << "0 - 0 parameters (default)" << endl;
   cin >> choice;
   cout << endl;
   
   if (choice == 2) {
      cout << "numerator? ";
      cin >> numer;
      cout << endl;
      cout << "denominator? ";
      cin >> denom;
      cout << endl;
      return Rational(numer, denom);
   } else if (choice == 1) {
      cout << "numerator? ";
      cin >> numer;
      cout << endl;
      return Rational(numer);
   } else {
      return Rational();
   }
}

void displayResult(const string &op, const Rational &lhs, const Rational&rhs, const Rational &result) {
   cout << "(";
   lhs.display();
   cout << ") " << op << " (";
   rhs.display();
   cout << ") = (";
   result.display();
   cout << ")";
}

