
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
    int numElements {-1}; //This will be useful to save for loops later
    
public:
    Data_Set(string name, int numElements) {
        this->data_name = name;
        this->numElements = numElements;
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
            }while(validDataPoint <= 0);
            ptr_to_data[i] = validDataPoint; // Validated input put into the array
        }
    }

    void sortData();
    void displayData();
    void dataMenu();
    void getMean();

    
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
    Data->sortData(); // Going ahead and sorting the data - I thought about making it a user option, but
                      // I was only going to give one sorting option, so I'll just do it automatically


    Data->dataMenu();
    
    
    return 0;
}

void Data_Set::sortData() {
    bool arraySorted {true};
    for(int i = 0; i < numElements - 1; i++){
        int temp {-1};

        if(ptr_to_data[i] > ptr_to_data[i+1]){
            temp = *(ptr_to_data + i);
            *(ptr_to_data + i) = *(ptr_to_data + i + 1);
            *(ptr_to_data + i + 1) = temp;
            arraySorted = false;
        }
        if(!arraySorted){
            sortData();
        }
    }
}

void Data_Set::displayData() {

    cout << endl
         << data_name << endl
         << "==========================" << endl;
    
    for(int i = 0; i < numElements; i++){
        cout << *(ptr_to_data + i) << endl;
        if(i == numElements - 1){
            cout << "==========================" << endl;
        }
    }
}


void Data_Set::dataMenu() {
    string userSelection {"Unknown"};
    bool exit {false};
    
    do{
        cout << endl
             << "============================================" << endl
             << "| Choose an option below by selecting the  |" << endl
             << "|  corresponding number.                   |" << endl
             << "============================================" << endl
             << "| 1.) Display Data                         |" << endl
             << "| 2.) Display Mean                         |" << endl
             << "| 3.) End Program                          |" << endl
             << "============================================" << endl
             << "My Selection: ";
        getline(cin, userSelection);
    }while(userSelection != "1" && userSelection != "2" && userSelection != "3");

    if(userSelection == "1"){
        displayData();
    }
    else if(userSelection == "2"){
        getMean();
    }
    else if(userSelection == "3"){
        exit = true;
    }
    
    if(exit == false){
        dataMenu();    
    }
    
}

void Data_Set::getMean() {
    double dataMean {-1.00};
    double dataSum {0};

    // Sum the data
    for (int i = 0; i < numElements; i++){
        dataSum += *(ptr_to_data + i);
    }
    dataMean = dataSum/ static_cast<double> (numElements);

    displayData();
    cout << "Mean: " << dataMean << endl
         << "==========================" << endl;
    
}
