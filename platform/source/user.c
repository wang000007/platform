#include "platform.h"
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

Product_user products[MAX_PRODUCTS_user]; //�洢������Ʒ
int productNum_user = 0; //��ǰ��Ʒ����

Order_user orders[MAX_ORDERS_user]; //�洢���ж���
int orderNum; //��ǰ��������

int history[MAX_HISTORY]; //�洢����������Ʒ���
int historyNum = 0; //��ǰ�㼣����

Account_user accounts[MAX_ACCOUNT_NUM_user]; //���������˺�
int accountNum_user = 0; //��ǰ�˺�����

////////////////////////////////////�˺ŵ�¼/////////////////////////////////

//ע���˺�
void registerAccount_user()
{
	//�ж��˺������Ƿ��Ѵ�����
	if (accountNum_user >= MAX_ACCOUNT_NUM_user)
	{
		printf("�˺������Ѵ����ޣ�ע��ʧ�ܣ�\n");
		return;
	}

	//�������˺�
	Account_user newAccount;
	printf("�������û�����\n");
	scanf("%s", newAccount.username);

	//�ж��û����Ƿ��ѱ�ע��
	for (int i = 0; i < accountNum_user; i++)
	{
		if (strcmp(accounts[i].username, newAccount.username) == 0)
		{
			printf("���û����ѱ�ע�ᣬ���˳��û�ע����棡\n");
			break;
		}
	}

	if (strcmp(accounts[accountNum_user - 1].username, newAccount.username) != 0)
	{
		printf("���������룺\n");
		scanf("%s", newAccount.password);

		accounts[accountNum_user] = newAccount; //������˺ŵ�������
		accountNum_user++;

		printf("�˺�ע��ɹ���\n");
		return;
	}
	return;
}

//��¼
void login_user()
{
	//�����˺��������鼰��С
	char username[50];
	char password[50];

	printf("�������û�����\n");
	scanf("%s", username);
	printf("���������룺\n");
	scanf("%s", password);
	system("cls");

	//�ж��û����������Ƿ���ȷ
	for (int i = 0; i < accountNum_user; i++)
	{
		if (strcmp(accounts[i].username, username) == 0 && strcmp(accounts[i].password, password) == 0)
		{
			printf("*----------------------------------*\n");
			printf("*             ��¼�ɹ���           *\n");
			printf("*----------------------------------*\n");
			printf("*          �𾴵��û���%s           *\n",username);
			show_user();
			return;
		}

	}
	printf("�û���������������˳��û���¼���棡\n");
}

//�һ�����
void findPassword_user()
{
	//�����û�������
	char username[50];

	printf("�������û�����\n");
	scanf("%s", username);

	//�ж��û����Ƿ���ڣ����������
	for (int i = 0; i < accountNum_user; i++)
	{
		if (strcmp(accounts[i].username, username) == 0)
		{
			printf("�������Ϊ��%s\n", accounts[i].password);
			return;
		}
	}
	printf("���û��������ڣ����˳������һؽ��棡\n");
}

//�������ݵ��ļ�
void saveData_user()
{
	FILE* fp = fopen("data.txt", "w"); //�������ļ�

	fprintf(fp, "%d\n", accountNum_user); //��д���˺�����
	for (int i = 0; i < accountNum_user; i++) //ѭ��д��ÿ���˺ŵ��û���������
	{
		fprintf(fp, "%s %s\n", accounts[i].username, accounts[i].password);
	}
	fclose(fp); //�ر��ļ�
}

//���ļ��м�������
void loadData_user()
{
	FILE* fp = fopen("data.txt", "r"); //�������ļ�

	if (fp == NULL) //�ж��Ƿ�ɹ����ļ�
	{
		printf("�޷���ȡ�����ļ����Ѵ����µ������ļ���\n");
		return;
	}
	fscanf(fp, "%d", &accountNum_user); //�ȶ�ȡ�˺�����
	for (int i = 0; i < accountNum_user; i++) //ѭ����ȡÿ���˺ŵ��û���������
	{
		Account_user account;
		fscanf(fp, "%s %s", account.username, account.password);
		accounts[i] = account; //��ӵ�������
	}
	fclose(fp);
}

//////////////////////////////////////�û�����/////////////////////////////////////

//��ʾ������Ʒ��Ϣ
void showALLProducts_user()
{
	
	printf("��Ʒ�б�\n");
	
	//��ӡ��������Ʒ
	for (int i = 0; i < productNum_user; i++)
	{
		printf("%d,%s,�۸�%2fԪ\n", products[i].id, products[i].name, products[i].price);
	}

}

//������Ʒ
void searchProduct(char* keyword)
{
	printf("���������\n");

	//�ж���Ʒ�Ƿ����
	int flag = 0;
	for (int i = 0; i < productNum_user; i++)
	{
		if (strstr(products[i].name, keyword) != NULL)
		{
			printf("%d,%s,�۸�%.2fԪ\n", products[i].id, products[i].name, products[i].price);
			flag = 1;
		}
	}

	if (!flag)
	{
		printf("û��ƥ�����Ʒ��\n");
	}


	//�������ؼ�����ӵ��㼣��
	if (historyNum >= MAX_HISTORY)
	{
		//����㼣������ɾ��������ӵ�һ����¼
		for (int i = 0; i < historyNum - 1;i++)
		{
			history[i] = history[i + 1];
		}

		historyNum--;
	}
	history[historyNum] = -1; //���Ϊ�����ؼ���
	historyNum++;
}

