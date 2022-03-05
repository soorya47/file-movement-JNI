import java.util.Scanner;

public class FileMovement {  
	   static {
	      System.loadLibrary("fileMovement"); 
	   }
	 
	   // Declare an instance native method sayHello() which receives no parameter and returns void
	   private native boolean fileMove(String s1,String s2);
	 
	   // Test Driver
	   public static void main(String[] args) {
		
		Scanner sc=new Scanner(System.in);
		System.out.println("enter Path1");
		String s1=sc.nextLine();
		System.out.println("enter Path2");
		String s2=sc.nextLine();
		FileMovement obj= new FileMovement();
		boolean process= obj.fileMove(s1,s2);
		if(process)
			System.out.println("file movement success");
		else
			System.out.println("file movement success");
	   }
	}