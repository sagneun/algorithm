package soni.com;

public class string {
	
	public static int lengthofString(String str) {	// 문자열의 길이 계산하기.
		if(str.equals("")) {
			return 0;
		}else {
			return 1 + lengthofString(str.substring(1));
		}
	}
	public static void printString(String str) { 	// 문자열 출력하기.
		if(str.equals("")) {
			return;
		}else {
			System.out.print(str.charAt(0));
			printString(str.substring(1));
		}
	}
	public static void reverseString(String str) {	// 문자열 뒤집어서 출력하기.
		if(str.equals("")) {
			return;
		}else {
			reverseString(str.substring(1));
			System.out.print(str.charAt(0));
		}
	}
	public static int binarySearch(String [] items, int from, int to, String str) {	// binary search로 문자열 배열중에 문자열 찾기
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
		System.out.println(str +"의 문자열 길이는 " + v +" 입니다.");
		
		System.out.println(str +" 출력하기 :");
		printString(str);
		System.out.println("\n"+str+" 거꾸로 출력하기 :");
		reverseString(str);
		
		String items[] = {"가나다", "가나다라", "가나다라마", "가나다라마바", "가나다라마바사"};
		v = binarySearch(items, 0, 4, "가나다라마");
		System.out.println("\n가나다라마는 " + (v+1) +"번 째에 있습니다");
	}
}
