//
// Created by Jay Vatti on 9/26/22.
//

#include "StockSpan.h" //including the header file
StockSpan::StockSpan(): len(0) { //member initializer list
    int value = 0; //storing the input (len)

    std::cout<<" --------- STOCK SPAN ----------"<<std::endl;
    std::cout<<"Enter the 'Length' of the stock:";
    std::cin>>value; //taking input for length of the stock
    len = value;//setting len

    std::cout<<std::endl;
    std::cout<<"(only enter "<<len<<" numbers)"<<std::endl;
    std::cout<<"Enter the Stock:"<<std::endl;
    for(int i = 0; i < len; i++){ //repeats len - 1 times
        std::cin>>value; //input for stock;
        stock.push_back(value);//pushing the input to the std::vector<int> stock in the Class StockSpan
    }
}
std::vector<int> StockSpan::spanBruteForce() const{
    std::vector<int>output(len);
    for(int i = 0; i < len; i++){
        int value = 1; //default value = 1
        while(value <= i && stock[i-value] <= stock[i]){
            value++;//increments if value <= i  && //if the value of i less than i-value
        }
        output[i] = value; // sets "value" to index "i" in std::vector<int> output
    }
    return output;//returns std::vector<int> output
}
std::stack<int> StockSpan::spanStack() {
    std::stack<int>output; //output stored using stack // can reduce complexity if std::vector<int> used
    for(int i = 0; i< len; i++){
        int value = 1;
        while(not(stockPrices.empty()) && not(stockPrices.empty()) && stock[i] >= stockPrices.top()){
            value = value + days.top();
            stockPrices.pop();
            days.pop();
        }
        stockPrices.push(stock[i]);
        days.push(value);

        output.push(value);
    }

    return output; //returning stack
}
void StockSpan::printStack(std::stack<int>stackInput){ //printing stack // O(n^2) //
    if(not(stackInput.empty())){
        int printStackValue = stackInput.top();
        stackInput.pop();
        printStack(stackInput);
        std::cout<<printStackValue<<" ";
    }
}

void StockSpan::print(std::vector<int> input) const{ //takes a std::vector<int> and prints it
    for(int i = 0; i < len; i++){
        std::cout<<input[i]<<" ";//printing the index
    }
    std::cout<<std::endl;
}
void StockSpan::GUI(){
    std::cout<<" --------- STOCK SPAN ----------"<<std::endl;
    bool keepGoing = true;
    for(;keepGoing;){
        std::cout<<std::endl;
        std::string input;
        std::cout<<"Enter 1 for BRUTE FORCE!"<<std::endl;
        std::cout<<"Enter 2 for USING STACK!"<<std::endl;
        std::cout<<"Enter 3 for BRUTEFORCE & USING STACK!"<<std::endl;
        std::cout<<"Enter 4 to EXIT!"<<std::endl;
        std::cout<<"Enter an option:";
        std::cin>>input;
        std::cout<<std::endl;
        if(input == "1"){
            std::cout<<"Stock Prices: "; //Printing Stock Prices
            print(stock);//stack is a std::vector<int>

            std::cout<<"Stock Span (BRUTE FORCE): "; //Printing BRUTE FORCE
            print(spanBruteForce());//spanBruteForce() returns std::vector<int>
        }
        else if (input == "2"){
            std::cout<<"Stock Prices: "; //Printing Stock Prices
            print(stock);//stack is a std::vector<int>

            std::cout<<"Stock Span (USING STACK): "; //Printing using STACK
            //stock1.printStraightStack(stock1.spanStack());//spanStack() returns std::vector<int>
            printStack(spanStack());//spanStack() returns std::stack<int> // printStack prints the stack (reverse order)
            std::cout<<std::endl;
        }
        else if (input == "3"){

            std::cout<<"Stock Prices: "; //Printing Stock Prices
            print(stock);//stack is a std::vector<int>

            std::cout<<"Stock Span (BRUTE FORCE): "; //Printing BRUTE FORCE
            print(spanBruteForce());//spanBruteForce() returns std::vector<int>

            std::cout<<"Stock Span (USING STACK): "; //Printing using STACK

            while(not(stockPrices.empty()) && not(days.empty())){ //emptying stacks
                stockPrices.pop();//clearing the stack
                days.pop();//clearing the stack
            }
            //stock1.printStraightStack(stock1.spanStack());//spanStack() returns std::vector<int>
            printStack(spanStack());//spanStack() returns std::stack<int> // printStack prints the stack (reverse order)
            std::cout<<std::endl;

            while(not(stockPrices.empty()) && not(days.empty())){ //emptying stacks
                stockPrices.pop();//clearing the stack
                days.pop();//clearing the stack
            }
        }
        else if (input == "4"){
            std::cout<<"Exiting the program!!"<<std::endl;
            keepGoing = false;//stops the for loop;
        }
        else{
            std::cout<<"Enter a correct Option!"<<std::endl;
        }
    }
}