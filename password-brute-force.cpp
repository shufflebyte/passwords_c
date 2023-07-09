#include <iostream>
#include <iomanip>
#include <sstream>
// openssl muss installiert sein: Linux: sudo apt install libssl-dev
// MacOS: brew install openssl
// Windows: https://sourceforge.net/projects/libssl/files/latest/download herunterladen und in den Ordner zur cpp Datei legen
#include <openssl/sha.h>
#include <stdlib.h>
#include <unistd.h>
#include <math.h>

using namespace std;

clock_t beginClock;
clock_t endClock;
bool foundPassword = false;

time_t beginTime;
time_t endTime;

double cntAttempts = 0;

enum Kind
{
    num,
    alpha,
    alphanumspecial
};

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

static const char alphabet_num[] = "0123456789";

static const char alphabet_alpha[] = "abcdefghijklmnopqrstuvwxyz";

static const char alphabet_alphanumspecial[] =
    "abcdefghijklmnopqrstuvwxyz"
    "ABCDEFGHIJKLMNOPQRSTUVWXYZ"
    "0123456789";

int alphabetSize;

void bruteImpl(char *str, int index, int maxDepth, string password, Kind kind, bool verbose)
{
    for (int i = 0; i < alphabetSize && foundPassword == false; ++i)
    {
        switch (kind)
        {
        case num:
            str[index] = alphabet_num[i];
            break;
        case alpha:
            str[index] = alphabet_alpha[i];

        case alphanumspecial:
            str[index] = alphabet_alphanumspecial[i];

        default:
            str[index] = alphabet_alphanumspecial[i];
        }
        cntAttempts++;
        if (index == maxDepth - 1)
        {    
            if (verbose)
            {
                printf("%s\n", str);
            }
            if (sha256(str) == sha256(password))
            {
                cout << endl
                     << "YESS" << str << sha256(password);
                endClock = clock();
                endTime = time(NULL);
                cout << "bruteimpl" << clock() << endl;
                foundPassword = true;
            }
        }
        else {
            bruteImpl(str, index + 1, maxDepth, password, kind, verbose);
            }
    }
}

void bruteSequential(int maxLen, string password, Kind kind, bool verbose)
{
    char *buf = (char *)malloc(maxLen + 1);

    for (int i = 1; i <= maxLen; ++i)
    {
        memset(buf, 0, maxLen + 1);
        bruteImpl(buf, 0, i, password, kind, verbose);
    }

    free(buf);
}

int main(int argc, char *argv[])
{
    if (argc < 3)
    {
        fprintf(stderr, "Usage: %s password alphabet [num, alpha, alphanumspecial], [verbose 1/0]\n", argv[0]);
        fprintf(stderr, "Usage Exmaple: %s myPasswd alpha 0\n", argv[0]);
        return -1;
    }
    string password = argv[1];
    int length = password.length();
    bool verbose = false;

    // cout << "kind" << argv[2];
    // cout << "verbose" << argv[3];
    Kind kind;
    if (strcmp(argv[2], "num") == 0)
    {
        kind = num;
        alphabetSize = sizeof(alphabet_num) - 1;
    }
    else if (strcmp(argv[2], "alpha") == 0)
    {
        kind = alpha;
        alphabetSize = sizeof(alphabet_alpha) - 1;
    }
    else
    {
        kind = alphanumspecial;
        alphabetSize = sizeof(alphabet_alphanumspecial) - 1;
    }

    verbose = argc > 2 ? argv[3] : 0;

    cout << "length: " << length << endl;
    cout << "kind: " << kind << endl;
    cout << "verbose: " << verbose << endl;

    beginClock = clock();
    beginTime = time(NULL);

    bruteSequential(length, password, kind, verbose);

    // cout << beginClock << endl;
    // cout << endClock << endl;
    // cout << CLOCKS_PER_SEC << endl;
    double timeSeconds = (double)(endClock - beginClock) / CLOCKS_PER_SEC;
    double attemptsPerSecond = pow(alphabetSize, password.length());

    cout << "I needed " << timeSeconds << " seconds to crack" << endl;
    cout << "I tried somewhat " << cntAttempts / timeSeconds << " attempts per second "<< "(attempts:" << cntAttempts << ")" << endl;
    //cout << cntAttempts << endl;

    return 0;
}