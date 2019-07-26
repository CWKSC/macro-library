#pragma once

#include "SupportingMacro.h"

// 简化版 for loop
#define easyFor(var, start, end) \
    for(int var = start; var <= end; var++)

// 較灵活的 for loop
#define flexFor(var, start, end, ...) \
    for(int var = start; var <= end; __VA_ARGS__)

// 合并以上两个 for loop
#define ffor(var, start, end, ...)                   \
    select0_1(easyFor(var, start, end),              \
              flexFor(var, start, end, __VA_ARGS__), \
              __VA_ARGS__)


