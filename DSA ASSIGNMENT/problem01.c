#include <stdio.h>

#define NUM_STUDENTS 3
#define NUM_SUBJECTS 5

void calculateTotalAndAverage(int marks[][NUM_SUBJECTS], int numStudents)
{
    int i, j;
    float total, average;
    printf("Student\tTotal\tAverage\n");
    for (i = 0; i < numStudents; i++)
    {
        total = 0;
        for (j = 0; j < NUM_SUBJECTS; j++)
        {
            total += marks[i][j];
        }
        average = total / NUM_SUBJECTS;
        printf("%d\t%.2f\t%.2f\n", i + 1, total, average);
    }

    printf("\nSubject\tAverage\n");
    for (j = 0; j < NUM_SUBJECTS; j++)
    {
        total = 0;
        for (i = 0; i < numStudents; i++)
        {
            total += marks[i][j];
        }
        average = total / numStudents;
        printf("%d\t%.2f\n", j + 1, average);
    }
}

int main()
{
    int marks[NUM_STUDENTS][NUM_SUBJECTS];
    int i, j;

    printf("Enter marks for %d students in %d subjects:\n", NUM_STUDENTS, NUM_SUBJECTS);
    for (i = 0; i < NUM_STUDENTS; i++)
    {
        printf("Enter marks for student %d->\n", i + 1);
        for (j = 0; j < NUM_SUBJECTS; j++)
        {
            printf("Enter marks for subject %d: ", j + 1);
            scanf("%d", &marks[i][j]);
        }
    }

    calculateTotalAndAverage(marks, NUM_STUDENTS);

    return 0;
}
