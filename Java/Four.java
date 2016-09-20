package one;
import java.util.Scanner;
public class Four {
	public static void main(String[] args){
		Scanner input = new Scanner(System.in);
		System.out.print("enter your name  time salary suilv :");
		String name=input.next();
		int time=input.nextInt();
		float salary=input.nextFloat();
		float suilv=input.nextFloat();
		System.out.printf("name: %s   time: %d   salary : %f  suilv : %f",name,time,salary,suilv);
		
	}
}
