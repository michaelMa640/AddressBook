#include<iostream>
#include<string>
using namespace std;
#define MAX 1000

//联系人结构体
struct Person
{
	string m_Name;
	int m_Sex; // 1、男 2、女
	int m_Age;
	string m_Phone;
	string m_Addr;
};

//通讯录结构体
struct Addressbooks
{
	struct Person personArray[MAX]; //联系人数组
	int m_Size; //通讯录中当前存储的联系人数量
};

// 1、添加联系人
void addPerson(Addressbooks* abs)
{
	// 判断通讯录是否已满
	if (abs->m_Size == MAX)
	{
		cout << "通讯录已满，无法添加！" << endl;
		return;
	}
	else
	{
		//添加具体联系人
		string name;
		cout << "请输入联系人姓名" << endl;
		cin >> name;
		abs->personArray[abs->m_Size].m_Name = name;

		cout << "请输入性别： " << endl;
		cout << "1 -- 男" << endl;
		cout << "2 -- 女" << endl;
		int sex = 0;
		while (true)
		{
			cin >> sex;
			if (sex == 1 || sex == 2)
			{
				abs->personArray[abs->m_Size].m_Sex = sex;
				break;
			}
			cout << "输入有误，请重新输入： " << endl;
		}

		cout << "请输入年龄： " << endl;
		int age;
		cin >> age;
		abs->personArray[abs->m_Size].m_Age = age;

		cout << "请输入联系电话： " << endl;
		string phone;
		cin >> phone;
		abs->personArray[abs->m_Size].m_Phone = phone;

		cout << "请输入家庭住址： " << endl;
		string addr;
		cin >> addr;
		abs->personArray[abs->m_Size].m_Addr = addr;

		//更新通讯率人数
		abs->m_Size++;

		cout << "添加成功！" << endl;

		system("pause");
		system("cls");
	}
}

// 2、显示联系人
void showPerson(Addressbooks* abs)
{
	//判断通讯录中人数是否为0
	if (abs->m_Size == 0)
	{
		cout << "当前记录为空，请先添加联系人" << endl;
	}
	else
	{
		for (int i = 0; i < abs->m_Size; i++)
		{
			cout << "姓名： " << abs->personArray[i].m_Name << "\t";
			cout << "性别： " << (abs->personArray[i].m_Sex == 1 ? "男" : "女") << "\t";
			cout << "年龄： " << abs->personArray[i].m_Age << "\t";
			cout << "电话： " << abs->personArray[i].m_Phone << "\t";
			cout << "家庭住址： " << abs->personArray[i].m_Addr << endl;
		}
	}
	system("pause");
	system("cls");
}

//检测联系人是否存在，不存在返回-1
int isExist(Addressbooks* abs, string name)
{
	for (int i = 0; i < abs->m_Size; i++)
	{
		if (abs->personArray[i].m_Name == name)
		{
			return i; //找到了，返回这个人在数组中的下标
		}
	}
	return -1; //如果遍历结束都没有找到，返回-1
}

//3、删除联系人
void deletPerson(Addressbooks* abs)
{
	cout << "请输入要删除的联系人" << endl;
	string name;
	cin >> name;
	int ret = isExist(abs, name);
	if (ret != -1)
	{
		for (int i = ret; i < abs->m_Size; i++)
		{
			abs->personArray[i] = abs->personArray[i + 1];
		}
		abs->m_Size--;
		cout << "删除成功！" << endl;
	}
	else
	{
		cout << "查无此人" << endl;
	}
	system("pause");
	system("cls");
}

//4、查找联系人
void findPerson(Addressbooks* abs)
{
	cout << "请输入您要查找的联系人" << endl;
	string name;
	cin >> name;

	//判断联系人是否存在
	int ret = isExist(abs, name);
	if (ret == -1)
	{
		cout << "未找到该联系人" << endl;
	}
	else
	{
		cout << "姓名： " << abs->personArray[ret].m_Name << "\t";
		cout << "年龄： " << abs->personArray[ret].m_Age << "\t";
		cout << "电话： " << abs->personArray[ret].m_Phone << "\t";
		cout << "住址： " << abs->personArray[ret].m_Addr << endl;
	}

	system("pause");
	system("cls");
}

