package prictice;
import java.util.*;
// java.util.Date;
//import java.util.Scanner;
public class Weekend {
	public static void main(String[] args){
		@SuppressWarnings("resource")
		Scanner input= new Scanner(System.in);
		System.out.print("Enter year month day: ");
		int year=input.nextInt();
		int month=input.nextInt();
		@SuppressWarnings("unused")
		int day=input.nextInt();
		int h,q,m=0,k,j;
		q=getDaysByYearMonth(year,month);
		if(month==1||month==2){
			--year;
			//year=year-1;
			if(month==1)
				m=13;
			else m=14;
			}
		
		j=Math.abs(year/100);
		k=year%100;	
	   h=(q+(26*(m+1))/10+k+(k/4)+(j/4)+5*j)%7;
	   switch(h)
	   {
	   case 0:System.out.print("saturday");break;
	   case 1:System.out.print("sunday");break;
	   case 2:System.out.print("monday");break;
	   case 3:System.out.print("Tuesday");break;
	   case 4:System.out.print("wednesday");break;
	   case 5:System.out.print("thursday");break;
	   case 6:System.out.print("Friday");break;
	   }
	   
		
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
}
