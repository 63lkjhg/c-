#include <iostream>
using namespace std;

int main()
{
	//可能用到的函数声明
	void caesar_en(char arr[], int n1, int n2);
	char arr[] = "0123456789 abcxyz ABCXYZ";
	caesar_en(arr, 2, 2);
	return 0;
}

//凯撒密码：加密
void caesar_en(char arr[], int n1, int n2)
{
	if (n1 % 26 == 0)
	{
		cout << "uneffective encryption to letters";
		return;
	}
	else if (n2 % 10 == 0)
	{
		cout << "uneffective encryption to numbers";
		return;
	}
	else
	{
		for (int i = 0; arr[i] != '\0'; i++)
		{
			if (arr[i] >= 'a' && arr[i] <= 'z')
				arr[i] = ((arr[i] + n1 - 'a') % 26) + 'a';
			else if (arr[i] >= 'A' && arr[i] <= 'z')
				arr[i] = ((arr[i] + n1 - 'A') % 26) + 'A';
			else if (arr[i] >= '0' && arr[i] <= '9')
				arr[i] = ((arr[i] + n2 - '0') % 10) + '0';
		}
		cout << arr << endl;
	}
	return;
}