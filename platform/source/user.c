#include "platform.h"
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

Product_user products[MAX_PRODUCTS_user]; //存储所有商品
int productNum_user = 0; //当前商品数量

Order_user orders[MAX_ORDERS_user]; //存储所有订单
int orderNum; //当前订单数量

int history[MAX_HISTORY]; //存储最近浏览的商品编号
int historyNum = 0; //当前足迹数量

Account_user accounts[MAX_ACCOUNT_NUM_user]; //储存所有账号
int accountNum_user = 0; //当前账号数量

////////////////////////////////////账号登录/////////////////////////////////

//注册账号
void registerAccount_user()
{
	//判断账号数量是否已达上限
	if (accountNum_user >= MAX_ACCOUNT_NUM_user)
	{
		printf("账号数量已达上限，注册失败！\n");
		return;
	}

	//创建新账号
	Account_user newAccount;
	printf("请输入用户名：\n");
	scanf("%s", newAccount.username);

	//判断用户名是否已被注册
	for (int i = 0; i < accountNum_user; i++)
	{
		if (strcmp(accounts[i].username, newAccount.username) == 0)
		{
			printf("该用户名已被注册，已退出用户注册界面！\n");
			break;
		}
	}

	if (strcmp(accounts[accountNum_user - 1].username, newAccount.username) != 0)
	{
		printf("请输入密码：\n");
		scanf("%s", newAccount.password);

		accounts[accountNum_user] = newAccount; //添加新账号到数组中
		accountNum_user++;

		printf("账号注册成功！\n");
		return;
	}
	return;
}

//登录
void login_user()
{
	//定义账号密码数组及大小
	char username[50];
	char password[50];

	printf("请输入用户名：\n");
	scanf("%s", username);
	printf("请输入密码：\n");
	scanf("%s", password);
	system("cls");

	//判断用户名和密码是否正确
	for (int i = 0; i < accountNum_user; i++)
	{
		if (strcmp(accounts[i].username, username) == 0 && strcmp(accounts[i].password, password) == 0)
		{
			printf("*----------------------------------*\n");
			printf("*             登录成功！           *\n");
			printf("*----------------------------------*\n");
			printf("*          尊敬的用户：%s           *\n",username);
			show_user();
			return;
		}

	}
	printf("用户名或密码错误，已退出用户登录界面！\n");
}

//找回密码
void findPassword_user()
{
	//定义用户名数组
	char username[50];

	printf("请输入用户名：\n");
	scanf("%s", username);

	//判断用户名是否存在，并输出密码
	for (int i = 0; i < accountNum_user; i++)
	{
		if (strcmp(accounts[i].username, username) == 0)
		{
			printf("你的密码为：%s\n", accounts[i].password);
			return;
		}
	}
	printf("该用户名不存在，已退出密码找回界面！\n");
}

//保存数据到文件
void saveData_user()
{
	FILE* fp = fopen("data.txt", "w"); //创造或打开文件

	fprintf(fp, "%d\n", accountNum_user); //先写入账号数量
	for (int i = 0; i < accountNum_user; i++) //循环写入每个账号的用户名和密码
	{
		fprintf(fp, "%s %s\n", accounts[i].username, accounts[i].password);
	}
	fclose(fp); //关闭文件
}

//从文件中加载数据
void loadData_user()
{
	FILE* fp = fopen("data.txt", "r"); //打开数据文件

	if (fp == NULL) //判断是否成功打开文件
	{
		printf("无法读取数据文件，已创建新的数据文件。\n");
		return;
	}
	fscanf(fp, "%d", &accountNum_user); //先读取账号数量
	for (int i = 0; i < accountNum_user; i++) //循环读取每个账号的用户名和密码
	{
		Account_user account;
		fscanf(fp, "%s %s", account.username, account.password);
		accounts[i] = account; //添加到数组中
	}
	fclose(fp);
}

//////////////////////////////////////用户操作/////////////////////////////////////

//显示所有商品信息
void showALLProducts_user()
{
	
	printf("商品列表：\n");
	
	//打印出所有商品
	for (int i = 0; i < productNum_user; i++)
	{
		printf("%d,%s,价格：%2f元\n", products[i].id, products[i].name, products[i].price);
	}

}

//搜索商品
void searchProduct(char* keyword)
{
	printf("搜索结果：\n");

	//判断商品是否存在
	int flag = 0;
	for (int i = 0; i < productNum_user; i++)
	{
		if (strstr(products[i].name, keyword) != NULL)
		{
			printf("%d,%s,价格：%.2f元\n", products[i].id, products[i].name, products[i].price);
			flag = 1;
		}
	}

	if (!flag)
	{
		printf("没有匹配的商品。\n");
	}


	//将搜索关键词添加到足迹中
	if (historyNum >= MAX_HISTORY)
	{
		//如果足迹已满，删除最早添加的一条记录
		for (int i = 0; i < historyNum - 1;i++)
		{
			history[i] = history[i + 1];
		}

		historyNum--;
	}
	history[historyNum] = -1; //标记为搜索关键词
	historyNum++;
}

