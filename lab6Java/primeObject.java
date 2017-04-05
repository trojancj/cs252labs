public class primeObject implements Runnable{
    private int startVal;
    private int endVal;
    int threadNumber;
    int numThreads;
    int total;
    
    public primeObject(int startVal, int endVal, int threadNumber, int numThreads){
        this.startVal = startVal;
        this.endVal = endVal;
        this.threadNumber = threadNumber;
        this.numThreads = numThreads;
        total = 0;
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
    public int getTotal(){
        return total;
    }
    @Override
    public void run(){
        int start = (endVal /numThreads) * threadNumber;
        int end = (endVal / numThreads) * (threadNumber + 1);
        total = numPrimes(start, end);
    }
}