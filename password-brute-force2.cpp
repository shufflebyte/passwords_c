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
char startChar = 'a';
char endChar = 'z';

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

    searchedHash = (string)argv[1];

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

/* zu ersetzen!*/
string sha256(string word)
{

    return word;
}

bool check(string word)
{
    if (verbose)
    {
        for (int i = 0; i < passwordLength; i++)
            cout << word[i];
        cout << endl;
    }

    string hash = sha256(word);
    if (hash.compare(searchedHash) == 0)
    {
        cout << "Found password!" << endl;
        cout << "word: " << word << '\t' << "hash: " << hash << '\t' << "searched: " << searchedHash << endl;
        return true;
    }
    return false;
}

int bruteForce3()
{
    char word[MAX_PWD_LENGTH + 1];
    word[passwordLength] = '\0';

    for (word[0] = startChar; word[0] <= endChar; word[0]++)
    {
        for (word[1] = startChar; word[1] <= endChar; word[1]++)
        {
            for (word[2] = startChar; word[2] <= endChar; word[2]++)
            {
                if (check(word))
                {
                    return 0;
                }
            }
        }
    }
    cout << "Kein Passwort mit Länge " << passwordLength << " gefunden." << endl;
    return 0;
}

int bruteForce4()
{
    char word[MAX_PWD_LENGTH + 1];
    word[passwordLength] = '\0';

    for (word[0] = startChar; word[0] <= endChar; word[0]++)

        for (word[1] = startChar; word[1] <= endChar; word[1]++)
            for (word[2] = startChar; word[2] <= endChar; word[2]++)
                for (word[3] = startChar; word[3] <= endChar; word[3]++)
                {
                    if (check(word))
                    {
                        return 0;
                    }
                }

    cout << "Kein Passwort mit Länge " << passwordLength << " gefunden." << endl;
    return 0;
}
int bruteForce5()
{
    char word[MAX_PWD_LENGTH + 1];
    word[passwordLength] = '\0';

    for (word[0] = startChar; word[0] <= endChar; word[0]++)

        for (word[1] = startChar; word[1] <= endChar; word[1]++)
            for (word[2] = startChar; word[2] <= endChar; word[2]++)
                for (word[3] = startChar; word[3] <= endChar; word[3]++)
                    for (word[4] = startChar; word[4] <= endChar; word[4]++)
                    {
                        if (check(word))
                        {
                            return 0;
                        }
                    }

    cout << "Kein Passwort mit Länge " << passwordLength << " gefunden." << endl;
    return 0;
}
int bruteForce6()
{
    char word[MAX_PWD_LENGTH + 1];
    word[passwordLength] = '\0';

    for (word[0] = startChar; word[0] <= endChar; word[0]++)

        for (word[1] = startChar; word[1] <= endChar; word[1]++)
            for (word[2] = startChar; word[2] <= endChar; word[2]++)
                for (word[3] = startChar; word[3] <= endChar; word[3]++)
                    for (word[4] = startChar; word[4] <= endChar; word[4]++)
                        for (word[5] = startChar; word[5] <= endChar; word[5]++)
                        {
                            if (check(word))
                            {
                                return 0;
                            }
                        }

    cout << "Kein Passwort mit Länge " << passwordLength << " gefunden." << endl;
    return 0;
}

int bruteForce7()
{
    char word[MAX_PWD_LENGTH + 1];
    word[passwordLength] = '\0';

    for (word[0] = startChar; word[0] <= endChar; word[0]++)

        for (word[1] = startChar; word[1] <= endChar; word[1]++)
            for (word[2] = startChar; word[2] <= endChar; word[2]++)
                for (word[3] = startChar; word[3] <= endChar; word[3]++)
                    for (word[4] = startChar; word[4] <= endChar; word[4]++)
                        for (word[5] = startChar; word[5] <= endChar; word[5]++)
                            for (word[6] = startChar; word[6] <= endChar; word[6]++)
                            {
                                if (check(word))
                                {
                                    return 0;
                                }
                            }

    cout << "Kein Passwort mit Länge " << passwordLength << " gefunden." << endl;
    return 0;
}

int bruteForce8()
{
    char word[MAX_PWD_LENGTH + 1];
    word[passwordLength] = '\0';

    for (word[0] = startChar; word[0] <= endChar; word[0]++)

        for (word[1] = startChar; word[1] <= endChar; word[1]++)
            for (word[2] = startChar; word[2] <= endChar; word[2]++)
                for (word[3] = startChar; word[3] <= endChar; word[3]++)
                    for (word[4] = startChar; word[4] <= endChar; word[4]++)
                        for (word[5] = startChar; word[5] <= endChar; word[5]++)
                            for (word[6] = startChar; word[6] <= endChar; word[6]++)
                                for (word[7] = startChar; word[7] <= endChar; word[7]++)
                                {
                                    if (check(word))
                                    {
                                        return 0;
                                    }
                                }

    cout << "Kein Passwort mit Länge " << passwordLength << " gefunden." << endl;
    return 0;
}

int bruteForce9()
{
    char word[MAX_PWD_LENGTH + 1];
    word[passwordLength] = '\0';

    for (word[0] = startChar; word[0] <= endChar; word[0]++)
        for (word[1] = startChar; word[1] <= endChar; word[1]++)
            for (word[2] = startChar; word[2] <= endChar; word[2]++)
                for (word[3] = startChar; word[3] <= endChar; word[3]++)
                    for (word[4] = startChar; word[4] <= endChar; word[4]++)
                        for (word[5] = startChar; word[5] <= endChar; word[5]++)
                            for (word[6] = startChar; word[6] <= endChar; word[6]++)
                                for (word[7] = startChar; word[7] <= endChar; word[7]++)
                                    for (word[8] = startChar; word[8] <= endChar; word[8]++)
                                    {
                                        if (check(word))
                                        {
                                            return 0;
                                        }
                                    }

    cout << "Kein Passwort mit Länge " << passwordLength << " gefunden." << endl;
    return 0;
}

int main(int argc, char *argv[])
{
    // Argumente einlesen
    if (parseArguments(argc, argv))
    {
        return -1;
    }
    cout << "Beginne Suche..." << endl;

    // brute force
    switch (passwordLength)
    {
    case 3:
        bruteForce3();
        break;
    case 4:
        bruteForce4();
        break;
    case 5:
        bruteForce5();
        break;
    case 6:
        bruteForce6();
        break;
    case 7:
        bruteForce7();
        break;
    case 8:
        bruteForce8();
        break;
    case 9:
        bruteForce9();
        break;
    default:
        cout << "Wird nicht unterstützt, nur 3 bis 10";
        break;
    }
    return 0;
}