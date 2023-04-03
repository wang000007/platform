#include "platform.h"
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

Product_seller products[MAX_PRODUCTS_seller]; //�洢������Ʒ
int productNum = 0; //��ǰ��Ʒ����

Order_seller orders[MAX_ORDERS_seller]; //�洢���ж���
int orderNum = 0; //��ǰ��������

RecommendedProduct recommendedProducts[MAX_PRODUCTS_seller]; //�洢�����Ƽ���Ʒ
int recommendedProductNum = 0; //��ǰ�Ƽ���Ʒ����

Account_seller accounts1[MAX_ACCOUNT_NUM_seller]; //���������˺�
int accountNum_seller = 0; //��ǰ�˺�����

//////////////////////////////////�˺ŵ�¼////////////////////////////////

//ע���˺�
void registerAccount_seller()
{
	//�ж��˺������Ƿ�ﵽ����
	if (accountNum_seller >= MAX_ACCOUNT_NUM_seller)
	{
		printf("�˺������Ѵ����ޣ�ע��ʧ�ܣ�\n");
		return;
	}
	 
	//�������˺�
	Account_seller newAccount;
	printf("�������û�����\n");
	scanf("%s", newAccount.username);

	//�ж��û����Ƿ��ѱ�ע��
	for (int i = 0; i < accountNum_seller; i++)
	{
		if (strcmp(accounts1[i].username, newAccount.username) == 0)
		{
			printf("���û����ѱ�ע�ᣬ���������룡\n");
			return;
		}
	}

	printf("���������룺\n");
	scanf("%s", newAccount.password);

	accounts1[accountNum_seller] = newAccount; //������˺ŵ�������
	accountNum_seller++;

	printf("�˺�ע��ɹ���\n");
}

//��¼
void login_seller()
{
	//�����˺���������
	char username[50];
	char password[50];

	printf("�������û�����\n");
	scanf("%s", username);
	printf("���������룺\n");
	scanf("%s", password);

	//�ж��û����������Ƿ���ȷ
	for (int i = 0; i < accountNum_seller; i++)
	{
		if (strcmp(accounts1[i].username, username) == 0 && strcmp(accounts1[i].password, password) == 0)
		{
			printf("*----------------------------------*\n");
			printf("*             ��¼�ɹ���           *\n");
			printf("*----------------------------------*\n");
			printf("*          �𾴵��û���%s           *\n", username);

			show_seller();//��¼�ɹ���Ĳ���ҳ��
			return;
		}

	}
	printf("�û���������������˳���¼���棡\n");
}

//�һ�����
void findPassword_seller()
{
	char username[50];

	printf("�������û�����\n");
	scanf("%s", username);

	//�ж��û����Ƿ���ڣ����������
	for (int i = 0; i < accountNum_seller; i++)
	{
		if (strcmp(accounts1[i].username, username) == 0)
		{
			printf("�������Ϊ��%s\n", accounts1[i].password);
			return;
		}
	}
	printf("���û��������ڣ����������룡\n");
}

//�������ݵ��ļ�
void saveData_seller()
{
	FILE* fp = fopen("data.txt", "w"); //�������ļ�

	fprintf(fp, "%d\n", accountNum_seller); //��д���˺�����
	for (int i = 0; i < accountNum_seller; i++) //ѭ��д��ÿ���˺ŵ��û���������
	{
		fprintf(fp, "%s %s\n", accounts1[i].username, accounts1[i].password);
	}
	fclose(fp); //�ر��ļ�
}

//���ļ��м�������
void loadData_seller()
{
	FILE* fp = fopen("data.txt", "r"); //�������ļ�

	if (fp == NULL) //�ж��Ƿ�ɹ����ļ�
	{
		printf("�޷���ȡ�����ļ����Ѵ����µ������ļ���\n");
		return;
	}
	fscanf(fp, "%d", &accountNum_seller); //�ȶ�ȡ�˺�����
	for (int i = 0; i < accountNum_seller; i++) //ѭ����ȡÿ���˺ŵ��û���������
	{
		Account_seller account;
		fscanf(fp, "%s %s", account.username, account.password);
		accounts1[i] = account; //��ӵ�������
	}
	fclose(fp);
}

/////////////////////////////////�̼Ҳ���/////////////////////////////////

//�����Ʒ
void addProduct(int id, char* name, float price)
{
	//�ж���Ʒ�����Ƿ�ﵽ����
	if (productNum >= MAX_PRODUCTS_seller)
	{
		printf("��Ʒ�����Ѵ����ޣ����ʧ�ܣ�\n");
		return;
	}

	//��������Ʒ
	Product_seller newProduct;
	newProduct.id = id;
	strcpy(newProduct.name, name);
	newProduct.price = price;

	products[productNum] = newProduct;
	productNum++;

	printf("��Ʒ��ӳɹ���\n");
}

