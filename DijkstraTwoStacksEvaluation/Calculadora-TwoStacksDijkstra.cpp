// CPP program to evaluate a given 
// expression where tokens are 
// separated by space. 
#include <bits/stdc++.h> 
using namespace std; 

// Function to find precedence of 
// operators. 
int precedence(string op){ 
	if (op == "+"||op == "-") 
		return 1; 
	if (op == "*"||op == "/") 
		return 2; 
	
	cerr << "Operador no detectado: " << op << endl;
	return 0; 
} 

char isBinary(string op) {
	return (op == "+" || op == "-" || op == "*" || op == "/");
}

// Function to perform arithmetic operations. 
int applyOp(int a, int b, string op){ 
	if (op == "+")
		return a + b;
	else if (op == "-")
		return a - b;
	else if (op == "*")
		return a * b;
	else if (op == "/")
		return a / b;
	else {
		cerr << "Operador no detectado: " << op << endl;
		return 0;
	}
} 

// Function to perform arithmetic operations. 
double applyFunc(int a, string func){ 
	if (func == "sqrt")
		return sqrt(a);
	else if (op == "-")
		return a - b;
	else if (op == "*")
		return a * b;
	else if (op == "/")
		return a / b;
	else {
		cerr << "Operador no detectado: " << op << endl;
		return 0;
	}
} 

// Function that returns value of 
// expression after evaluation. 
int evaluate(string tokens){ 
	string token;
	int i;
	
	// stack to store integer values. 
	stack <int> values; 
	
	// stack to store operators. 
	stack <string> ops; 
	
	for(i = 0; i < tokens.length(); i++) { 
		token = "";
		token += tokens[i];
		// Current token is a whitespace, 
		// skip it. 
		if(tokens[i] == ' ') 
			continue; 
		
		// Current token is an opening 
		// brace, push it to 'ops' 
		else if(tokens[i] == '('){ 
			ops.push(token); 
		} 
		
		// Current token is a number, push 
		// it to stack for numbers. 
		else if(isdigit(tokens[i])){ 
			int val = 0; 
			
			// There may be more than one 
			// digits in number. 
			while(i < tokens.length() && 
						isdigit(tokens[i])) 
			{ 
				val = (val*10) + (tokens[i]-'0'); 
				i++; 
			} 
			
			values.push(val); 
		} 
		
		// Closing brace encountered, solve 
		// entire brace. 
		else if(tokens[i] == ')') 
		{ 
			while(!ops.empty() && ops.top() != "(") 
			{ 
				
				int val2 = values.top(); 
				values.pop(); 
				
				int val1 = values.top(); 
				values.pop(); 
				
				string op = ops.top(); 
				ops.pop(); 
				
				values.push(applyOp(val1, val2, op)); 
			} 
			
			// pop opening brace. 
			ops.pop(); 
		} 
		else {
			int j = i+1;
			while(j < tokens.length() && !isdigit(tokens[j]) && tokens[j] != '(' 
				&& tokens[j] != ')' && tokens[j] != ' ' ) 
			{ 
				token += tokens[j];
				j++; 
			}
			
			if (isBinary(tokens[i].to_string()))
			{ 
				// While top of 'ops' has same or greater 
				// precedence to current token, which 
				// is an operator. Apply operator on top 
				// of 'ops' to top two elements in values stack. 
				while(!ops.empty() && precedence(ops.top()) 
									>= precedence(tokens[i])){ 
					int val2 = values.top(); 
					values.pop(); 
					
					int val1 = values.top(); 
					values.pop(); 
					
					string op = ops.top(); 
					ops.pop(); 
					
					values.push(applyOp(val1, val2, op)); 
				} 
				
				// Push current token to 'ops'. 
				ops.push(tokens[i].to_string()); 
			}
			else if (			
			ops.push(token);
		}
		// Current token is an operator. 

		else 
		{ 
			string func = tokens[i].to_string();
			while(i < tokens.length() && 
				isdigit(tokens[i])) 
			cerr << "KK"<<endl;
			
		}
	} 
	
	// Entire expression has been parsed at this 
	// point, apply remaining ops to remaining 
	// values. 
	while(!ops.empty()){ 
		int val2 = values.top(); 
		values.pop(); 
				
		int val1 = values.top(); 
		values.pop(); 
				
		string op = ops.top(); 
		ops.pop(); 
				
		values.push(applyOp(val1, val2, op)); 
	} 
	
	// Top of 'values' contains result, return it. 
	return values.top(); 
} 

int main() { 
	cout << "Calculadora" << endl;
	cout << evaluate("10 + 2 * 6") << "\n"; 
	cout << evaluate("100 * 2 + 12") << "\n"; 
	cout << evaluate("100 * ( 2 + 12 )") << "\n"; 
	cout << evaluate("100 * ( 2 + 12 ) / 14") << endl; 
	cout << evaluate("8 / 2 * 4") << endl; 
	cout << evaluate("64 / 2 * 2 / 2 / 4") << endl; 
	return 0; 
} 

// This code is contributed by Nikhil jindal. 

