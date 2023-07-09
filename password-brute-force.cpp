#include <iostream>
#include <iomanip>
#include <sstream>
// openssl muss installiert sein: Linux: sudo apt install libssl-dev
// MacOS: brew install openssl
// Windows: https://sourceforge.net/projects/libssl/files/latest/download herunterladen und in den Ordner zur cpp Datei legen
#include <openssl/sha.h>
#include <stdlib.h>

using namespace std;

clock_t beginClock;
clock_t endClock;
bool foundPassword = false;

enum Kind
{
    num,
    alpha,
    alphanumspecial
};
Kind kind = alpha;

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

//static const char alphabet_alphanumspecial[] =
static const char alphabet[] =
"abcdefghijklmnopqrstuvwxyz"
"ABCDEFGHIJKLMNOPQRSTUVWXYZ"
"0123456789";

/*static const char alphabet[] =
    "abcdefg";
    */

int alphabetSize = sizeof(alphabet) - 1;

void bruteImpl(char *str, int index, int maxDepth, string password)//, char alphabet[])
{
    for (int i = 0; i < alphabetSize && foundPassword == false; ++i)
    {
        str[index] = alphabet[i];

        if (index == maxDepth - 1)
        {
            // printf("%s\n", str);

            if (sha256(str) == sha256(password))
            {
                cout << endl
                     << "YESS" << str << sha256(password);
                endClock = clock();
                cout << "bruteimpl" << clock() << endl;
                foundPassword = true;
            }
        }
        else
            bruteImpl(str, index + 1, maxDepth, password);//, alphabet);
    }
}

void bruteSequential(int maxLen, string password)//, char alphabet[])
{
    char *buf = (char *)malloc(maxLen + 1);

    for (int i = 1; i <= maxLen; ++i)
    {
        memset(buf, 0, maxLen + 1);
        bruteImpl(buf, 0, i, password);//, alphabet);
    }

    free(buf);
}

int main(int argc, char *argv[])
{
    if (argc < 2)
    {
        fprintf(stderr, "Usage: %s password\n", argv[0]);
    }
    string password = argv[1];
    int length = password.length();

    char alphabet2 = *alphabet;
    int alphabetSize = sizeof(alphabet)/sizeof(char);
    cout << alphabetSize;
    /*

    cout << "length:" <<length << endl;

    beginClock = clock();

    bruteSequential(length, password);//, &alphabet_num);
    cout << beginClock << endl;
    cout << endClock << endl;
    cout << CLOCKS_PER_SEC << endl;
    cout << (double)(endClock - beginClock) / CLOCKS_PER_SEC << endl;
*/
    /*

        // Einlesen
        cout << "Enter Password" << endl;
        string password;
        string hash;

        getline(cin, password);
        cout << password << '\t' << sha256(password) << '\n';

        // Berechnen:
        double estimatedTime;

        // char startASCII = 33; // '!'
        // char endASCII = 126; // '~'

        char startASCII = 'a';
        char endASCII = 'c';

        // Bruteforce durchführen und Zeit messen: wir zählen die Clock Cycles und teilen durch Cycles / s
        clock_t beginClock = clock();
        clock_t endClock;

        int maxLength = 4;

        string foundPassword = bruteForce(hash, maxLength, startASCII, endASCII);
        cout << "Entered password:" << '\t' << "Found password: " << foundPassword << '\t' << "Hash: " << hash;

        endClock = clock();
        cout << (double)(endClock - beginClock) / CLOCKS_PER_SEC << endl;
        */

    return 0;
}