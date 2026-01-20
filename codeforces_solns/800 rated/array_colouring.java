// if all elements are odd => yes : as we can sum up the half half and they'd be of same parity
// example: [1, 7]
// colour 1 as red and 7 as blue
// both are odd, and different coloured so valid
// example: [1, 3, 7, 5]
// colour 1, 3 as red and 7,5 as blue
// 4 and 12 is the sum, same parity and different colours
// sample applies when all elements are even
// so answer is YES, when the sums of blue and red are odd and odd, even and even, but not odd and even or even and odd
// odd number + odd number = even
// even + even = even
// boils down to number of odd numbers

// if we odd number of odd numbers, then the parity will change
// we must have even number of odd numbers, so that we can equally put them in subsets, and the parity will be same

// example: [1, 2, 3, 7]
// number of odds : 3
// 1+2=3, 7+3=10, different parity
// 1+3=4, 2+7=9, different parity
// 1+7=8, 2+3=5, different parity
// 1, 2+3+7=12, different parity

import java.util.Scanner;

public class array_colouring {
    public static void main(String[] args) {
        Scanner scanner = new Scanner(System.in);
        int t = scanner.nextInt();
        while (t-- > 0) {
            int n = scanner.nextInt();
            int[] a = new int[n];
            for (int i = 0; i < n; i++) {
                a[i] = scanner.nextInt();
            }

            int countOfOdd = 0;
            for (int i = 0; i < n; i++) {
                if (a[i] % 2 == 1) {
                    countOfOdd++;
                }
            }

            if (countOfOdd % 2 == 1) {
                System.out.println("NO");
            } else {
                System.out.println("YES");
            }
        }
        scanner.close();
    }
}

/*
 * Time Complexity (TC): O(n) = O(50)
 * Space Complexity (SC): O(n) = O(50)
 */