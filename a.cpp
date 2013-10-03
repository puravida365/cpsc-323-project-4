#include <iostream>  
#include <stack>  
#include <string>  

using namespace std;  

class INTOPOST{
	private:
		stack <char> s;
		char infix[100];
		string postfix;
		char answer;
		char *p;
		bool loop;
	
	public:
		INTOPOST(){ postfix = " "; p = infix;}
		void getData(){
			cout << "Enter an infix expression with $ at the end: ";
			cin.getline(infix,100);
		}
		void processData(){
			while(*p != '$'){
			if( (isalpha(*p)) && (*p != '(') && (*p!= ')')){
				postfix+=*p;
			}
			else if((*p == '+')||(*p == '-')||(*p == '*')||(*p == '/')){
				while(!s.empty() && s.top()!='(' && (s.top()==*p)){
					postfix+=s.top();
					s.pop();
				}
				s.push(*p);
			}
			else if(*p == '('){
				s.push(*p);
			}
			else if(*p == ')'){
				while(!s.empty()){
					if(s.top()=='('){
						s.pop();
						break;
					}
					postfix += s.top();
					s.pop();
				}
			}
			++p;
			}
			while(!s.empty()){
				postfix += s.top();
				s.pop();
			}
		}
		bool runAgain(){
			cout << "Continue(y/n)? ";
			cin >> answer;
			cout << endl << endl;
			answer = toupper(answer);
			if(answer == 'Y'){
				return true;
			}
			else{
				return false;
			}
		}
		void printResults(){
			cout << "The postfix form is: " << postfix << endl << endl;
		}
};

int main()
{
	bool answer = true;
	INTOPOST A;
	
	do{
		A.getData();
		A.processData();
		A.printResults();
    	answer = A.runAgain();
	}while(answer == true);
	
	return 0;
}




