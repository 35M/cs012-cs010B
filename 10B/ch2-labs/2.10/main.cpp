#include <fstream>
#include <iostream>
#include <cstdlib> //needed for exit function

using namespace std;

int fileSum(string userFile); //Related to "string filename in main"

int main() {

   string filename;
   int sum = 0;
   
   cout << "Enter the name of the input file: ";
   cin >> filename;
   cout << endl;
   
   sum = fileSum(filename);
   cout << "Sum: " << sum << endl;
   
   return 0;
}

int fileSum(string userFile) {

ifstream fileStream;

//actually open file
fileStream.open(userFile);
if (!fileStream.is_open()) {                           //If the file does not exist, this function should output an error message  
   cout << "Error opening " << userFile << endl;       //and then call the exit function to exit the program with an error value of 1.
   exit(1);
}

int nums;
int sum = 0;
while (fileStream >> nums) {
   sum += nums;
}

fileStream.close();
return sum;
}