#include "Utils.hpp"

#include <iostream>
#include <fstream>
#include <sstream>
#include <iomanip>


using namespace std;


bool ImportData(const string& inputFilePath,
                double& S,
                size_t& n,
                double*& w,
                double*& r)
{
    ifstream inFile(inputFilePath);

    if(inFile.fail())
    {
        cerr << "file open failed" << endl;
        return false;
    }


    string ignore;
    string line;
    string fraction;
    string rate;


    getline(inFile,ignore,';');
    getline(inFile,line);

    istringstream sum(line);
    sum >> S;


    getline(inFile,ignore,';');
    getline(inFile,line);

    istringstream assets(line);
    assets >> n;


    getline(inFile,ignore);


    w = new double[n];
    r = new double[n];


    unsigned int i = 0;

    while(i<=n)
    {
        getline(inFile,fraction,';');
        getline(inFile,rate);

        istringstream convertw;
        convertw.str(fraction);

        istringstream convertr;
        convertr.str(rate);

        convertw >> w[i];
        convertr >> r[i];

        i = i+1;
    }


    inFile.close();

    return true;
}


double RateOfReturn(const size_t& n,
                    const double* const& w,
                    const double* const& r)
{
    double rateOfReturn = 0;

    for(unsigned int i = 0; i < n; i++)
        rateOfReturn += w[i] * r[i];

    return rateOfReturn;
}


double FinalValueOfPortfolio(const double& S,
                             const size_t& n,
                             const double* const& w,
                             const double* const& r)
{
    double V = 0;

    for(unsigned int i = 0; i < n; i++)
        V += (1+r[i])*(w[i]*S);

    return V;
}


bool ExportResults(const string& outputFilePath,
                   const double& S,
                   const size_t& n,
                   const double* const& w,
                   const double* const& r,
                   const double& rateOfReturn,
                   const double& V)
{
    ofstream outFile(outputFilePath);

    if (outFile.fail())
    {
        cerr<< "file open failed"<< endl;
        return false;
    }


    outFile << fixed << setprecision(2) << "S = " << S << ", n = " << n <<endl;

    outFile << "w = " << ArrayToString(n,w) << endl;

    outFile << "r = " << ArrayToString(n,r) << endl;

    outFile << fixed << setprecision(4) << "Rate of return of the portfolio: " << rateOfReturn << endl;

    outFile << fixed << setprecision(2) << "V: " << V << endl;

    outFile.close();

    return true;
}


string ArrayToString(const size_t& n,
                     const double* const& v)
{
    string str;
    ostringstream toString;
    toString << "[ ";
    for (unsigned int i = 0; i < n; i++)
        toString << v[i] << " ";
    toString << "]";

    return toString.str();
}
