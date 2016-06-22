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
#include "../Service/play.h"
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
   play_list_t     list;
    play_node_t     *p;
    Pagination_t    paging;
    char            choice;
    int             i,id;
    List_Init(list,play_node_t);
    
    List_Init(list, play_node_t);
	paging.offset = 0;
	paging.pageSize = PLAY_PAGE_SIZE;

    
    paging.totalRecords = Play_Srv_FetchAll(list);
    Paging_Locate_FirstPage(list,paging);         
    system("cls");
    do {
        printf("--------------------------------- 剧目列表 ---------------------------------------\n");
        printf("ID\t剧目名称\t剧目类型\t剧目出品地区\t剧目等级\t放映时长\t开始放映时间\t结束放映时间\t票价\n\n");
        printf("---------------------------------------------------------------------------------------\n");
       	for (i = 0, p = (play_node_t *) (paging.curPos);
				p != list && i < paging.pageSize; i++) {
            printf("%d\t%s\t%s\t%s\t%s\t%d\t\t%d.%d.%d\t%d.%d.%d\t%d\n", p->data.id, p->data.name,
                   (p->data.type == 1)?"电影":(p->data.type == 2?"歌剧":"音乐会"),
                   p->data.area,
                   (p->data.rating == 1)?"儿童":(p->data.rating == 2?"青少年":"成年人"),
                   p->data.duration,
                   p->data.start_date.year,p->data.start_date.month,p->data.start_date.day,
                   p->data.end_date.year,p->data.end_date.month,p->data.end_date.day,
                   p->data.price);
            p=p->next;
        }
        printf("--总页码:%2d ------------------------------ 页数 %2d/%2d --\n",
               paging.totalRecords, Pageing_CurPage(paging),
               Pageing_TotalPages(paging));
        if(flag == 1)
        {				printf("------------------------剧目信息查询页面-----------------------\n\n");
						printf("[s]查询演出计划\n\n");
						printf("[Q]查询剧目信息\n\n");
						printf("[R]退出管理系统\n\n");
            do{
                printf("please input your choice :");
		fflush(stdin);
                scanf("%c", &choice);
                switch(choice)
                {
                		   case 's':
                           case 'S':
                               printf("请输入 ID:");
                               scanf("%d",&id);
                               if (Play_UI_Query(id)) {
                                   Schedule_UI_MgtEntry(id);
                               }
                               else
                                   printf("此剧目不存在\n");
                               break;
                           case 'q':
                           case 'Q':
                                   printf("P请输入 ID:");
                                   scanf("%d",&id);
                                   if (Play_UI_Query(id)) {
                                     paging.totalRecords = Play_Srv_FetchAll(list);
                                     Paging_Locate_LastPage(list, paging, play_node_t);
                                     }
                                    break;

                }
            }while(choice != 'a' && choice != 'A' && choice != 'd' && choice != 'D' &&
                   choice != 'u' && choice != 'U' && choice != 'r' && choice != 'R'&& choice != 'S' && choice != 's');
        }
        else if(flag == 0)
        {


            printf("---------------------------------剧目信息管理页面--------------------------------\n");
            					printf("[s]演出计划\n\n");
                    			//printf("[Q]查询剧目信息\n\n");
                    			printf("[A]新增剧目信息\n\n");
                    			printf("[D]删除剧目信息\n\n");
                    			printf("[U]修改剧目信息\n\n");
                    			printf("[P]当前页码\n\n");
                    			printf("[n]当前页吗最大页码\n\n");
                    			printf("[R]退出管理系统\n\n");
            do{
                printf("please input your choice : ");
		fflush(stdin);
                scanf("%c", &choice);
            }while(choice != 'q' && choice != 'Q' && choice != 'S' && choice != 's' &&
                   choice != 'r' && choice != 'R');
        }
        
        switch (choice) {
            case 's':
            case 'S':
                printf("请输入 ID:");
                scanf("%d",&id);
                if (Play_UI_Query(id)) {
                    Schedule_UI_MgtEntry(id);
                }
                else
                    printf("此剧目不存在\n");
                break;
            case 'q':
            case 'Q':
                printf("P请输入 ID:");
                scanf("%d",&id);
                 if (Play_UI_Query(id)) {
                    paging.totalRecords = Play_Srv_FetchAll(list);
                    Paging_Locate_LastPage(list, paging, play_node_t);    
                }
                break;
            case 'a':
            case 'A':
                if (Play_UI_Add()) {
                    paging.totalRecords = Play_Srv_FetchAll(list);
                    Paging_Locate_LastPage(list, paging, play_node_t);    
                }
                break;
            case 'd':
            case 'D':
                printf("请输入 ID:");
                scanf("%d",&id);
                if (Play_UI_Delete(id)) {
                    paging.totalRecords = Play_Srv_FetchAll(list);
                    List_Paging(list, paging, play_node_t);
                }
                break;
            case 'u':
            case 'U':
                printf("请输入 ID:");
                scanf("%d",&id);
                if (Play_UI_Modify(id)) {
                    paging.totalRecords = Play_Srv_FetchAll(list);
                    List_Paging(list, paging, play_node_t);
                }
                break;
            case 'p':
            case 'P':
                if (1 < Pageing_CurPage(paging)) {
                    Paging_Locate_OffsetPage(list, paging, -1, play_node_t); 
                }
                break;
            case 'n':
            case 'N':
                if (Pageing_TotalPages(paging) > Pageing_CurPage(paging)) {
                    Paging_Locate_OffsetPage(list, paging, 1, play_node_t);  
                }
                break;
        }
        
    } while (choice != 'r' && choice != 'R');
    
    List_Destroy(list,play_node_t);
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
 int     newCount = 0;
    int     key;
    char    choice;
    int a;
    play_t  pnew;
    system("cls");
    printf("--------------------------【添加】 剧目 --------------------------\n");
    do{
        printf("请输入剧目名称:\n");
        scanf("%s",pnew.name);
        fflush(stdin);
        printf("请输入类型选择: 1.电影  2.歌剧  3.音乐会\n");
        scanf("%d",&a);
               			fflush(stdin);
               			switch(a)
               			{
               				case 1:pnew.type=(play_type_t)a;break;
               				case 2:pnew.type=(play_type_t)a;break;
               				case 3:pnew.type=(play_type_t)a;break;
               				default:printf("error\n");break;
               			}
        printf("请输入地区:\n");
        scanf("%s",pnew.area);
        printf("请输入适合范围: 1.儿童  2.青少年  3.成年人\n");
        scanf("%d",&a);
                			switch(a)
                			{
                				case 1:pnew.rating=( play_rating_t)a;break;
                				case 2:pnew.rating=( play_rating_t)a;break;
                				case 3:pnew.rating=( play_rating_t)a;break;
                				default:printf("error\n");
                			}

        printf("请输入时长 (minute):");
        scanf("%d",&pnew.duration);
        printf("请输入开始日期(like 2015 06 29):\n");
        scanf("%d %d %d",&pnew.start_date.year, &pnew.start_date.month, &pnew.start_date.day);
        printf("请输入结束日期 (like 2015 06 29):\n");
        scanf("%d %d %d",&pnew.end_date.year, &pnew.end_date.month, &pnew.end_date.day);
        printf("请输入价格:");
        scanf("%d",&pnew.price);
        key = EntKey_Srv_CompNewKey("play"); 
        pnew.id = key;
        if (Play_Srv_Add(&pnew)) {
            printf("添加成功!!\n");
            newCount++;
            printf("是否继续? (y/n):");
            getchar();
		fflush(stdin);
            scanf("%c",&choice);
        }
        else
        {
            printf("添加失败!\n");
            //sleep(1);
            return newCount;
        }
    }while (choice == 'y' || choice == 'Y');
    return newCount;
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
	
   int     rtn = 0;
    play_t  temp;
    int a;
    printf("========================= 剧目修改 =========================\n");
    if (Play_Srv_FetchByID(id,&temp)) {
        printf("--------------------------- 旧资料 ----------------------------\n");
        printf("==================================== 剧目列表 ========================================\n");
               printf("ID\t名称\t类型\t地区\t等级\t时长\t开始日期\t结束日期\t价格\n");
               printf("---------------------------------------------------------------------------------------\n");
                   printf("%d\t%s\t%s\t%s\t%s\t%d\t\t%d.%d.%d\t%d.%d.%d\t%d\n", temp.id, temp.name,
                          (temp.type == 1)?"电影":(temp.type == 2?"歌剧":"音乐会"),
                        		  temp.area,
                          (temp.rating == 1)?"儿童":(temp.rating == 2?"青少年":"成年人"),
                        		  temp.duration,
								  temp.start_date.year,temp.start_date.month,temp.start_date.day,
								  temp.end_date.year,temp.end_date.month,temp.end_date.day,
								  temp.price);

        printf("--------------------------- New Data ----------------------------\n");
        printf("请输入新的剧目名称:\n");

        scanf("%s",temp.name);
        	fflush(stdin);
        printf("请输入新的类型 ：     1.电影  2.歌剧  3.音乐会\n");
          scanf("%d",&a);
        			fflush(stdin);
        			switch(a)
        			{
        				case 1:temp.type=(play_type_t)a;break;
        				case 2:temp.type=(play_type_t)a;break;
        				case 3:temp.type=(play_type_t)a;break;
        				default:printf("error\n");break;
        			}
        printf("请输入新的地区:\n");
        scanf("%s",temp.area);
        printf("(1.儿童  2.青少年  3.成年人)\n");
        printf("请输入新的适合范围:\n");
        scanf("%d",&a);
        			switch(a)
        			{
        				case 1:temp.rating=( play_rating_t)a;break;
        				case 2:temp.rating=( play_rating_t)a;break;
        				case 3:temp.rating=( play_rating_t)a;break;
        				default:printf("error\n");
        			}
        printf("请输入新的时长 (minute):");
        scanf("%d",&temp.duration);
        printf("请输入开始日期 ( 例如：2016 06 18):\n");
        scanf("%d %d %d",&temp.start_date.year, &temp.start_date.month, &temp.start_date.day);
        printf("请输入结束日期 ( 例如：2016 06 25):\n");
        scanf("%d %d %d",&temp.end_date.year, &temp.end_date.month, &temp.end_date.day);
        printf("请输入新的票价:");
        scanf("%d",&temp.price);
        if (Play_Srv_Modify(&temp)) {
            rtn = 1;
            printf("修改成功  [Successful] \n");
        }
        else
            printf("修改失败   [File]\n");
    }
    else
    {
        printf("该剧目不存在!\n");
        fflush(stdin);
        return 0;
    }
    return rtn;


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
int rtn = 0;
    printf(" --------------------删除剧目------------------------\n");
    if (Play_Srv_DeleteByID(id)) {
        rtn = 1;
        printf("删除成功!\n");
    }
    else
        printf("删除失败!\n");
    return rtn;

	
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
	
   
    int     rtn = 0;
    play_t  buf;
    if (Play_Srv_FetchByID(id,&buf)) {
        rtn = 1;
        printf("Found this play!!\n");
        printf("=========================== 剧目信息===========================\n");
        printf("ID\t名称\t类型\t地区\t适合范围\t时长\t开始日期\t结束日期\t票价\n");
        printf("-----------------------------------------------------------------------\n");
        printf("%d\t%s\t%s\t%s\t%s\t%d\t%d.%d.%d\t%d.%d.%d\t%d\n", buf.id, buf.name,
               (buf.type == 1)?"电影":(buf.type == 2?"歌剧":"音乐会"),
               buf.area,
               (buf.rating == 1)?"儿童":(buf.rating == 2?"青少年":"成年人"),
               buf.duration,
               buf.start_date.year, buf.start_date.month, buf.start_date.day,
               buf.end_date.year, buf.end_date.month, buf.end_date.day,
               buf.price);
        	   fflush(stdin);
    }
    else
        printf("此剧目不存在.\n");

    return rtn;


}
