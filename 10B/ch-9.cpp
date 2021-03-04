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

9.6 Recursive Algorithm: Search {
    ```9. 6. 1: A Recursive Function Carrying Out A Binary Search Algorithm```
    #include <iostream>
    using namespace std;

    void GuessNumber(int lowVal, int highVal) {
        int midVal;            // Midpoint of low and high value
        char userAnswer;       // User response
        
        midVal = (highVal + lowVal) / 2;
        
        // Prompt user for input
        cout << "Is it " << midVal << "? (l/h/y): ";
        cin >> userAnswer;
        
        if ( (userAnswer != 'l') && (userAnswer != 'h') ) { // Base case: found number
            cout << "Thank you!" << endl;                   
        }
        else {                                             // Recursive case: split into lower OR upper half
            if (userAnswer == 'l') {                       // Guess in lower half
                GuessNumber(lowVal, midVal);               // Recursive call
            }
            else {                                         // Guess in upper half
                GuessNumber(midVal + 1, highVal);          // Recursive call
            }
        }
    }

    int main() {
        // Print game objective, user input commands
        cout << "Choose a number from 0 to 100." << endl;
        cout << "Answer with:" << endl;
        cout << "   l (your num is lower)" << endl;
        cout << "   h (your num is higher)" << endl;
        cout << "   any other key (guess is right)." << endl;
        
        // Call recursive function to guess number
        GuessNumber(0, 100);
        
        return 0;
    }
    //SAMPLE OUTPUT:
    /* Choose a number from 0 to 100.
    Answer with:
    l (your num is lower)
    h (your num is higher)
    any other key (guess is right).
    Is it 50? (l/h/y): l
    Is it 25? (l/h/y): h
    Is it 38? (l/h/y): l
    Is it 32? (l/h/y): y
    Thank you! */
--------------------------------------------------------------------------------------------
    ```9. 6. 2: Recursively searching a sorted list```
    #include <iostream>
    #include <string>
    #include <vector>

    using namespace std;

    /* Finds index of string in vector of strings, else -1.
    Searches only with index range low to high
    Note: Upper/lower case characters matter
    */

    int FindMatch(vector<string> stringsList, string itemMatch, int lowVal, int highVal) {
        int midVal;        // Midpoint of low and high values
        int itemPos;       // Position where item found, -1 if not found
        int rangeSize;     // Remaining range of values to search for match
        
        rangeSize = (highVal - lowVal) + 1;
        midVal = (highVal + lowVal) / 2;
        
        if (itemMatch == stringsList.at(midVal)) {   // Base case 1: item found at midVal position
            itemPos = midVal;
        }
        else if (rangeSize == 1) {                   // Base case 2: match not found
            itemPos = -1;
        }
        else {                                       // Recursive case: search lower or upper half
            if (itemMatch < stringsList.at(midVal)) { // Search lower half, recursive call
                itemPos = FindMatch(stringsList, itemMatch, lowVal, midVal);
            }
            else {                                    // Search upper half, recursive call
                itemPos = FindMatch(stringsList, itemMatch, midVal + 1, highVal);
            }
        }
        
        return itemPos;
    }

    int main() {
        vector<string> attendeesList(0); // List of attendees
        string attendeeName;             // Name of attendee to match
        int matchPos;                    // Matched position in attendee list
        
        // Omitting part of program that adds attendees
        // Instead, we insert some sample attendees in sorted order
        attendeesList.push_back("Adams, Mary");
        attendeesList.push_back("Carver, Michael");
        attendeesList.push_back("Domer, Hugo");
        attendeesList.push_back("Fredericks, Carlos");
        attendeesList.push_back("Li, Jie");
        
        // Prompt user to enter a name to find
        cout << "Enter person's name: Last, First: ";
        getline(cin, attendeeName); // Use getline to allow space in name
        
        // Call function to match name, output results
        matchPos = FindMatch(attendeesList, attendeeName, 0, attendeesList.size() - 1);
        if (matchPos >= 0) {
            cout << "Found at position " << matchPos << "." << endl;
        }
        else {
            cout << "Not found. " << endl;
        }
        
        return 0;
    }
    // SAMPLE OUTPUT:
    /* Enter person's name: Last, First: Meeks, Stan
    Not found. 

    ...

    Enter person's name: Last, First: Adams, Mary
    Found at position 0.

    ...

    Enter person's name: Last, First: Li, Jie
    Found at position 4. */
}

