// Bank_Project.cpp : This file contains the 'main' function. Program execution begins and ends there.
//
#include "BankAccount.h"



void saveToFile(vector<BankAccount>& accounts) {
	ofstream out("bank accounts.txt");
	for (vector<BankAccount>::const_iterator ci = accounts.begin(); ci != accounts.end(); ++ci) {
		BankAccount b = *ci;
		out << b;
	}
	out.close();
}
void printHoldersMoreOneAccount(vector<BankAccount>& accounts) {
    vector<char*> h;

    for (vector<BankAccount>::const_iterator ci = accounts.begin(); ci != accounts.end(); ++ci) {
        BankAccount b = *ci;
        h.push_back(b.getHolderName());
    }

    for (unsigned i = 0; i < h.size() - 1; i++) {
        for (unsigned j = i + 1; j < h.size(); j++) {
            if (strcmp(h.at(i), h.at(j)) > 0) {
                char* tmp = h.at(i);
                h.at(i) = h.at(j);
                h.at(j) = tmp;
            }
        }
    }
    for (unsigned i = 0; i < h.size() - 1; i++) {
        for (unsigned j = i + 1; j < h.size(); j++) {
            if (strcmp(h.at(i), h.at(j)) == 0) {
                cout << h.at(i) << endl;
            }
        }
    }
}
void accountBallances(vector<BankAccount>& accounts) {
    for (unsigned j = 0; j < accounts.size(); j++) {
        BankAccount b = accounts.at(j);
        double sum = 0;

        for (unsigned i = 0; i < b.getCommitments().size(); i++) {
            sum += b.getCommitments().at(i);
        }
        for (unsigned i = 0; i < b.getWithdraws().size(); i++) {
            sum -= b.getWithdraws().at(i);
        }
        cout << b.getId() << " " << b.getHolderName() << " has " << sum << endl;
    }
}

void saveToFileZeroBallace(vector<BankAccount>& accounts){
    ofstream out1("zero balance.txt");
    for (unsigned j = 0; j < accounts.size(); j++) {
        BankAccount b = accounts.at(j);
        double sum = 0;

        for (unsigned i = 0; i < b.getCommitments().size(); i++) {
            sum += b.getCommitments().at(i);
        }
        for (unsigned i = 0; i < b.getWithdraws().size(); i++) {
            sum -= b.getWithdraws().at(i);
        }
        if (sum == 0)
            out1 << b;
    }
    out1.close();
}

int main()
{
	BankAccount a((char*)"Todor Petkov");
	BankAccount b((char*)"Stanislav Ivanov");
	BankAccount c((char*)"Mariq Petkova");
    BankAccount d((char*)"Todor Petkov");
    BankAccount e((char*)"Stanislav Ivanov");

	cout << a.getId() << " : " << a.getHolderName() << endl;
	cout << b.getId() << " : " << b.getHolderName() << endl;
	cout << c.getId() << " : " << c.getHolderName() << endl;

    vector<BankAccount> accounts;

    a.submit(200);
    a.submit(200);
    a.submit(50);
    a.withdraw(400);
    a.submit(500);
    a.withdraw(550);

    b.submit(50);
    b.submit(25);
    b.submit(50);
    b.withdraw(15);

    c.submit(10);
    c.submit(20);
    c.submit(500);
    c.withdraw(100);

    d.submit(20);
    d.submit(20);
    d.submit(5);
    d.withdraw(10);
    d.submit(50);

    e.submit(20);
    e.submit(20);
    e.submit(5);
    e.withdraw(10);
    e.submit(50);

    accounts.push_back(a);
    accounts.push_back(b);
    accounts.push_back(c);
    accounts.push_back(d);
    accounts.push_back(e);

    saveToFile(accounts);
    printHoldersMoreOneAccount(accounts);
    accountBallances(accounts);
    saveToFileZeroBallace(accounts);
    system("PAUSE");
    return 0;
}
