package com.company.kickstarter;


 import java.util.Arrays;
 import java.util.Scanner;

class FotballTeamTraining {


     public static int N;
     public static int P;
     public static int[] skills;
     public static boolean toPrint = false;

     private static final Scanner scanner = new Scanner(System.in);

    public static void main(String[] args) {


        int NT = scanner.nextInt();
        int counter =1;
        while (NT>0){

            N = scanner.nextInt();
            P = scanner.nextInt();
            scanner.nextLine();
            String[] line = scanner.nextLine().split(" ");

            skills = new int[N];

            for (int i = 0 ; i < N ; i++) {
                skills[i] = Integer.parseInt(line[i]);
                if (toPrint)System.out.print(skills[i] + " ");
            }
            if (toPrint)System.out.println("");

            Arrays.sort(skills);
            for (int i = 0 ; i < N ; i++) {
                if (toPrint)System.out.print(skills[i] + " ");
            }
            if (toPrint)System.out.println("");

            int sum = 0;
            for (int i = 0 ; i < P-1 ; i++ ){
                if (toPrint) System.out.println("--"+i+" P: "+P + " N: " + N + " : "+ sum);
                sum = sum + skills[P-1] - skills[i];
            }
            System.out.println("Case #"+ counter++ +": "+ sum);

            if (toPrint)System.out.println("");
            NT--;
        }
    return;
    }

}
