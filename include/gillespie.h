/*
 * Copyright (c) 2017 <copyright holder> <email>
 *
 * Permission is hereby granted, free of charge, to any person
 * obtaining a copy of this software and associated documentation
 * files (the "Software"), to deal in the Software without
 * restriction, including without limitation the rights to use,
 * copy, modify, merge, publish, distribute, sublicense, and/or sell
 * copies of the Software, and to permit persons to whom the
 * Software is furnished to do so, subject to the following
 * conditions:
 *
 * The above copyright notice and this permission notice shall be
 * included in all copies or substantial portions of the Software.
 *
 * THE SOFTWARE IS PROVIDED "AS IS", WITHOUT WARRANTY OF ANY KIND,
 * EXPRESS OR IMPLIED, INCLUDING BUT NOT LIMITED TO THE WARRANTIES
 * OF MERCHANTABILITY, FITNESS FOR A PARTICULAR PURPOSE AND
 * NONINFRINGEMENT. IN NO EVENT SHALL THE AUTHORS OR COPYRIGHT
 * HOLDERS BE LIABLE FOR ANY CLAIM, DAMAGES OR OTHER LIABILITY,
 * WHETHER IN AN ACTION OF CONTRACT, TORT OR OTHERWISE, ARISING
 * FROM, OUT OF OR IN CONNECTION WITH THE SOFTWARE OR THE USE OR
 * OTHER DEALINGS IN THE SOFTWARE.
 *
 */

#ifndef GILLESPIE_H
#define GILLESPIE_H

#include <vector>
#include <math.h>
#include <stdlib.h>
#include <time.h>
#include <iostream>
#include <fstream>

using namespace std;

class Gillespie{

  double NA, NB;

  vector<double> molecules{200,50}; //Anzahl Moleküle N_A, N_B, ...

  vector<double> reactions_rate{4.5e-1, 3e-2}; //Reaktionskonstanten k1 und k2
  double nrReactions = 1000; // Anzahl der Reaktionen

  double wplus, wminus, t;

  // output file
  ofstream fs;
    
 public:

  Gillespie();

  double randomnumber();
  void doreaction();

  // -------------------
  // getter and setter
  // -------------------

  double getNrReactions();
  void setNrReactions(double n);


};

#endif // GILLESPIE_H
