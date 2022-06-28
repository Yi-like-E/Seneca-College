public class Stack {
    private char[] arr;
    private int pushCnt;
//    private int popCnt;

    //Default constructor
    Stack(){
        pushCnt = 0;
//        popCnt = 0;
    }

    // Parameterized constructor which creates a new char array with a size
    // and assign a value to popCnt
    Stack(int size){
        arr = new char[size];
//        popCnt = size;
    }

    public void push(char c){
        arr[pushCnt] = c;
        pushCnt++;
    }

    public char pop(){
//        popCnt--;
//        return arr[popCnt];
        pushCnt--;
        return arr[pushCnt];
    }

    // Return the arr field inside Stack class
    public char[] getCharArr(){

        return this.arr;
    }
}
