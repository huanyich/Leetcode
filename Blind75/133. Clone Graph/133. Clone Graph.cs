public class Solution {
    Dictionary<Node,Node> clone = new Dictionary<Node,Node>();
    public Node CloneGraph(Node node) {
        //BFS
        if(node==null) return null;
        Queue<Node> q = new Queue<Node>();
        clone[node] = new Node(node.val);
        q.Enqueue(node);

        while(q.Count>0){
            Node curr = q.Peek();
            q.Dequeue();
            
            foreach(var it in curr.neighbors){
                if(!clone.ContainsKey(it)){
                    clone[it] = new Node(it.val);
                    q.Enqueue(it);
                }
                clone[curr].neighbors.Add(clone[it]);
            }

        }
        return clone[node];
    }
}
