import java.net.*;

public class Local {
	public static void main(String[] args) {
		try {
			InetAddress myLocalHostAddress = InetAddress.getLocalHost();
			System.out.println("My host name is: " + myLocalHostAddress.getHostName());
			System.out.println("My host IP address is: " + myLocalHostAddress.getHostAddress());
		} catch (UnknownHostException e) {
			System.err.println("Could not determine local address.");
		}
	}
}
