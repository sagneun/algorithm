package soni.com;

public class Recursion_countingCellsInABob {
	static int NOIMAGE = 0, IMAGE = 1, VISITED = 2;
	static int sizeOfArr = 8;
	static int images[][] =	{	{ 0, 0, 0, 0, 0, 0, 0, 1 },
								{ 1, 1, 1, 0, 1, 1, 0, 1 },
								{ 0, 0, 0, 0, 0, 0, 0, 1 },
								{ 0, 1, 0, 0, 1, 1, 0, 0 },
								{ 0, 1, 1, 0, 0, 0, 1, 1 },
								{ 0, 1, 0, 0, 0, 1, 0, 1 },
								{ 0, 0, 0, 1, 0, 0, 0, 1 },
								{ 0, 1, 1, 1, 0, 1, 0, 1 }
							};
	public static boolean isInside(int x, int y) {
		if(x < 0 || y < 0 || x >= sizeOfArr || y >= sizeOfArr) {
			return false;
		}else {
			return true;
		}
	}
	public static int countingCells(int x, int y) { // (x, y)와 연결된 이미지의 갯수
		
		// 범위 내에 존재하지 않는 셀이거나, 이미지가 없거나 이미 방문한 셀이라면 카운팅을 하지 않는다
		if(isInside(x, y) == false) {
			return 0;
		}else {
			if(images[x][y] == NOIMAGE || images[x][y] == VISITED)
			{
				return 0;
			}
	
			images[x][y] = VISITED;
			return 1 + countingCells(x-1, y) + countingCells(x-1, y+1) + countingCells(x, y+1) + countingCells(x+1, y+1) 
				+ countingCells(x+1, y) + countingCells(x+1, y-1) + countingCells(x, y-1) + countingCells(x-1, y-1);
		}
	}
	public static void printTheBob() {
		for(int i = 0; i < sizeOfArr ; i++) {
			for(int j = 0; j < sizeOfArr ; j++) {
				System.out.print(images[i][j]+" ");
			}
			System.out.println();
		}
	}
	public static void main(String[] args) {
		// TODO Auto-generated method stub
		int cells = countingCells(7, 7);
		System.out.println("(7, 7)에 연결된 모든 cell들은 총 "+cells+"개이다.");
		printTheBob();
	}

}
