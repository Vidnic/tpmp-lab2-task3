/* student.h */
/* Author: Видук Павел, group 10 */

#ifndef STUDENT_H
#define STUDENT_H

#define N_SUBJECTS 5
#define N_STUDENTS 10
#define NAME_MAX 64

typedef struct
{
    char name[NAME_MAX];
    int kurs;
    int ses[N_SUBJECTS];
} STUDENT;

double student_avg(const STUDENT *s);
int student_cmp_by_name(const void *a, const void *b);
void student_input(STUDENT *students, int n);
void student_print(const STUDENT *s);
int find_above_avg(const STUDENT *students, int n, double overall_avg, int *indices, int max_indices);
double overall_average(const STUDENT *students, int n);

#endif
