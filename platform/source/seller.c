#include "platform.h"
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

Product_seller products[MAX_PRODUCTS_seller]; //存储所有商品
int productNum = 0; //当前商品数量

Order_seller orders[MAX_ORDERS_seller]; //存储所有订单
int orderNum = 0; //当前订单数量

RecommendedProduct recommendedProducts[MAX_PRODUCTS_seller]; //存储所有推荐商品
int recommendedProductNum = 0; //当前推荐商品数量

Account_seller accounts1[MAX_ACCOUNT_NUM_seller]; //储存所有账号
int accountNum_seller = 0; //当前账号数量

//////////////////////////////////账号登录////////////////////////////////

//注册账号
void registerAccount_seller()
{
	//判断账号数量是否达到上限
	if (accountNum_seller >= MAX_ACCOUNT_NUM_seller)
	{
		printf("账号数量已达上限，注册失败！\n");
		return;
	}
	 
	//创建新账号
	Account_seller newAccount;
	printf("请输入用户名：\n");
	scanf("%s", newAccount.username);

	//判断用户名是否已被注册
	for (int i = 0; i < accountNum_seller; i++)
	{
		if (strcmp(accounts1[i].username, newAccount.username) == 0)
		{
			printf("该用户名已被注册，请重新输入！\n");
			return;
		}
	}

	printf("请输入密码：\n");
	scanf("%s", newAccount.password);

	accounts1[accountNum_seller] = newAccount; //添加新账号到数组中
	accountNum_seller++;

	printf("账号注册成功！\n");
}

//登录
void login_seller()
{
	//创建账号密码数组
	char username[50];
	char password[50];

	printf("请输入用户名：\n");
	scanf("%s", username);
	printf("请输入密码：\n");
	scanf("%s", password);

	//判断用户名和密码是否正确
	for (int i = 0; i < accountNum_seller; i++)
	{
		if (strcmp(accounts1[i].username, username) == 0 && strcmp(accounts1[i].password, password) == 0)
		{
			printf("*----------------------------------*\n");
			printf("*             登录成功！           *\n");
			printf("*----------------------------------*\n");
			printf("*          尊敬的用户：%s           *\n", username);

			show_seller();//登录成功后的操作页面
			return;
		}

	}
	printf("用户名或密码错误，已退出登录界面！\n");
}

//找回密码
void findPassword_seller()
{
	char username[50];

	printf("请输入用户名：\n");
	scanf("%s", username);

	//判断用户名是否存在，并输出密码
	for (int i = 0; i < accountNum_seller; i++)
	{
		if (strcmp(accounts1[i].username, username) == 0)
		{
			printf("你的密码为：%s\n", accounts1[i].password);
			return;
		}
	}
	printf("该用户名不存在，请重新输入！\n");
}

//保存数据到文件
void saveData_seller()
{
	FILE* fp = fopen("data.txt", "w"); //创造或打开文件

	fprintf(fp, "%d\n", accountNum_seller); //先写入账号数量
	for (int i = 0; i < accountNum_seller; i++) //循环写入每个账号的用户名和密码
	{
		fprintf(fp, "%s %s\n", accounts1[i].username, accounts1[i].password);
	}
	fclose(fp); //关闭文件
}

//从文件中加载数据
void loadData_seller()
{
	FILE* fp = fopen("data.txt", "r"); //打开数据文件

	if (fp == NULL) //判断是否成功打开文件
	{
		printf("无法读取数据文件，已创建新的数据文件。\n");
		return;
	}
	fscanf(fp, "%d", &accountNum_seller); //先读取账号数量
	for (int i = 0; i < accountNum_seller; i++) //循环读取每个账号的用户名和密码
	{
		Account_seller account;
		fscanf(fp, "%s %s", account.username, account.password);
		accounts1[i] = account; //添加到数组中
	}
	fclose(fp);
}

/////////////////////////////////商家操作/////////////////////////////////

