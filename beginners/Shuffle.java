import java.util.Random;
import java.util.Scanner;

public class Shuffle {

    public static void main(String[] args){

        Scanner input = new Scanner(System.in);
        int n = input.nextInt();
        Integer[] array = new Integer[n];
        for(int i=0; i<n; i++){
            array[i] = i+1;
        }

        Random generator = new Random();
        for(int i=0; i<n; i++){
            System.out.print(array[i]+ " ");
        }
        System.out.println();

        //shuffling
        for(int currentIndex=n-1; currentIndex>0; currentIndex--){
            int randomIndex = generator.nextInt(currentIndex);//[0, currentIndex]

            //swap
            int tmp = array[currentIndex];
            array[currentIndex]=array[randomIndex];
            array[randomIndex]=tmp;
        }

        for(int i=0; i<n; i++){
            System.out.print(array[i]+ " ");
        }

    }
}
