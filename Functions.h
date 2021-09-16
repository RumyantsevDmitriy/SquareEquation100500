#ifndef FUNCTIONS_H_INCLUDED
#define FUNCTIONS_H_INCLUDED

void CheckData(double *a);
void GetData(double *a, double *b, double *c);

void RunManualMode();

void RunUnitTest();
void UnitTestOfSolveEquation(int num_of_test, int status_ref, double a, double b, double c,
                             double root1_ref, double root2_ref, int *nFails);

bool IsSuccess(int status_of_programm);
const char* StatusOfErrorToString(int status_of_programm);

int SolveSquareEquation(double a, double b, double c, double *root1, double *root2);
//-----------------------------------------------------------------------------
//! Solves a square equation (a * x^2 + b * x + c = 0)
//! @param [in]  a      a-coefficient
//! @param [in]  b      b-coefficient
//! @param [in]  c      c-coefficient
//! @param [out] root1  root1-first root of the equation
//! @param [out] root2  root2-second root of the equation
//!
//! @return Number of roots
//!
//! @note   In case of one root return ONE_ROOT
//!                    two root return TWO_ROOT
//!                    no  root return NO_ROOT
//!                    infinite number of roots return INF_ROOT
//!                    bad entered data return BAD_ENTERED_DATA
//!                    bad address of one(both) root(s) return BAD_ROOT_ADDR
//-----------------------------------------------------------------------------

int SolveLineEquation(double b, double c, double *root);
//-----------------------------------------------------------------------------
//! Solves a line equation (k * x + b = 0)
//! @param [in]  k      k-coefficient
//! @param [in]  b      b-coefficient
//! @param [out] root   root-root of the equation
//!
//! @return Number of roots
//!
//! @note   In case of one root return ONE_ROOT
//!                    no  root return NO_ROOT
//!                    infinite number of roots return INF_ROOT
//!                    bad entered data return BAD_ENTERED_DATA
//!                    bad address of one(both) root(s) return BAD_ROOT_ADDR
//-----------------------------------------------------------------------------

int CompareDoubles(double val1, double val2);

#endif // FUNCTIONS_H_INCLUDED
