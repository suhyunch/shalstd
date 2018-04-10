/*
 * 디저트 카페
 * https://www.swexpertacademy.com/main/code/problem/problemDetail.do?contestProbId=AV5VwAr6APYDFAWu&categoryId=AV5VwAr6APYDFAWu&categoryType=CODE&&&
 */

package study;

import java.util.Scanner;

public class swea2105 {
   static int N;

   public static void main(String[] args) {
      Scanner sc = new Scanner(System.in);
      int T = sc.nextInt();
      for (int t = 1; t <= T; t++) {
         N = sc.nextInt();
         int[][] dessert = new int[N + 1][N + 1];
         for (int i = 1; i <= N; i++) {
            for (int j = 1; j <= N; j++) {
               dessert[i][j] = sc.nextInt();
               // // System.out.print(dessert[i][j]);
            }
         }
          System.out.println("#" + t + " " + swea2105(dessert));
      }

   }

   public static int swea2105(int[][] dessert) {
      int[] numbers;
      int C = -1;

      for (int i = 1; i <= N; i++) {
         for (int j = 1; j <= N; j++) {
            for (int l = 1; l <= N; l++) {
               loop: for (int r = 1; r <= N; r++) {
                  // // System.out.println("(i, j, l, r): (" + i + ", " + j + ", " + l + ", " + r
                  // +
                  // ")");
                  if (checkRange(i, j) && checkRange(i + r, j + r) && checkRange(i + l + r, j - l + r)
                        && checkRange(i + l, j - l))
                     // // System.out.println("- pass - : (" + i + ", " + j + ")" + "(" + (i + r) +
                     // ", "
                     // + (j + r)
                     // + ")" + "(" + (i + l + r) + ", " + (j - l + r) + ")" + "(" + (i + l) + ", "
                     // + (j - l) + ")");
                     numbers = new int[101]; // visited
                     int temp = 0; // 현재 디저트 개수

                     // // System.out.println("#1: (" + i + ", " + j + ") -> (" + (i + r) + ", " + (j
                     // +
                     // r) + ")");
                     for (int x = i, y = j; x < i + r && y < j + r; x++, y++) {
                        if (++numbers[dessert[x][y]] > 1)
                           continue loop;
                        // System.out.println(
                        // "(" + x + ", " + y + "): " + dessert[x][y] + ": " + numbers[dessert[x][y]]);
                        temp++;
                     }

                     // System.out.println("#2: (" + (i + r) + ", " + (j + r) + ") -> (" + (i + l +
                     // r) + ", "
                     // + (j - l + r) + ")");
                     for (int x = i + r, y = j + r; x < i + l + r && y > j - l + r; x++, y--) {
                        if (++numbers[dessert[x][y]] > 1) {
                           // System.out.println("----------------------------");
                           continue loop;
                        }
                        // System.out.println(
                        // "(" + x + ", " + y + "): " + dessert[x][y] + ": " + numbers[dessert[x][y]]);
                        temp++;
                     }

                     // System.out.println("#3: (" + (i + l + r) + ", " + (j - l + r) + ") -> (" + (i
                     // + l) + ", "
                     // + (j - l) + ")");
                     for (int x = i + l + r, y = j - l + r; x > i + l && y > j - l; x--, y--) {
                        if (++numbers[dessert[x][y]] > 1)
                           continue loop;
                        // System.out.println(
                        // "(" + x + ", " + y + "): " + dessert[x][y] + ": " + numbers[dessert[x][y]]);
                        temp++;
                     }

                     // System.out.println("#4: (" + (i + l) + ", " + (j - l) + ") -> (" + i + ", " +
                     // j + ")");
                     for (int x = i + l, y = j - l; x > i && y < j; x--, y++) {
                        if (++numbers[dessert[x][y]] > 1)
                           continue loop;
                        // System.out.println(
                        // "(" + x + ", " + y + "): " + dessert[x][y] + ": " + numbers[dessert[x][y]]);
                        temp++;
                     }
                     // System.out.println(temp);
                     C = Math.max(C, temp);
                  }
               }
            }
         }
      }
      return C;

   }

   public static boolean checkRange(int x, int y) {
      return x >= 1 && y >= 1 && x <= N && y <= N;
   }
}
