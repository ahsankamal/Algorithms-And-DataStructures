import java.util.ArrayList;
import java.util.Collections;
import java.util.Comparator;
import java.util.Scanner;

//Given a set of non-negative integers, print the biggest integer possible by reordering and concatination
//of elements in the array.
public class BiggestNumber{

    public static void main(String[] args){

        Scanner inp = new Scanner(System.in);
        ArrayList<Integer> arr = new ArrayList<>();
        int n = inp.nextInt();
        for(int i=0;i<n;i++){
            arr.add(inp.nextInt());
        }

        //a=9,b=97
        //97+9 compareTo 9+97
        //979 < 997
        //return -1
        Comparator<Integer> sortBy = (Integer a, Integer b) -> {
            return (b.toString() + a.toString()).compareTo(a.toString() + b.toString()) ;
        };

        Collections.sort(arr, sortBy);//N Log(N)

        //printing Biggest integer possible
        for(int i=0; i<n; i++){
            System.out.print(arr.get(i));
        }
    }


}