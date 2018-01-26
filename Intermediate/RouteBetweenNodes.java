import java.util.*;

public class RouteBetweenNodes {
    public static void main(String[] args){

        Scanner input = new Scanner(System.in);
        int n = input.nextInt();//no of nodes
        int i=0;
        ArrayList<Integer> parent = new ArrayList<>(n);//to print path
        for(int j=0;j<n;j++){
            parent.add(0);
        }
        LinkedList<Integer>[] adjList = new LinkedList[n];
        int e = input.nextInt();//no of edges
        while(i<e){
            int a,b;
            a = input.nextInt();
            b = input.nextInt();
            if(adjList[a]==null){
                adjList[a] = new LinkedList<>();
            }
            adjList[a].add(b);
            i++;
        }

        //displaying graph
        i=0;
        for(LinkedList<Integer> node : adjList){
            if(node==null){
                i++;
                continue;
            }
            Iterator itr = node.iterator();
            System.out.print("Node " + i + " : ");
            while (itr.hasNext()){
                System.out.print(itr.next()+", ");
            }
            System.out.println();
            i++;
        }

        int startNode = input.nextInt();
        int endNode = input.nextInt();
        ArrayList<Boolean> visited = new ArrayList<>(n);
        for(int j=0;j<n;j++){
           visited.add(false);
        }
        Deque<Integer> stack = new ArrayDeque<>();
        stack.push(startNode);
        parent.set(startNode,-1);

        //Depth first search
        while (!stack.isEmpty()){
            int top = stack.pop();
            visited.set(top,true);
            if(top==endNode) {
                System.out.print(top+"<-");
                int tmp = parent.get(top);
                while(tmp!=-1){
                    System.out.print(tmp+"<-");
                    tmp = parent.get(tmp);
                }
            }
            if(adjList[top]==null){
                continue;
            }
            Iterator it = adjList[top].iterator();
            while (it.hasNext()){
                int nextNode = (Integer)it.next();
                if(!visited.get(nextNode)){
                    parent.set(nextNode,top);
                    stack.push(nextNode);
                }
            }
        }


    }
}
/*
Test case

10 10
1 2
2 3
2 4
1 8
4 8
3 5
5 6
5 7
6 7
7 4

Node 1 : 2, 8,
Node 2 : 3, 4,
Node 3 : 5,
Node 4 : 8,
Node 5 : 6, 7,
Node 6 : 7,
Node 7 : 4,

3 4
4<-7<-5<-3<-
 */