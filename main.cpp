//============================================================================
// Name        : CS115_IP5_LuisCamachoJr.cpp
// Author      : Luis Camacho Jr.
// University  : Colorado Technical University
// Course#     : CS115-1601A-01
// Course      : Programming with C++
// Instructor  : Instructor Charles Hale
// Version     : Week 5 Feburary 08, 2016
// Copyright   : Educational Purposes
// Description : C++, Ansi-style Successful Compile, Run, and updated application with objects, classes, functions, pointers
//============================================================================

#include <iostream>
#include <iomanip>

using namespace std;

// Declaring class
// class created to store and retrieve customer data
// Functions created that set and get values from variables for use in application
class StoredCustomerData{
public:

    //Functions created to set values to the class private variables
    //Functions utilized within class for initial customer interaction
    void setCustomerFirstName() {

        cout << "Welcome to Fix All Systems Inc." << endl;
        cout << "*******************************" << endl;
        cout << "*******************************" << endl;
        cout << "Create your Customer Account for faster check out and SAVINGS!!!"<< endl;
        cout << "*******************************" << endl;
        cout << "Enter your First Name" << endl;
        cin >> customerFirstName;
    }
    void setCustomerLastName() {

        cout << "Enter your Last Name" << endl;
        cin >> customerLastName;
    }
    void setHouseNumber() {

        cout << "Enter your House Number" << endl;
        cin >> houseNumber;
    }
    void setStreetAddress() {

        cout << "Enter your Street Address" << endl;
        cin >> streetAddress;
    }
    void setCity() {

        cout << "Enter your City" << endl;
        cin >> city;
    }
    void setState() {

        cout << "Enter your State" << endl;
        cin >> state;
    }
    void setZipCode() {

        cout << "Enter your zipcode" << endl;
        cin >> zipCode;
        cout << "*******************************" << endl;
        cout << "*******************************" << endl;
    }

    //Functions created to retrieve values from class private variables utilizing get

    string getCustomerFirstName(){
        return customerFirstName;
    }
    string getCustomerLastName(){
        return customerLastName;
    }

    int getHouseNumber(){
        return houseNumber;
    }
    string getStreetAddress(){
        return streetAddress;
    }

    string getCity(){
        return city;
    }
    string getState(){
        return state;
    }
    int getZipCode(){
        return zipCode;
    }

private:
    string customerFirstName, customerLastName, streetAddress, city, state;
    int houseNumber, zipCode;
};

// Declaring class
// class created to retrieve services list and display description and price of services
// function displayServiceList that will verify that the options offered are selected if not loop back into user question
class ServiceList{
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

    // Object's created in order to access classes
    StoredCustomerData *customerData = new StoredCustomerData; // Memory being allocated for object

    ServiceList *listDescriptionPrice = new ServiceList; // Memory being allocated for object


    // Collecting Customer data in order to create an account
    // objects utilized to store user input into class
    // object customerData calls function that collects and sets
    // user input values into private variable in class StoredCustomerData
    customerData ->setCustomerFirstName(); // accessing member class "StoreCustomerData" using member access operator

    customerData->setCustomerLastName(); // accessing member class "StoreCustomerData" using member access operator

    customerData->setHouseNumber(); // accessing member class "StoreCustomerData" using member access operator

    customerData->setStreetAddress(); // accessing member class "StoreCustomerData" using member access operator

    customerData->setCity(); // accessing member class "StoreCustomerData" using member access operator

    customerData->setState(); // accessing member class "StoreCustomerData" using member access operator

    customerData->setZipCode(); // accessing member class "StoreCustomerData" using member access operator

    // Display newly created customer account and uses object
    // to get values from private variables in class
    // accessing member class "StoreCustomerData" using member access operator to retrieve stored data in memory
    cout << "Your new Customer Account has been created:" << endl;
    cout << "Account Number "<<&customerData << endl; // Utilized reference operator to display memory address for customer account number
    cout << "Welcome " + customerData->getCustomerFirstName() << " " + customerData->getCustomerLastName() << endl;
    cout << "Of " << customerData->getHouseNumber() << " " + customerData->getStreetAddress() << endl;
    cout << "From " + customerData->getCity() << ", " + customerData->getState() << endl;
    cout << customerData->getZipCode() << endl;
    cout << "*******************************" << endl;
    cout << "*******************************" << endl;

    // Display list of services provided and descriptions
    // iterates through bi-dimensional array in order to display list of services and description
    // iterates through array to list prices of service offered
    listDescriptionPrice->displayServiceList();// object accesses class ServiceList - function displays list of services provided

    delete customerData; // delete operator utilized free memory from dynamic memory allocation
    delete listDescriptionPrice; // delete operator utilized free memory from dynamic memory allocation
    return 0;
}   