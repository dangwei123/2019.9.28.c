#define _CRT_SECURE_NO_WARNINGS 1
#include<stdio.h>
/*给定一个二进制数组， 计算其中最大连续1的个数。

示例 1:

输入: [1,1,0,1,1,1]
输出: 3
解释: 开头的两位和最后的三位都是连续1，所以最大连续1的个数是 3.

来源：力扣（LeetCode）
链接：https://leetcode-cn.com/problems/max-consecutive-ones
著作权归领扣网络所有。商业转载请联系官方授权，非商业转载请注明出处。

int findMaxConsecutiveOnes(int* nums, int numsSize)
{
	int i = 0;
	int count = 0;
	int countmax = 0;
	for (i = 0; i<numsSize; i++)
	{
		if (nums[i] == 1)
		{
			count++;
		}
		if (nums[i] == 0)
		{
			count = 0;
		}
		if (count>countmax)
		{
			countmax = count;
		}
	}
	return countmax;

}
int main()
{
	int arr[] = { 1, 1, 0, 0, 1, 1, 1, 0, 0, 1 };
	int len = sizeof(arr) / sizeof(arr[0]);
	int ret=findMaxConsecutiveOnes(arr,len);
	printf("%d\n", ret);
	return 0;
}
*/

/*给定由一些正数（代表长度）组成的数组 A，返回由其中三个长度组成的、
面积不为零的三角形的最大周长。

如果不能形成任何面积不为零的三角形，返回 0。*/

int largestPerimeter(int* A, int ASize)
{
	int i = 0;
	int j = 0;
	int tmp = 0;
	int s1 = 0;
	int s2 = 0;
	int s3 = 0;
	for (i = 0; i<ASize - 1; i++)
	{
		for (j = 0; j<ASize - 1 - i; j++)
		{
			if (A[j]>A[j + 1])
			{
				tmp = A[j];
				A[j] = A[j + 1];
				A[j + 1] = tmp;
			}
		}

	}
	for (i = ASize - 1; i >= 2; i--)
	{
		s3 = A[i];
		s2 = A[i - 1];
		s1 = A[i - 2];
		if (s1 + s2>s3)
		{
			return s1 + s2 + s3;
		}
	}
	return 0;
}

int main()
{
	int arr[] = { 1,2,1 };
	int len = sizeof(arr) / sizeof(arr[0]);
	int ret = largestPerimeter(arr,len);
	printf("%d\n", ret);
	return 0;
}
