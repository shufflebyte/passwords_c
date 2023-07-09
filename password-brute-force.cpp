#include <iostream>
#include <iomanip>
#include <sstream>
// openssl muss installiert sein: Linux: sudo apt install libssl-dev
// MacOS: brew install openssl
// Windows: https://sourceforge.net/projects/libssl/files/latest/download herunterladen und in den Ordner zur cpp Datei legen
#include <openssl/sha.h>

using namespace std;

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

string bruteForce(string hash, int length, int startASCII, int endASCII)
{
    char password[length + 1];
    for (int i = 0; i <= length; i++)
    {
        password[i] = '\0';
    }

    bool foundPassword=false;

    for (int cntStellen = 0; (cntStellen < length && foundPassword==false); cntStellen++)
    {
        // immer wenn Länge um 1 erhöht wird
        // password[cntStellen - 1] = startASCII;
        for (int i = 0; i <= cntStellen; i++)
        {
            password[i] = 'a';
        }

        int merkeDurchlaeufe = 0;
        // optimization für ersten Durchlauf
        if (cntStellen == 0)
        {
            merkeDurchlaeufe = endASCII - startASCII;
        }

        // wiederhole für jede Stelle endASCII-startASCII+1 mal
        for (; (merkeDurchlaeufe < endASCII - startASCII + 1) && foundPassword ==false; merkeDurchlaeufe++)
        {

            for (int cntChar = startASCII; cntChar < endASCII + 1; cntChar++)
            {
                password[cntStellen] = cntChar;
                cout << password << endl;
                if (sha256(password) == sha256("zzzzzzzzz"))
                {
                    foundPassword=true;
                    cout << "FOUND!!!!!!!\n";
                    cout << password << sha256(password) << sha256("zzzzzzzzz");
                    break;
                }
            }
            if (cntStellen > 0 && password[cntStellen - 1] < endASCII && foundPassword==false)
            {
                password[cntStellen - 1] = password[cntStellen - 1] + 1;
            }
        }
    }
    cout << "WARUM?" << password;
    return password;
}

int main()
{
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

    return 0;
}