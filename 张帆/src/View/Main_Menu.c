#include <stdio.h>

#include "Main_Menu.h"
#include "Schedule_UI.h"
#include "Studio_UI.h"
#include "Play_UI.h"
#include "Queries_Menu.h"
#include "Account_UI.h"
#include "Sale_UI.h"
#include "SalesAnalysis_UI.h"

void Main_Menu(void) {
	char choice;
	int i;
	do {
		printf("\n  ==================================================================\n\n");
		printf("**************** Theater Ticket Management System ****************\n\n");
		printf("**************** 剧院票务管理系统 ****************\n\n");
		//printf("[S]tudio Management.\n");
		printf("[S]演出厅管理.\n\n");
	//	printf("[P]lay Management.\n");
		printf("[P]剧目管理.\n\n");
	//	printf("[T]icket Sale.\n");
		printf("[T]售票管理.\n\n");
	//	printf("[R]eturn Ticket.\n");
		printf("[R]退票管理.\n\n");
	//	printf("[Q]ueries\n");
		printf("[Q]查询菜单.\n\n");
	//	printf("Ra[n]king and Statistics.\n");
		printf("Ra[n]分页显示.\n\n");
	//	printf("[A]ccount Management.\n");
		printf("[A]系统用户管理.\n\n");
	//	printf("[E]xist.\n");
		printf("[E]退出系统.\n\n");
		printf("\n==================================================================\n");
		printf("Please input your choice:");
		fflush(stdin);
		choice = getchar();
		switch (choice) {
		case 'S':
		case 's':
			Studio_UI_MgtEntry();
			break;
		case 'P':
		case 'p':
			do{printf("\n0:剧目管理界面\t 1 :剧目查询界面\n ");
			scanf("%d",&i);
			if(i!=0 || i!=1)
				printf("输入有误！请重新输入!!\n");
			}while(i!=0 || i!=1);
			fflush(stdin);
			Play_UI_MgtEntry(i);
			break;
		case 'Q':
		case 'q':
			Queries_Menu();
			break;
		case 'T':
		case 't':
			Sale_UI_MgtEntry();
			break;
		case 'R':
		case 'r':
			Sale_UI_ReturnTicket();
			break;
		case 'N':
		case 'n':
			SalesAanalysis_UI_MgtEntry();
			break;
		case 'A':
		case 'a':
			Account_UI_MgtEntry();
			break;
		}
	} while ('E' != choice && 'e' != choice);
}

