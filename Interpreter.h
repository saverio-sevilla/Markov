#pragma once
#include <string>
#include <iostream>
#include <fstream>
#include <vector>

using namespace std;

#define DEBUG_PARSER

typedef enum TokenType {
	RULE,
	END,
	INPUT,
	OUTPUT,
} TokenType;

std::ostream& operator<<(std::ostream& out, TokenType type);

struct Token
{
	TokenType m_type;
	string m_lhs;
	string m_rhs;


	Token(TokenType type) :
		m_type{ type },
		m_lhs{""},
		m_rhs{""}
	{

	}


	Token(TokenType type, string lhs, string rhs) :
		m_type{ type },
		m_lhs{ lhs },
		m_rhs{ rhs }
	{

	}

	void print() {
		cout << m_lhs << ", " << m_rhs << ", " << m_type << endl;
	}
};

Token tokenizeRule(string input, string delimiter);
void parseFile(string filename, vector<Token>& token_vec);
string interpret(const vector<Token>& token_vec);



