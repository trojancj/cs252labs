public class primeObject implements Runnable{
    private int startVal;
    private int endVal;
    int threadNumber;
    int numThreads;
    int[] theArray;
    
    public primeObject(int startVal, int endVal, int threadNumber, int numThreads, int[] theArray){
        this.startVal = startVal;
        this.endVal = endVal;
        this.threadNumber = threadNumber;
        this.numThreads = numThreads;
        this.theArray = theArray;
    }
    public boolean isPrime(int inQuestion){
        int i = 2;
        while(i < inQuestion){
            if(inQuestion % i == 0){
                return false;
            }
            i++;
        }
        return true;
    }
    public int numPrimes(int min, int max){
        int counter = 0;
        for(int i=min; i<=max; i++){
            if(isPrime(i)){
                counter++;
            }
        }
        return counter;
    }
    @Override
    public void run(){
        int start = (int)((((double)(endVal-startVal) / (double)numThreads) * (double)threadNumber) + (double)startVal);
        int end = (int)(((double)(endVal-startVal) / (double)numThreads) * (double)(threadNumber + 1) + (double)startVal);
        theArray[threadNumber] = numPrimes(start, end);
    }
}
