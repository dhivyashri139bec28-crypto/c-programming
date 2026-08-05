/******************************************************************************

Welcome to GDB Online.
GDB online is an online compiler and debugger tool for C, C++, Python, Java, PHP, Ruby, Perl,
C#, OCaml, VB, Swift, Pascal, Fortran, Haskell, Objective-C, Assembly, HTML, CSS, JS, SQLite, Prolog.
Code, Compile, Run and Debug online from anywhere in world.

*******************************************************************************/
// Bank Management System - Linked List Implementation
#include <iostream>
using namespace std;

struct date {
    int dd, mm, yyyy;
};

// ------------------- ACCOUNT CLASS (Linked List Node) -------------------
class AccountList {
private:
    struct Node {
        int accountNo;
        string accountHolder;
        string accountType;
        date dateOfWithdrawal;
        float withdrawalAmount;
        float balanceAmount;
        Node* next;
    } *head, *temp, *p;

public:
    AccountList() {
        head = NULL;
        temp = NULL;
        p = NULL;
    }

    void createAccount();
    void displayAccounts();
    void searchAccount(int accNo);
    void withdrawAmount(int accNo, float amt);
};

// ------------------- CREATE NEW ACCOUNT -------------------
void AccountList::createAccount() {
    temp = new Node;

    cout << "\nEnter Account Number: ";
    cin >> temp->accountNo;

    cout << "Enter Account Holder Name: ";
    cin >> temp->accountHolder;

    cout << "Enter Account Type (Savings/Current): ";
    cin >> temp->accountType;

    cout << "Enter Last Withdrawal Date (dd mm yyyy): ";
    cin >> temp->dateOfWithdrawal.dd >> temp->dateOfWithdrawal.mm >> temp->dateOfWithdrawal.yyyy;

    cout << "Enter Withdrawal Amount: ";
    cin >> temp->withdrawalAmount;

    cout << "Enter Current Balance Amount: ";
    cin >> temp->balanceAmount;

    temp->next = NULL;

    // Insert at end of list
    if (head == NULL) {
        head = temp;
        return;
    }
    p = head;
    while (p->next != NULL)
        p = p->next;

    p->next = temp;
}

// ------------------- DISPLAY ALL ACCOUNTS -------------------
void AccountList::displayAccounts() {
    if (head == NULL) {
        cout << "\nNo accounts available.";
        return;
    }

    cout << "\n------ ACCOUNT DETAILS ------\n";
    p = head;
    while (p != NULL) {
        cout << "\nAccount Number: " << p->accountNo;
        cout << "\nHolder Name: " << p->accountHolder;
        cout << "\nAccount Type: " << p->accountType;
        cout << "\nLast Withdrawal Date: " 
             << p->dateOfWithdrawal.dd << "/" 
             << p->dateOfWithdrawal.mm << "/"
             << p->dateOfWithdrawal.yyyy;
        cout << "\nWithdrawal Amount: " << p->withdrawalAmount;
        cout << "\nBalance Amount: " << p->balanceAmount << "\n";
        p = p->next;
    }
}

// ------------------- SEARCH ACCOUNT -------------------
void AccountList::searchAccount(int accNo) {
    p = head;
    while (p != NULL) {
        if (p->accountNo == accNo) {
            cout << "\nAccount Found!";
            cout << "\nAccount Number: " << p->accountNo;
            cout << "\nHolder Name: " << p->accountHolder;
            cout << "\nAccount Type: " << p->accountType;
            cout << "\nLast Withdrawal Date: "
                 << p->dateOfWithdrawal.dd << "/"
                 << p->dateOfWithdrawal.mm << "/"
                 << p->dateOfWithdrawal.yyyy;
            cout << "\nWithdrawal Amount: " << p->withdrawalAmount;
            cout << "\nBalance Amount: " << p->balanceAmount << "\n";
            return;
        }
        p = p->next;
    }
    cout << "\nAccount not found!";
}

// ------------------- WITHDRAW AMOUNT -------------------
void AccountList::withdrawAmount(int accNo, float amt) {
    p = head;
    while (p != NULL) {
        if (p->accountNo == accNo) {
            if (p->balanceAmount >= amt) {
                p->balanceAmount -= amt;
                p->withdrawalAmount = amt;

                cout << "\nWithdrawal Successful!";
                cout << "\nUpdated Balance: " << p->balanceAmount << endl;

                cout << "Enter New Withdrawal Date (dd mm yyyy): ";
                cin >> p->dateOfWithdrawal.dd
                    >> p->dateOfWithdrawal.mm
                    >> p->dateOfWithdrawal.yyyy;
            }
            else {
                cout << "\nInsufficient Balance!";
            }
            return;
        }
        p = p->next;
    }
    cout << "\nAccount not found!";
}

// ------------------- MAIN FUNCTION -------------------
int main() {
    AccountList bank;
    int choice, accNo;
    float amt;

    while (true) {
        cout << "\n\n===== BANK MENU =====";
        cout << "\n1. Create Account";
        cout << "\n2. Display All Accounts";
        cout << "\n3. Search Account";
        cout << "\n4. Withdraw Amount";
        cout << "\n5. Exit";
        cout << "\nEnter choice: ";
        cin >> choice;

        switch (choice) {
        case 1:
            bank.createAccount();
            break;

        case 2:
            bank.displayAccounts();
            break;

        case 3:
            cout << "Enter Account Number: ";
            cin >> accNo;
            bank.searchAccount(accNo);
            break;

        case 4:
            cout << "Enter Account Number: ";
            cin >> accNo;
            cout << "Enter Amount to Withdraw: ";
            cin >> amt;
            bank.withdrawAmount(accNo, amt);
            break;

        case 5:
            return 0;

        default:
            cout << "\nInvalid choice!";
        }
    }
}
