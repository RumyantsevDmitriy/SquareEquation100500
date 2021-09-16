#include <TXLib.h>
#include <stdio.h>

#include "Functions.h"
#include "Constants.h"

void UnitTestOfSolveEquation(int num_of_test, int status_ref, double a, double b, double c,
                             double root1_ref, double root2_ref, int *nFails)
{
        double root1 = NAN, root2 = NAN;

        int status = SolveSquareEquation(a, b, c, &root1, &root2);

        if(CompareDoubles(status, status_ref) != EQUAL &&
          (CompareDoubles(root1, root1_ref)   != EQUAL &&
           CompareDoubles(root2, root2_ref)   != EQUAL ||
           CompareDoubles(root1, root2_ref)   != EQUAL &&
           CompareDoubles(root2, root1_ref)   != EQUAL ))
        {
            printf("Тест№ %d  содержит ошибку:\n"
                   "   Сейчас: Status = %d, x1 = %lg, x2 = %lg\n"
                   "Правильно: Status = %d, x1 = %lg, x2 = %lg\n",
                    num_of_test, status, root1, root2, status_ref, root1_ref, root2_ref);
            *nFails++;
        }
}

void RunUnitTest()
{
    int nFails = 0;

    UnitTestOfSolveEquation(1, 2, 1, 5, -6, 1, -6, &nFails);
    UnitTestOfSolveEquation(2, 2, 1, -2, 0, 0, 2, &nFails);
    UnitTestOfSolveEquation(3, 1, 1, 2, 1, -1, NAN, &nFails);
    UnitTestOfSolveEquation(4, NO_ROOT, 6, 1, 2, NAN, NAN, &nFails);
    UnitTestOfSolveEquation(5, INF_ROOT, 0, 0, 0, NAN, NAN, &nFails);
    UnitTestOfSolveEquation(6, NO_ROOT, 0, 0, 1, NAN, NAN, &nFails);
    UnitTestOfSolveEquation(7, 1, 0, 1, -2, 2, NAN, &nFails);

    if(nFails == 0)
    {
        printf("Все тесты верны");
    }
    else
    {
        printf("\nПрограмма содержит %d ошибок", nFails);
    }

}
