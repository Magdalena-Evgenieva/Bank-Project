#pragma once
#include <iostream>
#include<vector>
#include<string>
#include <fstream>
using namespace std;

class BankAccount
{
private:
	static char uniqueSymbol;
	static string uniqueNumber;
	string id;
	char* holderName;
	vector<double> commitments;
	vector<double> withdraws;
	void setUniqueId();
public:
	BankAccount(char* name);
	string& getId();
	char* getHolderName();
	void setHolderName(char* holder);
	vector<double>const &getCommitments();
	vector<double>const &getWithdraws();
	void submit(double money);
	void withdraw(double money);
	friend ostream& operator<<(ostream& out, const BankAccount& b);
};




