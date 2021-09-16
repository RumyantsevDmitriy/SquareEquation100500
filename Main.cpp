#include <TXLib.h>
#include <stdio.h>

#include "Functions.h"
#include "Constants.h"

int main(void)
{
	printf("�� ������� ���������, �������� ���������� ���������\n"
	       "���������� ��������� ����� ���: a * x^2 + b * x + c = 0 , ��� a, b, c - �����\n\n"
           "���� �� ������ �������������� ��������� ������������� - ������� Y ");

    switch(getchar())
    {
        case 'Y': RunUnitTest();
                  break;
        default:  RunManualMode();
                  break;
    }

    return 0;
}

void RunManualMode()
{
    double a = NAN, b = NAN, c = NAN, root1 = NAN, root2 = NAN;

    GetData(&a, &b, &c);

    int status_of_programm = SolveSquareEquation(a, b, c, &root1, &root2);

    if(!IsSuccess(status_of_programm))
    {
        printf("%s", StatusOfErrorToString(status_of_programm));
    }
    else
    {
        switch(status_of_programm)
        {
            case NO_ROOT:    printf("\n������ ��������� �� ����� �������");
                             break;
            case ONE_ROOT:   printf("\n������ ��������� ����� ���� �������: x = %lg", root1);
                             break;
            case TWO_ROOT:   printf("\n������ ��������� ����� ��� �������: x1 = %lg\n\t\t\t\t\t\b\b\b\bx2 = %lg", root1, root2);
                             break;
            case INF_ROOT:   printf("\n������ ��������� ����� ���������� ������� ���������� �������");
                             break;
            default:         break;
        }
    }
}

void GetData(double *a, double *b, double *c)
{
    printf("������� �������� ��������� a: ");
	CheckData(a);

	printf("������� �������� ��������� b: ");
	CheckData(b);

	printf("������� �������� ��������� c: ");
	CheckData(c);
}

void CheckData(double *value)
{
    assert(value != NULL);

	scanf("%lg", value);

    if(!isfinite(*value) || !isspace(getchar()))
    {
        printf("%s\n��������� ��������� ������", StatusOfErrorToString(BAD_ENTERED_DATA));
        exit(0);
    }
}

const char* StatusOfErrorToString(int status_of_programm)
{
    switch(status_of_programm)
	{
        case BAD_ENTERED_DATA: return(BAD_ENTERED_DATA_MSG);
                               break;
        case BAD_ROOT_ADDR:    return(BAD_ROOT_ADDR_MSG);
                               break;
        default:               return(UNIDENTIFIED_ERROR_MSG);
                               break;
	}
}

bool IsSuccess(int status_of_programm)
{
    return (status_of_programm >= 0) ? 1 : 0;
}
