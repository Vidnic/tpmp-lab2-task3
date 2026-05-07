/* car.c */
/* Author: Видук Павел, group 10 */

#include "car.h"
#include <stdio.h>
#include <string.h>

void car_input(CAR *c)
{
    printf("Марка: ");
    fgets(c->brand, BRAND_MAX, stdin);
    c->brand[strcspn(c->brand, "\n")] = '\0';
    printf("Цвет: ");
    fgets(c->color, COLOR_MAX, stdin);
    c->color[strcspn(c->color, "\n")] = '\0';
    printf("Серийный номер: ");
    fgets(c->serial, SERIAL_MAX, stdin);
    c->serial[strcspn(c->serial, "\n")] = '\0';
    printf("Регистрационный номер: ");
    fgets(c->reg_num, REG_MAX, stdin);
    c->reg_num[strcspn(c->reg_num, "\n")] = '\0';
    printf("Год выпуска: ");
    scanf("%d", &c->year_manufacture);
    printf("Год техосмотра: ");
    scanf("%d", &c->year_inspection);
    printf("Цена: ");
    scanf("%d", &c->price);
    getchar();
}

void car_print(const CAR *c)
{
    printf("%-15s | %-10s | Серийный: %-10s | Рег.номер: %-10s | Год: %d | Техосмотр: %d | Цена: %d\n",
           c->brand, c->color, c->serial, c->reg_num, c->year_manufacture, c->year_inspection, c->price);
}

int car_is_older_than_2_years(const CAR *c, int current_year)
{
    return (current_year - c->year_manufacture) > 2;
}

void print_old_cars(const CAR *cars, int n, int current_year)
{
    int found = 0;
    printf("\nАвтомобили старше 2 лет (от %d года):\n", current_year);
    for (int i = 0; i < n; i++)
    {
        if (car_is_older_than_2_years(&cars[i], current_year))
        {
            car_print(&cars[i]);
            found = 1;
        }
    }
    if (!found) printf("Таких автомобилей нет.\n");
}
