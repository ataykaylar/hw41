#include "AlgebraicExpression.h"
int main()
{
    cout << infix2prefix("1+2*(2/5)") << endl;
    cout << evaluatePrefix("+1*2/25") << endl;
    cout << infix2prefix("1+2*(2/5)") << endl;
    cout << evaluatePrefix("+1*2/25") << endl;
    cout << infix2prefix("(4+5)-2*4") << endl;
    cout << evaluatePrefix("/4+3*-528") << endl;
    return 0;
}
