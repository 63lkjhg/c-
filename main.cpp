#include <iostream>
#include <cmath>
using namespace std;

int main()
{
	//可能用到的函数声明
	void caesar_en(char arr[], int n1, int n2);
	void caesar_de(char arr[], int n1, int n2);
	int gcd(int a, int b);
	void affine_en(char arr[], int a1, int b1, int a2, int b2);
	int bezout(int a, int n);
	void affine_de(char arr[], int a1, int b1, int a2, int b2);
	//char arr[] = "ABCDEFG xyz 1234567890";
	char arr[] = "FMTAHOV kry 5814703692";
	affine_de(arr,33,5,3,2);
	return 0;
}

//凯撒密码：加密
void caesar_en(char arr[], int n1, int n2)
{
	if (n1 >= 26 || n1 <= 0)
	{
		cout << "uneffective encryption to letters";
		cout << endl;
		return;
	}
	else if (n2 >= 10 || n1 <= 0)
	{
		cout << "uneffective encryption to numbers";
		cout << endl;
		return;
	}
	else
	{
		for (int i = 0; arr[i] != '\0'; i++)
		{
			if (arr[i] >= 'a' && arr[i] <= 'z')
				arr[i] = ((arr[i] + n1 - 'a') % 26) + 'a';
			else if (arr[i] >= 'A' && arr[i] <= 'Z')
				arr[i] = ((arr[i] + n1 - 'A') % 26) + 'A';
			else if (arr[i] >= '0' && arr[i] <= '9')
				arr[i] = ((arr[i] + n2 - '0') % 10) + '0';
		}
		cout << arr << endl;
	}
	return;
}

//由于凯撒密码解密计算时会出现负数，对正负数进行分类讨论
inline char caesar_de_class(char n, int m)
{
	return n >= 0 ? n % m : m - (abs(n) % m);
}

//凯撒密码：解密
void caesar_de(char arr[], int n1, int n2)
{
	if (n1 >= 26 || n1 <= 0)
	{
		cout << "uneffective decryption to letters";
		cout << endl;
		return;
	}
	else if (n2 >= 10 || n1 <= 0)
	{
		cout << "uneffective decryption to numbers";
		cout << endl;
		return;
	}
	else
	{
		for (int i = 0; arr[i] != '\0'; i++)
		{
			if (arr[i] >= 'a' && arr[i] <= 'z')
				arr[i] = caesar_de_class(arr[i] - n1 - 'a', 26) + 'a';
			else if (arr[i] >= 'A' && arr[i] <= 'Z')
				arr[i] = caesar_de_class(arr[i] - n1 - 'A', 26) + 'A';
			else if (arr[i] >= '0' && arr[i] <= '9')
				arr[i] = caesar_de_class(arr[i] - n2 - '0', 10) + '0';
		}
		cout << arr << endl;
	}
	return;
}

//判断最大公约数
int gcd(int a, int b)
{
	int r;
	while (b > 0)
	{
		r = a % b;
		a = b;
		b = r;
	}
	return a;
}

//仿射密码：加密
void affine_en(char arr[], int a1, int b1,int a2,int b2)
{
	if (gcd(a1,26) != 1 || a1 <= 0)
	{
		cout << "uneffective encryption to letters";
		cout << endl;
		return;
	}
	else if (gcd(a2, 10) != 1 || a2 <= 0)
	{
		cout << "uneffective encryption to numbers";
		cout << endl;
		return;
	}
	else
	{
		for (int i = 0; arr[i] != '\0'; i++)
		{
			if (arr[i] >= 'a' && arr[i] <= 'z')
				arr[i] = (((arr[i] - 'a') * a1) + b1) % 26 + 'a';
			else if (arr[i] >= 'A' && arr[i] <= 'Z')
				arr[i] = (((arr[i] - 'A') * a1) + b1) % 26 + 'A';
			else if (arr[i] >= '0' && arr[i] <= '9')
				arr[i] = (((arr[i] - '0') * a2) + b2) % 10 + '0';
		}
		cout << arr << endl;
	}
	return;
}

//裴蜀定理求s
int bezout(int a,int n) 
{
	for (int i = 1; i < n; i++) 
	{
		if (a * i % n == 1) 
		{
			return i;
		}
	}
}

//仿射密码：解密
void affine_de(char arr[], int a1, int b1, int a2, int b2)
{
	if (gcd(a1, 26) != 1 || a1 <= 0)
	{
		cout << "uneffective decryption to letters";
		cout << endl;
		return;
	}
	else if (gcd(a2, 10) != 1 || a2 <= 0)
	{
		cout << "uneffective decryption to numbers";
		cout << endl;
		return;
	}
	else
	{
		int s1 = bezout(a1, 26);
		int s2 = bezout(a2, 10);
		for (int i = 0; arr[i] != '\0'; i++)
		{
			if (arr[i] >= 'a' && arr[i] <= 'z')
				arr[i] = (((arr[i] - 'a') * s1) + b1 * (26 - s1)) % 26 + 'a';
			else if (arr[i] >= 'A' && arr[i] <= 'Z')
				arr[i] = (((arr[i] - 'A') * s1) + b1 * (26 - s1)) % 26 + 'A';
			else if (arr[i] >= '0' && arr[i] <= '9')
				arr[i] = (((arr[i] - '0') * s2) + b2 * (10 - s2)) % 10 + '0';
		}
		cout << arr << endl;
	}
	return;
}
