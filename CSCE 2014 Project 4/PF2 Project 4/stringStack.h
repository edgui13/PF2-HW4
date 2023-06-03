#ifndef STRINGSTACK_H
#define STRINGSTACK_H

//-----------------------------------------------------------
//  Purpose:    Header file for the integer Stack class.
//  Author:     John Gauch
//-----------------------------------------------------------
#include <cmath>
#include <iostream>
using namespace std;

//-----------------------------------------------------------
// Stack data node definition
//-----------------------------------------------------------
struct StackNode
{
    string Word;
    StackNode *Next;
};

//-----------------------------------------------------------
// Define the Stack class interface
//-----------------------------------------------------------
class Stack
{
public:
    // Constructors
    Stack();
    Stack(const Stack &stack);
    ~Stack();

    // Methods
    bool IsFull();
    bool IsEmpty();
    void Push(string Word);
    void Pop(string &Word);
    string Top();
    int GetLength();
    void Print();

private:
    StackNode *Head;
    int Length;
};

#endif