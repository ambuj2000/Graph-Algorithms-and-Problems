<i><strong>
So my point was that dfs is much more useful.
Bfs has limitations in sense that everytime you cannot apply it 
But dfs has randomness due to which you can use it at most of the places.
It also helps you to improve dp/ recursion type of concepts.
What i will recommend is that solve some problems and in all cases try to give priority to dfs you will understand its beauty!!
</br>


  Depth-First Search (DFS) is not typically used to find the shortest path in a graph. It explores as far as possible along each branch before backtracking. While it can be adapted to find paths between nodes, it doesn't guarantee finding the shortest path. Instead, it's more commonly used to explore all nodes reachable from the starting point.

For finding the shortest path, algorithms like Breadth-First Search (BFS) or Dijkstra's algorithm are more appropriate. BFS explores all the neighbors of a node before moving on to the next level, ensuring that the shortest path to each node is found first. Dijkstra's algorithm, on the other hand, iteratively selects the node with the smallest tentative distance from the start node until the destination is reached.

So, while DFS can be used to find paths, it's not the best choice for finding the shortest path in a graph.
</strong>
</i>
