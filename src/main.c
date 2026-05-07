/* main.c */
/* Author: Видук Павел, group 10 */

#include <stdio.h>
#include "max_digit_sum.h"
#include "student.h"
#include "car.h"

#define ARRAY_SIZE 10
#define RESULT_SIZE 10

int main(void)
{
    printf("Задание 1\n");
    int arr[ARRAY_SIZE] = {123, 45, 678, 9, 100, 999, 456, 7, 888, 12345};
    printf("Массив: ");
    for (int i = 0; i < ARRAY_SIZE; i++)
        printf("%d ", arr[i]);
    printf("\n");
    
    int result[RESULT_SIZE];
    size_t count = find_numbers_with_max_sum(arr, ARRAY_SIZE, result, RESULT_SIZE);
    
    printf("Числа с максимальной суммой цифр (%d шт): ", (int)count);
    for (size_t i = 0; i < count; i++)
        printf("%d ", result[i]);
    printf("\n");
    
    printf("\nЗадание 2\n");
    STUDENT students[N_STUDENTS] = {
        {"Иванов Иван", 2, {5, 4, 5, 4, 5}},
        {"Петров Петр", 3, {3, 4, 3, 4, 3}},
        {"Сидоров Сидор", 1, {5, 5, 5, 5, 5}},
        {"Кузнецова Анна", 2, {4, 4, 4, 4, 4}},
        {"Смирнова Ольга", 4, {5, 5, 4, 5, 5}},
        {"Волков Дмитрий", 3, {3, 3, 3, 3, 3}},
        {"Морозова Елена", 1, {5, 4, 4, 5, 4}},
        {"Новиков Андрей", 2, {2, 3, 2, 3, 2}},
        {"Козлова Татьяна", 4, {5, 5, 5, 4, 5}},
        {"Лебедев Алексей", 3, {4, 4, 5, 4, 4}}
    };
    
    qsort(students, N_STUDENTS, sizeof(STUDENT), student_cmp_by_name);
    
    printf("Список студентов по алфавиту:\n");
    for (int i = 0; i < N_STUDENTS; i++)
        student_print(&students[i]);
    
    double overall = overall_average(students, N_STUDENTS);
    printf("\nОбщий средний балл: %.2f\n", overall);
    
    int indices[N_STUDENTS];
    int count_above = find_above_avg(students, N_STUDENTS, overall, indices, N_STUDENTS);
    
    if (count_above > 0)
    {
        printf("\nСтуденты со средним баллом выше общего:\n");
        for (int i = 0; i < count_above; i++)
            student_print(&students[indices[i]]);
    }
    else
    {
        printf("\nНет студентов со средним баллом выше общего.\n");
    }
    
    printf("\nЗадание 3\n");
    CAR cars[] = {
        {"Toyota", "Красный", "JT123", "A001AA", 2019, 2023, 1500000},
        {"BMW", "Черный", "BM456", "B002BB", 2022, 2024, 3500000},
        {"Lada", "Белый", "LA789", "C003CC", 2015, 2022, 500000},
        {"Hyundai", "Синий", "HY012", "D004DD", 2023, 2024, 2000000},
        {"Nissan", "Серый", "NI345", "E005EE", 2018, 2023, 1800000}
    };
    int n = sizeof(cars) / sizeof(CAR);
    
    printf("Все автомобили:\n");
    for (int i = 0; i < n; i++)
        car_print(&cars[i]);
    
    int current_year = 2026;
    printf("\nТекущий год: %d\n", current_year);
    print_old_cars(cars, n, current_year);
    
    return 0;
}
