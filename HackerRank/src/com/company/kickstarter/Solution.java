package com.company.kickstarter;

//https://codingcompetitions.withgoogle.com/codejam/round/0000000000051705/0000000000088231

import java.util.Arrays;
import java.util.Scanner;

public class Solution {


    private static final Scanner scanner = new Scanner(System.in);
    public static int N;
    public static int P;



    public static void main(String[] args) {

        boolean flag = false;

        int NT = scanner.nextInt();

        int iNT = 0;
        while (iNT < NT ){


            N = scanner.nextInt();

            String str = Integer.toString(N);

            char[] no1 = str.toCharArray();
            char[] no2 = new char[no1.length];


            if (flag)System.out.println(no1);
            if (flag)System.out.println(no2);


            for ( int i = str.length() - 1 ; i > -1 ; i--){
                no2[i] = '0';
            }

            for ( int i = str.length() - 1 ; i > -1 ; i--){
                if ( no1[i] == '4' ){
                    no1[i] = '3';
                    no2[i] = '1';
                }
            }


            iNT++;

            System.out.print("\nCase #" + iNT + ": ");
            System.out.print(Integer.parseInt(String.copyValueOf(no1)));
            System.out.print(" ");
            System.out.print(Integer.parseInt(String.copyValueOf(no2)));



        }
        return;
    }
}
