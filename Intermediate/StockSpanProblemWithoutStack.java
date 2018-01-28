public class StockSpanProblemWithoutStack {

    //O(n)
    public static void main(String[] args){

        Integer[] stocks = {100, 80, 60, 70, 60, 75, 85};
        Integer[] stock_span = {0,0,0,0,0,0,0};
        stock_span[0]=1;
        for(int i=1;i<stocks.length;i++){
            int j=i-1;
            while(j>=0 && stocks[i]>stocks[j]){
                stock_span[i]+=stock_span[j];
                j=j-stock_span[j];
            }
            stock_span[i]++;
        }
        for(int i=0;i<stock_span.length;i++){
            System.out.print(stock_span[i]+" ");
        }
        System.out.println();
    }
}
