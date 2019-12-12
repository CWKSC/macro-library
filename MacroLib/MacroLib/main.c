#include <stdio.h>
#include <stdlib.h>
#include <math.h>
#include <stdarg.h>

#include "SupportingMacro.h"
#include "ForLoopMacro.h"
#include "ArrayLoopingMacro.h"
#include "LinkedList.h"
#include "TryCatch.h"


double check_negative_function(double input) {
    if (input < 0) {
        throw(isNegative_FromFunction);
    }
}

double my_sqrt(double input) {
    check_negative_function(input);

    checkThrow(isNegative_FromFunction_changeName, 0.0);

    return sqrt(input);
}


#define check_negative_macro(input) \
    if (input < 0) { \
        giveThrow(isNegative_FromMacro); \
    }

double my_sqrt2(double input) {

    // 檢查值是否小於零，默認 給出 名爲 isNegative 的錯誤
    check_negative_macro(input);

    // 檢查有否發生錯誤，有則回傳括弧内的值
    check(0.0);

    return sqrt(input);
}



int main() {


    // easyFor() //
    // 1 至 100 的总和 //
    printf("[easyFor] 1 至 100 的总和\n");
    int sum_easyFor = 0;
    easyFor(i, 1, 100) {  // for(int i = 1; i <= 100; i++)
        sum_easyFor += i;
    }
    printf("%d\n", sum_easyFor);
    ln;


    // flexFor() //
    // 1 至 100 内奇数的总和 //
    printf("[flexFor] 1 至 100 内奇数的总和\n");
    int sum_flexFor = 0;
    flexFor(i, 1, 100, i += 2) {  // for(int i = 1; i <= 100; i+=2)
        sum_flexFor += i;
    }
    printf("%d\n", sum_flexFor);
    ln;


    // ffor() //
    // 计算 [1 至 100] 及 [101 至 200 内奇数] 的总和 //
    printf("[ffor] 计算 [1 至 100] 及 [101 至 200 内奇数] 的总和\n");
    int sum_ffor = 0;
    ffor(i, 1, 100) {  //easyFor(i, 1, 100)
        sum_ffor += i;
    }
    ffor(i, 101, 200, i += 2) {  //flexFor(i, 101, 200, i+=2)
        sum_ffor += i;
    }
    printf("%d\n", sum_ffor);  //12550
    ln;


    // loopBy() //
    // 遍历 x * y 的二维阵列 //
    printf("[loopBy] 遍历 x * y 的二维阵列\n");
#define x 3
#define y 4
    int array2d_loopBy[x][y] = { 0 };
    loopBy(i, x) {  // for(int i = 0; i != x; i++)
        loopBy(j, y) {  // for(int j = 0; j != x ; j++)
            printf("%d", array2d_loopBy[i][j]);
        }
        ln;
    }
#undef x
#undef y
    ln;


    // pureLoop() //
    // 输出 n * n 的 * 方阵 //
    printf("[pureLoop] 输出 n * n 的 * 方阵\n");
#define n 3
    pureLoop(n) {
        pureLoop(n) {
            printf("* ");
        }
        ln;
    }
#undef n
    ln;


    // loop2d() //
    // 遍历 x * y 的二维阵列 //
    printf("[loop2d] 遍历 x * y 的二维阵列\n");
#define x 3
#define y 4
    int array2d_loop2d[x][y] = { 0 };
    loop2d(i, x, j, y) {
        printf("%d", array2d_loop2d[i][j]);
        rightCurlyBracket
    ln;
    }
    ln;
#undef x
#undef y


    // loop2d() //
    // 二维纯粹循环 //
    // 输出 n * n 的 * 方阵 //
    printf("[loop2d] 输出 n * n 的 * 方阵 \n");
#define n 3
    loop2d(n, n) {
        printf("* ");
        rightCurlyBracket
    ln;
    }
#undef n
    ln;


    // forech() //
    printf("[forech] 遍历阵列\n");
    int arr[10] = { 1, 3, 4, 2, 1, 2, 3, 7, 9, 1 };
    forech(int, x, arr,
        printf("%d ", x);
    );
    ln2;

    // ifTrue() //
    printf("[ifTrue]\n");
    printf("ifTrue(1, printf(\"OK\")) : ");  ifTrue(1, printf("OK")); ln;
    printf("ifTrue(0, printf(\"OK\")) : ");  ifTrue(0, printf("OK")); ln;
    ln;

    // ifFalse() //
    printf("[ifFalse]\n");
    printf("ifFalse(1, printf(\"OK\")) : "); ifFalse(1, printf("OK")); ln;
    printf("ifFalse(0, printf(\"OK\")) : "); ifFalse(0, printf("OK")); ln;
    ln;

    // conditionalOperator() // 
    printf("[conditionalOperator]\n");
    printf("conditionalOperator(1, exp1, exp2) : ");
    conditionalOperator(1, printf("exp1"), printf("exp2");); ln;
    printf("conditionalOperator(0, exp1, exp2) : ");
    conditionalOperator(0, printf("exp1"), printf("exp2"););
    ln2;

    // Linked List //
    printf("[Linked List] push 10, push 12, print\n");
    createLinkedList(list);
    pushFrontByValue(list, 10);
    pushFrontByValue(list, 12);
    printLinkedList(list);
    freeLinkedList(list);
    ln2;


    // 有發生錯誤，由 throw() 拋出 isNegative_FromFunction 錯誤
    check_negative_function(-10); try(ex1);

    // 有發生錯誤，由 check_negative_function() 的 throw() 拋出 isNegative_FromFunction 錯誤
    // checkThrow() 把錯誤名稱改爲 isNegative_FromFunction_changeName 錯誤
    my_sqrt(-20); try(ex2);

    // 有發生錯誤，由 giveThrow() 拋出 isNegative_FromMacro 錯誤
    // 由 check() 檢測並再次拋出
    my_sqrt2(-30); try(ex3);

    // 沒有發生錯誤
    my_sqrt2(40); try(ex4);

    // 有發生錯誤，由 giveThrow() 拋出 isNegative_FromMacro 錯誤
    // 由 check() 檢測並再次拋出
    // try() 把它改名為 tryChangeExeptionName 錯誤
    my_sqrt2(-50); try(ex5, tryChangeExeptionName);

    system("pause");

    // 正常到達這裏，會回傳括弧内的值 //
    catchStart(0);
    catch (isNegative_FromFunction) {
        printf("[isNegative_FromFunction] exception is happened!\n");
    }
    catch (isNegative_FromFunction_changeName) {
        printf("[isNegative_FromFunction_changeName] exception is happened!\n");
    }
    catch (isNegative_FromMacro) {
        printf("[isNegative_FromMacro] exception is happened!\n");
    }
    catch (tryChangeExeptionName) {
        printf("[changeExeptionName] exception is happened!\n");
    }
    finally() {
        printf("[finally()] exception is happened!\n\n");
    }
    // 標出所有返回點
    catchEnd(ex1, ex2, ex3, ex4, ex5)


    system("pause");
    return 0;
}
