#pragma once

#include <stdio.h>
#include <stdlib.h>
#include "SupportingMacro.h"

char* cwksc_ExceptionName = NULL;
char* cwksc_BackPointName = NULL;


#define try(backPointName, ...)                     \
    if(strcmp(cwksc_ExceptionName, "")){            \
	    cwksc_BackPointName = #backPointName;       \
	    if(strcmp("" #__VA_ARGS__, ""))             \
		    cwksc_ExceptionName = "" #__VA_ARGS__;  \
	    goto cwksc_catchStart;                      \
    }                                               \
    backPointName:



#define catchStart(...) \
    cwksc_catchStart:        \
    if(!strcmp(cwksc_ExceptionName, "")) return __VA_ARGS__;

#define catch(exceptionName) \
    if(!strcmp(cwksc_ExceptionName, #exceptionName))

#define back(backPoint)                            \
    if(!strcmp(cwksc_BackPointName, #backPoint)){  \
	    goto backPoint;                            \
    }

#define back2(arg2, arg1) back(arg2) back(arg1) printf("[Error] 沒有透過 try 進入 catch / 找不到相應的返回點");
#define back3(arg3, ...) back(arg3) back2  midLayer((__VA_ARGS__))
#define back4(arg4, ...) back(arg4) back3  midLayer((__VA_ARGS__))
#define back5(arg5, ...) back(arg5) back4  midLayer((__VA_ARGS__))
#define back6(arg6, ...) back(arg6) back5  midLayer((__VA_ARGS__))
#define back7(arg7, ...) back(arg7) back6  midLayer((__VA_ARGS__))
#define back8(arg8, ...) back(arg8) back7  midLayer((__VA_ARGS__))
#define back9(arg9, ...) back(arg9) back8  midLayer((__VA_ARGS__))
#define back10(arg10, ...) back(arg10) back9  midLayer((__VA_ARGS__))

#define catchEnd(...)                                            \
    cwksc_ExceptionName = "";                                    \
    select0_8(printf("[Error] Zero parameters of catchEnd()");,  \
              back,                                              \
              back2,                                             \
              back3,                                             \
              back4,                                             \
              back5,                                             \
              back6,                                             \
              back7,                                             \
              back8,                                             \
              __VA_ARGS__) midLayer((__VA_ARGS__))

#define finally() 



#define throw(exceptionName, ...)          \
    cwksc_ExceptionName = #exceptionName;  \
    return __VA_ARGS__;

#define giveThrow(ex_name) \
    cwksc_ExceptionName = #ex_name;

#define clearThrow() \
    cwksc_ExceptionName = "";

#define checkThrow(ex_name, ...)         \
    if(strcmp(cwksc_ExceptionName, "")){  \
        cwksc_ExceptionName = #ex_name;   \
        return __VA_ARGS__;               \
    }

#define check(...)                        \
    if(strcmp(cwksc_ExceptionName, "")){  \
        return __VA_ARGS__;               \
    }

