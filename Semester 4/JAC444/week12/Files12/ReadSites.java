import java.net.*;
import java.io.*;

public class ReadSites {
	public static void main(String[] args) {
		for (int i = 0; i < args.length; i++) {
			System.out.println("==================" +  args[i] + "=================");
			try {
				URL url = new URL("http://" + args[i]);
				
				InputStream is = url.openStream();
				InputStreamReader isr = new InputStreamReader(is);
				BufferedReader br = new BufferedReader(isr);
				
				String theLine;
				while ((theLine = br.readLine()) != null) {
					System.out.println(theLine);
				}
			} catch (MalformedURLException e) {
				System.err.println(e);
			} catch (IOException e) {
				System.err.println(e);
			}
		}
	}
}