#ifndef CONSTANTS_H_INCLUDED
#define CONSTANTS_H_INCLUDED

const double PRECISION = 1e-9;

enum STATUS_OF_SOLVE_EQUATION
{
    BAD_ROOT_ADDR = -2,
    BAD_ENTERED_DATA = -1,
    NO_ROOT = 0,
    ONE_ROOT = 1,
    TWO_ROOT = 2,
    INF_ROOT = 3
};

enum COMPARE_VALUE
{
    LESS  = -1,
    EQUAL =  0,
    MORE  =  1
};

extern const char* BAD_ENTERED_DATA_MSG;
extern const char* BAD_ROOT_ADDR_MSG;
extern const char* UNIDENTIFIED_ERROR_MSG;

#endif // CONSTANTS_H_INCLUDED
