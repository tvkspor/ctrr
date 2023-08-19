#include "process.h"

int main() 
{   
	string s = "59+107*83*72*91/(27-(112*153)*(111+76))";
	cout << "Cau1a"<<endl;
	cout << "Infix expression: " << s << endl;
	cout << "Postfix expression: " << infix_to_postfix(s) << endl;


	cout << "Cau1b" << endl;
	cout << "Infix expression: " << s << endl;
	cout << "Prefix expression: " << infix_to_prefix(s) << endl;


	cout << "Cau1c" << endl;
	string ss = "+ 59 / * * * 107 83 72 91 - 27 * * 112 153 + 111 76";
	cout << "Expression: " << ss << endl;
	cout << "Result: " << PostfixPrefixCalculator(ss) << endl;


	string sss = "~t->t&~w|(z&(p&(w&(p|p&q)|y&z&z)<->x&(~p|z)&~y))";
	cout << "Cau2a" << endl;
	cout << "Infix expression: " << sss << endl;
	cout << "Postfix expression: " << LogicInfix2Postfix(sss) << endl;


	cout << "Cau2b" << endl;
	cout << "Infix expression: " << sss << endl;
	cout << "Prefix expression: " << LogicInfix2Prefix(sss) << endl;

	string input = "->~t|&t~w&z<->&p&&|&w&|ppqyzz&&x|~pz~y";
	string varlue = "t w z p q y x 1 1 1 1 1 1 1";
	cout << "Cau2c" << endl;
	cout << "Input: " << input << endl;
	cout << "Variable value: " << varlue << endl;
	cout << "Result: " << LogicPostfixPrefixCalculator( input, varlue) << endl;
	return 0;
}