//推荐商品
void recommendProducts()
{
	printf("推荐商品：\n");

	//遍历所有订单，统计每个商品被购买的次数
	int count[MAX_PRODUCTS_user] = { 0 };

	for (int i = 0; i < orderNum; i++)
	{
		count[orders[i].productId]++;
	}

	//找到购买次数最多的商品
	int maxCount = 0;
	int maxId = -1;

	for (int i = 0; i < orderNum; i++)
	{
		if (count[i] > maxCount)
		{
			maxCount = count[i];
			maxId = i;
		}
	}

	if (maxId == -1)
	{
		printf("暂无推荐商品！\n");
		return;
	}

	//输出购买次数最多的商品，并将其添加到足迹中
	printf("%d,%s,价格：%.2f元\n", products[maxId].id, products[maxId].name, products[maxId].price);

	if (historyNum >= MAX_HISTORY)
	{
		//如果足迹已满，删除最早添加的一条记录
		for (int i = 0; i < historyNum - 1; i++)
		{
			history[i] = history[i + 1];
		}

		historyNum--;
	}
	history[historyNum] = maxId;
	historyNum++;
}

//购买商品
void buyProduct(int id)
{
	//查找商品是否存在
	int index = -1;
	for (int i = 0; i < productNum_user; i++)
	{
		if (products[i].id == id)
		{
			index = i;
			break;
		}
	}

	if (index == -1)
	{
		printf("该商品不存在！\n");
		return;
	}

	//添加订单
	Order_user newOrder;
	newOrder.id = orderNum + 1; //订单编号从1开始
	newOrder.productId = id;
	newOrder.price = products[index].price;


	orders[orderNum] = newOrder; //添加新订单到数组中
	orderNum++;

	printf("购买成功！\n");

	//将购买的商品添加到足迹中
	if (historyNum >= MAX_HISTORY)
	{
		//如果足迹已满，删除最早添加的一条记录
		for (int i = 0; i < historyNum - 1; i++)
		{
			history[i] = history[i + 1];
		}

		historyNum--;
	}
}

//查看订单
void showALLOrders_user()
{
	printf("订单列表：\n");

	//打印出所有订单

	for (int i = 0; i < orderNum; i++)
	{
		printf("%d,商品编号：%d,价格：%.2f元\n", orders[i].id, orders[i].productId, orders[i].price);
	}
}

//查看足迹
void showHistory()
{
	printf("浏览足迹：\n");

	//打印出所有足迹
	for (int i = 0; i < historyNum; i++)
	{
		if (history[i] == -1)
		{
			printf("搜索关键词\n");
		}
		else
		{
			Product_user product = products[history[i]];

			printf("%d,%s,价格：%.2f元\n", product.id, product.name, product.price);
		}
	}
}

//显示操作菜单
void show_user()
{
	//初始化无效值
	int choice = 0;

	do
	{
		printf("*----------------------------------*\n");
		printf("*         欢迎使用用户系统         *\n");
		printf("*----------------------------------*\n");
		printf("*            请选择操作            *\n");
		printf("*----------------------------------*\n");
		printf("*          *>1.显示所有商品信息    *\n");
		printf("*          *>2.搜索商品            *\n");
		printf("*          *>3.推荐商品            *\n");
		printf("*          *>4.购买商品            *\n");
		printf("*          *>5.查看订单            *\n");
		printf("*          *>6.查看足迹            *\n");
		printf("*          *>7.退出                *\n");
		printf("*----------------------------------*\n");
		printf("          请输入选择编号 :");

		scanf("%d", &choice);

		system("cls");

		switch (choice)
		{
		case 1: //显示所有商品信息
		{
			showALLProducts_user();//显示商品函数
			break;
		}
		case 2: //搜索商品
		{
			//输入要搜索商品的关键字
			char keyword[50];
			printf("请输入关键词：\n");
			scanf("%s", keyword);
			searchProduct(keyword); //搜索商品函数
			break;
		}
		case 3: //查看推荐商品
		{
			recommendProducts(); //推荐商品函数
			break;
		}
		case 4: //购买商品
		{
			//输入要购买商品的编号
			int id;
			printf("请输入商品编号：\n");
			scanf("%d", &id);
			buyProduct(id); //购买商品函数
			break;
		}
		case 5: //显示订单
		{
			showALLOrders_user(); //展示所有订单
			break;
		}
		case 6: //查看足迹
		{
			showHistory(); //查看足迹函数
			break;
		}
		case 7: //退出
		{
			saveGoods(); //保存数据
			printf("已退出用户系统！\n");
			return 0;
		}
		default:
		{
			printf("无效操作，请重新输入。\n");
			break;
		}
		}
	} while (choice != 7);
	return ;
}

