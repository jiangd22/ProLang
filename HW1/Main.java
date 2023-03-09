import java.util.regex.Matcher;
import java.util.regex.Pattern;


public class Main {
    public static void main(String[] args) {
        System.out.println("Hello world!");
        System.out.println("Matched 1: " + Pattern.matches("[789][0-9]{9}", "99530389490"));
        System.out.println("Matched 2: " + Pattern.matches("[789][0-9]", "895"));
        System.out.println("Matched 3: " + Pattern.matches("[a-d[m-p]]", "p"));
        System.out.println("Matched 4: " + Pattern.matches("[a-d][m-p]", "p"));
        System.out.println("Matched 5: " + Pattern.matches("[a-d][m-p]", "co"));
        System.out.println("Matched 6: " + Pattern.matches(".s", "effg"));
        System.out.println("Matched 7: " + Pattern.matches("...m", "ertm"));
        System.out.println("Matched 8: " + Pattern.matches("[^abc]","o"));
        System.out.println("Matched 9: " + Pattern.matches("[\\d]", "98"));

        System.out.print("\n");

        System.out.println("Matched 10: " + Pattern.matches("[\\d]{2}", "98"));
        System.out.println("Matched 11: " + Pattern.matches("[\\D]", "a"));
        System.out.println("Matched 12: " + Pattern.matches("b?a", "a"));
        System.out.println("Matched 13: " + Pattern.matches("colo*r", "color"));
        System.out.println("Matched 14: " + Pattern.matches("[789][0-9]{4}", "99530"));
        System.out.println("Matched 15: " + Pattern.matches("[789]{2}[0-5]{3}", "89530"));

        Pattern p = Pattern.compile("\\d{3}");
        Matcher m = p.matcher("332");
        System.out.println("Find 1: " + m.matches());

        p = Pattern.compile("[^abc]");
        m = p.matcher("123The ");
        System.out.println("Find 2: " + m.find());

        p = Pattern.compile("[\\w]");
        m = p.matcher("The color green ");
        System.out.println("Find 3: " + m.find());




    }
}