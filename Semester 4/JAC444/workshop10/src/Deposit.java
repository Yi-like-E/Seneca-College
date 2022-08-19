class Deposit extends Thread {
    private BankAccount depositAccount;
    private String[] currency;
    private double[] amount;

    public Deposit(BankAccount acc, String[] cur, double[] amt) {
        super("Deposit money process:\n");//naming thread
        this.depositAccount = acc;
        this.currency = cur;
        this.amount = amt;
    }

    @Override
    public void run() {
        for (int i = 0; i < currency.length; i++) {
            synchronized (depositAccount) {
                try {
                    Thread.sleep((int) (Math.random() * 3000));
                } catch (InterruptedException e) {
                    System.err.println(e);
                }
                depositAccount.deposit(currency[i], amount[i]);
            }
        }
    }
}
