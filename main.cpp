#include "ArrayStack.h"
#include"StackInterface.h"
#include <fstream>
#include<iostream>
#include<string>

using namespace std;
int main()
{
	fstream inData;
	ArrayStack <float> myPostfix;
	string ArrayPostfix;
	int val;
	float operand1, operand2, result;
	char ch;
	inData.open("Postfix.txt");
	if (!inData)
		cout << "Error opning file!"<<endl;

	while (!inData.eof())
	{
		getline(inData, ArrayPostfix);
	}
	
	cout << "Postfix expression : ";
	for (int i = 0; i < ArrayPostfix.length(); i++)
		cout << ArrayPostfix[i];

	for (int i = 0; i < ArrayPostfix.length(); i++)
	{
		ch = ArrayPostfix[i];
		if (ch >= '0' && ch <= '9')
		{
			val = ch - '0'; // convert the char to an int (offset from char 0 ) 
			myPostfix.push(val);
		}
		else if (ch == '+' || ch == '-' || ch == '*' || ch == '/')
		{
			switch (ch)
			{
			case '+':
				operand2 = myPostfix.peek();
				myPostfix.pop();
				operand1 = myPostfix.peek();
				myPostfix.pop();
				result = operand1 + operand2;
				myPostfix.push(result);
				break;
			case '-':
				operand2 = myPostfix.peek();
				myPostfix.pop();
				operand1 = myPostfix.peek();
				myPostfix.pop();
				result = operand1 - operand2;
				myPostfix.push(result);
				break;
			case '*': 
				operand2 = myPostfix.peek();
				myPostfix.pop();
				operand1 = myPostfix.peek();
				myPostfix.pop();
				result = operand1 * operand2;
				myPostfix.push(result);
				break;
			case '/':
				operand2 = myPostfix.peek();
				myPostfix.pop();
				operand1 = myPostfix.peek();
				myPostfix.pop();
				result = operand1 / operand2;
				myPostfix.push(result);
				break;
			}

		}
	}
	
	cout<<"\nPostfix evalution : "<< myPostfix.peek()<<endl;
	myPostfix.pop();

	system("PAUSE");
	return 0;
}
/*
#include <string> 
#include <iostream> 
#include <stack> 
using namespace std;

void main() {

	string postfix = "3 2 *";
	char ch;
	int value;
	stack <float> operandStack;

	for (int i = 0; i < postfix.length(); i++) {
		ch = postfix[i];
		if (ch >= '0' && ch <= '9') { // digit 
			value = ch - '0';  // convert the char to an int (offset from char 0 ) 
			operandStack.push(value);

		}

	}

	while (!operandStack.empty()) {
		cout << operandStack.top() << endl;
		operandStack.pop();
	}

}
*/