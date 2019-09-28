#define _CRT_SECURE_NO_WARNINGS 1
#include<stdio.h>
/*给定一个单词，你需要判断单词的大写使用是否正确。

我们定义，在以下情况时，单词的大写用法是正确的：

全部字母都是大写，比如"USA"。
单词中所有字母都不是大写，比如"leetcode"。
如果单词不只含有一个字母，只有首字母大写， 比如 "Google"。
否则，我们定义这个单词没有正确使用大写字母。

来源：力扣（LeetCode）
链接：https://leetcode-cn.com/problems/detect-capital
著作权归领扣网络所有。商业转载请联系官方授权，非商业转载请注明出处。*/
int detectCapitalUse(char * tmp)
{
	char *word = tmp;
	while (*word != '\0')
	{
		if (*word >= 'A'&&*word <= 'Z')
		{
			word++;
		}
		else
		{
			break;
		}
		if (*word == '\0')
		{
			return 1;
		}
	}
	word = tmp;
	while (*word != '\0')
	{
		if (*word >= 'a'&&*word <= 'z')
		{
			word++;
		}
		else
		{
			break;
		}
		if (*word == '\0')
		{
			return 1;
		}
	}
	word = tmp;
	if (*word >= 'A'&&*word <= 'Z')
	{
		word++;
		while (*word >= 'a'&&*word <= 'z')
		{
			word++;
			if (*word == '\0')
			{
				return 1;
			}
		}

	}
	return 0;

}
int main()
{
	char str[] = "LKSHhI";
	int ret = detectCapitalUse(str);
	if (ret)
	{
		printf("true\n");
	}
	else
	{
		printf("false\n");
	}
	return 0;
}

