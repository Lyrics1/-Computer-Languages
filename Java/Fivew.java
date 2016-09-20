package prictice;
import javax.swing.JOptionPane;
public class Fivew {
	
	
		public static void main(String[] args){
			String data=JOptionPane.showInputDialog("Enter an value:");
			System.out.printf("%s",data);
			
			int option=JOptionPane.showConfirmDialog(null, "continue?");
			
		}
	}

