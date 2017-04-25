package main;

import java.io.IOException;
import java.io.InputStream;
import java.io.ObjectInputStream;
import java.io.ObjectOutputStream;
import java.io.OutputStream;
import java.net.Socket;
import java.net.UnknownHostException;

public class Node {

	public static void main(String[] args) {

		try {
			@SuppressWarnings("resource")
			Socket s = new Socket("localhost", 7000);
			System.out.println("connected");

			OutputStream os = s.getOutputStream();
			ObjectOutputStream oos = new ObjectOutputStream(os);

			InputStream is = s.getInputStream();
			ObjectInputStream ois = new ObjectInputStream(is);

			Integer start = (Integer) (ois.readObject());
			Integer end = (Integer) (ois.readObject());

			System.out.println(start + " - " + end);

			int number = howManyPrime(start, end);

			oos.writeObject(new Integer(number));

		} catch (UnknownHostException e) {
			e.printStackTrace();
		} catch (IOException e) {
			e.printStackTrace();
		} catch (ClassNotFoundException e) {
			e.printStackTrace();
		}

	}

	public static boolean isPrime(double num) {
		int count = 2;
		while (num > count) {
			if ((num % count) == 0) {
				return false;
			}
			count++;
		}
		return true;
	}

	public static int howManyPrime(int start, int end) {
		int count = 0;

		for (long i = start; i < end; i++) {
			if (isPrime(i)) {
				count++;
			}
		}
		return count;
	}

}
