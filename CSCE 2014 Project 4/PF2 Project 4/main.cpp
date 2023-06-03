#include "stringStack.h"
#include <iostream>
#include <fstream>
#include <string>

using namespace std;
//-----------------------------------------------------------
// Read files
//-----------------------------------------------------------
void readFile(Stack &stk, string fileName)
{
    // open input file
    ifstream din;
    din.open(fileName);

    // decalre variables
    char delim;
    string input;

    if (din.fail())
    {
        cout << "Could not open unknown file" << endl;
    }

    do
    {
        din.get(delim);
        if (delim == '<')
        {
            getline(din, input, '>');
            // verify the input
            if (input[0] != '/')
            {
                cout << " valid input " << input << endl;
                for (int i = 0; i < input.length(); i++)
                {
                    // remove whitespace if neccessary
                    if (input[i] == ' ')
                    {
                        input = input.erase(i, input.length() - i);
                    }
                }
                // push to stack if valid or when whitespace is removed
                stk.Push(input);
            }
            else // if the input has a '/'
            {
                // erase the '/' before the rest of the string
                cout << " input before " << input << endl;
                input.erase(0, 1);
                cout << "input after" << endl;
                // pop input if its the same as the Top of the stack
                if (input == stk.Top())
                {
                    cout << " popping input " << input << endl;
                    stk.Pop(input);
                }
            }
        }
    } while (din.get(delim));
    cout << stk.GetLength() << endl;
    din.close();
}

//-----------------------------------------------------------
// Main program.
//-----------------------------------------------------------
int main()
{
    // initialize stack
    int selection;

    do
    {
        cout << "<><><><><><><><><><><><><><><><><><><>" << endl;
        cout << "Welcome to Project 4!!!" << endl;
        cout << "<><><><><><><><><><><><><><><><><><><>" << endl;
        cout << "1. Create stack for sample 1" << endl;
        cout << "2. Create stack for sample 2" << endl;
        cout << "3. Create stack for sample 3" << endl;
        cout << "4. Create stack for sample 4" << endl;
        cout << "5. Create stack for sample 5" << endl;
        cout << "6. Quit The Program" << endl;
        cout << "Please Select an option: ";
        cin >> selection;

        if (selection <= 0 || selection > 7)
        {
            cout << "Error!, please select an option between 1-3" << endl;
        }

        switch (selection)
        {
        case 1:
        {
            Stack stk;
            readFile(stk, "sample1.txt");
            break;
        }
        case 2:
        {
            Stack stk;
            readFile(stk, "sample2.txt");
            stk.Print();
            break;
        }
        case 3:
        {
            Stack stk;
            readFile(stk, "sample3.txt");
            stk.Print();
            break;
        }
        case 4:
        {
            Stack stk;
            readFile(stk, "sample4.txt");
            stk.Print();
            cout << "XML file was in incorrect format" << endl;
            break;
        }
        case 5:
        {
            Stack stk;
            readFile(stk, "sample5.txt");
            stk.Print();
            cout << "XML file was in incorrect format" << endl;
            break;
        }
        }
    } while (selection != 6);
}
