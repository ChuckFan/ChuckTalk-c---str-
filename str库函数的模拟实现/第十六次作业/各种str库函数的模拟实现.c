#include<stdio.h>
#include<stdlib.h>
#include<assert.h>//assert的头文件
#include<string.h>
//1.实现strstr

//
//char* my_strstr(const char* dest, const char* str)
//{
//	const char *pdest = dest;//pdest为标记目标字符串的首位
//	char *s1, *s2;//s1，s2分别为目标字符串和寻找字符串的流动寻找指针
//	if (!(*str))
//	{
//		return (char*)dest;
//	}
//	while (*pdest)
//	{
//		s1 = (char*)pdest;
//		s2 = (char*)str;
//		while ((*s1!='\0') && (*s2!='\0') && (*s1 == *s2))//当两个流动寻找指针没有到结尾且
//			//相等时，继续向后一位寻找
//		{
//			s1++;
//			s2++;
//		}
//		if (*s2 == '\0')//当寻找字符串到结尾了则表示子串找到，返回pdest位置
//		{
//			return (char*)pdest;
//		}
//		pdest++;//若只是前几位相等但不是子串时，将目标字符串指针继续向后移动查找
//	}
//	return NULL;
//}
//
//
//
//int main()
//{
//	char* ret = my_strstr("student", "dent");
//	if (ret != NULL)
//	{
//		printf("%s", ret);
//	}
//	else
//	{
//		printf("false");
//	}
//	system("pause");
//	return 0;
//}
//2.实现strchr

//char* my_strchr(const char* dest, char str)//被查找目标用const稳定
//{
//	assert(dest != 0);
//	assert(str != 0);
//	while (*dest)
//	{
//		if (*dest == str)//比较的为起始位置，所以前者需用指针
//		{
//			return dest;//返回指针
//		}
//		else
//		{
//			dest++;//指针移动
//		}
//	}
//	return NULL;
//}
//int main()
//{
//	char arr[] = "i am a student";
//	char a = 'a';
//	char* ret = my_strchr(arr, a);
//	printf("%s", ret);
//	system("pause");
//	return 0;
//}
//3.实现strcmp
//int My_strcmp(const char* arr1, const char* arr2)
//{
//	int len = 0;
//	int i;
//	if (strlen(arr1) <= strlen(arr2))
//	{
//		len = strlen(arr2);
//	}
//	else
//		len = strlen(arr1);
//	for (i = 0; i <= len; i++)
//	{
//		if ((arr1[i] == arr2[i]) && (arr1[i] != 0))//若相等且不为最后一位则继续向后比较
//		{
//			continue;
//		}
//		else if (arr1[i] < arr2[i])//若arr1小于arr2则返回-1
//		{
//			return -1;
//		}
//		else if ((arr1[i] == '\0') && (arr2[i] == '\0'))//若两数组相等则返回0
//		{
//			return 0;
//		}
//		else 
//		{
//			break;
//		}
//	}
//	return 1;//若arr1大于arr2，则返回1
//}
//int main()
//{
//	char arr1[] = "hey girl";
//	char arr2[] = "hey man";
//	int Ans = My_strcmp(arr1, arr2);
//	printf("%d\n", Ans);
//	system("pause");
//	return 0;
//}
//4.实现memcpy
//void* my_memcpy(void* dest, const void* src, int n)//因为memcpy是内存拷贝函数，所以必须什么类型都能接收，所以此处用void*做参数类型和返回值类型
//{
//	assert(dest != NULL);
//	assert(src != NULL);
//	char* ret = dest;//因为dest在循环体中不断发生变化，所以将dest的地址存放在指针变量ret中，此后ret就随着dest进行变化，但dest不会随着ret进行变化，最后函数返回ret的值
//	while (n--)
//	{
//		*(char*)dest = *(const char*)src;//void类型不能进行解引用操作，所以要进行强制类型转化，因为此处n指的是字节数，需要一个字节一个字节拷贝，所以强制类型转化为char*。
//		++(char*)dest;//void*类型不能进行++操作，所以要进行强制类型转化，如果是后置++，那么强制类型转化先对dest进行，所以要进行前置++
//		++(char*)src;
//	}
//	return ret;
//}
//
////arr1打印输出函数
//void print(int arr1[], int sz)
//{
//	int i = 0;
//	for (i = 0; i < sz; i++)
//	{
//		printf("%d ", arr1[i]);
//	}
//	printf("\n");
//}
//
//int main()
//{
//	char* str1[10] = { 0 };
//	char* str2 = "abcdefg";
//	char* ret = NULL;
//	ret = my_memcpy(str1, str2, 5);//n代表的是字节数
//	printf("%s\n", ret);
//	system("pause");
//	return 0;
//}
//5.实现memmove,不会像memcpy出现重叠情况，因为把之前要复制的内容先拷贝出来用于给dest复制
//void *my_memmove(void *dest, const void *src, int n)
//{
//	/*因为char类型为1字节，所以将数据转化为char*
//	进行操作。并不是因为操作的对象是字符串*/
//	char* pdest = (char *)dest;
//	const char* psrc = (const char *)src;
//	assert(dest);
//	assert(src);
//	if (pdest <= psrc&&pdest >= psrc + n)//正常情况下从前向后拷贝
//	{
//		while (n--)
//		{
//			*pdest = *psrc;
//		}
//	}
//	else //当出现内存覆盖时从后向前拷贝
//	{
//		while (n--)
//		{
//			*(pdest + n) = *(psrc + n);
//		}
//	}
//	return dest;
//}
//
//int main()
//{
//	char arr[10] = "abcdefg";
//	char arr0[10] = "abcdefg";
//	char arr1[10] = { 0 };
//	my_memmove(arr + 2, arr, 4);
//	my_memmove(arr1, arr0, 4);
//	printf("内存覆盖情况：%s\n", arr + 2);
//	printf("正常情况：%s\n", arr1);
//	system("pause");
//	return 0;
//}
//3.模拟实现strcpy
//char* my_strcpy(char* strdest, char* strsrc)
//{
//	if (strdest == NULL || strsrc == NULL)//判断两字符串是否为空
//	{
//		return NULL;
//	}
//	char *address = strdest;//保留一份strdest
//	while ((*strdest++ = *strsrc++) != '\0')//逐个复制到strdest之后
//	{
//		;
//	}
//	return address;
//}
//int main()
//{
//	char src[] = "abcdef";
//	char dest[] = { 0 };
//	my_strcpy(dest, src);
//	int i = 0;
//	for (i = 0; i < 6; i++)
//	{
//		printf("%c", dest[i]);
//	}
//	system("pause");
//	return 0;
//}
//4.模拟实现strcat
//#include<assert.h>
//char * my_strcat(char *dest, const char *src)
//{
//	//assert为判断是否为空
//	assert(dest);     //断言，若字符串为空，则不执行后面的代码
//	assert(src);      //断言，若字符串为空，则不执行后面的代码
//	char * ret = dest;
//	while (*dest)     //找出目标字符串的'\0'的位置
//	{
//		dest++;
//	}
//	while (*dest++ = *src++) //将源字符串的内容拷贝到目标字符串上
//注意这里是从之前循环走道的dest末尾处的'\0’处开始复制src的内容
//	{
//		;
//	}
//	return ret;
//}
//int main()
//{
//	char a[20] = "abcd";  //目标空间必须足够大且必须有\0
//	char b[5] = "efgh";   //源字符串必须有\0
//	my_strcat(a, b);
//	printf("%s\n", a);
//	system("pause");
//	return 0;
//}