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

#include <math.h>
#include <vector>
#include <iostream>
#include <fstream>
#include <random>

#include <Gillespie.h>

using namespace std;

Gillespie::Gillespie() {

  std::string filename = "timeSeries.csv";
  fs.open(filename.c_str(),ios::out);
  fs << "# t, NA, NB "<< endl;
  cout << "writing header"<< endl;

}



double Gillespie::randomnumber(){
   
  double r = 1.0*rand()/RAND_MAX; //generiere Zufallszahl zwischen 1 und 0.
  //  cout << r <<endl;
  return r;

}

void Gillespie::doreaction()
{

  double k0, k1;
  double dmolecules;

  double w0 = reactions_rate[0]*molecules[0];
  double w1 = reactions_rate[1]*molecules[1];
  double wtotal = w0 + w1;

  k0 = reactions_rate[0];
  k1 = reactions_rate[1];
  
  w1 /= wtotal;
  w0 /= wtotal;

  double r2 = randomnumber();
  if (w1 < r2)
    dmolecules = -1;
  else 
    dmolecules = 1;
  
  molecules[0] = molecules[0]+dmolecules;
  molecules[1]= molecules[1]-dmolecules;
  
  double r1 = randomnumber();
  double dt = (1.0/wtotal)*log(1.0/r1);

  t = t + dt;
  fs << t <<"  "<< molecules[0] <<"  "<< molecules[1] << endl;
  
  //fs << t <<","<< NA <<","<< NB << ","<< r << "," << r2 << ","<< wminus<<","<<wplus<< endl;

  cout << "writing data" << endl;
  
  cout << "NA "<< molecules[0] << endl;
  cout << "NB "<< molecules[1] << endl;
  cout << t << endl;

}

  // -------------------
  // getter and setter
  // -------------------

double Gillespie::getNrReactions() {
  return nrReactions;
}
void Gillespie::setNrReactions(double n) {
  nrReactions = n;
}

