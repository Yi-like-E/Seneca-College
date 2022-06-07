public class NestedForLoops {
    public static void main(String[] args) {
        final int ROWS = 8; // Total rows of the output
        int spaces = 29; // Spaces needed to create the triangular output

        for(int i = 1; i <= ROWS; i++){
            int base = 2;
            int val = 1;

            // for loop to print the decreasing space for each row
            for(int j = 1; j <= spaces; j++){
                System.out.print(" ");
            }

            // determine how many spaces needed on each row
            if(i < 4){
                spaces-=3;
            } else{
                spaces-=4;
            }

            // start of the output
            System.out.print(val);

            // for loop to calculate the value (power of 2 with a base of 2) up to the midpoint of each row
            for(int power = 0; power < i - 1; power++){
                val *= base;
                System.out.print("  "+val);
            }
            System.out.print("  ");

            // for loop for the remaining value after the midpoint of each row
            for(int power = 1; power < i; power++){
                val /= base;
                System.out.print(val+"  ");
            }
            System.out.println();
        }
    }
}

