package prictice;
import java.util.Scanner;
public class triang {
	public static void main(String[] args){
		@SuppressWarnings("resource")
		Scanner input=new Scanner(System.in);
		System.out.print("Enter three points for a trigangle:");
		float x1=input.nextFloat();
		float y1=input.nextFloat();
		float x2=input.nextFloat();
		float y2=input.nextFloat();
		float x3=input.nextFloat();
		float y3=input.nextFloat();
		double sta1=0,sta3=0,sta2,end1=0,end2=0,end3=0;
		sta1=Math.pow(x2-x1, 2)+Math.pow(y2-y1, 2);
		end1=Math.pow(sta1, 0.5);
		sta2=Math.pow(x3-x1, 2)+Math.pow(y3-y1, 2);
		end2=Math.pow(sta2, 0.5);
		sta3=Math.pow(x2-x3, 2)+Math.pow(y2-y3, 2);
		end3=Math.pow(sta3, 0.5);
		double s,area;
		s=(end1+end2+end3)/2.0;
		area=Math.pow(s*(s-end1)*(s-end2)*(s-end3),0.5);
		System.out.printf("The area of triangle is %.2f",area);
		
	}
}
