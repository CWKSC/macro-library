#pragma once

#include "SupportingMacro.h"

// 针对遍历阵列，默认 var 从 0 开始，递增为 1
#define loopBy(var, ...) \
    for(int var = 0; var != __VA_ARGS__; var++)

// 不在乎循环变量，只要单纯的重复次数
#define pureLoop(...) \
    loopBy( uniqueVarName(macroLoopTempVar), __VA_ARGS__)

// 合并两个 Looping
#define loop(p1, ...)                  \
    select0_1(pureLoop(p1),            \
              loopBy(p1, __VA_ARGS__), \
              __VA_ARGS__)

// 遍历二维阵列的 Looping 
#define loopBy2d(var1, times1, var2, ...) \
    loopBy(var1, times1){                 \
        loopBy(var2, __VA_ARGS__)

// 二维纯粹循环
#define pureLoop2d(n, ...) \
    pureLoop(n){           \
        pureLoop(__VA_ARGS__)

// 合并两个二维 Looping
#define loop2d(p1, p2, ...)                    \
    select0_2(pureLoop2d(p1, p2),              \
              pureLoop2d(p1, p2, __VA_ARGS__), \
              loopBy2d(p1, p2, __VA_ARGS__),   \
              __VA_ARGS__)

