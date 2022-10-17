public class Codec {

    // Encodes a tree to a single string.
    public string serialize(TreeNode root) {
        if(root==null) return "x,";
        return root.val.ToString() + "," + serialize(root.left)+serialize(root.right);
    }
    Queue<string> Q = new Queue<string>();
    // Decodes your encoded data to tree.
    public TreeNode deserialize(string data) {
        int n = data.Length;
        for(int i=0; i<n; i++){
            int r = i+1;
            while(r<n && data[r]!=',') r++;
            string tmp = data.Substring(i,r-i);
            Q.Enqueue(tmp);
            i=r;
        }
        
        

        //return null;
        return tree(ref Q);
    }


    public TreeNode tree(ref Queue<string> Q){
        //if(Q.Count==0) return null;
        if(Q.Peek()=="x"){
            Q.Dequeue();
            return null;
        }


        TreeNode node = new TreeNode(Int32.Parse(Q.Peek()));
        Q.Dequeue();

        node.left = tree(ref Q);
        node.right = tree(ref Q);

        return node;
    }
}
