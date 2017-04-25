package main;

import java.io.IOException;
import java.io.InputStream;
import java.io.ObjectInputStream;
import java.io.ObjectOutputStream;
import java.io.OutputStream;
import java.net.ServerSocket;
import java.net.Socket;

public class Head {

	public static void main(String[] args) {

		int numNodes = 1; // the number of connections we want to connect to our
							// head node
		try {
			ServerSocket ss = new ServerSocket(7000); // blocking

			for (int i = 0; i < numNodes; i++) {
				System.out.println("Head node starting");
				Socket s = ss.accept();

				OutputStream os = s.getOutputStream();
				ObjectOutputStream oos = new ObjectOutputStream(os);

				InputStream is = s.getInputStream();
				ObjectInputStream ois = new ObjectInputStream(is);
				try {
					System.out.println(i + " node connected");

					Integer start = 10; // beginning of the ranges
					Integer end = 100; // end of the ranges

					oos.writeObject(start);
					oos.writeObject(end); // writes to the node console
											// that it has been accepted
					Integer num = (Integer) (ois.readObject()); // creates a
																// variable to
																// be read from
																// the nodes

					System.out.println(num);

				} catch (ClassNotFoundException e) {
					e.printStackTrace();
				}
			}

			System.out.println("head closing");
			ss.close(); // closes the socket to basically stop the program

		} catch (IOException e) {
			e.printStackTrace();
		}

	}

}
