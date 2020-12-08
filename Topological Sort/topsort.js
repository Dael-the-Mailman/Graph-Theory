const INF = Number.MAX_SAFE_INTEGER

class Graph{
    constructor(size){
        this.V = size
        this.adj = []
        for(let i = 0; i < size; i++){
            this.adj[i] = {}
        }
        this.top_order = new Array(size)
        this.calculated = false
    }

    addEdge(src, dest, w){
        this.adj[src][dest] = w
    }

    printGraph(){
        for(let src = 0; src < this.V; src++){
            let output  = `\n Vertex ${src}:`
            for(let dest in this.adj[src]){
                output += `-> ${dest} weight: ${this.adj[src][dest]}`
            }
            console.log(output)
        }
    }

    topsort(print=false){
        let in_degree = new Array(this.V)
        for(let i = 0; i < this.V; i++){
            in_degree[i] = 0
        }

        for(let u = 0; u < this.V; u++){
            for(let x in this.adj[u]){
                in_degree[x[0]]++
            }
        }

        let q = []
        for(let i = 0; i < this.V; i++){
            if(in_degree[i] === 0)
                q.push(i)
        }

        let count = 0

        while(q.length){
            let u = q.shift()
            try {
                this.top_order[count] = u
                for(let x in this.adj[u]){
                    if(--in_degree[x[0]] === 0)
                        q.push(x[0])
                }
                count++
            } catch(e){
                console.log("There's a cycle in the graph")
            }
        }

        if(print){
            let out = '\nTopological Order: '
            for(let i = 0; i < this.V; i++)
                out += `${this.top_order[i]}-> `
            console.log(out)
        }
        this.calculated = true
    }

    shortestPath(start, end){
        if(!this.calculated) this.topsort()
        let dist =  new Array(this.V)
        for(let i = 0; i < this.V; i++) dist[i] = INF
        dist[start] = 0

        for(let i = 0; i < this.V; i++){
            let index = this.top_order[i]
            if(dist[index] !== INF){
                for(let e in this.adj[index]){
                    let newDist = dist[index] + this.adj[index][e]
                    dist[e] = Math.min(dist[e], newDist)
                } 
            }
        }

        if(dist[end] === INF){
            console.log(`\nNode ${end} is unreachable from node ${start}`)
            return
        }
        console.log(`\nShortest Distance from node ${start} to node ${end} is ${dist[end]}`)
    }

    longestPath(start, end){
        if(!this.calculated) this.topsort()
        let dist =  new Array(this.V)
        for(let i = 0; i < this.V; i++) dist[i] = INF
        dist[start] = 0

        for(let i = 0; i < this.V; i++){
            let index = this.top_order[i]
            if(dist[index] !== INF){
                for(let e in this.adj[index]){
                    let newDist = dist[index] - this.adj[index][e]
                    dist[e] = Math.min(dist[e], newDist)
                } 
            }
        }

        if(dist[end] === INF){
            console.log(`\nNode ${end} is unreachable from node ${start}`)
            return
        }
        console.log(`\nShortest Distance from node ${start} to node ${end} is ${-dist[end]}`)
    }
}

let g = new Graph(7)
g.addEdge(0, 1, 3)
g.addEdge(0, 2, 2)
g.addEdge(0, 5, 3)
g.addEdge(1, 3, 1)
g.addEdge(1, 2, 6)
g.addEdge(2, 3, 1)
g.addEdge(2, 4, 10)
g.addEdge(3, 4, 5)
g.addEdge(5, 4, 7)
g.printGraph()
g.topsort(true)
g.shortestPath(0,4)
g.longestPath(0,4)
g.shortestPath(0,6)
