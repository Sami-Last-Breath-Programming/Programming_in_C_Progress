#include <stdio.h>

#define EXIT_SUCCESS 0 

void getGrade(int *grade, int count)
{
    printf("Enter Grade %i: ", count);
    scanf("%i", grade);
}

void checkGrade(int grade, int *failed)
{   if (grade < 65) (*failed)++; }

void getTotalAvg(int gradeSum, int totalGradeCount, float *avgGrade)
{   *avgGrade = (float) gradeSum / totalGradeCount; }

void makeUi(void)
{
    int totalGradeCount, grade, gradeSum = 0, failed = 0;
    float avgGrade = 0.0f;
    
    printf("Welcome, Enter Number of Grades: ");
    scanf("%i", &totalGradeCount);

    for (int count = 1; count <= totalGradeCount; count++)
    {   
        getGrade(&grade, count);
        gradeSum += grade;
        checkGrade(grade, &failed);
    }
    getTotalAvg(gradeSum, totalGradeCount, &avgGrade);
    
    printf("The Average Grade: %.2f \n", avgGrade);
    printf("Number of Failures: %i \n", failed);
}

int main(void)
{
    makeUi();
    return EXIT_SUCCESS;
}