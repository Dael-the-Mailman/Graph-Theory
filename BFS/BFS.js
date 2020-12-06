class Graph{
    constructor(V){
        this.V = V
        this.adj = {}
        for (let i = 0; i < V; i++){
            this.adj[i] = []
        }
    }

    addEdge(src, dest){
        this.adj[src].push(dest)
    }

    printGraph(){
        for (let i = 0; i < this.V; i++){
            let output = `\n Vertex ${i}:`
            for(let x = 0; x < this.adj[i].length; x++){
                output += `-> ${this.adj[i][x]}`
            }
            console.log(output)
        }
    }

    BFS(start){
        let visited = []
        for(let i = 0; i < this.V; i++)
            visited.push(false)
        let q = []
        q.push(start)
        let output = `\n BFS: `
        
        while(q.length){
            start = q.shift()

            if(!visited[start]){
                output += `${start}-> `
                visited[start] = true
            }

            for (let i = 0; i < this.adj[start].length; i++){
                if(!visited[this.adj[start][i]])
                    q.push(this.adj[start][i])
            }
        }
        console.log(output)
    }
}

let adj = new Graph(5)
adj.addEdge(0, 1)
adj.addEdge(0, 2)
adj.addEdge(0, 3)
adj.addEdge(1, 2)
adj.addEdge(3, 4)
adj.printGraph()
adj.BFS(0)