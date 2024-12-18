#include "day01/day01.h"

#include <stdio.h>
#include <time.h>

typedef void (*void_func_ptr)(const char*);
typedef int (*int_func_ptr)(const char*);


enum AocDayReturnType {
    r_int,
    r_str,
};

typedef struct s_aocday {
    void_func_ptr day01;
    void_func_ptr day02;
    enum AocDayReturnType ret;
} AoCDay;

AoCDay aoc_days[1] = {
    {.day01 = (void_func_ptr)(&day01_part01), .day02 = NULL, .ret = r_int }
};

int main(int argc, char** argv) {
    int day = 0;

    printf("Day %d\n", day+1);
    AoCDay aoc_day = aoc_days[day];

    switch (aoc_day.ret) {
        case r_int:
            printf("\tPart 01: %d\n", ((int_func_ptr)aoc_day.day01)("./day01/input.txt"));
        case r_str:
            break;
    }

    return 0;
}
