/*
Wie man das Programm benutzt:
* (optional) Generiere Hash den du suchen cracken willst: echo -n abc | shasum -a 256 | awk '{ print $1 }'
* Formuliere Argumente: ./password-brute-force2.o ba7816bf8f01cfea414140de5dae2223b00361a396177a9cb410ff61f20015ad alpha 3 1
Boom!
*/

#include <stdlib.h>
#include <iostream>

// sha256
#include <openssl/sha.h>
#include <sstream>
#include <iomanip>

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

clock_t beginClock;
clock_t endClock;

double cntAttempts = 0;

/* Command-Line Arguments richtig einlesen */
int parseArguments(int argc, char *argv[])
{
    if (argc < 3)
    {
        cerr << "Usage: \t\t\t" << argv[0] << " hash alphabet [passwordLength] [verbose]\n";
        cerr << "Usage Exmaple:\t\t" << argv[0] << " 6304fbfe2b22557c34c42a70056616786a733b3d09fb326308c813d6ab712ec0 alpha 5 0\n";
        cerr << "Minimum Exmaple:\t" << argv[0] << " 6304fbfe2b22557c34c42a70056616786a733b3d09fb326308c813d6ab712ec0 alpha\n";
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

// Funktion von https://terminalroot.com/how-to-generate-sha256-hash-with-cpp-and-openssl/
string sha256(const string str)
{
    unsigned char hash[SHA256_DIGEST_LENGTH];

    SHA256_CTX sha256;
    SHA256_Init(&sha256);
    SHA256_Update(&sha256, str.c_str(), str.size());
    SHA256_Final(hash, &sha256);

    stringstream ss;

    for (int i = 0; i < SHA256_DIGEST_LENGTH; i++)
    {
        ss << hex << setw(2) << setfill('0') << static_cast<int>(hash[i]);
    }
    return ss.str();
}

bool check(string word)
{
    cntAttempts += 1;
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

    beginClock = clock();

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
        cout << "Wird nicht unterstützt, nur 3 bis 9";
        break;
    }

    endClock = clock();
    double timeSeconds = (double)(endClock - beginClock) / CLOCKS_PER_SEC;
    // double attemptsPerSecond = pow(alphabetSize, password.length());

    cout << "I needed " << timeSeconds << " seconds to crack" << endl;
    cout << "I tried somewhat " << cntAttempts / timeSeconds << " attempts per second "
         << "(attempts:" << cntAttempts << ")" << endl;

    return 0;
}