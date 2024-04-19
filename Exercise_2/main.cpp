#include <iostream>
#include <fstream>
#include <sstream>
#include "Utils.hpp"


using namespace std;


int main()
{
    string inputFileName = "./data.csv";
    double S = 0;
    size_t n = 0;
    double* w = nullptr;
    double* r = nullptr;


    if (!ImportData(inputFileName, S, n, w, r))
    {
        cerr << "Something goes wrong with import" << endl;
        return -1;
    }


    double rateOfReturn = RateOfReturn(n, w, r);


    double V = FinalValueOfPortfolio(S, n, w ,r);


    string outputFileName = "./result.txt";

    if (!ExportResults(outputFileName, S, n, w, r, rateOfReturn, V))
    {
        cerr << "Something goes wrong with export" << endl;
        return -1;
    }
    else
        cout << "Export successful" << endl;


    delete[] w;
    delete[] r;

    return 0;
}

