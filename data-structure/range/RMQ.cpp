/*
	* reference: https://www.cnblogs.com/YSFAC/p/7189571.html
	* 			 https://blog.csdn.net/aitangyong/article/details/26940155
*/

// 区间求最大最小值，多次询问所以一定要初始化。

/*
	O(n^2) 简单粗暴， dp[i][j]: 从第 i 位开始向后长度为 j 的区间最值
*/


/*
	O(logn) 可以把一个区间的求值问题转化为两个等长子区间求值问题，这样可以充分利用求出区间的信息，
	和上一个 n方 的相比，有很多区间不需要再次求解只需要简单的求两个子区间的最值。
	ST table:
	因此 dp[i][j]: 从第 i 位开始向后长度为 2^j 的区间最值
	因为要通过两个区间组合出这个区间的值，所以在区间左右端点长度的一般作为两个区间，长度为 2^j-1
	状态转移方程: dp[i][j] = max/min(dp[i][j-1], dp[i + 2^(j-1)][j-1])
	当给出询问区间时候， 先求出所给区间的中间位置是 2 的几次方，然后查表。
	k = log2(j - i + 1);
	那么区间 max/min = max/min(dp[i][k], dp[j - (2^k) + 1][k]);
	第二段区间开始位置用 j 向前减去不少于区间一半的长度，保证一定是区间覆盖然后合并起来求最终值
	两个子区间覆盖不影响最值，因此这就是 RMQ 的局限性，不可以计算区间和只能求区间最值。

	**编码注意** ST 表不要缺少状态
	for 循环要 j 在外层，例如：因为在求解 i=0，j=10 这个区间最值，分成两个小段的区间，
	第二段的区间还不知道就没法求，因此不能让 i 在外层循环。
*/

#include "../../common.h"
#include <iostream>
#include <cstring>
#include <algorithm>
using namespace std;

const int MAXN = 10;
int a[] = {0, 1, 2, 3, 4, 5, 6, 7, 8, 9, 10};
int b[] = {0, 1, 2, 3, 4, 5, 6};
int F[MAXN + 5][MAXN + 5];

//转化为DP，f(i,j)		从第 i 个数往后 2^j个长度区间的最值，（max or min)
void pre_process() {
	//inti
	memset(F, 0, sizeof(F));
	for (int i = 1; i <= MAXN; i++) F[i][0] = b[i];	//步长为1 是自己本身，作为初始化转移初态
	for (int j = 1; (1 << j) <= MAXN; j++)
		for (int i = 1; i + (1 << (j - 1)) <= MAXN; i++)
			F[i][j] = max(F[i][j - 1], F[i + (1 << (j - 1))][j - 1]);
}

int RMQ(int low_bound, int high_bound)	{
	int k = 0; //log dis 的值，下取整
	int dis = high_bound - low_bound + 1;
	while (dis >>= 1) k++;
	return max(F[low_bound][k], F[high_bound - (1 << k) + 1][k]);
	//low_bound+(1<<k)不可以，从高往前移动保证距离为偶数
}

int main() {
	pre_process();

	int a, b;
	while (cin >> a >> b)
		cout << RMQ(a, b) << endl;
	return 0;
}
