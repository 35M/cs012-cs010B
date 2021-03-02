9.1 Recursion: Introduction {
    *algorithm: "a sequence of steps for solving a problem"
    *recursive algorithm: "an algorithm that breaks the problem into smaller subproblems and
    applies the same algorithm to solve the smaller subproblems"
    *base Case: "describes how to actually approach a problem"
}

9.2 Recursive Functions {
    *Recursive function: "a function that calls other functions, including itself"
        - Recursion can be direct, like f() itself calling f(), or indirect, such as
        f() calling g() and g() calling f()
============================================================================================
    ```A recursive function example```
    #include <iostream>
    using namespace std;

    void CountDown(int countInt) {
        if (countInt <= 0) {
            cout << "GO!\n";
        }
        else {
            cout << countInt << endl;               
            CountDown(countInt - 1);          //you can see the function calling itself here
        }                                     //continues to make copies and call itself
    }                                         //until it matches the "if" statement

    int main() {
        CountDown(2);                         //1. passes in value
        return 0;
    }

    /* Each call to CountDown() effectively creates a new "copy" of the executing function, 
    as shown on the right. Returning deletes that copy. */
}

9.3 Creating a Recursive Function {
    *Write the base Case: "every recursive function must have a case that returns a value
    without performing a recurisve call, which is called the base case. Programmers can
    write that part of the function first, and then test. There can be multiple base cases"
    *Write the recursive Case: "the programmer then adds the recursive case to the 
    function"
============================================================================================
    ```9. 3. 1: Recursive function: Writing the base Case```
    #include <iostream>
    using namespace std;

    // Returns number of pennies if pennies are doubled numDays times
    long long DoublePennies(long long numPennies, int numDays){
        long long totalPennies;

        if (numDays == 1) {
            totalPennies = numPennies * 2;
        }

        else {
            totalPennies = DoublePennies((numPennies * 2), numDays - 1);
        }

        return totalPennies;
    }

    // Program computes pennies if you have 1 penny today,
    // 2 pennies after one day, 4 after two days, and so on
    int main() {
        long long startingPennies;
        int userDays;

        cin >> startingPennies;
        cin >> userDays;
        cout << "Number of pennies after " << userDays << " days: "
                << DoublePennies(startingPennies, userDays) << endl;
        return 0;
    }

    //OUTPUTS:
    /* With input: 1 10
       Output is: Number of pennies after 10 days: 1024

       With input: 1 40
       Output is: Number of pennies after 40 days: 1099511627776

       With input: 1 1
       Output is: Number of pennies after 1 days: 2
    */
--------------------------------------------------------------------------------------------
    ```9. 3. 2: Recursive function: Writing the recursive Case```
    #include <iostream>
    using namespace std;

    void PrintFactorial(int factCounter, int factValue){
        int nextCounter;
        int nextValue;

        if (factCounter == 0) {            // Base case: 0! = 1
            cout << "1" << endl;
        }
        else if (factCounter == 1) {       // Base case: Print 1 and result
            cout << factCounter << " = " << factValue << endl;
        }
        else {                             // Recursive case
            cout << factCounter << " * ";
            nextCounter = factCounter - 1;
            nextValue = nextCounter * factValue;

            PrintFactorial(nextCounter, nextValue);

        }
    }

    int main() {
        int userVal;

        cin >> userVal;
        cout << userVal << "! = ";
        PrintFactorial(userVal, userVal);

        return 0;
    }

    //OUTPUTS:
    /*  With input: 5
        Output is: 5! = 5 * 4 * 3 * 2 * 1 = 120

        With input: 8
        Output is: 8! = 8 * 7 * 6 * 5 * 4 * 3 * 2 * 1 = 40320
    */
}

