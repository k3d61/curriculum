package com.company.kickstarter;

// https://codingcompetitions.withgoogle.com/codejam/round/0000000000051705/00000000000881da

import java.util.Arrays;
import java.util.Scanner;

public class Solution1 {


    private static final Scanner scanner = new Scanner(System.in);
    public static int N;
    public static int P;



    public static void main(String[] args) {

        boolean flag = false;

        int NT = scanner.nextInt();

        if (flag) System.out.println("--" + N);


        int iNT = 0;
        while (iNT < NT ){

            N = scanner.nextInt();
            if (flag) System.out.println("==" + N);

            String str = scanner.next();


            char[] str1 = str.toCharArray();

            for (int i = 0 ; i < str.length() ; i++){
                if (str1[i] == 'S')
                    str1[i] = 'E';
                else
                    str1[i] = 'S';
            }
            iNT++;

            System.out.print("\nCase #" + iNT + ": ");
            System.out.print(String.copyValueOf(str1));


        }
        return;
    }
}
