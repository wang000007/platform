#include "platform.h"
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int main()
{
	int choice=0; //��ʼ��Ϊ��Чֵ

	do
	{
		//��ʾ��¼ѡ��
		printf("*----------------------------------*\n");
		printf("*       ��ӭʹ�õ��̹���ƽ̨       *\n");
		printf("*----------------------------------*\n");
		printf("*          ��ѡ���¼��ʽ          *\n");
		printf("*----------------------------------*\n");
		printf("*          *>1.�û���¼            *\n");
		printf("*          *>2.�̼ҵ�¼            *\n");
		printf("*          *>3.����Ա��¼          *\n");
		printf("*          *>4.�˳�ƽ̨            *\n");
		printf("*----------------------------------*\n");
		printf("                                    \n");
		printf("          ������ѡ���� :");

		scanf("%d", &choice);

		system("cls"); //����

		//�����û�ѡ���ѡ��ִ����Ӧ�ĵ�¼����
		switch (choice)
		{
		case 1: //�û���¼
		{
			loadData_user(); //��������
			int choice_user=0; //��ʼ����Чֵ

			do //�պ��ڲ���whileѭ��
			{
				//��ʾ��¼����
				printf("*----------------------------------*\n");
				printf("*         ��ӭ�����û�ϵͳ         *\n");
				printf("*----------------------------------*\n");
				printf("*            ��ѡ�����            *\n");
				printf("*----------------------------------*\n");
				printf("*            *>1.ע���˺�          *\n");
				printf("*            *>2.��¼              *\n");
				printf("*            *>3.�һ�����          *\n");
				printf("*            *>4.�˳�              *\n");
				printf("*----------------------------------*\n");
				printf("                                    \n");
				printf("          ������ѡ���� :");

				scanf("%d", &choice_user);
				system("cls");

				switch (choice_user)
				{

					case 1: //ע���˺�
					{
						registerAccount_user(); //ע���˺ź���
						break;
					}
					case 2: //��¼
					{
						login_user(); //��¼����
					
						break;
					}
					case 3: //�һ�����
					{
						findPassword_user(); //�һ����뺯��
						break;
					}
					case 4: //�˳�
					{
						saveData_user(); //��������
						printf("���˳��û���¼��\n");
						printf("������ѡ���¼��ʽ��\n");
						break;
					}
					default:
					{
						printf("��Ч���������������롣\n");
						break;
					}
				} 

				
			} while (choice_user != 4);
				
			break;
		}
		case 2: //�̼ҵ�¼
		{
			loadData_seller(); //��������
			//��ʼ����Чֵ
			int choice_seller = 0;

			do
			{
				printf("*----------------------------------*\n");
				printf("*         ��ӭ�����̼�ϵͳ         *\n");
				printf("*----------------------------------*\n");
				printf("*            ��ѡ�����            *\n");
				printf("*----------------------------------*\n");
				printf("*            *>1.ע���˺�          *\n");
				printf("*            *>2.��¼              *\n");
				printf("*            *>3.�һ�����          *\n");
				printf("*            *>4.�˳�              *\n");
				printf("*----------------------------------*\n");
				printf("                                    \n");
				printf("          ������ѡ���� :");

				scanf("%d", &choice_seller);
				system("cls");

				switch (choice_seller)
				{

				case 1: //ע���˺�
				{
					registerAccount_seller(); //ע���˺ź���
					break;
				}
				case 2: //��¼
				{
					login_seller();  //��¼����
					break;
				}
				case 3: //�����һ�
				{
					findPassword_seller(); //�����һغ���
					break;
				}
				case 4: //�˳�
				{
					saveData_seller(); //��������
					printf("���˳��̼ҵ�¼��\n");
					printf("������ѡ���¼��ʽ��\n");
					break;
				}
				default:
				{
					printf("��Ч���������������롣\n");
					break;
				}
				} 

			} while (choice_seller != 4);

			break;
		}
		case 3: //����Ա��¼
		{
			printf("����Ա���������з��������ڴ���\n");
			break;
		}
		case 4: //�˳�ƽ̨
		{
			printf("���˳����̹���ƽ̨ϵͳ��\n");
			printf("ллʹ�ã�\n");
			break;
		}
		default:
			printf("����������������룡\n");
		}
		//ÿ�ε�¼��������
		printf("\n");
	} while (choice != 4);
	return 0;
}
