#include "platform.h"
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int main()
{
	int choice=0; //初始化为无效值

	do
	{
		//显示登录选项
		printf("*----------------------------------*\n");
		printf("*       欢迎使用电商管理平台       *\n");
		printf("*----------------------------------*\n");
		printf("*          请选择登录方式          *\n");
		printf("*----------------------------------*\n");
		printf("*          *>1.用户登录            *\n");
		printf("*          *>2.商家登录            *\n");
		printf("*          *>3.管理员登录          *\n");
		printf("*          *>4.退出平台            *\n");
		printf("*----------------------------------*\n");
		printf("                                    \n");
		printf("          请输入选择编号 :");

		scanf("%d", &choice);

		system("cls"); //清屏

		//根据用户选择的选择执行相应的登录函数
		switch (choice)
		{
		case 1: //用户登录
		{
			loadData_user(); //加载数据
			int choice_user=0; //初始化无效值

			do //闭合内部的while循环
			{
				//显示登录操作
				printf("*----------------------------------*\n");
				printf("*         欢迎进入用户系统         *\n");
				printf("*----------------------------------*\n");
				printf("*            请选择操作            *\n");
				printf("*----------------------------------*\n");
				printf("*            *>1.注册账号          *\n");
				printf("*            *>2.登录              *\n");
				printf("*            *>3.找回密码          *\n");
				printf("*            *>4.退出              *\n");
				printf("*----------------------------------*\n");
				printf("                                    \n");
				printf("          请输入选择编号 :");

				scanf("%d", &choice_user);
				system("cls");

				switch (choice_user)
				{

					case 1: //注册账号
					{
						registerAccount_user(); //注册账号函数
						break;
					}
					case 2: //登录
					{
						login_user(); //登录函数
					
						break;
					}
					case 3: //找回密码
					{
						findPassword_user(); //找回密码函数
						break;
					}
					case 4: //退出
					{
						saveData_user(); //保存数据
						printf("已退出用户登录！\n");
						printf("请重新选择登录方式：\n");
						break;
					}
					default:
					{
						printf("无效操作，请重新输入。\n");
						break;
					}
				} 

				
			} while (choice_user != 4);
				
			break;
		}
		case 2: //商家登录
		{
			loadData_seller(); //加载数据
			//初始化无效值
			int choice_seller = 0;

			do
			{
				printf("*----------------------------------*\n");
				printf("*         欢迎进入商家系统         *\n");
				printf("*----------------------------------*\n");
				printf("*            请选择操作            *\n");
				printf("*----------------------------------*\n");
				printf("*            *>1.注册账号          *\n");
				printf("*            *>2.登录              *\n");
				printf("*            *>3.找回密码          *\n");
				printf("*            *>4.退出              *\n");
				printf("*----------------------------------*\n");
				printf("                                    \n");
				printf("          请输入选择编号 :");

				scanf("%d", &choice_seller);
				system("cls");

				switch (choice_seller)
				{

				case 1: //注册账号
				{
					registerAccount_seller(); //注册账号函数
					break;
				}
				case 2: //登录
				{
					login_seller();  //登录函数
					break;
				}
				case 3: //密码找回
				{
					findPassword_seller(); //密码找回函数
					break;
				}
				case 4: //退出
				{
					saveData_seller(); //保存数据
					printf("已退出商家登录！\n");
					printf("请重新选择登录方式：\n");
					break;
				}
				default:
				{
					printf("无效操作，请重新输入。\n");
					break;
				}
				} 

			} while (choice_seller != 4);

			break;
		}
		case 3: //管理员登录
		{
			printf("管理员功能正在研发，敬请期待！\n");
			break;
		}
		case 4: //退出平台
		{
			printf("已退出电商管理平台系统！\n");
			printf("谢谢使用！\n");
			break;
		}
		default:
			printf("输入错误，请重新输入！\n");
		}
		//每次登录结束后换行
		printf("\n");
	} while (choice != 4);
	return 0;
}
