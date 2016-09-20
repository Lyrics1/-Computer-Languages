package prictice;
import java.util.Scanner;
public class Sixw {
	
	
		public static void main(String[] args){
			@SuppressWarnings("resource")
			Scanner input = new Scanner(System.in);
			System.out.println("enter  year benjin  lilv :");
			double value;
			int year = input.nextInt(),benjin = input .nextInt();
			float lilv=input.nextFloat();
			value=benjin*(Math.pow((1+lilv/12),year*12));
			System.out.print("value :"+ value);
			
			
			
		}

	}

