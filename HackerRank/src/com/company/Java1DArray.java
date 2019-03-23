package com.company;

/*
* https://www.hackerrank.com/challenges/java-1d-array/problem
* */

import java.util.Scanner;

public class Java1DArray {

    public static boolean toPrint = false;
    private static final Scanner scanner = new Scanner(System.in);
    public static int[] array;
    public static int increment;
    public static int m;
    public static boolean gamePlay(int i){

        if ( i < 0 || array[i] != 0 ) {
            if (toPrint)System.out.println("two");
            return false;
        }
        if (toPrint)System.out.println("in gameplay = " + i);
        if (i == m-1 || i+increment > m-1 ) {
            if (toPrint)System.out.println("one");
            return true;
        }
        if (toPrint)System.out.println("three");
        array[i] = 1;
        return gamePlay(i+1) || gamePlay(i-1) || gamePlay(i+increment)  ;
    }

    public static void main(String[] args) {

        int N = scanner.nextInt();

        while (N>0){

            m = scanner.nextInt();
            increment = scanner.nextInt();
            scanner.nextLine();
            String[] line = scanner.nextLine().split(" ");

            array = new int[m];

            for (int i = 0 ; i < m ; i++) {
                array[i] = Integer.parseInt(line[i]);
                if (toPrint)System.out.print(array[i] + " ");
            }
            if (gamePlay(0))
                System.out.println("YES");
            else
                System.out.println("NO");

            if (toPrint)System.out.println("");

            N--;
        }

    }
}
/*
   public static boolean canWin(int leap, int[] game) {
        // Return true if you can win the game; otherwise, return false.
    }

    public static void main(String[] args) {
        Scanner scan = new Scanner(System.in);
        int q = scan.nextInt();
        while (q-- > 0) {
            int n = scan.nextInt();
            int leap = scan.nextInt();

            int[] game = new int[n];
            for (int i = 0; i < n; i++) {
                game[i] = scan.nextInt();
            }

            System.out.println( (canWin(leap, game)) ? "YES" : "NO" );
        }
        scan.close();
    }

* */