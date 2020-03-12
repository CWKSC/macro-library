# MacroLib

This repository contains some advanced techniques for macros.

For example:

delayed expansion, distinguishing the number of parameters, expanding different macros according to the parameter integer

Implement default parameters, create unique variable names, and a bunch of derived syntactic sugar

Even try catch in C, of course not the original one

這個倉庫包括了一些巨集的進階技巧，

例如：延遲展開、辨別參數數目、**按照參數數目展開不同的宏**

**實現默認參數**、建立唯一的變數名稱，還有一堆衍生出來的語法糖

甚至用 C 實現 try catch，當然不是原版的那種

___

This repository is related to some articles, the relevant URL is at the bottom, but this is in simplified Chinese.

這個倉庫跟某些文章有關係，相關的網址在最底下，不過這是簡體中文的。

___

Let see the `main.c` for demo: 讓我們看一下 `main.c` 進行演示：

```c
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
    // 1 至 100 的總和 //
    printf("[easyFor] 1 至 100 的總和\n");
    int sum_easyFor = 0;
    easyFor(i, 1, 100) {  // for(int i = 1; i <= 100; i++)
        sum_easyFor += i;
    }
    printf("%d\n", sum_easyFor);
    ln;


    // flexFor() //
    // 1 至 100 內奇數的總和 //
    printf("[flexFor] 1 至 100 內奇數的總和\n");
    int sum_flexFor = 0;
    flexFor(i, 1, 100, i += 2) {  // for(int i = 1; i <= 100; i+=2)
        sum_flexFor += i;
    }
    printf("%d\n", sum_flexFor);
    ln;


    // ffor() //
    // 計算 [1 至 100] 及 [101 至 200 內奇數] 的總和 //
    printf("[ffor] 計算 [1 至 100] 及 [101 至 200 內奇數] 的總和\n");
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
    // 遍歷 x * y 的二維陣列 //
    printf("[loopBy] 遍歷 x * y 的二維陣列\n");
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
    // 輸出 n * n 的 * 方陣 //
    printf("[pureLoop] 輸出 n * n 的 * 方陣\n");
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
    // 遍歷 x * y 的二維陣列 //
    printf("[loop2d] 遍歷 x * y 的二維陣列\n");
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
    // 二維純粹循環 //
    // 輸出 n * n 的 * 方陣 //
    printf("[loop2d] 輸出 n * n 的 * 方陣 \n");
#define n 3
    loop2d(n, n) {
        printf("* ");
        rightCurlyBracket
    ln;
    }
#undef n
    ln;


    // forech() //
    // 遍歷陣列 //
    printf("[forech] 遍歷陣列\n");
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
```

___

And the corresponding output: 和相應的輸出：

```c
[easyFor] 1 至 100 的總和
5050

[flexFor] 1 至 100 內奇數的總和
2500

[ffor] 計算 [1 至 100] 及 [101 至 200 內奇數] 的總和
12550

[loopBy] 遍歷 x * y 的二維陣列
0000
0000
0000

[pureLoop] 輸出 n * n 的 * 方陣
* * *
* * *
* * *

[loop2d] 遍歷 x * y 的二維陣列
0000
0000
0000

[loop2d] 輸出 n * n 的 * 方陣
* * *
* * *
* * *

[forech] 遍歷陣列
1 3 4 2 1 2 3 7 9 1

[ifTrue]
ifTrue(1, printf("OK")) : OK
ifTrue(0, printf("OK")) :

[ifFalse]
ifFalse(1, printf("OK")) :
ifFalse(0, printf("OK")) : OK

[conditionalOperator]
conditionalOperator(1, exp1, exp2) : exp1
conditionalOperator(0, exp1, exp2) : exp2

[Linked List] push 10, push 12, print
12 10

[isNegative_FromFunction] exception is happened!
[finally()] exception is happened!

[isNegative_FromFunction_changeName] exception is happened!
[finally()] exception is happened!

[isNegative_FromMacro] exception is happened!
[finally()] exception is happened!

[changeExeptionName] exception is happened!
[finally()] exception is happened!

請按任意鍵繼續 . . .
```

