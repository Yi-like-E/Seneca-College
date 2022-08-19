import java.io.*;
import java.net.*;

public class ThreadedEchoServer {
	public static void main(String[] args) throws IOException {
		ServerSocket s = null;
		try {
			s = new ServerSocket(7777);
			int i = 0;

			for (;;) {
				Socket incoming = s.accept();
				System.out.println("Spawning " + ++i);
				new ThreadedEchoHandler(incoming, i).start();
			}
		} catch (Exception e) {
			System.out.println(e);
		} finally {
			s.close();
		}
	}
}

class ThreadedEchoHandler extends Thread {
	private Socket incoming;
	private int clientNumber;

	public ThreadedEchoHandler(Socket s, int c) {
		incoming = s;
		clientNumber = c;
	}

	public void run() {
		try {
			BufferedReader in = new BufferedReader(new InputStreamReader(incoming.getInputStream()));
			PrintWriter out = new PrintWriter(incoming.getOutputStream(), true);

			out.println("Hello! Enter BYE to exit.");

			boolean done = false;
			while (!done) {
				String str = in.readLine();
				if (str == null)
					done = true;
				else {
					out.println("Echo (" + clientNumber + "): " + str);
					System.out.println("Received from (" + clientNumber + "): " + str);
					if (str.trim().equals("BYE"))
						done = true;
				}
			}
			incoming.close();
		} catch (Exception e) {
			System.out.println(e);
		}
	}

}
