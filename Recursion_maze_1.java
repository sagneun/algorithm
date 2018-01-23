package soni.com;
// maze�� ���� : ����������, ���� �ִ���, �̹� ������ �������, ���� �ȿ� �����ϴ� cell����
public class maze_1 { // maze_1�� ��ΰ� �����ϴ����� �˾ƺ��� �ڵ�
	static int WALL_SIGNAL = 1, VISITED_SIGNAL = 2, sizeofmaze = 8; 
	static int maze[][] =	{	{ 0, 0, 0, 0, 0, 0, 0, 1 },
								{ 1, 1, 1, 0, 1, 1, 0, 1 },
								{ 0, 0, 0, 1, 0, 0, 0, 1 },
								{ 0, 1, 0, 0, 1, 1, 0, 0 },
								{ 0, 1, 1, 1, 0, 0, 1, 1 },
								{ 0, 1, 0, 0, 0, 1, 0, 1 },
								{ 0, 0, 0, 1, 0, 0, 0, 1 },
								{ 0, 1, 1, 1, 0, 1, 0, 0 }
							};
	public static boolean findPath(int x, int y) {
		
		if(x == 0 && y == 0) {
			return true;
		}
		
		if(maze[x][y] == VISITED_SIGNAL || maze[x][y] == WALL_SIGNAL){
			return false;
		}else {
			maze[x][y] = VISITED_SIGNAL;
			if(x > 0) {
				if(findPath(x - 1, y) == true) {
					return true;
				}
			}
			if(y > 0) {
				if(findPath(x, y - 1) == true) {
					return true;
				}
			}
			if(x < sizeofmaze - 1) {
				if(findPath(x + 1, y) == true) {
					return true;
				}
			}
			if(y < sizeofmaze - 1) {
				if(findPath(x, y + 1) == true) {
					return true;
				}
			}
			return false;
		}
	}
	public static void main(String[] args) {
		// TODO Auto-generated method stub
		boolean possible = findPath(7, 7);
		System.out.println("(7,7)���� �̷θ� ����Ͽ� ���������� ���� ���� �ִ� : " + possible);
	}

}
