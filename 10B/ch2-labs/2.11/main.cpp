#include <fstream>
#include <iostream>
#include <cstdlib>
#include <vector>

using namespace std;

int charCnt(string userFile, char userInput); //Related to string "filename" + char "ch" in main

int main() {
   string filename;
   char ch;
   int chCnt = 0;
   
   cout << "Enter the name of the input file: ";
   cin >> filename;
   cout << endl;
   cout << "Enter a character: ";
   cin.ignore(); // ignores newline left in stream after previous input statement
   cin.get(ch);
   cout << endl;

   chCnt = charCnt(filename, ch);   
   cout << "# of " << ch << "'s: " << chCnt << endl;
   
   return 0;
}

int charCnt(string userFile, char userInput) {

   ifstream fileStream;
   int count = 0;

   //actually open file
   fileStream.open(userFile);
   if (!fileStream.is_open()) {                          //If the file does not exist, this function should output an error message 
      cout << "Error opening " << userFile << endl;      //and then call the exit function to exit the program with an error value of 1.
      exit(1);
   }

   //vector<char> checkMatch;
   while (getline(fileStream, userFile)) {
      vector<char> checkMatch(userFile.begin(), userFile.end());
         for (unsigned int i = 0; i < checkMatch.size(); ++i) {
            if (checkMatch.at(i) == userInput) {
            ++count;
        }
      }
   }
   fileStream.close();
   return count;
}
