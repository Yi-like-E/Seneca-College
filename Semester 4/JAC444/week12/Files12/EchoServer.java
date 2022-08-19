import java.io.*;
import java.net.*;

class EchoServer {
	public static void main(String[] args) {
		System.out.println("EchoServer started.");

		try {
			ServerSocket serverSocket = new ServerSocket(7777);
			Socket clientSocket = serverSocket.accept();

			System.out.println("Connected to port: " + clientSocket.getLocalPort());

			BufferedReader in = new BufferedReader(new InputStreamReader(clientSocket.getInputStream()));
			PrintWriter out = new PrintWriter(new OutputStreamWriter(clientSocket.getOutputStream()));

			out.println("Hello! This is Java EchoServer. Enter BYE to exit.");
			out.flush();

			for (;;) {
				String str = in.readLine();

				if (str == null) {
					break;
				} else {
					// write (send) back to the client whatever was received
					// adding the Echo string in front of it
					out.println("Echo: " + str);
					out.flush();
					System.out.println("Received from Client: " + str);

					if (str.trim().equals("BYE"))
						break;
				}
			}
			
			clientSocket.close();
			serverSocket.close();
		} catch (Exception e) {
			System.out.println("Error: " + e);
		}
		System.out.println("EchoServer stopped.");
	}
}