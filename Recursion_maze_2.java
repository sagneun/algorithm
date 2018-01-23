package soni.com;
// maze의 조건 : 도착지인지, 벽이 있는지, 이미 지나간 경로인지, 범위 안에 존재하는 cell인지
public class maze_2 { // maze_2는 경로가 존재하는지만 알아보고 존재하는 경로를 출력하는 코드
	static int WALL_SIGNAL = 1, VISITED_SIGNAL = 2, PATH_SIGNAL = 3, sizeofmaze = 8; 
	static int maze[][] =	{	{ 0, 0, 0, 0, 0, 0, 0, 1 },
								{ 0, 1, 1, 0, 1, 1, 0, 1 },
								{ 0, 0, 0, 1, 0, 0, 0, 1 },
								{ 0, 1, 0, 0, 1, 1, 0, 0 },
								{ 0, 1, 1, 1, 0, 0, 1, 1 },
								{ 0, 1, 0, 0, 0, 1, 0, 1 },
								{ 0, 0, 0, 1, 0, 0, 0, 1 },
								{ 0, 1, 1, 1, 0, 1, 0, 0 }
							};
	public static boolean findPath(int x, int y) {
		
		if(x == 0 && y == 0) {
			maze[x][y] = PATH_SIGNAL;
			return true;
		}
		
		if(maze[x][y] == VISITED_SIGNAL || maze[x][y] == WALL_SIGNAL){
			return false;
		}else {
			maze[x][y] = VISITED_SIGNAL;
			if(x > 0) {
				if(findPath(x - 1, y) == true) {
					maze[x][y] = PATH_SIGNAL;
					return true;
				}
			}
			if(y > 0) {
				if(findPath(x, y - 1) == true) {
					maze[x][y] = PATH_SIGNAL;
					return true;
				}
			}
			if(x < sizeofmaze - 1) {
				if(findPath(x + 1, y) == true) {
					maze[x][y] = PATH_SIGNAL;
					return true;
				}
			}
			if(y < sizeofmaze - 1) {
				if(findPath(x, y + 1) == true) {
					maze[x][y] = PATH_SIGNAL;
					return true;
				}
			}
			return false;
		}
	}
	public static void printThePath() {
		for(int i = 0; i < sizeofmaze ; i++) {
			for(int j = 0; j < sizeofmaze ; j++) {
				System.out.print(maze[i][j]+" ");
			}
			System.out.println();
		}
	}
	public static void main(String[] args) {
		// TODO Auto-generated method stub
		boolean possible = findPath(7, 7);
		System.out.println("(7,7)에서 미로를 출발하여 도착지까지 가는 길이 있다 : " + possible);
		printThePath();
	}

}
