import java.util.Arrays;

public class Palindrome {
    public static boolean isPalindrome(char[] arg){

        // Create two stacks
        Stack ordered = new Stack(arg.length);
        Stack reverse = new Stack(arg.length);

        // Save the original ordered char array
        for (char c : arg) {
            ordered.push(c);
        }

        for(char c: arg){
            if( c != ordered.pop()) {
                return false;
            }
        }
        return true;

//        // Create a reverse ordered char array
//        for(int j = 0; j < arg.length; j++){
//            reverse.push(ordered.pop());
//        }
//
//        // Use Arrays.equals() to compare char arrays
//        return Arrays.equals(ordered.getCharArr(), reverse.getCharArr());

    }

    public static void main(String[] args){
        int i = 0;

        // loop through all the command lind arguments
        for(String s : args){
            // replaces all the characters including spaces that are not alphanumeric to "" then change the string
            // to lower case and converts to char array
            char[] letters = args[i].replaceAll("[^a-zA-Z\\d]", "").toLowerCase().toCharArray();
            System.out.println("Is \"" + s + "\" a palindrome phrase?");
            System.out.println(isPalindrome(letters));
            i++;
        }
    }
}

