public class PrimeNumberFinder{
    public static void main(String[] args){
        final long startTime = System.currentTimeMillis();
        int startVal = 1000;
        int endVal = 1000000;        
        int nThreads = 4;
        int[] totalArray = new int[nThreads];
        Thread[] theThreads = new Thread[nThreads];
        
        for (int tnum = 0; tnum < nThreads; tnum++){
            primeObject d = new primeObject(startVal, endVal, tnum, nThreads, totalArray);
            Thread t = new Thread(d);
            theThreads[tnum] = t;    
            t.start();
        }
        
        int theFinalTotal = 0;
        for (int tnum = 0; tnum < nThreads; tnum++){
            try{
                
                theThreads[tnum].join();
                theFinalTotal += totalArray[tnum];
            }
            catch(InterruptedException e){
                e.printStackTrace();
            }
        }
        
        System.out.println(theFinalTotal);    
        final long endTime = System.currentTimeMillis();
        System.out.println("Total execution time: " + (endTime - startTime));
    }
}
