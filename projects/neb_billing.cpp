// NEB Electricity Billing System
// Calculates electricity charges using a tiered rate system based on usage (kWh),
// processes multiple customers via a sentinel-controlled loop, and tracks totals.

#include <iostream>
#include <iomanip>
#include <string>
using namespace std;

int main() {
    string customerId, name, address;
    double usage, amountOwed;
    int totalCustomers = 0;
    double totalAmount = 0.0;
    char another;

    cout << fixed << setprecision(2);
    cout << "======= NEB ELECTRICITY BILLING SYSTEM =======\n";

    do {
        cout << "\nEnter Customer ID: ";
        cin >> customerId;
        cin.ignore(1000, '\n'); 

        cout << "Enter Name/Owner: ";
        getline(cin, name);

        cout << "Enter Address: ";
        getline(cin, address);

        cout << "Enter Electricity Usage (kWh): ";
        while (!(cin >> usage) || usage < 0) {
            cin.clear();
            cin.ignore(1000, '\n');
            cout << "Error: please enter a valid non-negative usage (kWh): ";
        }
        cin.ignore(1000, '\n'); 

        if (usage <= 200) {
            amountOwed = usage * 0.218;
        } else if (usage <= 800) {
            amountOwed = usage * 0.258;
        } else {
            amountOwed = (800 * 0.258) + ((usage - 800) * 0.278);
        }

        cout << "\n--- Customer Report ---\n";
        cout << "Customer ID   : " << customerId << "\n";
        cout << "Name/Owner    : " << name << "\n";
        cout << "Address       : " << address << "\n";
        cout << "Usage (kWh)   : " << usage << "\n";
        cout << "Amount Owing  : ₦" << amountOwed << "\n";

        totalCustomers++;
        totalAmount += amountOwed;

        cout << "\nProcess another customer? (y/n): ";
        while (!(cin >> another) || (another != 'y' && another != 'Y'
                && another != 'n' && another != 'N')) {
            cin.clear();
            cin.ignore(1000, '\n');
            cout << "Please enter y or n: ";
        }
        cin.ignore(1000, '\n'); 

    } while (another == 'y' || another == 'Y');

    cout << "\n======= END OF REPORT =======\n";
    cout << "Total Customers : " << totalCustomers << "\n";
    cout << "Total Amount    : ₦" << totalAmount << "\n";

    return 0;
}