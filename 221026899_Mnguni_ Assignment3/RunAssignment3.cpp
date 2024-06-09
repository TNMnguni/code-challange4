#include <fstream>
#include <stack>
#include <string>
#include <iostream>
#include <sstream>
#include <iomanip>
#include "DVD.cpp"

using namespace std;



void readFromFile(string filename, stack<DVD>& dvdStack) {
    ifstream infile(filename);

    if (!infile.is_open()) {
        cout << "File " << filename <<" could not be opened" << endl;
        exit(1); // Exit program with an error code
    }

    string line;
    while (getline(infile, line)) {
        
        istringstream iss(line);
        string name, director, category, priceStr;
        float price;

        if (getline(iss, name, ' ') && getline(iss, director, ' ') && getline(iss, category, ' ') && getline(iss, priceStr)) {
           
            price = stof(priceStr);

            
            DVD dvd(name, director, category, price);
            dvd.setPrice(); 
            dvdStack.push(dvd);
        }
        
    }

    infile.close();
}

int main() {
    stack<DVD> dvdStack;

    string filename = "DVD.txt"; 

    readFromFile(filename, dvdStack);

    while (!dvdStack.empty()) {
        DVD dvd = dvdStack.top();
        dvdStack.pop();


        cout << dvd.getName() << "   " << dvd.getDirector() <<"    "<< dvd.getCategory()<<"   "<< fixed << setprecision(0) << dvd.getPrice() << endl;
    }

    return 0;

}
