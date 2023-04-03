#ifndef PLATFORM_H_INCLUDED
#define PLATFORM_H_INCLUDED

///////////////////////////////////////////////�û�ģ��////////////////////////////////////////////////

#define MAX_ACCOUNT_NUM_user 100 //�û�����˺�����
#define MAX_PRODUCTS_user 100 //�����Ʒ����
#define MAX_HISTORY 100 //����㼣����
#define MAX_ORDERS_user 100 //��󶩵�����

//�ṹ������

typedef struct Protect_user 
{
	int id; //��Ʒ���
	char name[50]; //��Ʒ����
	float price; //��Ʒ�۸�
}Product_user;

typedef struct Order_user
{
	int id; //�������
	int productId; //��Ʒ���
	float price; //��Ʒ�۸�
}Order_user;

typedef struct Account_user
{
	char username[50]; //�û���
	char password[50]; //����
}Account_user;

//��������

void registerAccount_user(); //ע���˺�
void login_user(); //��¼
void findPassword_user(); //�һ�����
void saveData_user(); //�������ݵ��ļ�
void loadData_user(); //���ļ��м�������
void showALLProducts_user(); //��ʾ������Ʒ��Ϣ
void searchProduct(char* keyword); //������Ʒ
void recommendProducts(); //�Ƽ���Ʒ
void buyProduct(int id); //������Ʒ
void showALLOrders_user(); //�鿴����
void showHistory(); //�鿴�㼣
void show_user(); //��ʾ�����˵�

/////////////////////////////////////////�̼�ģ��//////////////////////////////////////

#define MAX_ACCOUNT_NUM_seller 100 //�̼�����˺�����
#define MAX_PRODUCTS_seller 100 //�����Ʒ����
#define MAX_ORDERS_seller 100 //��󶩵�����

//�ṹ�嶨��

typedef struct Account_seller
{
	char username[50]; //�û���
	char password[50]; //����
}Account_seller;

typedef struct Product_seller
{
	int id; //��Ʒ���
	char name[50]; //��Ʒ����
	float price; //��Ʒ�۸�
}Product_seller;

typedef struct Order_seller
{
	int id; //�������
	char customer_name[20]; //�ͻ�����
	int productId; //��Ʒ���
	char goods_name; //��Ʒ����
	float price; //��Ʒ�۸�
	int quantity; //��Ʒ����
	char status[20]; //����״̬
}Order_seller;

typedef struct RecommendedProduct
{
	int id; //�Ƽ���Ʒ���
	char name[50]; //�Ƽ���Ʒ����
	float price; //�Ƽ���Ʒ�۸�
}RecommendedProduct;

//��������

void registerAccount_seller(); //ע���˺�
void login_seller(); //��¼
void findPassword_seller(); //�һ�����
void saveData_seller(); //�������ݵ��ļ�
void loadData_seller(); //���ļ��м�������
void addProduct(int id, char* name, float price); //�����Ʒ
void updataProduct(int id, char* name, float price); //�޸���Ʒ
void deleteProduct(int id); //ɾ����Ʒ
void showALLProduct_seller(); //�鿴������Ʒ
void showALLOrders_seller(); //����ϵͳ
void addOrder();// ��Ӷ���
void queryOrder();// ��ѯ����
void sendOrder();// ��������
void notifyCustomer();// ֪ͨ�ͻ�
void addRecommendedProduct(int id, char* name, float price); //����Ƽ���Ʒ
void deleteRecommendedProduct(int id); //ɾ���Ƽ���Ʒ
void showALLRecommendedProducts(); //��ʾ�����Ƽ���Ʒ
void reviewRecommendProductApplication(); //�����Ʒ�Ƽ�����
void applyWithdrawal(float amount); //��������
void saveGoods();//������Ʒ��Ϣ���ļ�
void loadGoods();//���ļ��м�����Ʒ��Ϣ
void show_seller(); //��ʾ�����˵�

#endif //PLATFORM_H_INCLUDED