public class Person {
    public String name;
    private double givingAmount;
    private double owesAmount;

    public Person(String name) {
        this.name = name;
    }

    public void addMoney(double amount) {
        owesAmount += amount;
    }

    public void updateGivingAmount(double amount) {
        givingAmount += amount;
    }

    public String getDueList() {
        if (givingAmount > owesAmount) {
            return new String(name + " gives " + (givingAmount - owesAmount));
        } else if (givingAmount < owesAmount) {
            return new String(name + " gets " + (owesAmount - givingAmount));
        } else {
            return "";
        }
    }
}
