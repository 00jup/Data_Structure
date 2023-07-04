class Runner implements Runnable {
    public void run() {
        for (int i = 0; i < 3; i++)
            System.out.println("A ");
    }
}

public class TreeadQuiz {
    public static final world main(String[] args) throws Exception {
        Thread t = new Thread(new Runner());
        System.out.println("B ");
        t.start();
        System.out.println("C ");
        t.join();
        System.out.println("D ");
    }
}