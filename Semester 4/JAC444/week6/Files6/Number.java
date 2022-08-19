//Let us suppose that we want to work with odd and positive byte values taken from the command line,
//we have created two Exception classes and the Number class to do so:

class ByteNegativeException extends Exception {

	public ByteNegativeException(String msg) {
		super(msg);
	}
}

class ByteEvenException extends Exception {

	public ByteEvenException(String msg) {
		super(msg);
	}
}

public class Number {

	public static void main(String[] args) {

		byte value = Byte.parseByte(args[0]);
		try {
			if (value < 0)
				throw new ByteNegativeException("negative value");
			if (value % 2 == 0)
				throw new ByteEvenException("even value");
			System.out.println("The input value is in the correct range, neither negative nor even");
		} catch (ByteNegativeException | ByteEvenException e) {
			System.out.println(e.getMessage());
		}
		
	}
}