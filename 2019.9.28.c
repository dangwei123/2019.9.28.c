#define _CRT_SECURE_NO_WARNINGS 1
#include<stdio.h>
/*����һ�����������飬 ���������������1�ĸ�����

ʾ�� 1:

����: [1,1,0,1,1,1]
���: 3
����: ��ͷ����λ��������λ��������1�������������1�ĸ����� 3.

��Դ�����ۣ�LeetCode��
���ӣ�https://leetcode-cn.com/problems/max-consecutive-ones
����Ȩ������������С���ҵת������ϵ�ٷ���Ȩ������ҵת����ע��������

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

/*������һЩ�����������ȣ���ɵ����� A����������������������ɵġ�
�����Ϊ��������ε�����ܳ���

��������γ��κ������Ϊ��������Σ����� 0��*/

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
