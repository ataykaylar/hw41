#include "AlgebraicExpression.h"
#include <string>

using namespace std;



string infix2prefix(const string exp)
{
    Stack s;
    string prefixExpression;

    string newExpression = reverseExp(exp);

    for (unsigned int i = 0; i < newExpression.size(); i++)
    {

        if (newExpression[i] == '(')
        {
            newExpression[i] = ')';
            i++;
        }
        else if (newExpression[i] == ')')
        {
            newExpression[i] = '(';
            i++;
        }
    }


    for(unsigned int i = 0; i < newExpression.size(); i++)
    {

        char ch = newExpression[i];
        if( ch =='(')
        {
            s.push(ch);

        }
        else if ( ch ==')')
        {
            char chTop;
            s.getTop(chTop);
            while(chTop != '(')
            {
                prefixExpression += chTop;
                s.pop();
                s.getTop(chTop);
            }
            s.pop();
        }

        else if(ch == '1' ||ch == '2' ||ch == '3' ||ch == '4' ||ch == '5' ||ch == '6' ||ch == '7' ||ch == '8' ||ch == '9')
        {
            prefixExpression += ch;
        }
        else if(ch == '+' ||ch == '-' ||ch == '*' ||ch == '/')
        {
            char x;
            s.getTop(x);
            char chTop2;
            s.getTop(chTop2);
            while (!s.isEmpty() && chTop2 != '(' && precedenceFunc(ch)<= precedenceFunc(chTop2))
            {

                prefixExpression += chTop2;
                s.pop();
                s.getTop(chTop2);
            }
            s.push(ch);
            s.getTop(x);
        }
        if(i == newExpression.size() - 1)
        {
            while(!s.isEmpty())
            {
                char p;
                s.pop(p);
                prefixExpression += p;
            }
        }
    }
    return reverseExp(prefixExpression);
}

double evaluatePrefix(const string exp)
{
    Stack s;

    for(unsigned int i = 0; i < exp.size(); i++)
    {
        char ch = exp[exp.size()-1-i];

        if(ch == '1' ||ch == '2' ||ch == '3' ||ch == '4' ||ch == '5' ||ch == '6' ||ch == '7' ||ch == '8' ||ch == '9')
        {

            double pushOp = (int)ch - 48;
            s.push(pushOp);
        }
        else if (ch == '+' ||ch == '-' ||ch == '*' ||ch == '/')
        {
            double intPop1;
            s.getTop(intPop1);
            s.pop();
            double intPop2;
            s.getTop(intPop2);
            s.pop();
            if(ch == '+')
            {
                double resultPush = intPop1 + intPop2;
                s.push(resultPush);
            }
            else if(ch == '-')
            {
                double resultPush = intPop1 - intPop2;
                s.push(resultPush);
            }
            else if(ch == '*')
            {
                double resultPush = intPop1 * intPop2;
                s.push(resultPush);
            }
            else if(ch == '/')
            {
                double resultPush = intPop1 / intPop2;
                s.push(resultPush);
            }
            if(i == exp.size() - 1){
                double result;
                s.getTop(result);
                return result;
            }

        }
    }

    return 0.0; //couldn't calculate
}





string reverseExp(const string exp)
{
    string reverseExpression = exp;
    for(unsigned int i = 0; i < exp.size(); i++)
    {
        char t = exp[exp.size()-1- i];
        reverseExpression[i] = t ;
    }
    return reverseExpression;

}


int precedenceFunc(const char c)
{
    if(c == '+' ||c == '-')
        return 0;
    else if(c == '*' ||c == '/')
        return 1;

    return -1;
}


