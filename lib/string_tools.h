#ifndef _STRING_TOOLS_H_
#define _STRING_TOOLS_H_
#include <string>
#include <math.h>
#include <sstream>
void trim( std::string &s ) {
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

/*
Documentation:

	Class-1::ExpressionNode

	Brief:
		Node for the expression tree

	Data Members:

		expression:
			datatype: 
				string
			brief:
				contains the info about the operator or number

		type:
			datatype:
				bool
			brief:
				0 if number
				1 if operator

		left:
			type:
				*ExpressionNode
			brief:
				contains the operand 1
				
		right:
			type:
				*ExpressionNode
			brief:
				contains the operand 2


	Member Functions:

		ExpressionNode():
			returntype:
				Default Constructor

		ExpressionNode(with Parameters):
			returntype:
				Parametrized Constructor

		getValue():
			returntype:
				double
			brief:
				Evaluates and returns the value of the subtree


	Class-2::ExpressionTreeBuilder:

	Brief:
		Builds the Expression tree from a string input in infix form

	Data Members:

		Operator:
			type:
				stack<char>
			brief:
				necessary for building the Tree
				holds the operators until they are processed:
				OPERATORS are:
				+ - / g * ^

		Operand:
			type:
				stack<ExpressionNode*>
			brief:
				Holds the Nodes of the tree


	Member Functions:

		getPrecedence(char op):
			returntype:
				int
			brief:
				returns the precedence of the operators

		processOperator(char op):
			returntype:
				void
			brief:
				processes the stack Operators according to the precedence

		processRightParanthesis():
			returntype:
				void
			brief:
				Processes the encounters of right paranthesis in the string

		createExpression(char op):
			returntype:
				void
			brief:
				takes two nodes from the Operand stack and creates a new node

		changeGcdFormat(string str):
			returntype:
				string
			brief:
				changes the user friendly format of gcd(a,b) to binary operator with symbol 'g'

		parse(string str):
			returntype:
				ExpressionNode*
			brief:
				Main Function
				Parses the string to create the tree and returns the root of the tree


*/
class ExpressionNode
{

	private:
	
		string expression;
		bool type;
		ExpressionNode *left;
		ExpressionNode *right;
	
	
	public:
	
		ExpressionNode() : expression( "" ), type( false ), left( NULL ), right( NULL ) { }
		ExpressionNode( string exp, bool b, ExpressionNode *l, ExpressionNode *r ) : expression( exp ), type( b ), left( l ), right( r ) { }
		double getValue();

};

class ExpressionTreeBuilder
{
	
	private:
	
		stack<char> Operator;
		stack<ExpressionNode *> Operand;
	

	public:

		int getPrecedence( char op );
		void processOperator( char op );
		void processRightParanthesis();
		void createExpression( char op );
		string changeGcdFormat( string str );
		ExpressionNode* parse( string str );

};
int ExpressionTreeBuilder::getPrecedence( char op )
{

	switch( op )
	{
		case 'g':
			return 5;

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
void ExpressionTreeBuilder::processOperator( char op )
{

	int prec = getPrecedence( op );

	while( !Operator.empty() && prec <= getPrecedence( Operator.top() ) )
	{
		createExpression( Operator.top() );
		Operator.pop();
	}

	Operator.push( op );

}
void ExpressionTreeBuilder::processRightParanthesis()
{

	while( !Operator.empty() && Operator.top() != '(' ) 
	{
		createExpression( Operator.top() );
		Operator.pop();
	}

	if( Operator.top() == '(' )
	{
		Operator.pop();
	}

	else
	{
		throw 1;
	}

}
void ExpressionTreeBuilder::createExpression( char op )
{

	ExpressionNode *right, *left;

	if(!Operand.empty())
	{
		right = Operand.top();
		Operand.pop();
	}

	else
	{
		throw 1;
	}

	if( !Operand.empty() )
	{
		left = Operand.top();
		Operand.pop();
	}

	else
	{
		throw 1;
	}

	stringstream ss;
	ss << op;
	string s;
	ss >> s;

	ExpressionNode* temp = new ExpressionNode( s, 1, left, right );
	Operand.push( temp );

}


string ExpressionTreeBuilder::changeGcdFormat( string str )
{


	for ( int i = 0; i < str.size(); ++i )
	{

		if( str[i] >= 97 && str[i] <=122 )
		{
			str[i] = ' ';
		}

		else if( str[i] == ',' )
		{
			str[i] = 'g';
		}

	}

	return str;

}

ExpressionNode *ExpressionTreeBuilder::parse( string str )
{

    str = changeGcdFormat( str );
    cout << str;
	istringstream is( str );

	char tmp;
	string s;

	while( is >> tmp )
	{

		switch( tmp )
		{
			case '+':
			case '-':
			case '/':
			case '*':
			case 'g':
			case '^':
				processOperator( tmp );
				break;

			case ')':
				processRightParanthesis();
				break;

			case '(':
				Operator.push( tmp );
				break;

			default :
				is.putback( tmp );
	
	            stringstream ss;
	            double number;
				is >> number;
				ss << number;
				ss >> s;
				
				Operand.push( new ExpressionNode( s, 0, NULL, NULL ) );
		
		}

	}

	while( !Operator.empty() )
	{
		createExpression( Operator.top() );
		Operator.pop();
	}
	
	if( Operand.size() != 1 )
	{
		throw 1;
	}
	
	return Operand.top();

}
long long gcd( long long a, long long b )
{
	if( !b )
	{
		return a;
	}
	return gcd( b, a%b );
}
double ExpressionNode::getValue()
{
	if( type )
	{
		switch( this->expression[0] )
		{
			case '+': 
				return ( this->left->getValue() + this->right->getValue() );
				
			case '-': 
				return ( this->left->getValue() - this->right->getValue() );
				
			case '*': 
				return ( this->left->getValue() * this->right->getValue() ) ;
				
			case '/': 
				return ( this->left->getValue() / this->right->getValue() );
				
			case '^': 
				return ( pow(this->left->getValue(), this->right->getValue() ) );
				
			case 'g':
				return ( (double)gcd((long long)this->left->getValue(), (long long)this->right->getValue() ) );
		}
	}
	else
	{
		istringstream is( this->expression );
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
#endif