9.4 Recursive Math Functions {
    *Fibonacci sequence: "0, 1, 1, 2, 3, 5, 8, 13, 21, 34, etc.; starting with 0, 1, 
    the pattern is to compute the next number by adding the previous two numbers."
    *greatest common divisor (GCD): "the largest number that divides evenly into two numbers
    e.g., GCD(12, 8) = 4"
        - EX: GCD(12, 8): Subtract 8 from 12, yielding 4.
          EX: GCD(4, 8): Subtract 4 from 8, yielding 4.
          EX: GCD(4, 4): Numbers are equal, return 4.
============================================================================================
    ```Fibonacci sequence step-by-step```
    #include <iostream>
    using namespace std;

    /* Output the Fibonacci sequence step-by-step.
    Fibonacci sequence starts as:
    0 1 1 2 3 5 8 13 21 ... in which the first
    two numbers are 0 and 1 and each additional
    number is the sum of the previous two numbers
    */

    void ComputeFibonacci(int fibNum1, int fibNum2, int runCnt) {
    
        cout << fibNum1 << " + " << fibNum2 << " = "
                << fibNum1 + fibNum2 << endl;
        
        if (runCnt <= 1) { // Base case: Ran for user specified
                           // number of steps, do nothing
        }
        else {             // Recursive case: compute next value
            ComputeFibonacci(fibNum2, fibNum1 + fibNum2, runCnt - 1);
        }
    }

    int main() {
        int runFor;      // User specified number of values computed
        
        // Output program description
        cout << "This program outputs the" << endl
        << "Fibonacci sequence step-by-step," << endl
        << "starting after the first 0 and 1." << endl << endl;
        
        // Prompt user for number of values to compute
        cout << "How many steps would you like? ";
        cin >> runFor;
        
        // Output first two Fibonacci values, call recursive function
        cout << "0" << endl << "1" << endl;
        ComputeFibonacci(0, 1, runFor);
        
        return 0;
    }

    /*  OUTPUT:
        This program outputs the
        Fibonacci sequence step-by-step,
        starting after the first 0 and 1.

        How many steps would you like? 10
        0
        1
        0 + 1 = 1
        1 + 1 = 2
        1 + 2 = 3
        2 + 3 = 5
        3 + 5 = 8
        5 + 8 = 13
        8 + 13 = 21
        13 + 21 = 34
        21 + 34 = 55
        34 + 55 = 89
    */
--------------------------------------------------------------------------------------------
    ```Calculate greatest common divisor of two numbers```
    #include <iostream>
    using namespace std;

    /* Determine the greatest common divisor
    of two numbers, e.g. GCD(8, 12) = 4
    */
    int GCDCalculator(int inNum1, int inNum2) {
        int gcdVal;     // Holds GCD results
        
        if (inNum1 == inNum2) {     // Base case: Numbers are equal
            gcdVal = inNum1;       // Return value
        }
        else {                     // Recursive case: subtract smaller from larger
            if (inNum1 > inNum2) { // Call function with new values
                gcdVal = GCDCalculator(inNum1 - inNum2, inNum2);
            }
            else {
                gcdVal = GCDCalculator(inNum1, inNum2 - inNum1);
            }
        }
        
        return gcdVal;
    }

    int main() {
        int gcdInput1;     // First input to GCD calc
        int gcdInput2;     // Second input to GCD calc
        int gcdOutput;     // Result of GCD
        
        // Print program function
        cout << "Program outputs the greatest \n"
                << "common divisor of two numbers." << endl;
        
        // Prompt user for input
        cout << "Enter first number: ";
        cin >> gcdInput1;
        
        cout << "Enter second number: ";
        cin >> gcdInput2;
        
        // Check user values are > 1, call recursive GCD function
        if ((gcdInput1 < 1) || (gcdInput2 < 1)) {
            cout << "Note: Neither value can be below 1." << endl;
        }
        else {
            gcdOutput = GCDCalculator(gcdInput1, gcdInput2);
            cout << "Greatest common divisor = " << gcdOutput << endl;
        }
        
        return 0;
    }

    /* OUTPUT:
        Program outputs the greatest 
        common divisor of two numbers.
        Enter first number: 12
        Enter second number: 8
        Greatest common divisor = 4

        ...

        Program outputs the greatest 
        common divisor of two numbers.
        Enter first number: 456
        Enter second number: 784
        Greatest common divisor = 8

        ...

        Program outputs the greatest 
        common divisor of two numbers.
        Enter first number: 0
        Enter second number: 10
        Note: Neither value can be below 1.
    */
}

9.5 Stack Overflow {
    *stack frame: "exactly what it sounds like; a frame of data that gets placed on the
    stack, for things like local parameters, local variables, and other function items.
    upon return, the frame is deleted"
    *stack overflow: "when a stack frame extends beyond the memory region allocated
    for stack, usually causes the program to crash and report an error like segmentation
    fault, access violation, or bad access"
}