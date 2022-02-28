#include "Interpreter.h"

std::ostream& operator<<(std::ostream& out, TokenType type) {
	switch (type) {
	case RULE:
		out << "RULE";
		break;
	case END:
		out << "END";
		break;
	case INPUT:
		out << "INPUT";
		break;
	case OUTPUT:
		out << "OUTPUT";
		break;
	default:
		out << "NOT DEF";
	}
	return out;
}

Token tokenizeRule(string input, string delimiter) {
	string lhs, rhs;
	size_t pos{ 0 };
	while ((pos = input.find(delimiter)) != std::string::npos) {
		lhs = input.substr(0, pos);
		lhs.erase(std::remove(lhs.begin(), lhs.end(), ' '), lhs.end());
		rhs = input.erase(0, pos + delimiter.length());
		rhs.erase(std::remove(rhs.begin(), rhs.end(), ' '), rhs.end());
	}
	return Token(RULE, lhs, rhs);
}

void parseFile(string filename, std::vector<Token>& token_vec) {
	ifstream inFile;
	inFile.open(filename);
	string line;

	while (true) {
		getline(inFile, line);

		while (line.length() == 0) {
			getline(inFile, line);
		}

		if (!inFile) {
			break;
		}

		if ( line.find(":=") != std::string::npos) {
			Token token = tokenizeRule(line, ":=");
			token_vec.push_back(token);
		}

		else if (line.find("->") != std::string::npos) {
			token_vec.push_back(Token(OUTPUT, "", ""));
		}

		else {
			Token token(INPUT, line, "");
			token_vec.insert(token_vec.begin(), token);
		}
	}

	token_vec.push_back(Token(END));

	inFile.close();
}

bool apply_rules(string& input, const vector<Token>& token_vec) {
	
	for (auto it = token_vec.begin(); it != token_vec.end(); it++) {

		string lhs = it->m_lhs;
		string rhs = it->m_rhs;

		if (it->m_type == RULE && input.find(lhs) != std::string::npos) {

			#ifdef DEBUG_PARSER
			cout << "Rule applied: " << lhs << " -> " << rhs << endl;
			cout << "Input before: " << input << endl;
			#endif

			input.replace(input.find(lhs), lhs.length(), rhs);

			#ifdef DEBUG_PARSER
			cout << "Input after: " << input << endl;
			#endif

			return true;
		}
	}

	#ifdef DEBUG_PARSER
	cout << "Did not find an applicable rule" << "\n";
	#endif

	return false;
}

string interpret(const vector<Token>& token_vec) {
	
	if (token_vec.size() <= 1) {
		throw "Program is empty or does not contain any rules";
	}

	if (token_vec[0].m_type != INPUT) {
		throw "Did not find an input string";
	}

	int index{};
	string input = token_vec[0].m_lhs;


	bool result_val;

	while ( ( result_val = apply_rules(input, token_vec) ) == true) {
		;
	}

	return input;
}


