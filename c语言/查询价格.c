#include<stdio.h>
void main()
{
	int choice;
	printf ("    ******自动贩卖机查询系统******");
	printf("   1.绿茶\n");
	printf("   2.可乐\n");
	printf("   3.芬达\n");
	printf("   4.矿泉水\n");
	printf("查询价格请输入商品前的序号   按0退出\n");
	scnaf("%d",&choice);
	switch(choice)
	{
		case 1:printf("绿茶：4元/瓶");break;
		case 2:printf("可乐：3.5元/瓶");break;
		case 3:printf("芬达：4元/瓶");break;
		case 4: printf("矿泉水：1元/瓶"); break;
		case 0:return;
	}
	 printf("\n");
}
