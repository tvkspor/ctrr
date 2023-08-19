#include "process.h"

//***Hamphucau1***//
int pre(char c) {
    if (c == '+' || c == '-') {
        return 1;
    }
    else if (c == '*' || c == '/') {
        return 2;
    }
    else if (c == '^') {
        return 3;
    }
    else {
        return 0;
    }
}
string xoaSo0Cuoi(string s) {
    int i = s.size() - 1;
    while (i >= 0 && s[i] == '0') {
        i--;
    }
    if (i >= 0 && s[i] == '.') {
        i--;
    }
    return s.substr(0, i + 1);
}

//***Hamchinhcau1a***//
string infix_to_postfix(string infix_expr) {
    stack <char> op_stack;
    stringstream ss;
    ss << infix_expr;
    char c;
    string postfix_expr = "";
    while (ss >> c) {
        if (isdigit(c) || isalpha(c)) {
            postfix_expr += c;
        }
        else if (pre(c) != 0) {
            while (!op_stack.empty() && op_stack.top() != '(' &&
                pre(op_stack.top()) >= pre(c))
            {
                postfix_expr = postfix_expr + " " + op_stack.top();
                op_stack.pop();
            }
            op_stack.push(c);
            postfix_expr += " ";
        }
        else if (c == '(') {
            op_stack.push(c);
        }
        else if (c == ')') {
            while (!op_stack.empty() && op_stack.top() != '(') {
                postfix_expr = postfix_expr + " " + op_stack.top();
                op_stack.pop();
            }
            if (!op_stack.empty() && op_stack.top() == '(') {
                op_stack.pop();
            }
        }
    }
    while (!op_stack.empty()) {
        postfix_expr = postfix_expr + " " + op_stack.top();
        op_stack.pop();
    }
    return postfix_expr;
}

//***Hamchinhcau1b***//
string infix_to_prefix(string infix_expr) {
    reverse(infix_expr.begin(), infix_expr.end());
    stack<char> op_stack;
    stringstream ss;
    ss << infix_expr;
    char c;
    string prefix_expr = "";
    while (ss >> c) {
        if (isdigit(c) || isalpha(c)) {
            string num = "";
            num += c;
            while (ss >> c && (isdigit(c) || isalpha(c))) {
                num += c;
            }
            prefix_expr += num + " ";
            ss.putback(c);
        }
        else if (pre(c) != 0) {
            while (!op_stack.empty() && op_stack.top() != ')' &&
                pre(op_stack.top()) > pre(c)) {
                prefix_expr = prefix_expr + op_stack.top();
                op_stack.pop();
                prefix_expr += " ";
            }
            op_stack.push(c);
        }
        else if (c == ')') {
            op_stack.push(c);
        }
        else if (c == '(') {
            while (!op_stack.empty() && op_stack.top() != ')') {
                prefix_expr += op_stack.top();
                op_stack.pop();
                prefix_expr += " ";
            }
            if (!op_stack.empty() && op_stack.top() == ')') {
                op_stack.pop();
            }
        }
    }
    while (!op_stack.empty()) {
        prefix_expr += op_stack.top();
        op_stack.pop();
        prefix_expr += " ";
    }
    reverse(prefix_expr.begin(), prefix_expr.end());
    prefix_expr.erase(prefix_expr.find(" "), 1);
    return prefix_expr;
}


