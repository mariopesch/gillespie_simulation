#include <iostream>
#include "gillespie.h"
#include <fstream>
#include <time.h>

using namespace std;

gillespie reaction;



int main(int argc, char **argv) {
  srand (time(NULL)); // initiere Startzeitpunkt
reaction.doreaction(); //starte Simulation

return 0;
}
