#include <iostream>
#include <fstream>
#include <time.h>

#include <Gillespie.h>

using namespace std;


int main(int argc, char **argv) {

    Gillespie gillespie;
    
    srand (time(NULL)); // initiere Startzeitpunkt
    for (int i = 0; i<gillespie.getNrReactions(); i++){
        
        cout << i << endl;
        
        gillespie.doreaction(); //starte Simulation
    }
return 0;
}
