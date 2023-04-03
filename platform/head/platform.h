#ifndef PLATFORM_H_INCLUDED
#define PLATFORM_H_INCLUDED

///////////////////////////////////////////////用户模块////////////////////////////////////////////////

#define MAX_ACCOUNT_NUM_user 100 //用户最大账号数量
#define MAX_PRODUCTS_user 100 //最大商品数量
#define MAX_HISTORY 100 //最大足迹数量
#define MAX_ORDERS_user 100 //最大订单数量

//结构体声明

typedef struct Protect_user 
{
	int id; //商品编号
	char name[50]; //商品名称
	float price; //商品价格
}Product_user;

typedef struct Order_user
{
	int id; //订单编号
	int productId; //商品编号
	float price; //商品价格
}Order_user;

typedef struct Account_user
{
	char username[50]; //用户名
	char password[50]; //密码
}Account_user;

//函数声明

void registerAccount_user(); //注册账号
void login_user(); //登录
void findPassword_user(); //找回密码
void saveData_user(); //保存数据到文件
void loadData_user(); //从文件中加载数据
void showALLProducts_user(); //显示所有商品信息
void searchProduct(char* keyword); //搜索商品
void recommendProducts(); //推荐商品
void buyProduct(int id); //购买商品
void showALLOrders_user(); //查看订单
void showHistory(); //查看足迹
void show_user(); //显示操作菜单

/////////////////////////////////////////商家模块//////////////////////////////////////

#define MAX_ACCOUNT_NUM_seller 100 //商家最大账号数量
#define MAX_PRODUCTS_seller 100 //最大商品数量
#define MAX_ORDERS_seller 100 //最大订单数量

//结构体定义

typedef struct Account_seller
{
	char username[50]; //用户名
	char password[50]; //密码
}Account_seller;

typedef struct Product_seller
{
	int id; //商品编号
	char name[50]; //商品名称
	float price; //商品价格
}Product_seller;

typedef struct Order_seller
{
	int id; //订单编号
	char customer_name[20]; //客户名称
	int productId; //商品编号
	char goods_name; //商品名称
	float price; //商品价格
	int quantity; //商品数量
	char status[20]; //订单状态
}Order_seller;

typedef struct RecommendedProduct
{
	int id; //推荐商品编号
	char name[50]; //推荐商品名称
	float price; //推荐商品价格
}RecommendedProduct;

//函数声明

void registerAccount_seller(); //注册账号
void login_seller(); //登录
void findPassword_seller(); //找回密码
void saveData_seller(); //保存数据到文件
void loadData_seller(); //从文件中加载数据
void addProduct(int id, char* name, float price); //添加商品
void updataProduct(int id, char* name, float price); //修改商品
void deleteProduct(int id); //删除商品
void showALLProduct_seller(); //查看所有商品
void showALLOrders_seller(); //订单系统
void addOrder();// 添加订单
void queryOrder();// 查询订单
void sendOrder();// 发货操作
void notifyCustomer();// 通知客户
void addRecommendedProduct(int id, char* name, float price); //添加推荐商品
void deleteRecommendedProduct(int id); //删除推荐商品
void showALLRecommendedProducts(); //显示所有推荐商品
void reviewRecommendProductApplication(); //审核商品推荐申请
void applyWithdrawal(float amount); //申请提现
void saveGoods();//保存商品信息到文件
void loadGoods();//从文件中加载商品信息
void show_seller(); //显示操作菜单

#endif //PLATFORM_H_INCLUDED