#include<stdio.h>
#include<stdlib.h>
#include<assert.h>//assert��ͷ�ļ�
#include<string.h>
//1.ʵ��strstr

//
//char* my_strstr(const char* dest, const char* str)
//{
//	const char *pdest = dest;//pdestΪ���Ŀ���ַ�������λ
//	char *s1, *s2;//s1��s2�ֱ�ΪĿ���ַ�����Ѱ���ַ���������Ѱ��ָ��
//	if (!(*str))
//	{
//		return (char*)dest;
//	}
//	while (*pdest)
//	{
//		s1 = (char*)pdest;
//		s2 = (char*)str;
//		while ((*s1!='\0') && (*s2!='\0') && (*s1 == *s2))//����������Ѱ��ָ��û�е���β��
//			//���ʱ���������һλѰ��
//		{
//			s1++;
//			s2++;
//		}
//		if (*s2 == '\0')//��Ѱ���ַ�������β�����ʾ�Ӵ��ҵ�������pdestλ��
//		{
//			return (char*)pdest;
//		}
//		pdest++;//��ֻ��ǰ��λ��ȵ������Ӵ�ʱ����Ŀ���ַ���ָ���������ƶ�����
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
//2.ʵ��strchr

//char* my_strchr(const char* dest, char str)//������Ŀ����const�ȶ�
//{
//	assert(dest != 0);
//	assert(str != 0);
//	while (*dest)
//	{
//		if (*dest == str)//�Ƚϵ�Ϊ��ʼλ�ã�����ǰ������ָ��
//		{
//			return dest;//����ָ��
//		}
//		else
//		{
//			dest++;//ָ���ƶ�
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
//3.ʵ��strcmp
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
//		if ((arr1[i] == arr2[i]) && (arr1[i] != 0))//������Ҳ�Ϊ���һλ��������Ƚ�
//		{
//			continue;
//		}
//		else if (arr1[i] < arr2[i])//��arr1С��arr2�򷵻�-1
//		{
//			return -1;
//		}
//		else if ((arr1[i] == '\0') && (arr2[i] == '\0'))//������������򷵻�0
//		{
//			return 0;
//		}
//		else 
//		{
//			break;
//		}
//	}
//	return 1;//��arr1����arr2���򷵻�1
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
//4.ʵ��memcpy
//void* my_memcpy(void* dest, const void* src, int n)//��Ϊmemcpy���ڴ濽�����������Ա���ʲô���Ͷ��ܽ��գ����Դ˴���void*���������ͺͷ���ֵ����
//{
//	assert(dest != NULL);
//	assert(src != NULL);
//	char* ret = dest;//��Ϊdest��ѭ�����в��Ϸ����仯�����Խ�dest�ĵ�ַ�����ָ�����ret�У��˺�ret������dest���б仯����dest��������ret���б仯�����������ret��ֵ
//	while (n--)
//	{
//		*(char*)dest = *(const char*)src;//void���Ͳ��ܽ��н����ò���������Ҫ����ǿ������ת������Ϊ�˴�nָ�����ֽ�������Ҫһ���ֽ�һ���ֽڿ���������ǿ������ת��Ϊchar*��
//		++(char*)dest;//void*���Ͳ��ܽ���++����������Ҫ����ǿ������ת��������Ǻ���++����ôǿ������ת���ȶ�dest���У�����Ҫ����ǰ��++
//		++(char*)src;
//	}
//	return ret;
//}
//
////arr1��ӡ�������
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
//	ret = my_memcpy(str1, str2, 5);//n��������ֽ���
//	printf("%s\n", ret);
//	system("pause");
//	return 0;
//}
//5.ʵ��memmove,������memcpy�����ص��������Ϊ��֮ǰҪ���Ƶ������ȿ����������ڸ�dest����
//void *my_memmove(void *dest, const void *src, int n)
//{
//	/*��Ϊchar����Ϊ1�ֽڣ����Խ�����ת��Ϊchar*
//	���в�������������Ϊ�����Ķ������ַ���*/
//	char* pdest = (char *)dest;
//	const char* psrc = (const char *)src;
//	assert(dest);
//	assert(src);
//	if (pdest <= psrc&&pdest >= psrc + n)//��������´�ǰ��󿽱�
//	{
//		while (n--)
//		{
//			*pdest = *psrc;
//		}
//	}
//	else //�������ڴ渲��ʱ�Ӻ���ǰ����
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
//	printf("�ڴ渲�������%s\n", arr + 2);
//	printf("���������%s\n", arr1);
//	system("pause");
//	return 0;
//}
//3.ģ��ʵ��strcpy
//char* my_strcpy(char* strdest, char* strsrc)
//{
//	if (strdest == NULL || strsrc == NULL)//�ж����ַ����Ƿ�Ϊ��
//	{
//		return NULL;
//	}
//	char *address = strdest;//����һ��strdest
//	while ((*strdest++ = *strsrc++) != '\0')//������Ƶ�strdest֮��
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
//4.ģ��ʵ��strcat
//#include<assert.h>
//char * my_strcat(char *dest, const char *src)
//{
//	//assertΪ�ж��Ƿ�Ϊ��
//	assert(dest);     //���ԣ����ַ���Ϊ�գ���ִ�к���Ĵ���
//	assert(src);      //���ԣ����ַ���Ϊ�գ���ִ�к���Ĵ���
//	char * ret = dest;
//	while (*dest)     //�ҳ�Ŀ���ַ�����'\0'��λ��
//	{
//		dest++;
//	}
//	while (*dest++ = *src++) //��Դ�ַ��������ݿ�����Ŀ���ַ�����
//ע�������Ǵ�֮ǰѭ���ߵ���destĩβ����'\0������ʼ����src������
//	{
//		;
//	}
//	return ret;
//}
//int main()
//{
//	char a[20] = "abcd";  //Ŀ��ռ�����㹻���ұ�����\0
//	char b[5] = "efgh";   //Դ�ַ���������\0
//	my_strcat(a, b);
//	printf("%s\n", a);
//	system("pause");
//	return 0;
//}