//5、修改联系人
void modifyPerson(Addressbooks* abs)
{
	cout << "请输入您要修改的联系人" << endl;
	string name;
	cin >> name;
	int ret = isExist(abs, name);

	if (ret != -1)
	{
		string name;
		cout << "请输入姓名： " << endl;
		cin >> name;
		abs->personArray[ret].m_Name = name;

		cout << "请输入性别： " << endl;
		cout << "1 -- 男" << endl;
		cout << "2 -- 女" << endl;
		int sex = 0;
		cin >> sex;
		while (true)
		{
			if (sex == 1 || sex == 2)
			{
				abs->personArray[ret].m_Sex = sex;
				break;
			}
			else
			{
				cout << "性别输入错误，请重新输入" << endl;
			}
		}

		cout << "请输入年龄" << endl;
		int age;
		cin >> age;
		abs->personArray[ret].m_Age = age;

		cout << "请输入联系电话" << endl;
		string phone;
		cin >> phone;
		abs->personArray[ret].m_Phone = phone;

		cout << "请输入家庭住址： " << endl;
		string addr;
		cin >> addr;
		abs->personArray[ret].m_Addr = addr;

		cout << "修改成功" << endl;
	}
	else
	{
		cout << "未查找到该联系人" << endl;
	}

	system("pause");
	system("cls");
}

//6、清空联系人
void cleanPerson(Addressbooks* abs)
{
	cout << "确认要清空吗？" << endl;
	cout << "1 -- 确定" << endl;
	cout << "2 -- 返回" << endl;
	int confirm;
	cin >> confirm;

	if (confirm == 1)
	{
		abs->m_Size = 0;
		cout << "通讯录已清空" << endl;
	}
	else
	{
		return;
	}

	system("pause");
	system("cls");
}

//菜单显示
void showMenu()
{
	cout << "*************************" << endl;
	cout << "***** 1、添加联系人 *****" << endl;
	cout << "***** 2、显示联系人 *****" << endl;
	cout << "***** 3、删除联系人 *****" << endl;
	cout << "***** 4、查找联系人 *****" << endl;
	cout << "***** 5、修改联系人 *****" << endl;
	cout << "***** 6、清空联系人 *****" << endl;
	cout << "***** 0、退出通讯率 *****" << endl;
	cout << "*************************" << endl;
}

int main()
{
	//创建通讯录结构体变量
	Addressbooks abs;
	//初始化通讯录中当前人员个数
	abs.m_Size = 0;


	int select = 0;//用户选择输入的变量

	while (true)
	{
		showMenu();

		cin >> select;

		switch (select)
		{
		case 1: //1、添加联系人
			addPerson(&abs); //地址传递
			break;
		case 2: //2、显示联系人
			showPerson(&abs);
			break;
		case 3: // 3、删除联系人
		{
			deletPerson(&abs);

			/*cout << "请输入删除联系人姓名： " << endl;
			string name;
			cin >> name;

			if (isExist(&abs, name) == -1)
			{
				cout << "查无此人" << endl;
			}
			else
			{
				cout << "查找到" << endl;
			}*/
			break;
		}
		case 4: // 4、查找联系人
			findPerson(&abs);
			break;
		case 5: // 5、修改联系人
			modifyPerson(&abs);
			break;
		case 6: // 6、清空联系人
			cleanPerson(&abs);
			break;
		case 0: // 0、退出通讯录
			cout << "欢迎下次使用" << endl;
			system("pause");
			return 0;
			break;
		default:
			break;
		}
	}

	system("pause");
	return 0;
}