//package main;

import java.io.IOException;
import java.io.InputStream;
import java.io.ObjectInputStream;
import java.io.ObjectOutputStream;
import java.io.OutputStream;
import java.net.ServerSocket;
import java.net.Socket;

public class Head {

	public static void main(String[] args) {

		int numNodes = 5; // the number of connections we want to connect to our
							// head node
        //int numThreads = 4;
        //int[] totalArray = new int[numThreads];
        int[] total = new int[numNodes];
        
        Integer start = 1000;
        Integer end = 1000000;
        
        Socket[] sockets = new Socket[numNodes];
        
		try {
			ServerSocket ss = new ServerSocket(7000); // blocking

			for (int i = 0; i < numNodes; i++) {
				System.out.println("Head node starting");
				Socket s = ss.accept();
                sockets[i] = s;
            }
            
            final long startTime = System.currentTimeMillis();
            
            for(int i = 0; i < numNodes; i++){

				OutputStream os = sockets[i].getOutputStream();
				ObjectOutputStream oos = new ObjectOutputStream(os);

				InputStream is = sockets[i].getInputStream();
				ObjectInputStream ois = new ObjectInputStream(is);
				try {
					System.out.println(i + " node connected");

					Integer beginning = (end - start) / numNodes * i + start; // beginning of the ranges
					Integer stop = (end - start) / numNodes * (i+ 1) + start; // end of the ranges

					oos.writeObject(beginning);
					oos.writeObject(stop);
                    
					Integer num = (Integer) (ois.readObject()); 

					System.out.println(num);
                    total[i] = num;
                    
				} catch (ClassNotFoundException e) {
					e.printStackTrace();
				}
			}
            
            int finalTotal = 0;
            
            for(int i = 0; i < numNodes; i++){
                finalTotal += total[i];
            }
            
            final long endTime = System.currentTimeMillis();
            final long totalTime = (endTime - startTime) / 1000;
            System.out.println("Total primes is " + finalTotal);
            System.out.println("Total runtime is " + totalTime + " seconds");
            
			System.out.println("head closing");
			ss.close(); // closes the socket to basically stop the program

		} catch (IOException e) {
			e.printStackTrace();
		}

	}

}
