/*	
    CS 3342 - Programming Languages
    Sample program for homework 2
    Regular Expression - DFA
	
*/

import java.io.*;
import java.lang.String;

public class HW2_RegExp_Sample {
    public static void main(String argv[]) throws IOException {

        File file = new File("/Users/davidjiang/ProLang/hw2/test_sample.txt");

        BufferedReader br = new BufferedReader(new FileReader(file));

        String st;
        int line_num = 0;
        while ((st = br.readLine()) != null) {
            line_num++;
            String mystring = "(a|b)cd*";
            String mystring2 = "a(bc)*d";
            System.out.printf("This is line %d    :  ", line_num);
            System.out.println(st);
            System.out.println(" ********* This is for the first RE - " + mystring);
            String[] parts = st.split(" ");
            for (int i = 0; i < parts.length; i++) {
                String result = processRE(parts[i], mystring);
                System.out.println("      From main :  " + result + " - " + parts[i]);
            }
            System.out.println(" ********* This is for the second RE - " + mystring2);
            System.out.println(st);
            String[] part = st.split(" ");
            for (int i = 0; i < part.length; i++) {
                String result = processRE(part[i], mystring2);
                System.out.println("      From main :  " + result + " - " + parts[i]);
            }
        }
    }

    static String processRE(String in_str, String mystring) {
        //This is for RE - ab*c
        int i = 0;
        System.out.println("RE is:" + mystring + " & Input string is :  " + in_str);
        if (mystring == "(a|b)cd*") {
            if (in_str.length() == 0) {
                return "Reject";
            }
            if (in_str.length() == 1) {
                if (in_str.charAt(0) == 'a' || in_str.charAt(0) == 'b') {
                    return "Accept";
                } else {
                    return "Reject";
                }
            }
            if (in_str.length() == 2) {
                if (in_str.charAt(0) == 'a' || in_str.charAt(0) == 'b') {
                    if (in_str.charAt(1) == 'c') {
                        return "Accept";
                    } else {
                        return "Reject";
                    }
                } else {
                    return "Reject";
                }
            }
            if (in_str.length() > 2) {
                if (in_str.charAt(0) == 'a' || in_str.charAt(0) == 'b') {
                    if (in_str.charAt(1) == 'c') {
                        for (i = 2; i < in_str.length(); i++) {
                            if (in_str.charAt(i) != 'd') {
                                return "Reject";
                            }
                        }
                        return "Accept";
                    } else {
                        return "Reject";
                    }
                } else {
                    return "Reject";
                }
            }
        }  else if (mystring == "a(bc)*d") {
            if (in_str.length() == 0) {
                return "Reject";
            }
            if (in_str.length() == 1) {
                if (in_str.charAt(0) == 'a') {
                    return "Accept";
                } else {
                    return "Reject";
                }
            }
            if (in_str.length() == 2) {
                if (in_str.charAt(0) == 'a') {
                    if (in_str.charAt(1) == 'd') {
                        return "Accept";
                    } else {
                        return "Reject";
                    }
                } else {
                    return "Reject";
                }
            }
            if (in_str.length() > 2) {
                if (in_str.charAt(0) == 'a') {
                    if (in_str.charAt(1) == 'b'&& in_str.charAt(2) == 'c' && in_str.charAt(in_str.length()-1) == 'd') {
                        return "Accept";
                    } else {
                        return "Reject";
                    }
                } else {
                    return "Reject";
                }
            }
        } else {
            return "Reject";
        }
        return "Reject";
    }
}
