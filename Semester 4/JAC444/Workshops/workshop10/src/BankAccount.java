class BankAccount {
    private String currency = "";
    private double balance = 0;
    private boolean toDeposit = true;

    private void setCurrency(String currency) {
        this.currency = currency;
    }

    private String getCurrency() {
        return currency;
    }

    private double getBalance() {
        return balance;
    }

    private void setBalance(double oBalance) {
        this.balance = oBalance;
    }

    synchronized public void deposit(String currency, double amount) {
        while (!this.toDeposit) {
            try {
                if (!this.getCurrency().equals("") && !this.getCurrency().equals(currency)) {
                    System.out.printf("%s \"currency does not match!\" current currency: %s - incoming currency: %s\n", Thread.currentThread().getName(), this.getCurrency(), currency);
                } else {
                    break;
                }
                wait();
            } catch (InterruptedException e) {
                e.printStackTrace();
            }
        }
        this.setBalance(this.getBalance() + amount);
        this.setCurrency(currency);
        System.out.printf("%s deposited %s %s - balance: %s\n", Thread.currentThread().getName(), amount, currency, this.getBalance());
        this.toDeposit = false;// done deposited, allows next deposit or withdraw process to execute
        notify();//tell other processes that shared bank account is ready to use
    }

    synchronized public void withdraw(double withdrawAmount) {
        //if hasToDeposit flag is on, it means you are not ready to withdraw
        while (this.toDeposit) {
            try {
                System.out.printf("%s \"No money in the account, please wait for deposit!\"\n", Thread.currentThread().getName());
                wait();
            } catch (InterruptedException e) {
                e.printStackTrace();
            }
        }
        //program instruction reach to this point only if hasToDeposit = false
        // which means there is at least 1 completed deposit process -> we have money to withdraw
        if (this.getBalance() > 0) {
            this.setBalance(this.getBalance() - withdrawAmount);//balance - 1
        }
        if (this.getBalance() == 0) {
            this.setCurrency(""); //currency goes blank
            this.toDeposit = true; //after withdraw all money
        }
        System.out.printf("%s withdrew %s %s - balance: %s\n", Thread.currentThread().getName(), withdrawAmount, this.getCurrency(), this.getBalance());
        notify(); //tell deposit process it is good to go
    }
}
