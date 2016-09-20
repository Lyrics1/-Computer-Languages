package prictice;

import java.util.Scanner;
public class Point {
	public static void main(String[] args){
		@SuppressWarnings("resource")
		Scanner input =new Scanner(System.in);
		System.out.print("«Î ‰»Îx1,y1,x2,y2:");
		float x1=input.nextFloat();
		float y1=input.nextFloat();
		float x2=input.nextFloat();
		float y2=input.nextFloat();
		double end=0,sta=0;
		sta=Math.pow(x2-x1, 2)+Math.pow(y2-y1, 2);
		end=Math.pow(sta, 0.5);
		System.out.print("this distances of the two point is :"+ end);	
	}
}