//添加商品
void addProduct(int id, char* name, float price)
{
	//判断商品数量是否达到上限
	if (productNum >= MAX_PRODUCTS_seller)
	{
		printf("商品数量已达上限，添加失败！\n");
		return;
	}

	//创建新商品
	Product_seller newProduct;
	newProduct.id = id;
	strcpy(newProduct.name, name);
	newProduct.price = price;

	products[productNum] = newProduct;
	productNum++;

	printf("商品添加成功！\n");
}

//修改商品
void updataProduct(int id, char* name, float price)
{
	//查找要修改的商品是否存在
	int index = -1;

	for (int i = 0; i < productNum; i++)
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

	//修改商品信息
	strcpy(products[index].name, name);
	products[index].price = price;

	printf("商品修改成功！\n");
}

//删除商品
void deleteProduct(int id)
{
	//查找要删除的商品是否存在
	int index = -1;

	for (int i = 0; i < productNum; i++)
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

	//删除商品并将后面的商品向前移动
	for (int i = index; i < productNum - 1; i++)
	{
		products[i] = products[i + 1];
	}

	productNum--;

	printf("商品删除成功！\n");
}

//显示所有商品
void showALLProduct_seller()
{
	printf("商品列表：\n");

	//打印出所有商品
	for (int i = 0; i < productNum; i++)
	{
		printf("%d,%s,价格：%2f元\n", products[i].id, products[i].name, products[i].price);
	}
}

//订单系统
void showALLOrders_seller()
{
	//初始化无效值
	int choice=0;

	do {
		// 显示操作菜单
		printf("*----------------------------------*\n");
		printf("*          商家订单处理系统菜单    *\n");
		printf("*----------------------------------*\n");
		printf("*            请选择操作            *\n");
		printf("*----------------------------------*\n");
		printf("*          *>1. 添加订单           *\n");
		printf("*          *>2. 查询订单           *\n");
		printf("*          *>3. 发货               *\n");
		printf("*          *>4. 通知客户           *\n");
		printf("*          *>5. 退出               *\n");
		printf("*----------------------------------*\n");
		printf("          请输入选择编号 :");

		// 读取用户选择
		scanf("%d", &choice);

		system("cls");

		// 处理用户选择
		switch (choice) {
		case 1: //添加订单
			addOrder(); //添加订单函数
			break;
		case 2: //查询订单
			queryOrder(); //查询订单函数
			break;
		case 3: //发货
			sendOrder(); //发货函数
			break;
		case 4: //通知顾客
			notifyCustomer(); //通知顾客函数
			break;
		case 5:
			printf("已退出订单系统！\n");
			break;
		default:
			printf("无效的操作，请重新输入.\n");
			break;
		}
	} while (choice != 5);

	return 0;
}

// 添加订单
void addOrder() 
{
	//判断订单数量是否已达上限
	if (orderNum >= MAX_ORDERS_seller) {
		printf("已达到最大订单数量.\n");
		return;
	}

	//创建新订单
	Order_seller order;
	printf("请输入订单号: ");
	scanf("%d", &order.id);
	printf("请输入客户名称: ");
	scanf("%s", &order.customer_name);
	printf("请输入商品编号：");
	scanf("%d", &order.productId);
	printf("请输入商品名称: ");
	scanf("%s", &order.goods_name);
	printf("请输入商品价格: ");
	scanf("%f", &order.price);
	printf("请输入商品数量: ");
	scanf("%d", &order.quantity);
	strcpy(order.status, "待发货");

	orders[orderNum] = order;
	++orderNum;
	printf("订单已成功添加.\n");
}

// 查询订单
void queryOrder() 
{
	//查找订单信息
	if (orderNum == 0) {
		printf("订单信息为空.\n");
		return;
	}

	printf("订单号\t客户名称\t商品名称\t商品价格\t商品数量\t订单状态\n");
	for (int i = 0; i < orderNum; ++i) {
		printf("%d\t%s\t%s\t%.2f\t%d\t%s\n", orders[i].id, orders[i].customer_name, orders[i].goods_name, orders[i].price, orders[i].quantity, orders[i].status);
	}
}

