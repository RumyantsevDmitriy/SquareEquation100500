#include <stdio.h>
#include <math.h>

#include "Functions.h"
#include "Constants.h"

int SolveSquareEquation(double a, double b, double c, double* root1, double* root2)
{
    if (!isfinite(a) || !isfinite(b) || !isfinite(c))
    {
        return BAD_ENTERED_DATA;
    }

    if (root1 == NULL || root2 == NULL || root1 == root2)
    {
        return BAD_ROOT_ADDR;
    }

    if (CompareDoubles(a, 0) == EQUAL)
    {
        int status_of_solve_square_equation = SolveLineEquation(b, c, root1);
        return status_of_solve_square_equation;
    }
    else
    {
        double D = b * b - 4 * a * c;

        if(CompareDoubles(D, 0) == EQUAL)
        {
            *root1 = -b / (2 * a);
            return ONE_ROOT;
        }
        else if(CompareDoubles (D, 0) == LESS)
        {
            return NO_ROOT;
        }
        else
        {
            *root1 = (-b + sqrt (D)) / (2 * a);
            *root2 = (-b - sqrt (D)) / (2 * a);
            return TWO_ROOT;
        }
    }
}

int SolveLineEquation(double k, double b, double* root)
{
    if(!isfinite(k) || !isfinite(b))
    {
        return BAD_ENTERED_DATA;
    }

    if(root == NULL)
    {
        return BAD_ROOT_ADDR;
    }

    if(CompareDoubles(b, 0) == EQUAL)
    {
        if(CompareDoubles(k, 0) == EQUAL)
        {
            return INF_ROOT;
        }
    }
    else if(CompareDoubles(k, 0) != EQUAL)
    {
        *root = -b / k;
        return ONE_ROOT;
    }

    return NO_ROOT;
}

int CompareDoubles(double val1, double val2)
{
    if(isnan(val1) && isnan(val2))
    {
        return EQUAL;
    }

    if(fabs(val1 - val2) <= PRECISION)
    {
        return EQUAL;
    }
    else if(val1 - val2 < 0)
    {
        return LESS;
    }
    else
    {
        return MORE;
    }
}
