package prictice;
import java.util.*;
public class Pay {
	public static void main(String[] args){
		float Amount,years;
		@SuppressWarnings("resource")
		Scanner input=new Scanner(System.in);
		System.out.print("Enter amount  year:");
		Amount=input.nextFloat();
		years=input.nextFloat();
		System.out.println("Interest Rate         Monthly Payment       Total Payment");
		float k=5;
		
		for(int i=0;i<=8*3;i++)
		{
			System.out.printf("%.3f%c",k,'%');
			double Monthly_pay,Total_pay;
			Monthly_pay=(Amount*(k/1200.0))/(1-(1/Math.pow(1+k/1200.0, years*12)));
			Total_pay=Monthly_pay*years*12;
			System.out.printf("               %.2f",Monthly_pay);
			System.out.printf("                %.2f\n",Total_pay);
			k=(float) ((1/8.0)+k);
			
		}
	}
}