//�޸���Ʒ
void updataProduct(int id, char* name, float price)
{
	//����Ҫ�޸ĵ���Ʒ�Ƿ����
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
		printf("����Ʒ�����ڣ�\n");
		return;
	}

	//�޸���Ʒ��Ϣ
	strcpy(products[index].name, name);
	products[index].price = price;

	printf("��Ʒ�޸ĳɹ���\n");
}

//ɾ����Ʒ
void deleteProduct(int id)
{
	//����Ҫɾ������Ʒ�Ƿ����
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
		printf("����Ʒ�����ڣ�\n");
		return;
	}

	//ɾ����Ʒ�����������Ʒ��ǰ�ƶ�
	for (int i = index; i < productNum - 1; i++)
	{
		products[i] = products[i + 1];
	}

	productNum--;

	printf("��Ʒɾ���ɹ���\n");
}

//��ʾ������Ʒ
void showALLProduct_seller()
{
	printf("��Ʒ�б�\n");

	//��ӡ��������Ʒ
	for (int i = 0; i < productNum; i++)
	{
		printf("%d,%s,�۸�%2fԪ\n", products[i].id, products[i].name, products[i].price);
	}
}

//����ϵͳ
void showALLOrders_seller()
{
	//��ʼ����Чֵ
	int choice=0;

	do {
		// ��ʾ�����˵�
		printf("*----------------------------------*\n");
		printf("*          �̼Ҷ�������ϵͳ�˵�    *\n");
		printf("*----------------------------------*\n");
		printf("*            ��ѡ�����            *\n");
		printf("*----------------------------------*\n");
		printf("*          *>1. ��Ӷ���           *\n");
		printf("*          *>2. ��ѯ����           *\n");
		printf("*          *>3. ����               *\n");
		printf("*          *>4. ֪ͨ�ͻ�           *\n");
		printf("*          *>5. �˳�               *\n");
		printf("*----------------------------------*\n");
		printf("          ������ѡ���� :");

		// ��ȡ�û�ѡ��
		scanf("%d", &choice);

		system("cls");

		// �����û�ѡ��
		switch (choice) {
		case 1: //��Ӷ���
			addOrder(); //��Ӷ�������
			break;
		case 2: //��ѯ����
			queryOrder(); //��ѯ��������
			break;
		case 3: //����
			sendOrder(); //��������
			break;
		case 4: //֪ͨ�˿�
			notifyCustomer(); //֪ͨ�˿ͺ���
			break;
		case 5:
			printf("���˳�����ϵͳ��\n");
			break;
		default:
			printf("��Ч�Ĳ���������������.\n");
			break;
		}
	} while (choice != 5);

	return 0;
}

// ��Ӷ���
void addOrder() 
{
	//�ж϶��������Ƿ��Ѵ�����
	if (orderNum >= MAX_ORDERS_seller) {
		printf("�Ѵﵽ��󶩵�����.\n");
		return;
	}

	//�����¶���
	Order_seller order;
	printf("�����붩����: ");
	scanf("%d", &order.id);
	printf("������ͻ�����: ");
	scanf("%s", &order.customer_name);
	printf("��������Ʒ��ţ�");
	scanf("%d", &order.productId);
	printf("��������Ʒ����: ");
	scanf("%s", &order.goods_name);
	printf("��������Ʒ�۸�: ");
	scanf("%f", &order.price);
	printf("��������Ʒ����: ");
	scanf("%d", &order.quantity);
	strcpy(order.status, "������");

	orders[orderNum] = order;
	++orderNum;
	printf("�����ѳɹ����.\n");
}

// ��ѯ����
void queryOrder() 
{
	//���Ҷ�����Ϣ
	if (orderNum == 0) {
		printf("������ϢΪ��.\n");
		return;
	}

	printf("������\t�ͻ�����\t��Ʒ����\t��Ʒ�۸�\t��Ʒ����\t����״̬\n");
	for (int i = 0; i < orderNum; ++i) {
		printf("%d\t%s\t%s\t%.2f\t%d\t%s\n", orders[i].id, orders[i].customer_name, orders[i].goods_name, orders[i].price, orders[i].quantity, orders[i].status);
	}
}

