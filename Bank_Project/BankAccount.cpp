#include "BankAccount.h"
string BankAccount::uniqueNumber = "00000";
char BankAccount::uniqueSymbol = 'A';
void BankAccount::setUniqueId()
{
	int num= stoi(uniqueNumber);
	num++;
	string temp;
	if (num < 10) {
		temp = "0000";
		temp.append(to_string(num));
	}else if (num < 100) {
		temp = "000";
		temp.append(to_string(num));
	}else if(num < 1000) {
		temp = "00";
		temp.append(to_string(num));
	}else if (num < 10000) {
		temp = "0";
		temp.append(to_string(num));
	}
	else if (num < 100000) {
		temp = "";
		temp.append(to_string(num));
	}
	else{
		temp = "0000";
		uniqueSymbol++;
	}
	uniqueNumber = temp;
}

string& BankAccount::getId()
{
	return id;
}

char* BankAccount::getHolderName()
{
	return holderName;
}

vector<double> const &BankAccount::getCommitments()
{
	return commitments;
}

vector<double>const &BankAccount::getWithdraws()
{
	return withdraws;
}

BankAccount::BankAccount(char* name)
{
	setUniqueId();
	id = uniqueSymbol;
	id.append(uniqueNumber);
	holderName = name;
}

void BankAccount::setHolderName(char* holder) {
	holderName = holder;
}

void BankAccount::submit(double money) {
	if (money > 0) {
		commitments.push_back(money);
	}
}

void BankAccount::withdraw(double money) {
	if (money > 0) {
		withdraws.push_back(money);
	}
}

 ostream& operator<<(ostream& out, const BankAccount& b)
{
	out << "(";
	out << b.id;
	out << ")(";
	out << b.holderName;
	out << ")";
	out << "(";
	for (vector<double>::const_iterator i = b.commitments.begin(); i != b.commitments.end(); ++i) {
		out << *i << " ";
	}
	out << ")";
	out << "(";
	for (vector<double>::const_iterator i = b.withdraws.begin(); i != b.withdraws.end(); ++i) {
		out << *i << " ";
	}
	out << ");";
	out << endl;
	return out;
}
