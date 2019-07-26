#include <stdio.h>
#include <stdlib.h>
#include <math.h>
#include <stdarg.h>

#include "SupportingMacro.h"
#include "ForLoopMacro.h"
#include "ArrayLoopingMacro.h"
#include "LinkedList.h"

#define x 3
#define y 4

int main() {

	// 遍历x*y的二维阵列 //
	int array2d[x][y] = { 0 };
	loop2d(i, x, j, y) {
		printf("%d", array2d[i][j]);
		rightCurlyBracket
	ln;
	}

	// 输出 n * n 的 * 方阵 //
	int n = 3; // 以 3 為例子。
	loop2d(n, n) {
		printf("* ");
		rightCurlyBracket
	ln;
	}

	system("pause");
	return 0;
}
