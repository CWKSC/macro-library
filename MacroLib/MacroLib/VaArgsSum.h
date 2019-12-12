#pragma once

#include <stdarg.h>

int sum(int num, ...) {
    va_list args;
    va_start(args, num);
    int sum = 0;
    for (int i = 0; i < num; i++) {
        sum += va_arg(args, int);
    }
    va_end(args);
    return sum;
}

#define sum(...) sum( parameterNum(__VA_ARGS__), __VA_ARGS__)



