package prictice;
import java.util.*;
public class Calendars {
	   public static void main(String[] args){
		   @SuppressWarnings("resource")
		Scanner input=new Scanner(System.in);
		   System.out.print("Enter year  day:");
		   int year=input.nextInt();
		   @SuppressWarnings("unused")
		int day=input.nextInt();
		   int month=0;
		   int h,q,m=0,k,j;
			q=getDaysByYearMonth(year,month);
			System.out.print("+++"+q);
			if(month==1||month==2){
				--year;
				if(month==1)
					m=13;
				else m=14;
				}
			
			j=Math.abs(year/100);
			k=year%100;	
		   h=(q+(26*(m+1))/10+k+(k/4)+(j/4)+5*j)%7;
		   Calendar_List(year,q,h,month);
		   
	   }
	   public static int getDaysByYearMonth(int year,int month){
			Calendar a=Calendar.getInstance();
			a.set(Calendar.YEAR, year);
			a.set(Calendar.MONTH, month-1);
			a.set(Calendar.DATE, 1);
			a.set(Calendar.DATE, -1);
			int maxDate=a.get(Calendar.DATE);
			
			return maxDate;
		
	}
	   public static void Calendar_List(int year,int maxDay,int sta,int month){
		   switch(month)
		   {
		   case 0:System.out.print("     January");break;
		   case 1:System.out.print("     Feburary");break;
		   case 2:System.out.print("     March");break;
		   case 3:System.out.print("     Aprill");break;
		  // case 4:System.out.print("     thursday");break;
		 //  case 5:System.out.print("     Friday");break;
		 //  case 6:System.out.print("     saturday");break;
		   }
		   System.out.println(year);
		   System.out.println("------------------------------------");
		  
		  System.out.println(" Sun        Mon      Tue       Wed        Thu        Fri       Sta");
		  int k=1;
		  if(sta==2)
			   sta=7;
		   for(int j=0;j<=sta*8;j++)
		   {
			   System.out.print(" ");
			   if(k<sta) k++;
		   }
		   //System.out.println("+++++"+sta);
		   for(int i=1;i<=maxDay;i++)
		   {	
			   for(int j=sta;j<=7;j++){
				   System.out.print(i+"         ");   
				   i++;
			   }
			   System.out.printf("\n");
			   sta=1;   
		   }
	   }
}
