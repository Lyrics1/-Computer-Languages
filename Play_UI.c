/*
* File name:  Play_UI.c
* File ID:	  TTMS_SSF_Play_UI_Sour
* Author:     Huang Ru
* Version:    V1.0
* Date: 	  2015-04-25
*/


#include "Play_UI.h"
#include "Schedule_UI.h"

#include "../Common/list.h"
#include "../Service/Play.h"
#include "../Service/EntityKey.h"

#include <stdio.h>
#include <stdlib.h>


	/*
	 * Function:    Play_UI_ShowList
	 * Function ID:	TTMS_SCU_Play_UI_Show
	 * Description: 以列表模式显示剧目信息
	 * Input:       list剧目信息链表的头指针，paging分页设置参数
	 * Output:      所有剧目的信息
	 * Return:      返回查找到的记录数目
	 */
void Play_UI_ShowList(play_list_t list, Pagination_t paging) {
	
}

/*
 * Function:    Play_UI_MgtEntry
 * Function ID:	TTMS_SCU_Play_UI_MgtEnt
 * Description: 剧目信息管理界面
 * Input:       flag为0，进入管理页面，flag为1进入查询界面
 * Output:      剧目管理界面
 * Return:      无
 */
void Play_UI_MgtEntry(int flag){
		int i,id;
		char choice;
		play_list_t head;
		play_node_t *pos;
		Pagination_t paging;
		play_list_t p;
		
		List_Init(head,play_node_t);
		
		paging.offset=0;
		paging_Locate_FirstPage(head,paging);
		
		do{
			system("cls");
				printf("\n========================剧目列表========================\n\n");
		printf("%5s%10%10s%10s%12s%10s%12s%12s%10s","ID","剧目名称","剧目类型","剧目出品地区","剧目等级","放映时长","开始放映时间","结束放映时间","票价");
		printf("----------------------------------------------------------------------------------------------------------------------------------------\n\n");
		//显示数据
        for(i=0;pos=(play_node_t *)(paging.curPos),
			pos!=head && i<paging.pageSize;i++){
			printf("%d%s%s%s%s%d%s%s%d",p->data.id,p->data.name,p->data.type,p->data.area,p->data.rating,p->data.duration,p->data.start_date,p->data.end_date,p->data.price);
	}
    printf("-------------总剧目列表 :%3d------------page(页码） %3d/%3d\n---\n",paging.totalRecords, Pageing_CurPage(paging),
                Pageing_TotalPages(paging));
		printf("********************************************************************************\n");
	printf("[P]revPage|[N]extPage | [A]dd|[D]elete|[U]pdate | [S]eat | [R]eturn");//U更新 
        printf(
                "\n==================================================================\n");
        printf("Your Choice:");
        fflush(stdin);
        scanf("%c", &choice);
        fflush(stdin);
switch (choice) {
        case 'a':
        case 'A':
            if (Play_UI_Add()) //新添加成功，跳到最后一页显示
            {
                paging.totalRecords = Play_Srv_FetchAll(head);
                Paging_Locate_LastPage(head, paging, play_node_t);
            }
			break;
		case 'd':
        case 'D':
            printf("Input the ID:");
            scanf("%d", &id);
            if (Play_UI_Delete(id)) { //从新载入数据
                paging.totalRecords = Play_Srv_FetchAll(head);
                List_Paging(head, paging, play_node_t);
            }
            break;
        case 'u':
        case 'U':
            printf("Input the ID:");
            scanf("%d", &id);
            if (Play_UI_Modify(id)) { //从新载入数据
                paging.totalRecords = Play_Srv_FetchAll(head);
                List_Paging(head, paging, play_node_t);
            }
            break;
        case 's':
        case 'S':
            printf("Input the ID:");
            scanf("%d", &id);
            Seat_UI_MgtEntry(id);
            paging.totalRecords = Play_Srv_FetchAll(head);
            List_Paging(head, paging, play_node_t);
            break;
        case 'p':
        case 'P':
            if (1 < Pageing_CurPage(paging)) {
                Paging_Locate_OffsetPage(head, paging, -1, play_node_t);
            }
            break;
		 case 'n':
         case 'N':
            if (Pageing_TotalPages(paging) > Pageing_CurPage(paging)) {
                Paging_Locate_OffsetPage(head, paging, 1, play_node_t);
            }
            break;
        }
    } while (choice != 'r' && choice != 'R');
    //释放链表空间
 //   List_Destroy(head, studio_node_t);

		if(flag==0)
	{
		printf("\n\n=============================剧目信息管理页面=============================\n\n");
		printf("[s]查询剧目是否存在\n\n");
		printf("[Q]输入剧目信息\n\n");
		printf("[A]新增剧目信息\n\n");
		printf("[D]删除剧目信息\n\n");
		printf("[U]修改剧目信息\n\n");
		printf("[P]当前页码\n\n");
		printf("[n]当前页吗最大页码\n\n");
		printf("[R]退出管理系统\n\n");
		printf("please input your choice ； ");
		scanf("%c",&choice);
		do{
					switch(choice)
				{	case 's':
					case 'S':printf("please input id:");scanf("%d",&id);Play_UI_Query(id);break;
					case 'q':
					case 'Q':printf("please input id:");scanf("%d",&id);Play_UI_Query(id);break;
					case 'a':
					case 'A':printf("please input id:");scanf("%d",&id);Play_UI_Add();break;
					case 'd':
                    case 'D':printf("please input id:");scanf("%d",&id);Play_UI_Delete(id);break;
					case 'u':
					case 'U':printf("please input id:");scanf("%d",&id); Play_UI_Modify(id);break;
					case 'p':
					case 'P':
					  if (1 < Pageing_CurPage(paging)) {
                	Paging_Locate_OffsetPage(head, paging, -1, play_node_t);
					  }break;
					case 'n':
					case 'N':
					 if (Pageing_TotalPages(paging) > Pageing_CurPage(paging)) {
                Paging_Locate_OffsetPage(head, paging, 1, play_node_t);
           		 }
        	    break;
				}
			}while(choice!='r'||choice!='R');
	}
			if(flag==1)
			{
				printf("\n=============================剧目查询界面=============================\n\n");
				printf("please input id:");scanf("%d",&id);
				/* printf("[s]查询剧目是否存在\n\n");        printf("[Q]输入剧目信息\n\n");
					fflush(stdin);
					scanf("%c",&choice);
					fflush(stdin);*/
			Play_UI_Query(id); 
			}

		List_Destroy(head,play_node_t);//销毁链表

}



