public class ThreeThreadCounterUsingLambda {

    private static final int MAX_COUNT=10;
    private static int counter = 0;
    public static Object lock = new Object();

    public static void main(String[] args){
        Runnable work = ( )->{
            while(counter<MAX_COUNT){
//                System.out.println("T"+Thread.currentThread().getName()+" : "+counter);
                synchronized (lock){
                    while (counter%3!=Integer.parseInt(Thread.currentThread().getName())){
                        try {
                            lock.wait();
                        }catch (InterruptedException e){
                            e.printStackTrace();
                        }
                    }
                        counter++;
                        System.out.println("T"+Thread.currentThread().getName()+" : "+counter);
                        lock.notifyAll();
                    }
            }
        };

        ThreeThreadCounterUsingLambda obj = new ThreeThreadCounterUsingLambda();
        Thread th1 = new Thread(work,"0");
        Thread th2 = new Thread(work,"1");
        Thread th3 = new Thread(work, "2");
        th1.start();
        th2.start();
        th3.start();

    }
}
