#include <iostream>
#include <fstream>
using namespace std;

int main()
{
    ofstream output;
    ifstream i;
    // output.open("file.txt", ios::app); //out to overwrite the file
    // if (output.fail())
    // {
    //     cout << "File couldn't be either created or opened" << endl;
    //     exit(1);
    // }

    // output << "File created" << endl;
    // output.close();

    i.open("fileI.txt", ios::in);
    if (i.fail())
    {
        cout << "File couldn't be either created or opened" << endl;
        exit(1);
    }

    string text;

    while (!i.eof())
    {

        getline(i, text);
        cout << text;
    }

    i.close();

    return 0;
}

