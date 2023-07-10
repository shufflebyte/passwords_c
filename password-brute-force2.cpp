#include <stdlib.h>
#include <iostream>

using namespace std;

enum Alphabet
{
    num,
    alpha,
    alphanumspecial
};
const int MAX_PWD_LENGTH = 10;

string searchedHash;
Alphabet alphabet = num;
int passwordLength = MAX_PWD_LENGTH;
bool verbose = true;

/* Command-Line Arguments richtig einlesen */
int parseArguments(int argc, char *argv[])
{
    if (argc < 3)
    {
        cerr << "Usage: \t\t\t" << argv[0] << " hash alphabet [passwordLength] [verbose]\n";
        cerr << "Usage Exmaple:\t\t" << argv[0] << " 123abebfb3b5bdb3 alpha 5 0\n";
        cerr << "Minimum Exmaple:\t" << argv[0] << " 123abebfb3b5bdb3 alpha\n";
        return 1;
    }

    searchedHash = argv[1];

    if (strcmp(argv[2], "num") == 0)
    {
        alphabet = num;
    }
    else if (strcmp(argv[2], "alpha") == 0)
    {
        alphabet = alpha;
    }
    else
    {
        alphabet = alphanumspecial;
    }

    passwordLength = argc > 3 ? atoi(argv[3]) : MAX_PWD_LENGTH;
    verbose = argc > 4 ? atoi(argv[4]) : false;

    if (verbose)
        cout << searchedHash << alphabet << passwordLength << verbose;

    return 0;
}

int main(int argc, char *argv[])
{
    // Argumente einlesen
    if (parseArguments(argc, argv))
    {
        return -1;
    }
    cout << "YO";

    // brute force

    return 0;
}