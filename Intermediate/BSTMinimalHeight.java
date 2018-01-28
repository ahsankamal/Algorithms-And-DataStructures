public class BSTMinimalHeight {

    //given a sorted array of unique int, write an algo to create a BST with minimal height.
    public static class BSTNode{
        int value;
        BSTNode left;
        BSTNode right;
        public BSTNode(int v){
            this.value=v;
            this.left=null;
            this.right=null;
        }
    }
    public static void main(String[] args){
        Integer[] sorted = {10,20,30,40,50,60,70,80,90,100};
        BSTNode bstNode = constructBST(sorted,0, sorted.length-1);
        inorderTraversal(bstNode);
    }
    public static BSTNode constructBST(Integer[] arr, int start, int end){
        if(start>end){
            return null;
        }
        int mid = (start+end)/2;
        BSTNode root = new BSTNode(arr[mid]);
        root.left = constructBST(arr,start,mid-1);
        root.right = constructBST(arr,mid+1, end);
        return root;
    }
    public static void inorderTraversal(BSTNode root){
        if(root.left!=null){
            inorderTraversal(root.left);
        }
        System.out.print(root.value+" ");
        if(root.right!=null){
            inorderTraversal(root.right);
        }
    }
}

