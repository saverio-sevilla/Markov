#include <iostream>
#include "Interpreter.h"
#include <string>
#include <vector>

using namespace std;

int main() {

	string filename = "bin_test.txt";
	vector<Token> token_vec;
	string result;

	parseFile(filename, token_vec);

	for (auto token : token_vec) {
		token.print();
	}

	cout << "\n" << "Interpreting..." << endl;
		 
	try {
		result = interpret(token_vec);
	}
	catch (string& err) {
		cout << err << "\n";
	}

	cout << result << endl;

}