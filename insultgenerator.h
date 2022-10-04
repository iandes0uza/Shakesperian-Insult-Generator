#pragma once
#include <set>

using namespace std;

//Exception Class declaration
class NumInsultsOutOfBounds
{
    public:
        NumInsultsOutOfBounds(const string& message);
        string what() const;

    private:
        string message;
};

//Exception class decleration
class FileException
{
    public:
        FileException(const string& message);
        string what() const;

    private:
        string message;
};

//InsultGenerator class, functions defined in the .cpp file
class InsultGenerator
{
    public:
        InsultGenerator(); //NULL Constructor
        void initialize(); //Initialization
        void generatorInator(int amount); //Generates set of insults
        string talkToMe(); //Gnerates single insult
        int rnd(); //Generates random number between 0-49
        vector<string> generate(int amount); //Generates string vector of insults
        vector<string> generateAndSave(string file, int amount); //Generates string vector of insults and write to a file
        vector<string> first_insult, second_insult, third_insult; //Stores the different cols of insults
        int insult_counter;

    private:
        string insult;
        char insult_pieces[100]; //Variables used to split text up
        vector<string> final_insults;
        set<string> complete_insults;//Set and vector used for retun values
        
};