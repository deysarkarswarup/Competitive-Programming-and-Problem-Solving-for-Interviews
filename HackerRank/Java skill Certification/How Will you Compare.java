/*
How Will You Compare? Write a Comparator class with the following 3 overloaded compare methods:
1. boolean compare(int a, int b): Return true if int a = int b, otherwise return false. 
2. boolean compare(string a, string b): Return true if string a = string b, otherwise return false. 
3. boolean compare(int[] a, int[] b): Return true if both of the following conditions hold true: 
O Arrays a and b are of equal length. . For each indexi (where 0 si<lal, 16), a[i] = b[i]. Otherwise, return false. 
Note: For C++, both parameters are of type Vector<int>, Constraints 
• For strings, 1 sal, lbl s 2000 
• For integers, 0 s a, b s 10000000 
• For integer arrays, 0 sal, b[ s 10 
Input Format for Custom Testing Input from stdin will be processed as follows and passed to the function. 
The first line contains an integer T, the number of test cases. Each of the next T sets of lines is in one of the following formats:
• The first line contains the integer + representing the comparison type (1, 2 or 3 for int, string or array comparison respectively). 
The next two lines contain strings a and b. The first line contains the integer 2 representing the overloaded function type. 
The next two lines contain integers a and b. The first line contains the integer 3-representing the overloaded function type.
The next three lines contain the following:
1. Two space-separated integers fan and Hom, the lengths of arrays a and b. 
2. A line of ta n space-separated integers a[i]. 
3. A line of Ho m space-separated integers b[i]. 
Sample Case 0 Sample Input 0 Pew we wм NNW STDIN Function ----- → T = 3 number of test cases. 
→ Comparison type 1 hello world → a= "hello world" hello world + b = "hello world" 
→ Comparison type 2 → a = 3 + b = 4 
→ Comparison type 3 + a[] size n=3 b[] size m=3 
→ a= [1, 2, 3] 1 2 3 → b = [1, 2, 3]
Sample Output 0 Same Different Same Explanation o There are 3 test cases:
conditie #t ь Output Explanation Test Case compari son type "hello "hello world" "Same" 
Both strings are the same. world" "Different The two integers are different (3 + 4). {1,2,3} {1,2,3} "Same" 
Both arrays have the same number of elements and each element a[i] = b[i] 
Sample Case 1 Sample Input 1 STDIN Function 4 → T = 2 number of test cases. 
→ Comparison type 3 → a[] size=3 b[] size=4 → a = [1, 2, 3] + b = [1, 2, 3, 4] 
→ Comparison type 1 1 2 3 1 2 3 4 alcan - lal ا ابا ب 11 با لیا | ایا11ابا ابا ااا ااااااااT1T1الباي بالا با {1,2,3} {1,2,3) 
"Same" element a[i] = b[i] Sample Case 1 Sample Input 1 - - - WN! w STDIN Function -------- → T = 2 number of test cases. 
→ Comparison type 3 3 4 + a[] size=3 b[] size=4 1 2 3 → a= [1, 2, 3] 1 2 3 4 + b = [1, 2, 3, 4] 
→ Comparison type 1 Hacker Rank → a = "Hacker Rank" HackerRank + b = "HackerRank" Sample Output 1 Different Different Explanation 1 
There are 2 test cases. compar Test Case ison type Output Explanation "Differen {1,2,3} {1,2,3,4} The arrays are different.
HackerRan hackerran "Differen 1 The two strings are different.
*/

import java.io.*;
import java.util.*;

/*Write your code here. DO NOT use access modifiers (e.g.: 'public') in your class declarations.*/
class Comparator{
    boolean compare(int a, int b){
        if(a==b){
            return true;
        }
        else{
            return false;
        }
    }
    boolean compare(String a, String b){
        if(a.equals(b)){
            return true;
        }
        else{
            return false;
        }
    }
    boolean compare(int []a, int []b){
        if(Arrays.equals(a,b)){
            return true;
        }
        else{
            return false;
        }
    }
}
class Solution {
    public static void main(String[] args) {
        Scanner scan = new Scanner(System.in);
        Comparator comp = new Comparator();
        
        int testCases = Integer.parseInt(scan.nextLine());
        while(testCases-- > 0){
            int condition = Integer.parseInt(scan.nextLine());
            switch(condition){
                case 1:
                    String s1=scan.nextLine().trim();
                    String s2=scan.nextLine().trim();
                    
                    System.out.println( (comp.compare(s1,s2)) ? "Same" : "Different" );
                    break;
                case 2:
                    int num1 = scan.nextInt();
                    int num2 = scan.nextInt();
                    
                    System.out.println( (comp.compare(num1,num2)) ? "Same" : "Different");
                    if(scan.hasNext()){ // avoid exception if this last test case
                        scan.nextLine(); // eat space until next line
                    }
                    break;
                case 3:
                    // create and fill arrays
                    int[] array1 = new int[scan.nextInt()];
                    int[] array2 = new int[scan.nextInt()];
                    for(int i = 0; i < array1.length; i++){
                        array1[i] = scan.nextInt();
                    }
                    for(int i = 0; i < array2.length; i++){
                        array2[i] = scan.nextInt();
                    }
                    
                    System.out.println( comp.compare(array1, array2) ? "Same" : "Different");
                    if(scan.hasNext()){ // avoid exception if this last test case
                        scan.nextLine(); // eat space until next line
                    }
                    break;
                default:
                    System.err.println("Invalid input.");
            }// end switch
        }// end while
        scan.close();
    }
}
