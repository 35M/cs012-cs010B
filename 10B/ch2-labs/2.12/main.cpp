#include <iostream>
#include <fstream>
#include <vector>

using namespace std;

int main(int argc, char *argv[]) {
   
   string inputFile;
   string outputFile;
   
   // Assign to inputFile value of 2nd command line argument
   inputFile = argv[1];
   // Assign to outputFile value of 3rd command line argument
   outputFile = argv[2];
   // Create input stream and open input csv file.
   ifstream inFS;
   inFS.open(argv[1]);
   // Verify file opened correctly.
   if (!inFS.is_open()) {
      // Output error message and return 1 if file stream did not open correctly.
      cout << "Error opening " << argv[1] << endl;
      return 1;
   }
   // Read in integers from input file to vector.
   vector<int> inputVec;
   int nums;
   char comma;
   while (inFS >> nums) {
      inputVec.push_back(nums);
      inFS >> comma;
      }
   // Close input stream.
   inFS.close();
   // Get integer average of all values read in.
   int sum = 0;
   for (unsigned int i = 0; i < inputVec.size(); ++i) {
      sum = sum + inputVec.at(i);
   }
   int avg = sum / inputVec.size();
   // Convert each value within vector to be the difference between the original value and the average.
   for (unsigned int i = 0; i < inputVec.size(); ++i) {
      inputVec.at(i) = inputVec.at(i) - avg;
   }
   // Create output stream and open/create output csv file.
   ofstream oFS;
   oFS.open(outputFile);
   // Verify file opened or was created correctly.
   if (!oFS.is_open()) {
      // Output error message and return 1 if file stream did not open correctly.
      cout << "Error opening " << outputFile << endl;
      return 1;
   }

   // Write converted values into ouptut csv file, each integer separated by a comma.
   for (unsigned int i = 0; i < inputVec.size(); ++i) {
      oFS << inputVec.at(i); 
      if (i + 1 < inputVec.size()) {
      oFS << ", ";
      }
   }
   // Close output stream.
   oFS.close();

   return 0;
}