// 发货操作
void sendOrder() 
{
	//查找订单
	if (orderNum== 0) {
		printf("订单信息为空.\n");
		return;
	}

	//改变订单发货状态
	int order_num;
	printf("请输入要发货的订单号: ");
	scanf("%d", &order_num);

	int index = -1;
	for (int i = 0; i < orderNum; ++i) {
		if (orders[i].id== order_num && strcmp(orders[i].status, "待发货") == 0) {
			index = i;
			break;
		}
	}

	if (index == -1) {
		printf("无法找到指定的订单或该订单已处理.\n");
		return;
	}

	strcpy(orders[index].status, "已发货");
	printf("订单已成功发货.\n");
}

// 通知客户
void notifyCustomer()
{
	//查找订单
	if (orderNum == 0) {
		printf("订单信息为空.\n");
		return;
	}

	//通知客户
	int order_num;
	printf("请输入要通知客户的订单号: ");
	scanf("%d", &order_num);

	int index = -1;
	for (int i = 0; i < orderNum; ++i) {
		if (orders[i].id == order_num && strcmp(orders[i].status, "已发货") == 0) {
			index = i;
			break;
		}
	}

	if (index == -1) {
		printf("无法找到指定的订单或该订单未发货.\n");
		return;
	}

	printf("客户 %s，您好！您的订单 %d 已成功发货，请注意查收！", orders[index].customer_name, order_num);
}

//添加推荐商品
void addRecommendedProduct(int id, char* name, float price)
{
	//判断推荐商品数量是否已达上限
	if (recommendedProductNum >= MAX_PRODUCTS_seller)
	{
		printf("推荐商品数量已达上限，添加失败！\n");
		return;
	}

	//创建新推荐商品
	RecommendedProduct newProduct;
	newProduct.id = id;
	strcpy(newProduct.name, name);
	newProduct.price = price;
	recommendedProducts[recommendedProductNum] = newProduct; //添加新推荐商品到数组中
	recommendedProductNum++;

	printf("推荐商品添加成功！\n");
}

//删除推荐商品
void deleteRecommendedProduct(int id)
{
	//查找要删除的推荐商品是否存在
	int index = -1;

	for (int i = 0; i < recommendedProductNum; i++)
	{
		if (recommendedProducts[i].id == id)
		{
			index = i;
			break;
		}
	}

	if (index == -1)
	{
		printf("该推荐商品不存在！\n");
		return;
	}

	//删除推荐商品并将后面的商品向前移动
	for (int i = index; i < recommendedProductNum - 1; i++)
	{
		recommendedProducts[i] = recommendedProducts[i + 1];
	}

	recommendedProductNum--;

	printf("商品删除成功！\n");
}

//显示所有推荐商品
void showALLRecommendedProducts()
{
	//打印出所有推荐商品信息
	printf("推荐商品列表：\n");
	for (int i = 0; i < recommendedProductNum; i++)
	{
		printf("%d,商品编号：%d,商品名称：%s,价格：%f元\n", recommendedProducts[i].id, recommendedProducts[i].name, recommendedProducts[i].price);

	}
}

//审核商品推荐申请
void reviewRecommendProductApplication()
{
	//管理员进行审核
	//审核通过后，商家系统中增加商品推荐功能
	printf("推荐商品申请已提交，请等待管理员审核\n");
}

//申请提现
void applyWithdrawal(float amount)
{
	//商家填写提现申请表
	//管理员审核通过后，执行提现操作
	printf("提现申请已提交，请等待管理员审核！\n");
}

//保存商品信息到文件
void saveGoods()
{
	FILE* fp = fopen("goods.txt", "w"); //创造或打开文件

	fprintf(fp, "%d\n", productNum); //先写入商品数量
	
	for (int i = 0; i < productNum; i++) //循环写入每个商品的编号和名称和价格
	{
		fprintf(fp, "%d %s %d\n", products[i].id ,products[i].name,products[i].price);
	}

	fclose(fp); //关闭文件
}

