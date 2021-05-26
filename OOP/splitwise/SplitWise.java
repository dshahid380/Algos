import java.util.ArrayList;
import java.util.HashMap;

public class SplitWise {
    private ArrayList<Person> persons;
    private ArrayList<Transaction> transactions;
    private HashMap<String, Person> allPeople = new HashMap<>();

    public SplitWise(ArrayList<Person> persons, ArrayList<Transaction> transactions) {
        this.persons = persons;
        this.transactions = transactions;
        for (Person person : persons) {
            allPeople.put(person.name, person);
        }
    }

    public String getAllExpensesForEachPerson() {
        String expensesForAll = "";
        for (Transaction transaction : transactions) {
            transaction.updateDueList();
        }
        for (Person person : persons) {
            expensesForAll += person.getDueList();
        }
        return expensesForAll;
    }
}

