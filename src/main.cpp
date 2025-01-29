//============================================================================
// Name        : CS115_IP5_LuisCamachoJr.cpp
// Author      : Luis Camacho Jr.
// University  : Colorado Technical University
// Course#     : CS115-1601A-01
// Course      : Programming with C++
// Instructor  : Instructor Charles Hale
// Version     : Week 5 February 08, 2016
// Last updated: January 28, 2025
// Copyright   : Educational Purposes
// Description : C++, Ansi-style Successful Compile, Run, and updated application with objects, classes, functions, pointers, input validation, error logging 
//============================================================================

#include <iostream>
#include <iomanip>
#include <string>
#include <regex>
#include <fstream>

using namespace std;

// Function to log errors
void logError(const string& errorMessage) {
    ofstream errorLog("error.log", ios::app);
    if (errorLog.is_open()) {
        errorLog << "[ERROR] " << errorMessage << endl;
        errorLog.close();
    }
    cerr << "[ERROR] " << errorMessage << endl;
}

// Function to validate input
bool validateInput(const string& input, const string& pattern) {
    regex validPattern(pattern);
    return regex_match(input, validPattern);
}

// Class to store and retrieve customer data
class StoredCustomerData {
public:

    void setCustomerFirstName() {
        // Display the opening statement once
        cout << "Welcome to Fix All Systems Inc." << endl;
        cout << "*******************************" << endl;
        cout << "Create your Customer Account for faster check-out and SAVINGS!!!" << endl;
        cout << "*******************************" << endl;

        while (true) {
            // Prompt for first name
            cout << "Enter your First Name: ";
            cin >> customerFirstName;

            // Validate input
            if (validateInput(customerFirstName, "^[A-Za-z]{1,50}$")) {
                break; // Exit the loop if input is valid
            } else {
                string errorMsg = "Invalid first name: " + customerFirstName;
                logError(errorMsg); // Log the error
                cout << "Invalid input. Please try again." << endl;
            }
        }
    }

    void setCustomerLastName() {
        while (true) {
            cout << "Enter your Last Name: ";
            cin >> customerLastName;

            // Validate input
            if (validateInput(customerLastName, "^[A-Za-z]{1,50}$")) {
                break; // Exit the loop if input is valid
            } else {
                string errorMsg = "Invalid last name: " + customerLastName;
                logError(errorMsg);
                cout << "Invalid input. Please try again." << endl;
            }
        }
    }

    void setZipCode() {
        while (true) {
            cout << "Enter your Zip Code: ";
            cin >> zipCode;

            // Validate input
            if (validateInput(zipCode, "^\\d{5}$")) {
                break; // Exit the loop if input is valid
            } else {
                string errorMsg = "Invalid zip code: " + zipCode;
                logError(errorMsg);
                cout << "Invalid input. Please try again." << endl;
            }
        }
    }

    string getCustomerFirstName() { return customerFirstName; }
    string getCustomerLastName() { return customerLastName; }
    string getZipCode() { return zipCode; }

private:
    string customerFirstName, customerLastName, zipCode;
};

// Declaring class
// class created to retrieve services list and display description and price of services
// function displayServiceList that will verify that the options offered are selected if not loop back into user question
class ServiceList {
public:
    void displayServiceList() {
        do {
            cout << " Fix ALL Service List:" << endl;
            for (int r = 0; r < 3; r++) // loops through columns
            {
                cout << problemRepair[0][r] << " - " << problemRepair[1][r] << " - " << "$" << costOfRepair[r] <<
                endl; //statically set rows
            }
            cout << "*******************************" << endl;
            cout << "*******************************" << endl;
            cout << " Select the option number that corresponds with the service required:"<< endl;
            cin >> serviceSel[1];
            cout << "*******************************" << endl;
            cout << "*******************************" << endl;
        }
            // do while loop used during service option selection
            // if incorrect option selected options are listed until proper option selection
        while (serviceSel[1] !=1 && serviceSel[1] !=2 && serviceSel[1] !=3);

        // for loop created to iterate Array for value
        int serviceSelected = 0;
        for (int i = 0; i < 1; i++)
        {
            serviceSelected = serviceSel[1] - 1;
        }
        cout << "****Order Summary****" << endl;
        cout << "Option " << problemRepair[0][serviceSelected] << endl;
        cout << "Description of service:" << endl;
        cout << problemRepair[1][serviceSelected] << endl;
        cout << "Total price includes tax" << endl;
        cout <<"$"<<costOfRepair[serviceSelected] << endl;
        cout << "*******************************" << endl;
        cout << "*******************************" << endl;
        cout << " Are you having multiple units serviced (y or n)" << endl;
        cin >> unitServiced;
        if (unitServiced == 'y') {
            cout << "How many units will be serviced" << endl;
            cin >> totalUnitsServiced[1];

            // for loop created to iterate Array for value
            int servicedUnits = 0;
            for (int i = 0; i < 1; i++)
            {
                servicedUnits = totalUnitsServiced[1];
            }

            // Set decimal precision utilized to correct output of calculation
            cout <<"$"<<costOfRepair[serviceSelected] << " x " << servicedUnits << " = " << "$"<<fixed<<setprecision(2)<<costOfRepair[serviceSelected] * servicedUnits << endl;
            cout << "      :)  :)  :)  :)      "<<endl;
            cout << "Thank you for your patronage" << endl;
        }
        else
        {
            cout << "Thank you for your patronage" << endl;
        }
    }

    // Bi-dimensional array utilized for storing service for sale and description
    string problemRepair[2][3] = {{"[1] Virus Removal ", "[2] Registry Clean", "[3] Memory Upgrade"},
                                  {"Scan and remove virus from infected system", "Restore registry to default", "Remove and upgrade memory modules"},
    };

    // Array used to store float type variables for services provided
    float costOfRepair[3] = { 99.99, 149.99, 210.99};

    char unitServiced = 'Y';

    // Array utilized to store how many units serviced
    int totalUnitsServiced[3] = {0, 0, 0};

    // Array utilized to store customer service selection
    int serviceSel[3] = {0, 0, 0};
};

int main() {
    // Welcome message
    cout << "Welcome to the Customer Information Program!" << endl;
    cout << "Please enter the requested details below." << endl;

    StoredCustomerData* customerData = new StoredCustomerData();

    // Collect and validate user input
    customerData->setCustomerFirstName();
    customerData->setCustomerLastName();
    customerData->setZipCode();

    // Display newly created customer account and use object
    // to get values from private variables in the class.
    // Accessing member class "StoredCustomerData" using the member access operator (->) to retrieve stored data in memory.
    cout << "Your new Customer Account has been created:" << endl;

    // Utilize the reference operator to display the memory address for the customer account number
    cout << "Account Number: " << customerData << endl;

    // Display the full customer information using getter methods
    cout << "Welcome " << customerData->getCustomerFirstName() << " " << customerData->getCustomerLastName() << endl;
    cout << "From ZIP Code: " << customerData->getZipCode() << endl;
    cout << "*******************************" << endl;
    cout << "*******************************" << endl;

    // Create and display the service list
    ServiceList services;
    services.displayServiceList();

    // Free allocated memory
    delete customerData;

    return 0;
}

