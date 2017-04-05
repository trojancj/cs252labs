public class PrimeNumberFinder{
    public static void main(String[] args){
        final long startTime = System.currentTimeMillis();
        
        int startVal = 1;
        int endVal = 100;
        
        int nThreads = 4;
        Thread[] theThreads = new Thread[nThreads];
        for (int tnum = 0; tnum < nThreads; tnum++){
            primeObject d = new primeObject(startVal, endVal, tnum, nThreads);
            Thread t = new Thread(d);
            theThreads[tnum] = t;    
            t.start();
        }
        for (int tnum = 0; tnum < nThreads; tnum++){
            try{
                theThreads[tnum].join();
            }
            catch(InterruptedException e){
                e.printStackTrace();
            }
        }
        int theFinalTotal = 0;
        for(int i = 0; i<nThreads; i++){
            /*
            This is where I am stuck
            */
            theFinalTotal += theThreads[i].getTotal();
        }
        System.out.println(theFinalTotal);
        
        
        final long endTime = System.currentTimeMillis();
        System.out.println("Total execution time: " + (endTime - startTime));
    }
}