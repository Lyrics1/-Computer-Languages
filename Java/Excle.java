package prictice;
import java.util.*;
public class Excle {
	public static void main(String[] args){
		@SuppressWarnings("unused")
		double Mile,kilometer;
		@SuppressWarnings({ "unused", "resource" })
		Scanner input=new Scanner(System.in);
		//Mile=input.nextDouble();
	//	kilometer=input.nextDouble();
		System.out.println("Mile       kilometers       kilometers          Mile");
		int j=20;
		 
		for(int i=1;i<=10;i++){
			System.out.print(i);
			System.out.print("           "+i*1.609);
			System.out.printf("           %.3f",j*1.609);
			System.out.println("           "+j);
			j+=5;
			
		}
	}
}