//�Ƽ���Ʒ
void recommendProducts()
{
	printf("�Ƽ���Ʒ��\n");

	//�������ж�����ͳ��ÿ����Ʒ������Ĵ���
	int count[MAX_PRODUCTS_user] = { 0 };

	for (int i = 0; i < orderNum; i++)
	{
		count[orders[i].productId]++;
	}

	//�ҵ��������������Ʒ
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
		printf("�����Ƽ���Ʒ��\n");
		return;
	}

	//����������������Ʒ����������ӵ��㼣��
	printf("%d,%s,�۸�%.2fԪ\n", products[maxId].id, products[maxId].name, products[maxId].price);

	if (historyNum >= MAX_HISTORY)
	{
		//����㼣������ɾ��������ӵ�һ����¼
		for (int i = 0; i < historyNum - 1; i++)
		{
			history[i] = history[i + 1];
		}

		historyNum--;
	}
	history[historyNum] = maxId;
	historyNum++;
}

//������Ʒ
void buyProduct(int id)
{
	//������Ʒ�Ƿ����
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
		printf("����Ʒ�����ڣ�\n");
		return;
	}

	//��Ӷ���
	Order_user newOrder;
	newOrder.id = orderNum + 1; //������Ŵ�1��ʼ
	newOrder.productId = id;
	newOrder.price = products[index].price;


	orders[orderNum] = newOrder; //����¶�����������
	orderNum++;

	printf("����ɹ���\n");

	//���������Ʒ��ӵ��㼣��
	if (historyNum >= MAX_HISTORY)
	{
		//����㼣������ɾ��������ӵ�һ����¼
		for (int i = 0; i < historyNum - 1; i++)
		{
			history[i] = history[i + 1];
		}

		historyNum--;
	}
}

//�鿴����
void showALLOrders_user()
{
	printf("�����б�\n");

	//��ӡ�����ж���

	for (int i = 0; i < orderNum; i++)
	{
		printf("%d,��Ʒ��ţ�%d,�۸�%.2fԪ\n", orders[i].id, orders[i].productId, orders[i].price);
	}
}

//�鿴�㼣
void showHistory()
{
	printf("����㼣��\n");

	//��ӡ�������㼣
	for (int i = 0; i < historyNum; i++)
	{
		if (history[i] == -1)
		{
			printf("�����ؼ���\n");
		}
		else
		{
			Product_user product = products[history[i]];

			printf("%d,%s,�۸�%.2fԪ\n", product.id, product.name, product.price);
		}
	}
}

//��ʾ�����˵�
void show_user()
{
	//��ʼ����Чֵ
	int choice = 0;

	do
	{
		printf("*----------------------------------*\n");
		printf("*         ��ӭʹ���û�ϵͳ         *\n");
		printf("*----------------------------------*\n");
		printf("*            ��ѡ�����            *\n");
		printf("*----------------------------------*\n");
		printf("*          *>1.��ʾ������Ʒ��Ϣ    *\n");
		printf("*          *>2.������Ʒ            *\n");
		printf("*          *>3.�Ƽ���Ʒ            *\n");
		printf("*          *>4.������Ʒ            *\n");
		printf("*          *>5.�鿴����            *\n");
		printf("*          *>6.�鿴�㼣            *\n");
		printf("*          *>7.�˳�                *\n");
		printf("*----------------------------------*\n");
		printf("          ������ѡ���� :");

		scanf("%d", &choice);

		system("cls");

		switch (choice)
		{
		case 1: //��ʾ������Ʒ��Ϣ
		{
			showALLProducts_user();//��ʾ��Ʒ����
			break;
		}
		case 2: //������Ʒ
		{
			//����Ҫ������Ʒ�Ĺؼ���
			char keyword[50];
			printf("������ؼ��ʣ�\n");
			scanf("%s", keyword);
			searchProduct(keyword); //������Ʒ����
			break;
		}
		case 3: //�鿴�Ƽ���Ʒ
		{
			recommendProducts(); //�Ƽ���Ʒ����
			break;
		}
		case 4: //������Ʒ
		{
			//����Ҫ������Ʒ�ı��
			int id;
			printf("��������Ʒ��ţ�\n");
			scanf("%d", &id);
			buyProduct(id); //������Ʒ����
			break;
		}
		case 5: //��ʾ����
		{
			showALLOrders_user(); //չʾ���ж���
			break;
		}
		case 6: //�鿴�㼣
		{
			showHistory(); //�鿴�㼣����
			break;
		}
		case 7: //�˳�
		{
			saveGoods(); //��������
			printf("���˳��û�ϵͳ��\n");
			return 0;
		}
		default:
		{
			printf("��Ч���������������롣\n");
			break;
		}
		}
	} while (choice != 7);
	return ;
}