___

#### [【Just For Fun】系列文章索引](https://zhuanlan.zhihu.com/p/59807834)

整合 [【Just For Fun】](https://zhuanlan.zhihu.com/p/59807834) 所有文章中有关宏的代码。

## **【Just For Fun】**

> 本系列纯粹娱乐、研究用。一些旁门左道的东西。
> 事实上可能完全没用。 (๑•̀ω•́๑)

**开了一个坑，喜欢的话关注赞好謝謝。~**
学业繁重，尝试一周一更。

这个系列将会使用很多宏的技巧去帮助开发。

另外就是一些玩具，可能没什么用的研究。(っ●ω●)っ

## **▌目錄：**

### ▌github 源代码：

[【Just For Fun】github, 源代码，所有文章中有关宏的代码](https://zhuanlan.zhihu.com/p/75353995)

### ▌**Macro 宏技巧：**

1. [C - 宏开发 - 大綱、概括](https://zhuanlan.zhihu.com/p/59923365)
2. [C - 预处理器、宏 #, ##、预先定义的宏](https://zhuanlan.zhihu.com/p/60998127)
3. [C - 可变参数函数、可变参数宏 __VA_ARGS__、额外的逗号](https://zhuanlan.zhihu.com/p/60915174)
4. [C - 宏开发 - 选取第 n 项参数、按照参数数目展开不同的宏、缺陷](https://zhuanlan.zhihu.com/p/61152480)
5. [C - 宏开发 - 真正按照参数数目展开不同的宏、延迟展开](https://zhuanlan.zhihu.com/p/61467125)
6. [C - 宏开发 - 实现默认参数](https://zhuanlan.zhihu.com/p/62343197)
7. [C - 宏开发 - 建立唯一的变数名称, __COUNTER__](https://zhuanlan.zhihu.com/p/64479211)
8. [C - 宏开发 - _Generic() 泛型](https://zhuanlan.zhihu.com/p/66029308)

### ▌**衍生篇：**

1. [C - 更方便的 for loop ！更多的 loop ！](https://zhuanlan.zhihu.com/p/59654218) （未重制版）
2. [C - 更方便的 for loop](https://zhuanlan.zhihu.com/p/67516094) （ (1.) 的 for loop 部分重制版）
3. [C - 换行](https://zhuanlan.zhihu.com/p/69300862)
4. [C - 针对遍历阵列的 Looping](https://zhuanlan.zhihu.com/p/68627239) （ (1.) 的 Looping 部分重制版）
5. [C - 针对遍历二维阵列的 Looping](https://zhuanlan.zhihu.com/p/75323881)
6. [C 实现 try catch - 说明书](https://zhuanlan.zhihu.com/p/97061040)
7. [C 实现 try catch - 代码部分、使用例子、运行结果](https://zhuanlan.zhihu.com/p/97077403)

### ▌**应用篇：**

1. [n 階行列式計算 宏 生成器，四阶行列式的最优展开](https://zhuanlan.zhihu.com/p/77057988)
2. [n 階行列式計算 宏 生成器（重构）](https://zhuanlan.zhihu.com/p/77388741)
3. [拉格朗日插值多项式生成器](https://zhuanlan.zhihu.com/p/77491558)

### **▌**宏 **杂项：**

1. [危險的宏，宏定义污染](https://zhuanlan.zhihu.com/p/70292429)
2. [玩坏预处理器、无限递归展开](https://zhuanlan.zhihu.com/p/75584300)

### ▌数学：

1. [阶乘、Gamma 函数、斯特灵公式 Stirling's formula](https://zhuanlan.zhihu.com/p/91879417)

### ▌其他：

1. [AnyType 任意类型](https://zhuanlan.zhihu.com/p/91867932)
2. [测字符串长度的各种姿势](https://zhuanlan.zhihu.com/p/91880493)