9.8 Recursive Exploration of All Possibilities {
    ```9. 8. 1: Scramble a Word's Letters in Every Possible Way```
    #include <iostream>
    #include <string>
    using namespace std;

    /* Output every possible combination of a word.
    Each recursive call moves a letter from
    remainLetters to scramLetters.
    */
    void ScrambleLetters(string remainLetters,  // Remaining letters
                        string scramLetters) {  // Scrambled letters
        string tmpString; // Temp word combination
        unsigned int i;   // Loop index
        
        if (remainLetters.size() == 0) { // Base case: All letters used
            cout << scramLetters << endl;
        }
        else {                              // Recursive case: move a letter from
                                            // remaining to scrambled letters
            for (i = 0; i < remainLetters.size(); ++i) {
                // Move letter to scrambled letters
                tmpString = remainLetters.substr(i, 1);
                remainLetters.erase(i, 1);
                scramLetters = scramLetters + tmpString;
                
                ScrambleLetters(remainLetters, scramLetters);
                
                // Put letter back in remaining letters
                remainLetters.insert(i, tmpString);
                scramLetters.erase(scramLetters.size() - 1, 1);
            }
        }
    }

    int main() {
        string wordScramble; // User defined word to scramble
        
        // Prompt user for input
        cout << "Enter a word to be scrambled: ";
        cin >> wordScramble;
        
        // Call recursive function
        ScrambleLetters(wordScramble, "");
        
        return 0;
    }

    //SAMPLE OUTPUT:
    /* Enter a word to be scrambled: cat
    cat
    cta
    act
    atc
    tca
    tac */
------------------------------------------------------------------------------------------
    ```9. 8. 2: Shopping spree in which a user can fit 3 items in a shopping bag```
    #include <iostream>
    #include <string>
    #include <vector>
    using namespace std;

    class Item {
        public:
        string itemName;  // Name of item
        int priceDollars; // Price of item
    };

    const unsigned int MAX_ITEMS_IN_SHOPPING_BAG = 3; // Max num items

    /* Output every combination of items that fit
    in a shopping bag. Each recursive call moves
    one item into the shopping bag.
    */
    void ShoppingBagCombinations(vector<Item> currBag,          // Bag contents
                                vector<Item> remainingItems) { // Available items
        int bagValue;        // Cost of items in shopping bag
        Item tmpGroceryItem; // Grocery item to add to bag
        unsigned int i;      // Loop index
        
        if( currBag.size() == MAX_ITEMS_IN_SHOPPING_BAG ) { // Base case: Shopping bag full
            bagValue = 0;
            for(i = 0; i < currBag.size(); ++i) {
                bagValue += currBag.at(i).priceDollars;
                cout << currBag.at(i).itemName << "  ";
            }
            cout << "= $" << bagValue << endl;
        }
        else {                                              // Recursive case: move one
            for(i = 0; i < remainingItems.size(); ++i) {     // item to bag
                // Move item into bag
                tmpGroceryItem = remainingItems.at(i);
                remainingItems.erase(remainingItems.begin() + i);
                currBag.push_back(tmpGroceryItem);
                
                ShoppingBagCombinations(currBag, remainingItems);
                
                // Take item out of bag
                remainingItems.insert(remainingItems.begin() + i,tmpGroceryItem);
                currBag.pop_back();
            }
        }
    }

    int main() {
        vector<Item> possibleItems(0); // Possible shopping items
        vector<Item> shoppingBag(0);   // Current shopping bag
        Item tmpGroceryItem;           // Temp item
        
        // Populate grocery with different items
        tmpGroceryItem.itemName = "Milk";
        tmpGroceryItem.priceDollars = 2;
        possibleItems.push_back(tmpGroceryItem);
        
        tmpGroceryItem.itemName = "Belt";
        tmpGroceryItem.priceDollars = 24;
        possibleItems.push_back(tmpGroceryItem);
        
        tmpGroceryItem.itemName = "Toys";
        tmpGroceryItem.priceDollars = 19;
        possibleItems.push_back(tmpGroceryItem);
        
        tmpGroceryItem.itemName = "Cups";
        tmpGroceryItem.priceDollars = 12;
        possibleItems.push_back(tmpGroceryItem);
        
        // Try different combinations of three items
        ShoppingBagCombinations(shoppingBag, possibleItems);
        
        return 0;
    }
    //SAMPLE OUTPUT:
    /* Milk  Belt  Toys  = $45
    Milk  Belt  Cups  = $38
    Milk  Toys  Belt  = $45
    Milk  Toys  Cups  = $33
    Milk  Cups  Belt  = $38
    Milk  Cups  Toys  = $33
    Belt  Milk  Toys  = $45
    Belt  Milk  Cups  = $38
    Belt  Toys  Milk  = $45
    Belt  Toys  Cups  = $55
    Belt  Cups  Milk  = $38
    Belt  Cups  Toys  = $55
    Toys  Milk  Belt  = $45
    Toys  Milk  Cups  = $33
    Toys  Belt  Milk  = $45
    Toys  Belt  Cups  = $55
    Toys  Cups  Milk  = $33
    Toys  Cups  Belt  = $55
    Cups  Milk  Belt  = $38
    Cups  Milk  Toys  = $33
    Cups  Belt  Milk  = $38
    Cups  Belt  Toys  = $55
    Cups  Toys  Milk  = $33
    Cups  Toys  Belt  = $55 */
-----------------------------------------------------------------------------------------
    ```9. 8. 3: Find distance of traveling to 3 cities```
    #include <iostream>
    #include <iomanip>
    #include <vector>
    using namespace std;

    const unsigned int NUM_CITIES = 3;         // Number of cities
    int cityDistances[NUM_CITIES][NUM_CITIES]; // Distance between cities
    string cityNames[NUM_CITIES];              // City names

    /* Output every possible travel path.
    Each recursive call moves to a new city.
    */
    void TravelPaths(vector<int> currPath, vector<int> needToVisit) {
    int totalDist;     // Total distance given current path
    int tmpCity;       // Next city distance
    unsigned int i;    // Loop index
    
    if( currPath.size() == NUM_CITIES ) { // Base case: Visited all cities
        totalDist = 0;                     // return total path distance
        for (i = 0; i < currPath.size(); ++i) {
            cout << cityNames[currPath.at(i)] << "   ";
            
            if (i > 0) {
                totalDist += cityDistances[currPath.at(i - 1)][currPath.at(i)];
            }
        }
        
        cout << "= " << totalDist << endl;
    }
    else {                                // Recursive case: pick next city
        for(i = 0; i < needToVisit.size(); ++i) {
            // Add city to travel path
            tmpCity = needToVisit.at(i);
            needToVisit.erase(needToVisit.begin() + i);
            currPath.push_back(tmpCity);
            
            TravelPaths(currPath, needToVisit);
            
            // Remove city from travel path
            needToVisit.insert(needToVisit.begin() + i, tmpCity);
            currPath.pop_back();
        }
    }
    }

    int main() {
    vector<int> needToVisit(0); // Cities left to visit
    vector<int> currPath(0);    // Current path traveled
    
    // Initialize distances array
    cityDistances[0][0] = 0;
    cityDistances[0][1] = 960;  // Boston-Chicago
    cityDistances[0][2] = 2960; // Boston-Los Angeles
    cityDistances[1][0] = 960;  // Chicago-Boston
    cityDistances[1][1] = 0;
    cityDistances[1][2] = 2011; // Chicago-Los Angeles
    cityDistances[2][0] = 2960; // Los Angeles-Boston
    cityDistances[2][1] = 2011; // Los Angeles-Chicago
    cityDistances[2][2] = 0;
    
    cityNames[0] = "Boston";
    cityNames[1] = "Chicago";
    cityNames[2] = "Los Angeles";
    
    needToVisit.push_back(0); // Boston
    needToVisit.push_back(1); // Chicago
    needToVisit.push_back(2); // Los Angeles

    // Explore different paths   
    TravelPaths(currPath, needToVisit);
    
    return 0;
    }
    //SAMPLE OUTPUT
    /* 
    Boston   Chicago   Los Angeles   = 2971
    Boston   Los Angeles   Chicago   = 4971
    Chicago   Boston   Los Angeles   = 3920
    Chicago   Los Angeles   Boston   = 4971
    Los Angeles   Boston   Chicago   = 3920
    Los Angeles   Chicago   Boston   = 2971 */
}