#pragma once

#define ln putchar('\n')
#define ln2 printf("\n\n")

#define refer *

#define leftBracket (
#define rightBracket )

#define leftCurlyBracket {
#define rightCurlyBracket }

#define comma ,

#define midLayer(...) __VA_ARGS__
#define eatComma(...) ,##__VA_ARGS__

#define linkMacro_body(a, b) a ## b
#define linkMacro(a, b) linkMacro_body(a, b)
#define uniqueVarName(name) linkMacro(name, __COUNTER__)
#define uniqueVarName2(name) linkMacro_body leftBracket name, __COUNTER__ )

#define get1th(a1, ...) a1
#define get2th(a1, a2, ...) a2
#define get3th(a1, a2, a3, ...) a3
#define get4th(a1, a2, a3, a4, ...) a4
#define get5th(a1, a2, a3, a4, a5, ...) a5
#define get6th(a1, a2, a3, a4, a5, a6, ...) a6
#define get7th(a1, a2, a3, a4, a5, a6, a7, ...) a7
#define get8th(a1, a2, a3, a4, a5, a6, a7, a8, ...) a8
#define get9th(a1, a2, a3, a4, a5, a6, a7, a8, a9, ...) a9
#define get10th(a1, a2, a3, a4, a5, a6, a7, a8, a9, a10, ...) a10

#define get1thVS(...) midLayer( get1th(__VA_ARGS__) )
#define get2thVS(...) midLayer( get2th(__VA_ARGS__) )
#define get3thVS(...) midLayer( get3th(__VA_ARGS__) )
#define get4thVS(...) midLayer( get4th(__VA_ARGS__) )
#define get5thVS(...) midLayer( get5th(__VA_ARGS__) )
#define get6thVS(...) midLayer( get6th(__VA_ARGS__) )
#define get7thVS(...) midLayer( get7th(__VA_ARGS__) )
#define get8thVS(...) midLayer( get8th(__VA_ARGS__) )
#define get9thVS(...) midLayer( get9th(__VA_ARGS__) )
#define get10thVS(...) midLayer( get10th(__VA_ARGS__) )

#define parameterNum(...) get10thVS(__VA_ARGS__, 9, 8, 7, 6 , 5, 4, 3, 2, 1)

#define select0_1(m0, m1, ...) get3th leftBracket eatComma(__VA_ARGS__), m1, m0 )
#define select0_2(m0, m1, m2, ...) get4th leftBracket eatComma(__VA_ARGS__), m2, m1, m0)
#define select0_3(m0, m1, m2, m3, ...) get5th leftBracket eatComma(__VA_ARGS__), m3, m2, m1, m0)
#define select0_4(m0, m1, m2, m3, m4, ...) get6th leftBracket eatComma(__VA_ARGS__), m4, m3, m2, m1, m0)
#define select0_5(m0, m1, m2, m3, m4, m5, ...) get7th leftBracket eatComma(__VA_ARGS__), m5, m4, m3, m2, m1, m0)
#define select0_6(m0, m1, m2, m3, m4, m5, m6, ...) get8th leftBracket eatComma(__VA_ARGS__), m6, m5, m4, m3, m2, m1, m0)
#define select0_7(m0, m1, m2, m3, m4, m5, m6, m7, ...) get9th leftBracket eatComma(__VA_ARGS__), m7, m6, m5, m4, m3, m2, m1, m0)
#define select0_8(m0, m1, m2, m3, m4, m5, m6, m7, m8, ...) get10th leftBracket eatComma(__VA_ARGS__), m8, m7, m6, m5, m4, m3, m2, m1, m0)

#define select0_1VS(va_args, m0, m1) select_va_args_0_1(m1, m0, va_args)
#define select0_2VS(va_args, m0, m1, m2) select_va_args_0_2(m2, m1, m0, va_args)
#define select0_3VS(va_args, m0, m1, m2, m3) select_va_args_0_3(m3, m2, m1, m0, va_args)
#define select0_4VS(va_args, m0, m1, m2, m3, m4) select_va_args_0_4(m4, m3, m2, m1, m0, va_args)
#define select0_5VS(va_args, m0, m1, m2, m3, m4, m5) select_va_args_0_5(m5, m4, m3, m2, m1, m0, va_args)
#define select0_6VS(va_args, m0, m1, m2, m3, m4, m5, m6) select_va_args_0_6(m6, m5, m4, m3, m2, m1, m0, va_args)
#define select0_7VS(va_args, m0, m1, m2, m3, m4, m5, m6, m7) select_va_args_0_7(m7, m6, m5, m4, m3, m2, m1, m0, va_args)
#define select0_8VS(va_args, m0, m1, m2, m3, m4, m5, m6, m7, m8) select_va_args_0_8(m8, m7, m6, m5, m4, m3, m2, m1, m0, va_args)

#define ifTrue(condition, expersion) \
    condition && expersion

#define ifFalse(condition, expersion) \
    !condition && expersion

#define conditionalOperator(condition, exp1, exp2) \
    ifTrue(condition, exp1), ifFalse(condition, exp2)

