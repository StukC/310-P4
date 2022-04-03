#include <iostream>
#include <fstream>
#include <cstring>
#include <cmath>
using namespace std;
unsigned long long int hexadecimalToDecimal(string hex)
{
	unsigned long long decimalNum = 0;
	unsigned long long hexaLength = hex.length();
	for (int i = 0; i < hexaLength; i++)
	{
		if (hex[i] >= '0' && hex[i] <= '9')
		{
			decimalNum = decimalNum * 16 + (hex[i] - 48);
		}
		else if (hex[i] >= 'A' && hex[i] <= 'F')
		{
			decimalNum = decimalNum * 16 + (hex[i] - 55);
		}
	}
	return decimalNum;
}

void calculate(unsigned long long firstOperator, unsigned long long secondOperator, char operatorSymbol) {
	switch (operatorSymbol) {
	case '+':
		cout << firstOperator << operatorSymbol << secondOperator << "=" << (firstOperator + secondOperator) << endl;
		break;
	case '-':
		cout << firstOperator << operatorSymbol << secondOperator << "=" << (firstOperator - secondOperator) << endl;
		break;
	case '*':
		cout << firstOperator << operatorSymbol << secondOperator << "=" << (firstOperator * secondOperator) << endl;
		break;
	case '/':
		cout << firstOperator << operatorSymbol << secondOperator << "=" << "quotient " << (firstOperator / secondOperator) << ", remainder " << (firstOperator % secondOperator) << endl;
		break;
	case '$':
		cout << firstOperator << operatorSymbol << secondOperator << "=" << pow(firstOperator, secondOperator) << endl;
		break;
	default:
		cout << "\n Invalid";
	}

}


void file() {
	string op1;
	string op2;
	string fileData;
	char operatorSymbol;
	unsigned long long firstVal;
	unsigned long long secondVal;
	unsigned long long lineSpace;
	unsigned long long length;
	ifstream fileRead;
	fileRead.open("input.txt");
	if (!fileRead)
	{
		cout << "\n invalid";

		exit(0);
	}


	while (!fileRead.eof()) {
		fileRead >> fileData;
		length = fileData.length();
		for (lineSpace = 0; lineSpace < length; lineSpace++)
			if (fileData.at(lineSpace) == '+' || fileData.at(lineSpace) == '-' || fileData.at(lineSpace) == '*' || fileData.at(lineSpace) == '/'
				|| fileData.at(lineSpace) == '$')
				break;
		op1 = fileData.substr(0, lineSpace);
		operatorSymbol = fileData.at(lineSpace);
		op2 = fileData.substr(lineSpace + 1, (fileData.length() - op1.length() - 2));
		firstVal = hexadecimalToDecimal(op1);
		secondVal = hexadecimalToDecimal(op2);
		calculate(firstVal, secondVal, operatorSymbol);
	}
	fileRead.close();
}



int main()

{
	file();
	return 0;
}
