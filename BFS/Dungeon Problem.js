class Dungeon{ 
    constructor(){
        this.board = [['.', '.', '.', '#', '.', '.', '.'],
                      ['.', '#', '.', '.', '.', '#', '.'],
                      ['.', '#', '.', '#', '.', '.', '.'],
                      ['.', '.', '#', '#', '.', '.', '.'],
                      ['.', '.', '#', 'E', '.', '#', '.']]
    }

    printBoard(){
        console.log('')
        for (let i of this.board){
            let output = ``
            for (let j of i){
                output += `${j} `
            }
            console.log(output)
        }
    }

    solve(startRow, startCol) {
        // See if starting position is legal
        if (!this.#isLegal(startRow, startCol)){
            console.log('\nSpace is Occupied\n')
        }

        // Variables
        const rowVec = [1, -1, 0, 0]
        const colVec = [0, 0, 1, -1]

        this.board[startRow][startCol] = 'S';
        let start = [startRow, startCol]
        let node = []

        let q = []
        q.push(start)
        
        let visited = {}
        let prev = {}

        // BFS
        while(q.length){
            node = q.shift();
            
            if (this.board[node[0]][node[1]] == 'E')
                break
            
            for(let i = 0; i < 4; i++){
                let r = node[0] + rowVec[i], v = node[1] + colVec[i];
                if(this.#isLegal(r,v)){
                    let next = [r,v]
                    if(!visited[next]){
                        q.push(next)
                        visited[next] = true
                        prev[next] = node
                    }
                }
            }
        }

        // Reconstruct Path
        let path = []
        let at = node
        while(at[0] != startRow || at[1] != startCol){
            path.push(at)
            at = prev[at]
        }

        // Print Path
        let output = `\nReconstructed Path: (${at[0]}, ${at[1]})-> `
        while(path.length){
            at = path.pop()
            if(this.board[at[0]][at[1]] !== 'E')
                this.board[at[0]][at[1]] = '*'
            output += `(${at[0]}, ${at[1]})-> `
        }
        console.log(output)

    }

    #isLegal = (row, col) => {
        return (row >= 5 ||
                col >= 7 ||
                row < 0 ||
                col < 0 ||
                this.board[row][col] === '#')
                   ? false
                   : true;
    }
}

let d = new Dungeon()
d.printBoard()
d.solve(0,0)
d.printBoard()
