#include <iostream>
#include <string>
#include <stack>
using namespace std;

string infixToPostfix(string infix);
string infixToPrefix(string infix);
bool getPriority(char operator1, char operator2);

int main()
{
	string infix, prefix, postfix;

	while (1)
	{
		cout << "Please write the notation to convert to postfix and prefix: ";
		cin >> infix;

		postfix = infixToPostfix(infix);
		prefix = infixToPrefix(infix);

		cout << endl << "\tThe postfix notation is " << postfix;
		cout << endl << "\tThe prefix notation is " << prefix << endl << endl;

	}
	system("pause");
}

string infixToPostfix(string infix)
{
	string postfix = "";
	stack<char> oStack;
	int size = infix.size();

	for (int i = 0; i < size; i++)
	{
		if (infix[i] == '*' || infix[i] == '/' || infix[i] == '+' || infix[i] == '-')
		{
			while (!oStack.empty())
			{
				char temp;
				temp = oStack.top();

				if (temp == '(')
					break;
				if (getPriority(temp, infix[i]))
				{
					oStack.pop();
					postfix += temp;
				}
				else break; 
			}
			oStack.push(infix[i]);
		}
		else if (infix[i] == ')')
		{
			char temp;

			while(1)
			{
				temp = oStack.top();
				oStack.pop();

				if (temp == '(')
					break;
				postfix += temp;

				if (oStack.empty())
					break;
			}

		}
		else if (infix[i] == '(')
		{
			oStack.push(infix[i]);
		}
		else
		{
			postfix += infix[i];
		}
	}

	char temp;
	while (1)
	{
		temp = oStack.top();
		oStack.pop();

		postfix += temp;

		if (oStack.empty())
			break;
	}
	return postfix;
}

string infixToPrefix(string infix)
{
	int size = infix.size();

	reverse(infix.begin(), infix.end());

	for (int i = 0; i < size; i++)
	{
		if (infix[i] == '(')
		{
			infix[i] = ')';
			i++;
		}
		else if (infix[i] == ')')
		{
			infix[i] = '(';
			i++;
		}
	}
	string prefix = infixToPostfix(infix);
	reverse(prefix.begin(), prefix.end());

	return prefix;
}

bool getPriority(char operator1, char operator2)
{
	if (operator1 == '*' || operator1 == '/')
		return true;
	if (operator2 == '+' || operator2 == '-')
		return true;
	return false;
}

