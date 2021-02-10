#include <iostream>
#include <fstream>
#include <vector>
#include <string>
#include <algorithm>

using namespace std;

void readData(const string &file, vector<double> &angle, vector<double> &coefficient) {
    //1. Passes in the name of a file using string
    //2. Open the file
    ifstream inFS;
    inFS.open(file);
        //2a. If file doesn't open, output an error message and pass an exit value of 1.
        if (!inFS.is_open()) {
            cout << "Error opening " << file << endl;
            exit(1);
        }
    //3. Retreive the first column and store it into vector 1.
    //4. Retrieve the second column and store it into vector 2.
    double angleNum, coefNum;
    while (inFS >> angleNum >> coefNum) {   //**As file reads, stores first num as angle
        angle.push_back(angleNum);          //**and second num as coefficient
        coefficient.push_back(coefNum);     //**then just push-back values into appropriate vectors
    }
    inFS.close();
    return;
}

double interpolation(double userFlight, const vector<double> &angle, const vector<double> &coefficient) {
    //1. Passes in the requested flight-path angle along with 2 vectors of data
    //2. Turn f(b) into a variable
    double userFlightCoef = 0; 
    //3. Go through vector and check if given flight-path b already exists in the data set
    for (unsigned int i = 0; i < angle.size(); ++i) {
        if (angle.at(i) == userFlight) {
            return coefficient.at(i);               //if it does, return corresponding coefficient.
        }
    }
    //3a. if it doesn't, establish flight angle A and C based on a < b < c
    for (unsigned int i = 1; i < angle.size(); ++i) {
        double a = angle.at(i - 1);                 
        double c = angle.at(i);                     //placeholders for clarity
        double aCoef = coefficient.at(i - 1);
        double cCoef = coefficient.at(i);

        if (a < userFlight && c > userFlight) {
            userFlightCoef = (aCoef + ((userFlight - a) / (c - a)) * (cCoef - aCoef));     //calculate b coefficient from formula
        }
    }
    return userFlightCoef; 
}   

bool isOrdered(const vector<double> &angle) {
    //1. Establish a bool value and set it to true.
    bool ordered = true;
    //2. Make a for-loop to check all vector contents
    for (unsigned int i = 1; i < angle.size(); ++i) {
        double currVal = angle.at(i);       
        double small = angle.at(i-1);
        //2a. If the succeeding value is ever smaller than the preceding value, then it is not in order.
        if (currVal < small) {
            return false;
        }
    } //3. Return true otherwise.
    return ordered;
}

void reorder(vector<double> &angle, vector<double> &coefficient) {
    //1. Remember that the ANGLES are being swapped, so only focus on angles
        //You can worry about the coefficients corresponding later.
    for (unsigned i = 0; i < angle.size(); ++i) {
        int minIndx = i;    //To keep track of where the minimum value is 
        for (unsigned j = i + 1; j < angle.size(); ++j) { //Check succeeding variable
            if (angle.at(j) < angle.at(minIndx)) {        //If next value is smaller than minimum
                minIndx = j;                              //Then value becomes next smallest value
            }
        }
        swap(angle.at(minIndx), angle.at(i));             //Swap values so they're in ascending order.
        swap(coefficient.at(minIndx), coefficient.at(i)); 
    }
    return;
}

int main(int argc, char* argv[]) {

    string inputFile;
    inputFile = argv[1];
    vector<double> angle;
    vector<double> coefficient;

    readData(inputFile, angle, coefficient);

    double userFlight;
    cin >> userFlight;
    
    interpolation(userFlight, angle, coefficient);

    isOrdered(angle);

    reorder(angle, coefficient);

    string userAnswer;
    while (userAnswer != "no" && userAnswer != "No") {
        cout << "Do you want to enter another flight-path angle?" << endl;
        cin >> userAnswer;
        if (userAnswer == "yes" || userAnswer == "Yes") {
            cout << "Enter a flight-path angle" << endl;
            cin >> userFlight; 
            cout << interpolation(userFlight, angle, coefficient) << endl;
        }
    }
    return 0;
}