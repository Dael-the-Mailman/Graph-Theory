class Dungeon:
    def __init__(self):
        self.board = [['.', '.', '.', '#', '.', '.', '.'],
                      ['.', '#', '.', '.', '.', '#', '.'],
                      ['.', '#', '.', '#', '.', '.', '.'],
                      ['.', '.', '#', '#', '.', '.', '.'],
                      ['.', '.', '#', 'E', '.', '#', '.']]
    
    def printBoard(self):
        print('\n', end='')
        for i in self.board:
            for j in i:
                print(j, end=' ')
            print('\n', end='')
    
    def solve(self, startRow, startCol):
        # Check to see if starting position is legal
        if not self.__isLegal(startRow, startCol):
            print('\nSpace is Occupied\n')

        # Variables
        rowVec = [1, -1, 0, 0]
        colVec = [0, 0, 1, -1]

        self.board[startRow][startCol] = 'S'

        start = (startRow, startCol)
        node = ()

        q = []
        q.append(start)

        visited = {}
        prev = {}

        # BFS
        while(len(q)):
            node = q.pop(0)
            
            if self.board[node[0]][node[1]] == 'E':
                break
            
            for i in range(4):
                r = node[0] + rowVec[i]
                v = node[1] + colVec[i]
                if self.__isLegal(r, v):
                    next = (r, v)
                    if(not visited.get(next)):
                        q.append(next)
                        visited[next] = True
                        prev[next] = node
        
        # Reverse Prev Dict
        path = []
        at = node
        while(at[0] != startRow or at[1] != startCol):
            path.append(at)
            at = prev.get(at)
        
        # Reconstructed Path
        print(f'\nReconstructed Path: {start}-> ', end='')
        while(len(path)):
            at = path.pop()
            if(self.board[at[0]][at[1]] != 'E'):
                self.board[at[0]][at[1]] = '*'
            print(f'{at}-> ', end='')
        print('\n', end='')
               
    def __isLegal(self, row, col):
        return False if(row >= 5 or col >= 7 or row < 0 or col < 0 or self.board[row][col] == '#') else True

if __name__ == '__main__':
    d = Dungeon()
    d.printBoard()
    d.solve(0, 0)
    d.printBoard()
    