#include <iostream>
#include <fstream>
#include <string.h>

using namespace std;
ifstream infile("lab3-1.txt");
ofstream out("output.txt");
const int stackSize = 100;
int stack[stackSize]; int top;
int match(char, char);
int main() {
	void create_stack(), push(char);
	int pop(), isEmpty();
	int temp, i, ans;
	char buffer[80];

	while (infile.getline(buffer, 80)) {
		create_stack();
		ans = 0;
		for (i = 3; i < strlen(buffer); i++) {
			if (buffer[i] == '(' || buffer[i] == '{' || buffer[i] == '[') {
				push(buffer[i]);
			}
			else if (buffer[i] == ')' || buffer[i] == '}' || buffer[i] == ']') {
				if (isEmpty())
				{
					ans = 1;
					cout << buffer << "\t\t" << "Invalid(Unbalanced parentheses)" << endl;
					out << buffer << "\t\t" << "Invalid(Unbalanced parentheses)" << endl;
					break;
				}
				temp = pop();
				if (!match(temp, buffer[i]))
				{
					ans = 1;
					cout << buffer << "\t\t" << "Invalid(Mismatched parentheses)" << endl;
					out << buffer << "\t\t" << "Invalid(Mismatched parentheses)" << endl;
					break;
				}
			}
		}
		if (ans == 0)
		{
			if (isEmpty())
			{
				cout << buffer << "\t\t" << "Valid" << endl;
				out << buffer << "\t\t" << "Valid" << endl;
			}
			else
			{
				cout << buffer << "\t\t" << "Invalid(Unbalanced parentheses)" << endl;
				out << buffer << "\t\t" << "Invalid(Unbalanced parentheses)" << endl;
			}
		}
	}
}
void create_stack() { top = -1; }
int isEmpty() {
	if (top == -1) return 1;
	else return 0;
}
void push(char num) {
	++top;
	stack[top] = num;
}
int pop() {
	return (stack[top--]);
}
int match(char x, char y)
{
	if (x == '(' && y == ')')
	{
		return 1;
	}
	else if (x == '[' && y == ']')
	{
		return 1;
	}
	else if (x == '{' && y == '}')
	{
		return 1;
	}
	return 0;
}