/*
 * Function:    Play_UI_Add
 * Function ID:	TTMS_SCU_Play_UI_Add
 * Description: 添加一条剧目信息
 * Input:       无
 * Output:      输入信息时的各种提示
 * Return:      添加的记录数
 */
int Play_UI_Add(void)
{
		play_t rec;
		int newRecCount =0;
		char choice;
		int flag;
		
		do{
			system("cls");
			printf("\n========================================================================\n");
			printf("××××××××××添加新的剧目信息××××××××××\n\n");
			printf("----------------------------------------------------------------------------\n\n");
			printf("信息ID号:");
			scanf("%d",&(rec.id));
			printf("剧目名称：");
			scanf("%c",rec.name);
			printf("剧目类型  1:电影 2：歌剧 3：音乐会\n");
			scanf("%d",&(rec.rating));
			printf("剧目来源地：");
			scanf("%s",rec.area);
			printf("剧目级别 1：儿童可以观看 2：青少年可观看 3：成人可观看\n");
			printf("演出时长：");
			scanf("%d",&(rec.duration));
			printf("上映日期：");
			scanf("");
			printf("结束日期:");
			scanf("");
			printf("票的价格:");
			scanf("%d",&(rec.price));
			printf("===================================================================\n\n");
			//获取主键ID号
			rec.id=EntKey_Srv_CompBewKey("Play");
			if(Play_Srv_Add(&rec))
			{
			newRecCount++;
			printf("剧目添加成功\n");
			flag=1;
			}
			else 
			{printf("剧目添加失败\n");flag=2;}
			printf("[A]继续添加  [R]返回菜单\n");
			fflush(stdin);
			scanf("%c",&choice);
		//	return flag;
		if(choice!='a'||choice!='A')
			return newRecCount;
		}while(choice=='a'||choice=='A');
	return 0;
}

/*
 * Function:    Play_UI_Modify
 * Function ID:	TTMS_SCU_Play_UI_Mod
 * Description: 更新剧目信息
 * Input:       待更新的剧目ID号
 * Output:      输入信息时的各种提示
 * Return:      更新的剧目信息数，0表示未找到，1表示找到并更新
 */
int Play_UI_Modify(int id){
	int flag=2,rtn=0;
	play_t rec;
	flag=Play_UI_Query(id);
	if(flag==1)
	{
		printf("%5s%10s%10s%10s%12s%10s%12s%12s%10s","剧目名称","剧目类型","剧目出品地区","剧目等级","放映时长","开始放映时间","结束放映时间","票价");
		printf("%-5d%6s%6s%6s%6s%5d%6s%6s%5d",rec.id,rec.name,rec.type,rec.area,rec.rating,rec.duration,rec.start_date,rec.end_date,rec.price);
   		    printf("信息ID号:");
            scanf("%d",&(rec.id));
            printf("剧目名称：");
            scanf("%c",rec.name);
            printf("剧目类型  1:电影 2：歌剧 3：音乐会\n");
            scanf("%d",&(rec.rating));
            printf("剧目来源地：");
            scanf("%s",rec.area);
            printf("剧目级别 1：儿童可以观看 2：青少年可观看 3：成人可观看\
n");
            printf("演出时长：");
            scanf("%d",&(rec.duration));
            printf("上映日期：");
            /*scanf("");
            printf("结束日期:");
            scanf("");
            printf("票的价格:");
            scanf("%d",&(rec.price));*/
 			rtn=Play_Srv_Modify(&rec);
			if(rtn==1)
			printf("Modify  成功\n");
			else printf("Modify  失败\n");
			return rtn;
		}
		else return 0;
}

/*
 * Function:    Play_UI_Delete
 * Function ID:	TTMS_SCU_Play_UI_Del
 * Description: 按照ID号删除剧目信息
 * Input:       待删除的剧目ID号
 * Output:      提示删除是否成功
 * Return:      0表示删除失败，1表示删除成功
 */
int Play_UI_Delete(int id){
	int rtn=0;
	if(Play_UI_Query(id))
	{
			printf("存在此剧目，将进行删除\n");
		if(Play_Srv_DeleteByID(id))
		{
			printf("删除成功\n");
			rtn=1;}
		else printf("删除失败\n");
		return rtn;
	}
	else printf("此剧目不存在\n");			
	return 0;
}

/*
 * Function:    Play_UI_Query
 * Function ID:	TTMS_SCU_Play_UI_Qry
 * Description: 按照ID号查询剧目信息
 * Input:       待查找的剧目ID号
 * Output:      查找到的剧目信息
 * Return:      0表示未找到，1表示找到了
 */
int Play_UI_Query(int id){
	int rtn=0;
	play_t p;
	if(Play_Srv_FetchByID(id,&p))
	{
		printf("此剧目存在\n");
		rtn=1;
		return rtn;	
	}
	else printf("此剧目不存在\n");
	return 0;
}
//修改，调试过的
