package soni.com;

public class string {
	
	public static int lengthofString(String str) {	// ���ڿ��� ���� ����ϱ�.
		if(str.equals("")) {
			return 0;
		}else {
			return 1 + lengthofString(str.substring(1));
		}
	}
	public static void printString(String str) { 	// ���ڿ� ����ϱ�.
		if(str.equals("")) {
			return;
		}else {
			System.out.print(str.charAt(0));
			printString(str.substring(1));
		}
	}
	public static void reverseString(String str) {	// ���ڿ� ����� ����ϱ�.
		if(str.equals("")) {
			return;
		}else {
			reverseString(str.substring(1));
			System.out.print(str.charAt(0));
		}
	}
	public static int binarySearch(String [] items, int from, int to, String str) {	// binary search�� ���ڿ� �迭�߿� ���ڿ� ã��
		if(from <= to)
		{
			int middle = (from+to)/2;
			if(items[middle].compareTo(str) == 0) {
				return middle;
			}else if(items[middle].compareTo(str) < 0) {
				binarySearch(items, middle + 1 , to, str);
			}else {
				binarySearch(items, from, middle-1, str);
			}
		}
		return -1;
	}
	public static void main(String[] args) {
		// TODO Auto-generated method stub
		String str = "Hello";
		int v = lengthofString(str);
		System.out.println(str +"�� ���ڿ� ���̴� " + v +" �Դϴ�.");
		
		System.out.println(str +" ����ϱ� :");
		printString(str);
		System.out.println("\n"+str+" �Ųٷ� ����ϱ� :");
		reverseString(str);
		
		String items[] = {"������", "�����ٶ�", "�����ٶ�", "�����ٶ󸶹�", "�����ٶ󸶹ٻ�"};
		v = binarySearch(items, 0, 4, "�����ٶ�");
		System.out.println("\n�����ٶ󸶴� " + (v+1) +"�� °�� �ֽ��ϴ�");
	}
}
