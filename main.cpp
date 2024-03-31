/*
# Author:              Type-Your-Name
# BannerID:            Type-Your-BannerID
# Course:              CS 181
# Assignment:          PA4
# Date Assigned:       Monday, March 18, 2024
# Date/Time Due:       Saturday, March 30, 2024 -- 11:55 pm
# Description:         This program will exercise Object-
                       Oriented concepts with C++.
# Certification of Authenticity:
    I certify that this assignment is entirely my own work.
*/

#include <iostream>
#include <iomanip>
#include <string>
using namespace std;

#include "Employee.h"
#include "Manager.h"

int main() {
    int manCount;
    cout << "Enter number of managers: ";
    cin >> manCount;

    Manager* managers[manCount];

    for (int i = 0; i < manCount; ++i) {
        string manName;
        double wage, hours, bonus;

        cout << "Enter manager " << i << " name: ";
        cin.ignore();
        getline(cin, manName);

        cout << "Enter manager " << i << " hourly wage: ";
        cin >> wage;

        cout << "Enter manager " << i << " hours worked: ";
        cin >> hours;

        cout << "Enter manager " << i << " bonus: ";
        cin >> bonus;

        managers[i] = new Manager(manName, wage, hours, bonus);
    }

    double highestPay = managers[0]->calcPay();
    string topManager = managers[0]->getName();
    double totalManagerPay = highestPay;

    for (int i = 1; i < manCount; ++i) {
        double pay = managers[i]->calcPay();
        totalManagerPay += pay;

        if (pay > highestPay) {
            highestPay = pay;
            topManager = managers[i]->getName();
        }
    }

    cout << fixed << setprecision(2);
    cout << "Highest paid manager is " << topManager << " who is paid $" << highestPay << endl;
    cout << "Average pay is $" << (totalManagerPay / manCount) << endl;

    for (int i = 0; i < manCount; ++i) {
        delete managers[i];
    }

    return 0;
}