//从文件中加载商品信息
void loadGoods()
{
	FILE* fp = fopen("goods.txt", "r"); //打开数据文件

	if (fp == NULL) //判断是否成功打开文件
	{
		printf("无法读取数据文件，已创建新的数据文件。\n");
		return;
	}

	fscanf(fp, "%d", &productNum); //先读取账号数量
	
	for (int i = 0; i < productNum; i++) //循环读取每个账号的用户名和密码
	{
		Product_seller goods;
		fscanf(fp, "%d %s %d", goods.id,goods.name,goods.price);
		products[i] = goods; //添加到数组中
	}

	fclose(fp);
}

//显示操作菜单
void show_seller()
{
	//初始化无效值
	int choice = 0;

	do
	{
		printf("*----------------------------------*\n");
		printf("*         欢迎使用商家系统         *\n");
		printf("*----------------------------------*\n");
		printf("*            请选择操作            *\n");
		printf("*----------------------------------*\n");
		printf("*          *>1.显示所有商品        *\n");
		printf("*          *>2.添加商品            *\n");
		printf("*          *>3.修改商品            *\n");
		printf("*          *>4.删除商品            *\n");
		printf("*          *>5.进入订单系统        *\n");
		printf("*          *>6.添加推荐商品        *\n");
		printf("*          *>7.删除推荐商品        *\n");
		printf("*          *>8.查看所有推荐商品    *\n");
		printf("*          *>9.审核商品推荐申请    *\n");
		printf("*          *>10.申请提现           *\n");
		printf("*          *>11.退出               *\n");
		printf("*----------------------------------*\n");
		printf("          请输入选择编号 :");

		scanf("%d", &choice);

		system("cls");

		switch (choice)
		{
		case 1: //显示所有商品
		{
			showALLProduct_seller(); //显示所有商品函数
			break;
		}
		case 2: //添加商品
		{
			//输入商品信息
			int id;
			char name[50];
			float price;

			printf("请输入商品编号：");
			scanf("%d", &id);

			printf("请输入商品名称：");
			scanf("%s", &name);

			printf("请输入商品价格：");
			scanf("%f", &price);

			addProduct(id, name, price); //添加商品函数
			break;
		}
		case 3: //修改商品
		{
			//输入要修改商品的信息
			int id;
			char name[50];
			float price;

			printf("请输入要修改的商品编号：");
			scanf("%d", &id);

			printf("请输入新的商品名称：");
			scanf("%s", &name);

			printf("请输入新的商品价格：");
			scanf("%f", &price);

			updataProduct(id, name, price); //修改商品函数
			break;
		}
		case 4: //删除商品
		{
			//输入要删除商品的信息
			int id;

			printf("请输入要删除的商品编号：");
			scanf("%d", &id);

			deleteProduct(id); //删除商品函数
			break;
		}
		case 5: //显示订单系统
		{
			showALLOrders_seller(); //显示订单系统
			break;
		}
		case 6: //推荐商品
		{
			//输入推荐商品信息
			int id;
			char name[50];
			float price;

			printf("请输入推荐商品编号：");
			scanf("%d", &id);

			printf("请输入推荐商品名称：");
			scanf("%s", &name);

			printf("请输入推荐商品价格：");
			scanf("%f", &price);

			addRecommendedProduct(id, name, price);//推荐商品函数
			break;
		}
		case 7: //删除推荐商品
		{
			//输入要删除推荐商品的信息
			int id;

			printf("请输入要删除的推荐商品编号：");
			scanf("%d", &id);

			deleteRecommendedProduct(id); //删除推荐商品函数
			break;
		}
		case 8: //显示所有推荐商品
		{
			showALLRecommendedProducts(); //显示所有推荐商品函数
			break;
		}
		case 9: //推荐商品申请
		{
			reviewRecommendProductApplication(); //推荐商品申请函数
			break;
		}
		case 10: //提现收益
		{
			//输入要提现的金额
			float amount;

			printf("请输入提现金额：");
			scanf("%f", &amount);

			applyWithdrawal(amount); //提现收益函数
			break;
		}
		case 11: //退出商家系统
		{
			printf("已退出商家系统！\n");
			return 0;
		}
		default:
		{
			printf("无效操作！\n");
			break;
		}
		}
	}while (choice != 11);
	return;
}