// ��������
void sendOrder() 
{
	//���Ҷ���
	if (orderNum== 0) {
		printf("������ϢΪ��.\n");
		return;
	}

	//�ı䶩������״̬
	int order_num;
	printf("������Ҫ�����Ķ�����: ");
	scanf("%d", &order_num);

	int index = -1;
	for (int i = 0; i < orderNum; ++i) {
		if (orders[i].id== order_num && strcmp(orders[i].status, "������") == 0) {
			index = i;
			break;
		}
	}

	if (index == -1) {
		printf("�޷��ҵ�ָ���Ķ�����ö����Ѵ���.\n");
		return;
	}

	strcpy(orders[index].status, "�ѷ���");
	printf("�����ѳɹ�����.\n");
}

// ֪ͨ�ͻ�
void notifyCustomer()
{
	//���Ҷ���
	if (orderNum == 0) {
		printf("������ϢΪ��.\n");
		return;
	}

	//֪ͨ�ͻ�
	int order_num;
	printf("������Ҫ֪ͨ�ͻ��Ķ�����: ");
	scanf("%d", &order_num);

	int index = -1;
	for (int i = 0; i < orderNum; ++i) {
		if (orders[i].id == order_num && strcmp(orders[i].status, "�ѷ���") == 0) {
			index = i;
			break;
		}
	}

	if (index == -1) {
		printf("�޷��ҵ�ָ���Ķ�����ö���δ����.\n");
		return;
	}

	printf("�ͻ� %s�����ã����Ķ��� %d �ѳɹ���������ע����գ�", orders[index].customer_name, order_num);
}

//����Ƽ���Ʒ
void addRecommendedProduct(int id, char* name, float price)
{
	//�ж��Ƽ���Ʒ�����Ƿ��Ѵ�����
	if (recommendedProductNum >= MAX_PRODUCTS_seller)
	{
		printf("�Ƽ���Ʒ�����Ѵ����ޣ����ʧ�ܣ�\n");
		return;
	}

	//�������Ƽ���Ʒ
	RecommendedProduct newProduct;
	newProduct.id = id;
	strcpy(newProduct.name, name);
	newProduct.price = price;
	recommendedProducts[recommendedProductNum] = newProduct; //������Ƽ���Ʒ��������
	recommendedProductNum++;

	printf("�Ƽ���Ʒ��ӳɹ���\n");
}

//ɾ���Ƽ���Ʒ
void deleteRecommendedProduct(int id)
{
	//����Ҫɾ�����Ƽ���Ʒ�Ƿ����
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
		printf("���Ƽ���Ʒ�����ڣ�\n");
		return;
	}

	//ɾ���Ƽ���Ʒ�����������Ʒ��ǰ�ƶ�
	for (int i = index; i < recommendedProductNum - 1; i++)
	{
		recommendedProducts[i] = recommendedProducts[i + 1];
	}

	recommendedProductNum--;

	printf("��Ʒɾ���ɹ���\n");
}

//��ʾ�����Ƽ���Ʒ
void showALLRecommendedProducts()
{
	//��ӡ�������Ƽ���Ʒ��Ϣ
	printf("�Ƽ���Ʒ�б�\n");
	for (int i = 0; i < recommendedProductNum; i++)
	{
		printf("%d,��Ʒ��ţ�%d,��Ʒ���ƣ�%s,�۸�%fԪ\n", recommendedProducts[i].id, recommendedProducts[i].name, recommendedProducts[i].price);

	}
}

//�����Ʒ�Ƽ�����
void reviewRecommendProductApplication()
{
	//����Ա�������
	//���ͨ�����̼�ϵͳ��������Ʒ�Ƽ�����
	printf("�Ƽ���Ʒ�������ύ����ȴ�����Ա���\n");
}

//��������
void applyWithdrawal(float amount)
{
	//�̼���д���������
	//����Ա���ͨ����ִ�����ֲ���
	printf("�����������ύ����ȴ�����Ա��ˣ�\n");
}

//������Ʒ��Ϣ���ļ�
void saveGoods()
{
	FILE* fp = fopen("goods.txt", "w"); //�������ļ�

	fprintf(fp, "%d\n", productNum); //��д����Ʒ����
	
	for (int i = 0; i < productNum; i++) //ѭ��д��ÿ����Ʒ�ı�ź����ƺͼ۸�
	{
		fprintf(fp, "%d %s %d\n", products[i].id ,products[i].name,products[i].price);
	}

	fclose(fp); //�ر��ļ�
}

//���ļ��м�����Ʒ��Ϣ
void loadGoods()
{
	FILE* fp = fopen("goods.txt", "r"); //�������ļ�

	if (fp == NULL) //�ж��Ƿ�ɹ����ļ�
	{
		printf("�޷���ȡ�����ļ����Ѵ����µ������ļ���\n");
		return;
	}

	fscanf(fp, "%d", &productNum); //�ȶ�ȡ�˺�����
	
	for (int i = 0; i < productNum; i++) //ѭ����ȡÿ���˺ŵ��û���������
	{
		Product_seller goods;
		fscanf(fp, "%d %s %d", goods.id,goods.name,goods.price);
		products[i] = goods; //��ӵ�������
	}

	fclose(fp);
}

