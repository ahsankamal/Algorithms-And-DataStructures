import java.util.Scanner;

//Dutch National Flag Algorithm, or 3-way Partitioning
public class SortZeroOneTwosArray {

    public static void main(String[] args){
        Scanner inp = new Scanner(System.in);
        int n = inp.nextInt();
        Integer[] arr = new Integer[n];
        for(int i=0;i<n;i++){
            arr[i]=inp.nextInt();
        }

        int one=-1,two=n,cur=0;
        while(cur<two){
            if(arr[cur]==0){
                if(one==-1){
                    cur++;
                    continue;
                }
               else{
                    arr[one]=0;
                    arr[cur]=1;
                    one++;
                    cur++;
                }
            }
            else if(arr[cur]==1){
                if(one==-1) {
                    one=cur;
                }
                cur++;
            }
            else {//cur==2
                int tmp = arr[two-1];
                arr[two-1]=2;
                arr[cur]=tmp;
                two--;
            }
        }

        for(int i=0;i<n;i++){
            System.out.print(arr[i]+" ");
        }
    }

}
/*
test case

20
2 2 2 2 1 1 0 1 0 2 0 1 0 2 0 0 1 1 0 2
 */