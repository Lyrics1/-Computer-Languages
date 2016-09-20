package one;

import java.util.*;
import java.util.Scanner;
public class Six {
	public static void main(String[] args){
		Scanner input = new Scanner(System.in);
		System.out.println("enter benjin  year lilv :");
		double value;
		int year = input.nextInt(),benjin = input .nextInt();
		float lilv=input.nextFloat();
		value=benjin*(Math.pow((1+lilv/12),year*12));
		System.out.print("value :"+ value);
		
		
		
	}

}
