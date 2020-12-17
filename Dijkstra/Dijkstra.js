const INF = Number.MAX_SAFE_INTEGER

// Lazy version
class Graph{
    constructor(size){
        this.V = size
        this.adj = []
        for(let i = 0; i < size; i++){
            this.adj[i] = {}
        }
    }

    addEdge(src, dest, w){
        this.adj[src][dest] = w
    }

    dijkstra(src){
        let dist = new Array(this.V)
        let q = []
        for(let i = 0; i < this.V; i++){
            dist[i] = INF
            q.push(i)
        }
        dist[src] = 0

        while(q.length){
            let u = q.shift()
            for(let v in this.adj[u]){
                let alt = dist[u] + this.adj[u][v]
                if(alt < dist[v]){
                    dist[v] = alt
                }
            }
        }

        console.log(`List of the Shortest Distances from node ${src} to all other nodes:`)
        for(let i = 0; i < this.V; i++){
            console.log(`\tVertex: ${i}\tDistance: ${dist[i]}`)
        }
    }
}

let g = new Graph(9)
g.addEdge(0, 1, 4)
g.addEdge(0, 7, 8)
g.addEdge(1, 2, 8)
g.addEdge(1, 7, 11)
g.addEdge(2, 3, 7)
g.addEdge(2, 8, 2)
g.addEdge(2, 5, 4)
g.addEdge(3, 4, 9)
g.addEdge(3, 5, 14)
g.addEdge(4, 5, 10)
g.addEdge(5, 6, 2)
g.addEdge(6, 7, 1)
g.addEdge(6, 8, 6)
g.addEdge(7, 8, 7)
g.dijkstra(0)