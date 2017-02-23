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

#include <gillespie.h>
#include <math.h>
#include <vector>
#include <iostream>
#include <fstream>
#include <random>

using namespace std;

int i;
double NA, NB, k1, k2, wplus, wminus, z, t;
    
double gillespie::randomnumber(){
   
    time_t t;
    time(&t);
        double r = 1.0*rand()/RAND_MAX; //generiere Zufallszahl zwischen 1 und 0.
      //  cout << r <<endl;
}

void gillespie::doreaction()
{
    vector<double>reactions_rate{4.5e-1,3e-2,10000}; //Reaktionskonstanten k1 und k2 und Anzahl der Reaktionen
    vector<double>moleculs{2000,500,0.0}; //Anzahl Moleküle An
    ofstream fs;
    std::string filename = "data5.csv";
    
    
    int numtray = 2;
    
    NA = moleculs[0];
    NB = moleculs[1];
    double t = 0;
    int v;
    k1 = reactions_rate[0];
    k2 = reactions_rate[1];
    z =  reactions_rate[2];
    
    fs.open(filename);
    fs << "t, NA, NB "<< endl;
    cout << "writing header"<< endl;
    
    for (int i = 0; i<z; i++){
    double r = randomnumber();
    double wplus = k2*NB;
    double wminus =  k1*NA;
    double a = wplus + wminus;
    double r2 = randomnumber();
    wplus = (k2*NB)/(k1*NA)+(k2*NB);
    wminus = (k1*NA)/(k2*NB) + (k1*NA);
    double u = (1/a)*log(1/r);
    if (wplus < r2)
        v = -1;
    else 
        v= 1;
    
    NA = NA+v;
    NB = NB-v;
    t = t + u;
    fs << t <<","<< NA <<","<< NB << "," << k1 << ","<< k2<< endl;
    //fs << t <<","<< NA <<","<< NB << ","<< r << "," << r2 << ","<< wminus<<","<<wplus<< endl;
    cout << "writing data"<<endl;
    
    cout <<"NA"<< NA <<endl;
    cout <<"NB"<< NB <<endl;
    cout << t <<endl;
    cout << r <<endl;
    } 
    fs.close();
}