//��ʾ�����˵�
void show_seller()
{
	//��ʼ����Чֵ
	int choice = 0;

	do
	{
		printf("*----------------------------------*\n");
		printf("*         ��ӭʹ���̼�ϵͳ         *\n");
		printf("*----------------------------------*\n");
		printf("*            ��ѡ�����            *\n");
		printf("*----------------------------------*\n");
		printf("*          *>1.��ʾ������Ʒ        *\n");
		printf("*          *>2.�����Ʒ            *\n");
		printf("*          *>3.�޸���Ʒ            *\n");
		printf("*          *>4.ɾ����Ʒ            *\n");
		printf("*          *>5.���붩��ϵͳ        *\n");
		printf("*          *>6.����Ƽ���Ʒ        *\n");
		printf("*          *>7.ɾ���Ƽ���Ʒ        *\n");
		printf("*          *>8.�鿴�����Ƽ���Ʒ    *\n");
		printf("*          *>9.�����Ʒ�Ƽ�����    *\n");
		printf("*          *>10.��������           *\n");
		printf("*          *>11.�˳�               *\n");
		printf("*----------------------------------*\n");
		printf("          ������ѡ���� :");

		scanf("%d", &choice);

		system("cls");

		switch (choice)
		{
		case 1: //��ʾ������Ʒ
		{
			showALLProduct_seller(); //��ʾ������Ʒ����
			break;
		}
		case 2: //�����Ʒ
		{
			//������Ʒ��Ϣ
			int id;
			char name[50];
			float price;

			printf("��������Ʒ��ţ�");
			scanf("%d", &id);

			printf("��������Ʒ���ƣ�");
			scanf("%s", &name);

			printf("��������Ʒ�۸�");
			scanf("%f", &price);

			addProduct(id, name, price); //�����Ʒ����
			break;
		}
		case 3: //�޸���Ʒ
		{
			//����Ҫ�޸���Ʒ����Ϣ
			int id;
			char name[50];
			float price;

			printf("������Ҫ�޸ĵ���Ʒ��ţ�");
			scanf("%d", &id);

			printf("�������µ���Ʒ���ƣ�");
			scanf("%s", &name);

			printf("�������µ���Ʒ�۸�");
			scanf("%f", &price);

			updataProduct(id, name, price); //�޸���Ʒ����
			break;
		}
		case 4: //ɾ����Ʒ
		{
			//����Ҫɾ����Ʒ����Ϣ
			int id;

			printf("������Ҫɾ������Ʒ��ţ�");
			scanf("%d", &id);

			deleteProduct(id); //ɾ����Ʒ����
			break;
		}
		case 5: //��ʾ����ϵͳ
		{
			showALLOrders_seller(); //��ʾ����ϵͳ
			break;
		}
		case 6: //�Ƽ���Ʒ
		{
			//�����Ƽ���Ʒ��Ϣ
			int id;
			char name[50];
			float price;

			printf("�������Ƽ���Ʒ��ţ�");
			scanf("%d", &id);

			printf("�������Ƽ���Ʒ���ƣ�");
			scanf("%s", &name);

			printf("�������Ƽ���Ʒ�۸�");
			scanf("%f", &price);

			addRecommendedProduct(id, name, price);//�Ƽ���Ʒ����
			break;
		}
		case 7: //ɾ���Ƽ���Ʒ
		{
			//����Ҫɾ���Ƽ���Ʒ����Ϣ
			int id;

			printf("������Ҫɾ�����Ƽ���Ʒ��ţ�");
			scanf("%d", &id);

			deleteRecommendedProduct(id); //ɾ���Ƽ���Ʒ����
			break;
		}
		case 8: //��ʾ�����Ƽ���Ʒ
		{
			showALLRecommendedProducts(); //��ʾ�����Ƽ���Ʒ����
			break;
		}
		case 9: //�Ƽ���Ʒ����
		{
			reviewRecommendProductApplication(); //�Ƽ���Ʒ���뺯��
			break;
		}
		case 10: //��������
		{
			//����Ҫ���ֵĽ��
			float amount;

			printf("���������ֽ�");
			scanf("%f", &amount);

			applyWithdrawal(amount); //�������溯��
			break;
		}
		case 11: //�˳��̼�ϵͳ
		{
			printf("���˳��̼�ϵͳ��\n");
			return 0;
		}
		default:
		{
			printf("��Ч������\n");
			break;
		}
		}
	}while (choice != 11);
	return;
}