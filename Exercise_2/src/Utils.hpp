#pragma once
#include <iostream>


using namespace std;


bool ImportData(const string& inputFilePath,
                double& S,
                size_t& n,
                double*& w,
                double*& r);


double RateOfReturn(const size_t& n,
                    const double* const& w,
                    const double* const& r);


double FinalValueOfPortfolio(const double& S,
                             const size_t& n,
                             const double* const& w,
                             const double* const& r);



bool ExportResults(const string& outputFilePath,
                   const double& S,
                   const size_t& n,
                   const double* const& w,
                   const double* const& r,
                   const double& rateOfReturn,
                   const double& V);


string ArrayToString(const size_t& n,
                     const double* const& v);
