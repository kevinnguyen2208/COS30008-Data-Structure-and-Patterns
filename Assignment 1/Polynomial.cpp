#include "Polynomial.h"
#include <cmath>
using namespace std;

Polynomial::Polynomial()
{
    fDegree = 0;
    for (int i = 0; i < MAX_DEGREE; i++) {
        fCoeffs[i] = 0.0;
    }
}


Polynomial Polynomial::operator*(const Polynomial& aRHS) const
{
    Polynomial aResult;
    aResult.fDegree = fDegree + aRHS.fDegree;
    for (int i = 0; i <= fDegree; i++)
        for (int j = 0; j <= aRHS.fDegree; j++)
            aResult.fCoeffs[i + j] += fCoeffs[i] * aRHS.fCoeffs[j];
    return aResult;
}


bool Polynomial::operator==(const Polynomial& aRHS) const
{
    if (fDegree != aRHS.fDegree)
        return false;
    for (int i = 0; i <= fDegree; i++)
        if (fCoeffs[i] != aRHS.fCoeffs[i])
            return false;
    return true;
}


istream& operator>>(istream& aIStream, Polynomial& aObject)
{
    aIStream >> aObject.fDegree;

    for (int i = 0; i <= aObject.fDegree; i++)
    {
        aIStream >> aObject.fCoeffs[i];
    }
    return aIStream;
}


ostream& operator<<(ostream& aOStream, const Polynomial& aObject)
{
    bool lMustAddPlus = false;

    for (int i = 0; i <= aObject.fDegree; i++)
    {
        if (aObject.fCoeffs[i] != 0.0)
        {
            if (lMustAddPlus ) aOStream << " + ";
            aOStream << aObject.fCoeffs[i] << "x^" << i;
            lMustAddPlus  = true;
        }
    }
    return aOStream;
}


double Polynomial::operator()(double aX) const
{
    double result = 0.0;
    for (int i = 0; i <= fDegree; i++)
    {
        result += fCoeffs[i] * pow(aX, i);
    }
    return result;
}


Polynomial Polynomial::getDifferential() const
{
    Polynomial result;
    result.fDegree = fDegree - 1;
    for (int i = 0; i <= result.fDegree; i++)
    {
        result.fCoeffs[i] = fCoeffs[i + 1] * (i + 1);
    }
    return result;
}


Polynomial Polynomial::getIndefiniteIntegral() const
{
    Polynomial result;
    result.fDegree = fDegree + 1;
    result.fCoeffs[0] = 0;
    for (int i = 1; i <= result.fDegree; i++)
    {
        result.fCoeffs[i] = fCoeffs[i - 1] / i;
    }
    return result;
}


double Polynomial::getDefiniteIntegral(double aXLow, double aXHigh) const
{
    Polynomial integral = getIndefiniteIntegral();
    return integral(aXHigh) - integral(aXLow);
}
