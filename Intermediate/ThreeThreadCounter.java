public class ThreeThreadCounter implements Runnable{
    public static Object lock = new Object();
    public static final int MAX_COUNT = 100;
    public static int counter=0;
    public int remainder;

    public ThreeThreadCounter(int rem){
        this.remainder=rem;
    }

    @Override
    public void run() {
        while (counter<MAX_COUNT){
            synchronized (lock){
            while (counter%3 != remainder){
                try {
                    lock.wait();
                }
                catch (InterruptedException e){
                    e.printStackTrace();
                }
            }
                    counter++;
                    System.out.println(Thread.currentThread().getName()+": "+counter);
                    lock.notifyAll();
            }
        }
    }

    public static void main(String[] args){
//        Runnable work = ()->{
//
//        };
        ThreeThreadCounter workForThread1 = new ThreeThreadCounter(0);
        ThreeThreadCounter workForThread2 = new ThreeThreadCounter(1);
        ThreeThreadCounter workForThread3 = new ThreeThreadCounter(2);
        Thread thread1 = new Thread(workForThread1,"T1");
        Thread thread2 = new Thread(workForThread2,"T2");
        Thread thread3 = new Thread(workForThread3,"T3");


            thread1.start();
            thread2.start();
            thread3.start();


    }
}
