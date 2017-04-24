package trojanLab08;

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
			Socket s = new Socket("localhost", 7000);
			System.out.println("connected");
			
			OutputStream os = s.getOutputStream();	
			ObjectOutputStream oos = new ObjectOutputStream(os);
			
			InputStream is = s.getInputStream();
			ObjectInputStream ois = new ObjectInputStream(is);
			
			oos.writeObject(new Integer(5));
			oos.writeObject("foo");
			
			String str = (String)(ois.readObject());
			System.out.println(str);
			
			s.close();
		} catch (UnknownHostException e) {
			e.printStackTrace();
		} catch (IOException e) {
			e.printStackTrace();
		} catch (ClassNotFoundException e) {
			e.printStackTrace();
		}
	}

}