//***Hamchinhcau1c***//
double evaluate_postfix(string expr) {
    stack<double> s;
    stringstream ss(expr);
    string token;
    while (ss >> token) {
        if (isdigit(token[0])) {
            double operand = stod(token);
            s.push(operand);
        }
        else {
            double op2 = s.top();
            s.pop();
            double op1 = s.top();
            s.pop();
            switch (token[0]) {
            case '+':
                s.push(op1 + op2);
                break;
            case '-':
                s.push(op1 - op2);
                break;
            case '*':
                s.push(op1 * op2);
                break;
            case '/':
                s.push(op1 / op2);
                break;
            case'^':
                s.push(pow(op1, op2));
                break;
            }
        }
    }
    return s.top();
}
double evaluate_prefix(string expr) {
    stack<double> s;
    reverse(expr.begin(), expr.end());
    stringstream ss(expr);
    string token;
    while (ss >> token) {
        if (isdigit(token[0])) {
            reverse(token.begin(), token.end());
            double operand = stod(token);
            s.push(operand);
        }
        else {
            double op1 = s.top();
            s.pop();
            double op2 = s.top();
            s.pop();
            switch (token[0]) {
            case '+':
                s.push(op1 + op2);
                break;
            case '-':
                s.push(op1 - op2);
                break;
            case '*':
                s.push(op1 * op2);
                break;
            case '/':
                s.push(op1 / op2);
                break;
            case'^':
                s.push(pow(op1, op2));
            }
        }
    }
    return s.top();
}
string  PostfixPrefixCalculator(string expr) {
    if (isdigit(expr[0])) {
        double a = round(evaluate_postfix(expr) * 10000) / 10000.0;
        string s = to_string(a);
        return xoaSo0Cuoi(s);
    }
    else {
        double a = round(evaluate_prefix(expr) * 10000) / 10000.0;
        string s = to_string(a);
        return xoaSo0Cuoi(s);
    }
}



//***Hamphucau2***//
string spaceadd(string s)
{
    string a;
    for (int i = 0; i < s.length(); i++)
    {
        if (s[i] == '-') {
            a = a + "->" + " ";
            i++;
        }
        else if (s[i] == '<')
        {
            a = a + "<->" + " ";
            i = i + 2;
        }
        else a = a + s[i] + " ";
    }
    return a;
}
int prel(string c)
{

    if (c == "<->" || c == ">-<") {
        return 1;
    }
    else if (c == "->" || c == ">-") {
        return 2;
    }
    else if (c == "|" || c == "&") {
        return 3;
    }
    else if (c == "~") {
        return 4;
    }
    else {
        return 0;
    }
}

//***Hamchinhcau2a***//
string LogicInfix2Postfix(string infix) {
    string t = spaceadd(infix);
    stack <string> op_stack;
    stringstream ss;
    ss << t;
    string c;
    string postfix_expr = "";
    while (ss >> c) {
        if (prel(c) != 0) {
            while (!op_stack.empty() && op_stack.top() != "(" &&
                prel(op_stack.top()) >= prel(c)) {
                postfix_expr += op_stack.top();
                op_stack.pop();
            }
            op_stack.push(c);
        }
        else if (c == "(") {
            op_stack.push(c);
        }
        else if (c == ")") {
            while (!op_stack.empty() && op_stack.top() != "(") {
                postfix_expr += op_stack.top();
                op_stack.pop();
            }
            if (!op_stack.empty() && op_stack.top() == "(") {
                op_stack.pop();
            }
        }
        else {
            postfix_expr += c;
        }
    }
    while (!op_stack.empty()) {
        postfix_expr += op_stack.top();
        op_stack.pop();
    }
    return postfix_expr;
}


//***Hamchinhcau2b***//
string LogicInfix2Prefix(string infix) {
    string t = spaceadd(infix);
    reverse(t.begin(), t.end());
    // Initialize stacks
    stack <string> op_stack;
    stringstream ss;
    ss << t;
    string c;
    string prefix_expr = "";
    while (ss >> c) {
        if (prel(c) != 0) {
            while (!op_stack.empty() && op_stack.top() != ")" &&
                prel(op_stack.top()) > prel(c)) {
                prefix_expr = prefix_expr + op_stack.top();
                op_stack.pop();
            }
            op_stack.push(c);
        }
        else if (c == ")") {
            op_stack.push(c);
        }
        else if (c == "(") {
            while (!op_stack.empty() && op_stack.top() != ")") {
                prefix_expr += op_stack.top();
                op_stack.pop();

            }
            if (!op_stack.empty() && op_stack.top() == ")") {
                op_stack.pop();
            }
        }
        else {
            prefix_expr = prefix_expr + c;

        }
    }
    while (!op_stack.empty()) {
        prefix_expr += op_stack.top();
        op_stack.pop();

    }
    reverse(prefix_expr.begin(), prefix_expr.end());
    return prefix_expr;
}   


