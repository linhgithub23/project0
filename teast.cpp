#include<iostream>
#include<fstream>
using namespace std;
int main()
{
        ifstream MyFile;
        MyFile.open(input.txt);

        int sum = 0;
        string line;


        while (getline(MyFile, line))  //reading a line from the file while possible
        {
            sum = sum + stoi(line);    // convert string to number and add it to the sum
        }

        MyFile.close();   // closing the file

        cout << "sum is: " << sum;  // print the sum

    cin.get();

    return 0;
}