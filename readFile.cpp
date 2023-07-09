#include <iostream>
#include <fstream>
#include <string>

using namespace std;

int main()
{
    //   string filename;
    //   cout << "Datei: ";
    //   cin >> filename;
    string filename = "passwords.txt";

    ifstream input(filename);

    if (!input)
    {
        cerr << "Fehler beim Oeffnen der Datei " << filename << "\n";
        return 1;
    }

    string line;

    while (getline(input, line))
    {
        cout << line << '\n';
    }
    return 0;
}