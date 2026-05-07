/* student.c */
/* Author: Видук Павел, group 10 */

#include "student.h"
#include <stdio.h>
#include <string.h>
#include <stdlib.h>

double student_avg(const STUDENT *s)
{
    int sum = 0;
    for (int i = 0; i < N_SUBJECTS; i++)
        sum += s->ses[i];
    return (double)sum / N_SUBJECTS;
}

int student_cmp_by_name(const void *a, const void *b)
{
    const STUDENT *sa = (const STUDENT *)a;
    const STUDENT *sb = (const STUDENT *)b;
    return strcmp(sa->name, sb->name);
}

void student_input(STUDENT *students, int n)
{
    for (int i = 0; i < n; i++)
    {
        printf("\nСтудент %d:\n", i + 1);
        printf("Фамилия и инициалы: ");
        fgets(students[i].name, NAME_MAX, stdin);
        students[i].name[strcspn(students[i].name, "\n")] = '\0';
        printf("Курс: ");
        scanf("%d", &students[i].kurs);
        printf("Оценки (%d предметов): ", N_SUBJECTS);
        for (int j = 0; j < N_SUBJECTS; j++)
            scanf("%d", &students[i].ses[j]);
        getchar();
    }
}

void student_print(const STUDENT *s)
{
    printf("%-30s | Курс: %d | Оценки: ", s->name, s->kurs);
    for (int i = 0; i < N_SUBJECTS; i++)
        printf("%d ", s->ses[i]);
    printf("| Ср.балл: %.2f\n", student_avg(s));
}

int find_above_avg(const STUDENT *students, int n, double overall_avg, int *indices, int max_indices)
{
    int count = 0;
    for (int i = 0; i < n && count < max_indices; i++)
    {
        if (student_avg(&students[i]) > overall_avg)
        {
            indices[count] = i;
            count++;
        }
    }
    return count;
}

double overall_average(const STUDENT *students, int n)
{
    double total = 0.0;
    for (int i = 0; i < n; i++)
        total += student_avg(&students[i]);
    return total / n;
}
