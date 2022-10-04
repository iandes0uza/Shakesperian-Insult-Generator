#include "insultgenerator.h"
#include <fstream>
#include <sstream>
#include <string.h>
#include <vector>
using namespace std;


//predefined name of the file to avoid re-use issues
string FILE_NAME = "InsultSource.txt";
int MAX_GENERATED = 10000;


InsultGenerator::InsultGenerator() {}

void InsultGenerator::initialize() //reads file and saves insults in an array
{
    //starts the amount of insults at 0
    insult_counter = 0;

    //Open file and check if its there/readable
    ifstream file(FILE_NAME);
    if (file.fail())
    {
        throw FileException("Unable to open file: " + FILE_NAME);
        return;
    }

    //This while loop was created to prevent the program from crashing if running into an error during reading.
    while (!file.eof())
    {
        //This block inputs line, and consecutively splits at every "tab" instance
        getline(file, insult);
        if (insult == ""){
            continue;
        }
        strcpy(insult_pieces, insult.c_str());
        first_insult.push_back(strtok(insult_pieces, "\t"));
        second_insult.push_back(strtok(NULL, "\t"));
        third_insult.push_back(strtok(NULL, "\t"));
        insult_counter++;
    }
    file.close();
}

int InsultGenerator::rnd()
{
    //concise shortcut to avoid repitition
    return (rand() % insult_counter);
    //no srand as there is a very low chance a set of 3 numbers get produced again, rather use set functionality
}

string InsultGenerator::talkToMe()
{
    //generates a singular insult
    return "Thou " + first_insult[rnd()] + " " + second_insult[rnd()] + " " + third_insult[rnd()] + "!";
}

void InsultGenerator::generatorInator(int amount)
{
    //ensures set & vector is cleared to begin with
    complete_insults.clear();
    final_insults.clear();

    //checks to see if valid amount of strings were called
    if (amount > MAX_GENERATED || amount <= 0)
    {
        throw NumInsultsOutOfBounds("Invalid amount of insults, please try again with a different amount");
        return;
    }
    
    //generates specified amount of insults, uniqueness with sets
    while (complete_insults.size() < amount) complete_insults.insert(talkToMe());
}

vector<string> InsultGenerator::generate(int amount)
{
    //generates values and places them into a set
    generatorInator(amount);

    //returns set content's copied into a string vector
    final_insults.assign(complete_insults.begin(), complete_insults.end());
    return (final_insults);
}

vector<string> InsultGenerator::generateAndSave(string file, int amount)
{
    //generates values and places them into a set
    generatorInator(amount);

    //saves generated insults into a file with the specified name
    ofstream outputFile(file);
    for (set<string>::iterator i = complete_insults.begin(); i!=complete_insults.end(); ++i)
    {
        outputFile << *i;
        outputFile << "\n";
    }


    //returns set content's copied into a string vector
    final_insults.assign(complete_insults.begin(), complete_insults.end());
    return (final_insults);

}

//****************************EXCEPTION CLASSES****************************
FileException::FileException(const string& message){}

string FileException::what() const
{
    //returns message of the File Exception
	return message;
}

NumInsultsOutOfBounds::NumInsultsOutOfBounds(const string& message){}

string NumInsultsOutOfBounds::what() const
{
    //returns message of the NumInsults out of bounds
	return message;
}
//**************************************************************************
