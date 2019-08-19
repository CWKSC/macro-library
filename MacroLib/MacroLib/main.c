#include <stdio.h>
#include <stdlib.h>
#include <math.h>
#include <stdarg.h>

#include "SupportingMacro.h"
#include "ForLoopMacro.h"
#include "ArrayLoopingMacro.h"
#include "LinkedList.h"

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


	// Linked List //
	printf("[Linked List]\n");
	createLinkedList(list);
	pushFrontByValue(list, 10);
	pushFrontByValue(list, 12);
	printLinkedList(list);
	freeLinkedList(list);
	ln2;


	system("pause");
	return 0;
}
