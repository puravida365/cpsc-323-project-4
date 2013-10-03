#include <iostream>  
#include <stack>  
#include <string>  

using namespace std;  

class IN2POSTFIX{
	private:
		stack <char> expression;
		string input;
		char infix[256];
		string postfix;
		char answer;
		char *position;
		bool loop;
		int n;
	
	public:
		IN2POSTFIX(){ 
			//postfix = " "; 
			position = infix;
		}
		void getData(){
			cout << "Enter an infix expression with $ at the end: ";
			cin >> input;
			n = input.length();
			for(int i = 0; i < n; ++i){
				infix[i] = input[i];
			}
			
			//cin.getline(infix,256);
		}
		void processData(){
			while(*position != '$'){
			if( (isalpha(*position)) && (*position != '(') && (*position!= ')')){
				postfix += *position;
			}
			else if((*position == '+')||(*position == '-')||(*position == '*')||(*position == '/')){
				while(!expression.empty() && expression.top()!='(' && (expression.top() == *position)){
					postfix += expression.top();
					expression.pop();
				}
				expression.push(*position);
			}
			else if(*position == '('){
				expression.push(*position);
			}
			else if(*position == ')'){
				while(!expression.empty()){
					if(expression.top()=='('){
						expression.pop();
						break;
					}
					postfix += expression.top();
					expression.pop();
				}
			}
			++position;
			}
			while(!expression.empty()){
				postfix += expression.top();
				expression.pop();
			}
		}
		bool runAgain(){
			cout << "Continue(y/n)? ";
			cin >> answer;
			cout << endl;
			answer = toupper(answer);
			if(answer == 'Y'){
				loop = false;
			}
			else{
				loop = true;
			}
			return loop;
		}
		void printResults(){
			cout << "The postfix form is: " << postfix << endl << endl;
			//postfix.clear();
		}
		~IN2POSTFIX(){}
};

int main()
{
	bool answer = false;
	IN2POSTFIX A;
	
	while(answer == false){
		A.getData();
		A.processData();
		A.printResults();
    	answer = A.runAgain();
	}
	
	return 0;
}

/*
Enter an infix expression with $ at the end: c*(a-b))-d*a$
The postfix form is: cab-*da*-

Continue(y/n)? y

Enter an infix expression with $ at the end: a*(b+c*(a-b))+d$
The postfix form is: cab-*da*-d+

Continue(y/n)? n
*/


