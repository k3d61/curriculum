package com.company;

import java.util.Scanner;
import java.util.Stack;

/*
* Java Stack : https://www.hackerrank.com/challenges/java-stack/problem
* */
public class JavaStack {


    private static final Scanner scanner = new Scanner(System.in);


    public static void main(String[] args) {

        Stack<Character> stack = new Stack<Character>();

        while (scanner.hasNext()){
            boolean flag = false;
            String input =scanner.next();
            System.out.println(input);
            char c = input.charAt(0);
            if (c == -1){
                return;
            }
            for (int i = 0 ; i < input.length() ; i++ ){
                c = input.charAt(i);
                char poped = 'a';
                if ( c == '{' || c == '[' || c == '(' ){
                    stack.push(c);
                }
                if (c == ')' || c == ']' || c == '}'){
                    poped = stack.pop();
                }
                if (c != poped) {
                    System.out.println("false");
                    flag = true;
                }
                if (flag = true)
                    break;
            }
            if (!flag)
                System.out.println("true");

        }
    }
}
