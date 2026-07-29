// School Fees Calculator
// Calculates fees per student based on class level (Junior/Senior)
// and boarder status, then tracks a running grand total for all students.

#include <iostream>
#include <cstdlib> 
using namespace std;

int main()
{
    const int juniorFees = 15000;
    const int seniorFees = 25000;
    int studentId;
    char classLevel;
    char boarderStatus;
    int studentFee;
    int grandTotal = 0;
    char choice;

    do
    {
        cout << "Enter Student Id: " << endl;
        cin >> studentId;

        cout << "Enter Class Level (J/S): " << endl;
        cin >> classLevel;

        if (classLevel == 'J' || classLevel == 'j')
        {
            studentFee = juniorFees;
        }
        else
        {
            studentFee = seniorFees;
        }

        cout << "Are you a Boarder? (Y/N): " << endl;
        cin >> boarderStatus;

        if (boarderStatus == 'Y' || boarderStatus == 'y')
        {
            studentFee = studentFee + 10000;
        }

        cout << "Student Id: " << studentId << endl;
        cout << "Class Level: " << classLevel << endl;
        cout << "Boarder Status: " << boarderStatus << endl;
        cout << "Student Fee: " << studentFee << endl;

        grandTotal = grandTotal + studentFee;

        cout << "Add another student? (Y/N): " << endl;
        cin >> choice;

    } while (choice == 'Y' || choice == 'y');

    cout << "Grand Total for all students: " << grandTotal << endl;

    system("pause");
    return 0;
}