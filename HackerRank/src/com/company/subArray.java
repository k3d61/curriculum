package com.company;

import java.util.Scanner;

public class subArray {


    private static final Scanner scanner = new Scanner(System.in);

    public static void main(String[] args) {

        int N = scanner.nextInt();
        scanner.nextLine();
        String[] line = scanner.nextLine().split(" ");

        int[] array = new int[N];

        for (int i = 0 ; i < N ; i++) {
            array[i] = Integer.parseInt(line[i]);
        }

        int output = 0;
        for (int i = 0 ; i < N ; i++){
            int sum = 0;
            for (int j = i ; j < N ; j++){
                sum = sum + array[j];

                if (sum < 0){
                    output ++;
                }
            }
        }
        System.out.println(output);
    }
}



/* HackerRank : https://www.hackerrank.com/challenges/java-negative-subarray/problem?h_r=next-challenge&h_v=zen
    private static final Scanner scanner = new Scanner(System.in);

    public static void main(String[] args) {

        int N = scanner.nextInt();
        scanner.nextLine();
        String[] line = scanner.nextLine().split(" ");

        int[] array = new int[N];

        for (int i = 0 ; i < N ; i++) {
            array[i] = Integer.parseInt(line[i]);
        }

        int output = 0;
        for (int i = 0 ; i < N ; i++){
            int sum = 0;
            for (int j = i ; j < N ; j++){
                sum = sum + array[j];

                if (sum < 0){
                    output ++;
                }
            }
        }
        System.out.println(output);
    }
*/
