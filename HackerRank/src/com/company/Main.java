package com.company;

import java.io.*;
import java.math.*;
import java.security.*;
import java.text.*;
import java.util.*;
import java.util.concurrent.*;
import java.util.regex.*;
import java.util.Scanner;

public class Main {

    private static final Scanner scanner = new Scanner(System.in);

    public static void main(String[] args) {

        int[][] arrray = new int[6][6];

        for (int i = 0; i < 6; i++) {
            String[] row = scanner.nextLine().split(" ");

            for (int j = 0; j < 6; j++) {
                int item = Integer.parseInt(row[j]);
                arrray[i][j] = item;
            }
        }
        /*System.out.println("What you entered : ");
        for (int i = 0; i < 6; i++) {
            for (int j = 0; j < 6; j++) {
                System.out.print(arrray[i][j] + " ");
            }
            System.out.println();
        }*/
        int maxSum = 0;
        boolean flag = true;
        for (int i = 1; i < 5; i++) {
            for (int j = 1; j < 5; j++) {
                int sum = arrray[i-1][j-1] + arrray[i-1][j] + arrray[i-1][j+1] +
                                        arrray[i][j] +
                        arrray[i+1][j-1] +  arrray[i+1][j] +  arrray[i+1][j+1] ;

                if(sum > maxSum) {
                    maxSum = sum;
                } else if (flag == true) {
                    maxSum = sum;
                    flag = false;
                }
            }
        }
        System.out.println(maxSum);

    }
}

/* Take input from stdin
    Scanner scanner = new Scanner(System.in);
    int first  = scanner.nextInt();
    System.out.println(first);
*/
