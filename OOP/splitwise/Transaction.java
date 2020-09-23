import java.util.ArrayList;

public class Transaction {
    private Person whoIsPaying;
    private double howMuchPaying;
    private ArrayList<Person> payingToWhom;

    public Transaction(Person whoIsPaying, ArrayList<Person> payingToWhom, double howMuchPaying) {
        this.whoIsPaying = whoIsPaying;
        this.payingToWhom = payingToWhom;
        this.howMuchPaying = howMuchPaying;
    }

    public void updateDueList() {
        whoIsPaying.addMoney(howMuchPaying);
        for (Person person : payingToWhom) {
            person.updateGivingAmount(howMuchPaying / payingToWhom.size());
        }
    }

    public String getDuesList() {
        String dueList = whoIsPaying.getDueList();
        for (Person person : payingToWhom) {
            if (!person.equals(whoIsPaying)) {
                dueList += person.getDueList();
            }
        }
        return dueList;
    }
}
