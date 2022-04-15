
#include "Functions_Movies_Watched.h"
#include <iostream>
#include <string>

using std::cout;
using std::cin;
using std::endl;
using std::string;

class Data_Set{
private:
    int * ptr_to_data;
    string data_name {"Unknown"};
    
public:
    Data_Set(string name, int numElements) {
        this->data_name = name;
        this->ptr_to_data = new int [numElements]; //Dynamically allocates the array

        // Getting the data-points
        string userInput {"Unset"};
        int validDataPoint {-1};
        for(int i {0}; i < numElements; i++){
            do{
                cout << "Enter data-point #" << i + 1<< " for " << name << endl;
                cout << "Data-point #" << i + 1 << ": ";
                getline(cin, userInput);
                cin.clear();
                validDataPoint = posIntegerConvert(userInput);
            }while(validDataPoint < 0);
            ptr_to_data[i] = validDataPoint; // Validated input put into the array
        }
    }

    
};


int main(){
    string dataName {"Unset"};
    string unvalidatedNum {"Unset"};
    int validatedNum {-1};


    //  ===================================
    //  | Getting Data-Set name and the   |
    //  | number of elements              |
    //  ==================================
    cout << "\nEnter what kind of data you are going to input integer data-points for." << endl
         << "For example: \"Number of Movies Watched per Student Each Month\"" << endl
         << endl
         << "Name of Data: ";
    getline(cin, dataName);

    do{
        cout << endl
             << "===========================================================" << endl 
             << "Enter the number of data-points for: " << endl
             << "\"" << dataName << "\"" << endl
             << "Number of data-points: ";
        getline(cin, unvalidatedNum);
        validatedNum = posIntegerConvert(unvalidatedNum);
    }while(validatedNum < 0);
    // ===================================
    // | End of Data-Point Input         |
    // ===================================

    // Dynamically creating the object
    Data_Set *Data = new Data_Set(dataName, validatedNum);
    
    return 0;
}
