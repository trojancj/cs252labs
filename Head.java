package trojanLab08;

import java.io.IOException;
import java.io.InputStream;
import java.io.ObjectInputStream;
import java.io.ObjectOutputStream;
import java.io.OutputStream;
import java.net.ServerSocket;
import java.net.Socket;

public class Head {

	public static void main(String[] args) {
		
		int totalNodes = 5;
		
		try {
			ServerSocket ss = new ServerSocket(7000);
			
			for(int i = 0; i < totalNodes; i++) {
							
				Socket s = ss.accept();  // blocking
			
				InputStream is = s.getInputStream();
				ObjectInputStream ois = new ObjectInputStream(is);
				
				OutputStream os = s.getOutputStream();	
				ObjectOutputStream oos = new ObjectOutputStream(os);
				
				
				try {
					Integer x = (Integer)(ois.readObject());
					
					String str = (String)(ois.readObject());
					
					System.out.println(x);
					System.out.println(str);
					
					
					oos.writeObject("thanks");
					
				} catch (ClassNotFoundException e) {
					e.printStackTrace();
				}
			}
		ss.close();
		} 
		catch (IOException e) {
			e.printStackTrace();
		}
	}
}