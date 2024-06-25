#include <iostream>
using namespace std;

double calc(double x, double y, char op)
{
    double result;
    switch (op)
    {
    case '+':
        result = x + y;
        break;
    case '-':
        result = x - y;
        break;
    case '*':
        result = x * y;
        break;
    case '/':
        if (y != 0)
            result = x / y;
        else
        {
            cout << "Error: Division by zero is undefined.\n";
            result = 0;
        }
        break;
    default:
        cout << "Invalid operation.\n";
        result = 0;
    }
    return result;
}

int main()
{
    double x, y, result;
    char op;
    cout << "Enter a Number: ";
    cin >> x;
    result = x;

    while (true)
    {
        cout << "Enter operation to be performed: ";
        cin >> op;
        if (op == '=')
        {
            cout << "Result is: " << result << "\n";
            break;
        }
        else if ((op == '+') || (op == '-') || (op == '*') || (op == '/'))
        {
            cout << "Enter another Number: ";
            cin >> y;
            result = calc(result, y, op);
        }
        else
        {
            cout << "Invalid Argument Given\n";
            break;
        }
    }

    return 0;
}
