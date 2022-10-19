//
// Created by Jay Vatti on 9/26/22.
//
#include <iostream>
#include <vector>
#include <stack>
#include <string>

#pragma once

class StockSpan {
public:
    int len; //length of the Stock
    std::vector<int> stock;// input

    std::stack<int> stockPrices;
    std::stack<int> days;

    StockSpan(); //default constructor
    void print(std::vector<int> input) const; //printing the vector
    std::vector<int> spanBruteForce() const;// BRUTE FORCE ALGORITHM
    std::stack<int> spanStack() ;//returns a Stack
    void printStack(std::stack<int>stackInput);//printing stack (bottom-to-top) -> O(n^2) //can be reduced to O(n) if std::vector<int> used
    void GUI();
};
