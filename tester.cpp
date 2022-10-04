#include <iostream>
#include <string>
#include <vector>
#include <sstream>
#include <fstream>
#include <stdlib.h>
#include <set>


using namespace std;

int main()
{   
    /*
    char str[100];
    cout << "Enter a string:" << endl;
    cin.getline(str, 100);
    char* point;
    point = strtok(str, "\t");
    while (point!=NULL)
    {
        cout <<point <<endl;
        point = strtok(NULL, "\t");
    }
    */

    string line;
    ifstream name_ofFile("InsultSource.txt");
    if (name_ofFile.fail())
    {
        cout << "Unable to open file" << endl;
        return 1;
    }
    getline(name_ofFile, line);
    cout<<line<<endl;
    char str[100];
    char* point;
    strcpy(str, line.c_str()); 
    point = strtok(str, "\t");
    while (point!=NULL)
    {
        cout <<point<<"." <<endl;
        point = strtok(NULL, "\t");
    }
    getline(name_ofFile, line);
    cout<<line<<endl;
    strcpy(str, line.c_str()); 
    point = strtok(str, "\t");
    cout <<point<<"." <<endl;
    point = strtok(NULL, "\t");
    //cout <<point<<"." <<endl;
    point = strtok(NULL, "\t");
    cout <<point<<"." <<endl;
    /*
    set<string> s;
    s.insert("Thou ian");
    s.insert("Thou tony");
    s.insert("Thou aidan");
    s.insert("Thou andrew");
    s.insert("Thoumax");
    s.insert("Thouartie");
 
    cout << "Elements of set in sorted order: \n";
    for (auto it=s.begin(); it != s.end(); ++it)
    {
        cout << *it <<endl;
    }
    return 0;
*/



}