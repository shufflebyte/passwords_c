
#include <stdio.h>
#include <time.h>
#include <iostream>
#include <unistd.h> // sleep

using namespace std;

int main() {
     time_t begin = time(NULL);
     time_t end;

     //clock_t begin_clock = clock();
     //clock_t end_clock;

    cout << "Hello" << endl;
    sleep(3);
    
    end = time(NULL);
    cout << end-begin << endl;

    //end_clock = clock();
    //cout << (double)(end_clock - begin_clock) / CLOCKS_PER_SEC << endl;

    return 0;
}

// UIDeen:
// Nur auf 2 Aspekte fokussieren
// 1. Länge Passwoet
// 2. Wo man die Special Characters einfügt!
// über das howsecureismypassword ausprobieren und die Zeiträume, die da genannt werden mit einem C-Programm nachprüfen
// brute force und password table möglich