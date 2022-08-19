import java.util.*;

public class StrangeBank {
    public static void main(String[] args) {
        double[] balance = {1, 1, 1, 1, 1, 1};
        String[] currency = {"Dollar(s)", "Euro(s)", "Euro(s)", "Pound(s)", "Pound(s)", "Pound(s)"};

        BankAccount sharedBankAcc = new BankAccount();
        Deposit dep = new Deposit(sharedBankAcc, currency, balance);
        Withdraw wit = new Withdraw(sharedBankAcc, balance);
        dep.start();
        wit.start();
    }
}

