class Solution {
  public:
    int priority(string& op){
        if(op == "+" or op == "-") return 1;
        else if(op == "*" or op == "/") return 2;
        else return 3;
    }
    int operation(int& a, int& b, string& op){
            if(op == "+") return a + b;
            else if(op == "-") return a - b;
            else if(op == "*") return a * b;
            else if(op == "^") return pow(a,b);
            else{ // op == "/"
                // return a/b; // wrong
                return floor(float(a)/b);
            }
        }
    int evaluateInfix(vector<string>& arr) {
        stack<int> numbers;
        stack<string> operators;
        for(string s : arr){
            if(s=="+" or s=="-" or s=="*" or s=="/" or s=="^" ){ // work
                if(s=="^") operators.push(s);
                else{
                    while(operators.size() > 0 && priority(operators.top()) >= priority(s)){ // work
                        string op = operators.top();
                        operators.pop();
                        int b = numbers.top();
                        numbers.pop();
                        int a = numbers.top();
                        numbers.pop();
                        numbers.push(operation(a,b,op));
                    }
                    operators.push(s);
                }
            }
            else numbers.push(stoi(s));
        }
        while(operators.size() > 0){ // work
            string op = operators.top();
            operators.pop();
            int b = numbers.top();
            numbers.pop();
            int a = numbers.top();
            numbers.pop();
            numbers.push(operation(a,b,op));
        }
        return numbers.top();
    }
};
