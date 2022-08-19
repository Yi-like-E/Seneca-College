class Withdraw extends Thread {
    private BankAccount withdrawAccount;
    private double[] amount;

    public Withdraw(BankAccount acc, double[] money) {
        super("Friend withdraw money process:\n");
        this.withdrawAccount = acc;
        this.amount = money;
    }

    @Override
    public void run() {
        for (int i = 0; i < amount.length; i++) {
            synchronized (withdrawAccount) {
                try {
                    Thread.sleep((int) (Math.random() * 3000));
                } catch (InterruptedException e) {
                    System.err.println(e);
                }
                withdrawAccount.withdraw(amount[i]);
            }
        }
    }
}
