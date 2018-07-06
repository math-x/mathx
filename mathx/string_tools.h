#ifndef _STRING_TOOLS_H_
#define _STRING_TOOLS_H_

#include <string>
#include <stack>
#include <cmath>
#include <sstream>

namespace mathx {
    inline void trim(std::string &s) {
        int len = s.length();
        for (int i = 0; i < len; ++i)
        {
            if(s[i] == ' ') {
                s.erase(i,1);
                i--;
                len--;
            }
        }
    }

    class ExpressionNode {
        private:
            std::string expression;
            bool type;
            ExpressionNode *left;
            ExpressionNode *right;
        public:
            ExpressionNode() : expression(""), type(false), left(NULL), right(NULL) {}
            ExpressionNode(std::string exp, bool b, ExpressionNode *l, ExpressionNode *r) : expression(exp), type(b), left(l), right(r) {}
            double getValue();
    };

    class ExpressionTreeBuilder {
        private:
            std::stack<char> Operator;
            std::stack<ExpressionNode *> Operand;
        public:
            int getPrecedence(char op);
            void processOperator(char op);
            void processRightParanthesis();
            void createExpression(char op);
            ExpressionNode* parse(std::string str);
    };

    inline int ExpressionTreeBuilder::getPrecedence (char op) {
        switch(op) {
            case '^':
                return 4;
            case '/':
            case '*':
                return 3;
            case '+':
            case '-':
                return 2;
            default:
                return 0;
        }
    }

    inline void ExpressionTreeBuilder::processOperator (char op) {
        int prec = getPrecedence(op);
        while(!Operator.empty() && prec <= getPrecedence(Operator.top())) {
            createExpression(Operator.top());
            Operator.pop();
        }
        Operator.push(op);
    }

    inline void ExpressionTreeBuilder::processRightParanthesis() {
        while(!Operator.empty() && Operator.top() != '(') {
            createExpression(Operator.top());
            Operator.pop();
        }
        if(Operator.top() == '(') {
            Operator.pop();
        }
        else {
            throw 1;
        }
    }

    inline void ExpressionTreeBuilder::createExpression(char op) {
        ExpressionNode *right, *left;
        if(!Operand.empty()) {
            right = Operand.top();
            Operand.pop();
        }
        else {
            throw 1;
        }
        if(!Operand.empty()) {
            left = Operand.top();
            Operand.pop();
        }
        else {
            throw 1;
        }
        std::stringstream ss;
        ss << op;
        std::string s;
        ss >> s;
        ExpressionNode* temp = new ExpressionNode(s, 1, left, right);
        Operand.push(temp);
    }

    inline ExpressionNode *ExpressionTreeBuilder::parse(std::string str) {
        trim(str);
        std::istringstream is(str);
        char tmp;
        std::string s;
        while(is >> tmp) {
            switch(tmp) {
                case '+':
                case '-':
                case '/':
                case '*':
                case '^':
                    processOperator(tmp);
                    break;
                case ')':
                    processRightParanthesis();
                    break;
                case '(':
                    Operator.push(tmp);
                    break;
                default :
                    is.putback(tmp);
                    std::stringstream ss;
                    double number;
                    is >> number;
                    ss << number;
                    ss >> s;
                    Operand.push(new ExpressionNode(s, 0, NULL, NULL));
            }
        }
        while(!Operator.empty()) {
            createExpression(Operator.top());
            Operator.pop();
        }
        if(Operand.size() != 1) {
            throw 1;
        }
        return Operand.top();
    }

    inline double ExpressionNode::getValue() {
        if(type) {
            switch(this->expression[0]) {
                case '+':
                    return (this->left->getValue() + this->right->getValue());
                case '-':
                    return (this->left->getValue() - this->right->getValue());
                case '*':
                    return (this->left->getValue() * this->right->getValue()) ;
                case '/':
                    return (this->left->getValue() / this->right->getValue());
                case '^':
                    return (pow(this->left->getValue(), this->right->getValue()));
            }
        }
        else {
            std::istringstream is(this->expression);
            double n;
            is >> n;
            return n;
        }
    }
    /*Test Main
    int main()
    {

        string str;
        std :: cin >> str;
        ExpressionTreeBuilder t;
        try
        {
            ExpressionNode *u = t.parse(str);
            cout << u->getValue();
        }
        catch(int e)
        {
            std :: cout << "Error Occurred: Expression Not Valid\t";
        }
    }
    */
}
#endif /* _STRING_TOOLS_H_ */
