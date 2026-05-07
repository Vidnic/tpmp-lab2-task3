/* car.h */
/* Author: Видук Павел, group 10 */

#ifndef CAR_H
#define CAR_H

#define BRAND_MAX 32
#define COLOR_MAX 24
#define SERIAL_MAX 16
#define REG_MAX 16

typedef struct
{
    char brand[BRAND_MAX];
    char color[COLOR_MAX];
    char serial[SERIAL_MAX];
    char reg_num[REG_MAX];
    int year_manufacture;
    int year_inspection;
    int price;
} CAR;

void car_input(CAR *c);
void car_print(const CAR *c);
int car_is_older_than_2_years(const CAR *c, int current_year);
void print_old_cars(const CAR *cars, int n, int current_year);

#endif