//***Hamchinhcau2c***//
int logicresult(string m, int a, int b)
{
    if (m == "&")
    {
        if (a == 1)
        {
            if (b == 1) return 1;
        }
        return 0;
    }
    if (m == "|")
    {
        if (a == 0)
        {
            if (b == 0) return 0;
        }
        return 1;
    }
    if (m == "->")
    {
        if (a == 1)
        {
            if (b == 0) return 0;
        }
        return 1;
    }
    if (m == "<->")
    {
        if (a == 1)
        {
            if (b == 1) return 1;
        }
        if (a == 0)
        {
            if (b == 0) return 1;
        }
        return 0;
    }
    if (m == "~")
    {
        if (a == 1) return 0;
        return 1;
    }
}
int evaluate_logicpostfix(string expr) {
    stack<int> s;
    stringstream ss(expr);
    string token;
    while (ss >> token) {
        if (isdigit(token[0])) {
            int operand = stoi(token);
            s.push(operand);
        }
        else {
            if (token == "~")
            {
                int op = s.top();
                s.pop();
                s.push(logicresult("~", op, 1));
            }
            else {
                int op2 = s.top();
                s.pop();
                int op1 = s.top();
                s.pop();
                if (token == "&") {
                    s.push(logicresult("&", op1, op2));
                }
                if (token == "|") {
                    s.push(logicresult("|", op1, op2));
                }
                if (token == "->") {
                    s.push(logicresult("->", op1, op2));
                }
                if (token == "<->") {
                    s.push(logicresult("<->", op1, op2));
                }
            }
        }
    }
    return s.top();
}
int evaluate_logicprefix(string expr) {
    stack<int> s;
    reverse(expr.begin(), expr.end());
    stringstream ss(expr);
    string token;
    while (ss >> token) {
        if (isdigit(token[0])) {
            int operand = stoi(token);
            s.push(operand);
        }
        else {
            if (token == "~")
            {
                int op = s.top();
                s.pop();
                s.push(logicresult("~", op, 1));
            }
            else {
                int op1 = s.top();
                s.pop();
                int op2 = s.top();
                s.pop();
                if (token == "&") {
                    s.push(logicresult("&", op1, op2));
                }
                if (token == "|") {
                    s.push(logicresult("|", op1, op2));
                }
                if (token == ">-") {
                    s.push(logicresult("->", op1, op2));
                }
                if (token == ">-<") {
                    s.push(logicresult("<->", op1, op2));
                }
            }
        }
    }
    return s.top();
}
string LogicPostfixPrefixCalculator(string input, string varlue) {
    stringstream ss;
    string* a = new string[100];
    int i = 0;
    string b;
    ss << varlue;
    while (ss >> b)
    {
        a[i] = b; i++;
    }
    string t = spaceadd(input);
    stack <string> op_stack;
    stringstream f;
    f << t;
    string c;
    string replacenum;
    while (f >> c)
    {
        int r = 0;
        for (int j = 0; j <= i / 2; j++) {
            if (c == a[j]) {
                replacenum = replacenum + a[j + i / 2] + " "; r = 1;
            }
        }
        if (r != 1) replacenum = replacenum + c + " ";
    }
    int h = 0;
    if (isdigit(replacenum[0])) h = evaluate_logicpostfix(replacenum);
    else h = evaluate_logicprefix(replacenum);


    if (h == 1) return "TRUE";
    else return "FALSE";
}