package prictice;
import java.util.*;
@SuppressWarnings("unused")
public class List {
	public static void main(String[] args){
			@SuppressWarnings("resource")
			Scanner input=new Scanner(System.in);
			System.out.print("Enter year:");
			int year=input.nextInt();
			
			for(int i=0;i<4;i++){
				int maxDay=getDaysByYearMonth(year,i);
				Calendar c = Calendar.getInstance();
				c.set(year,i,1);//2011年1月1号
				int day;
				day=c.get(Calendar.DAY_OF_WEEK);//获取星期，1是周日，2是周1
				System.out.println("++++++"+day+maxDay);
				Show_List(day,maxDay,i,year);
			}
			
	}
	
	public static void Show_List(int day,int maxDay,int month,int year){
		switch(month)
		{
		   case 0:System.out.print("\t\t\tJanuary");break;
		   case 1:System.out.print("\t\t\tFeburary");break;
		   case 2:System.out.print("\t\t\tMarch");break;
		   case 3:System.out.print("\t\t\tAprill");break;
		}
		System.out.printf("%d\n------------------------------------------------------------------------\n",year);
		System.out.println("Sun\t\tMon\t\ttTue\t\tWed\t\tSta\t\tThu\t\tFri");
		if(day>1)
			for(int i=1;i<day*14;i++){
				System.out.print(" ");
			}
		for(int i=1;i<=maxDay;){
			int j;
			for(j=day;j<=7&&i<=maxDay;j++){
				System.out.print(i+"\t\t  ");
				i++;
			}
			
			System.out.printf("\n");
			day=1;
		}
		
	}
	 public static int getDaysByYearMonth(int year,int month){
		 month++;
		 switch(month)
		 {
		 case 1:
		 case 3:
		 case 5:
		 case 7:
		 case 8:
		 case 10:
		 case 12:
			 return 31;
		 case 2:
			 if(isleapYear(year))return 29;
			 return 28;
		 case 4:
		 case 6:
		 case 9:
		 case 11:
			  return 30;
		default:return 0;
			 
		 }
			/*Calendar a=Calendar.getInstance();
			a.set(Calendar.YEAR, year);
			a.set(Calendar.MONTH, month-1);
			a.set(Calendar.DATE, 1);
			a.set(Calendar.DATE, -1);
			int maxDate=a.get(Calendar.DATE);*/
			
			//return maxDate;
		
	}
	 public static boolean isleapYear(int year){
		 if((year%100==0&&year%400==0)||(year%4==0))
			 return true;
		 else return false;
	 }
}
