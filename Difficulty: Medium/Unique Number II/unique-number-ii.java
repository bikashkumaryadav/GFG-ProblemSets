//{ Driver Code Starts
// Initial Template for Java
import java.io.*;
import java.util.*;
import java.util.HashMap;


// } Driver Code Ends

class Solution {
    //check fir set bit
    public static boolean checkBit(int num, int pos) {
        return (num & (1 << pos)) != 0;
    }

    public int[] singleNum(int[] arr) {
        // Code here
        int n = arr.length;
        int[] ans = new int[2];
        int xor = 0;
        //finding xor for all array element
        for(int i=0; i < n; i++){
            xor = xor ^ arr[i];
        }
        //find any set bit position
        int pos = 0;
        for(int i = 0; i <= 31; i++){
            if(checkBit(xor, i)){
                pos = i;
                break;
            }
        }
        //making pair of set and unset pos bit
        int set = 0;
        int unset = 0;
        for(int i = 0; i < n; i++){
            if(checkBit(arr[i], pos)){
                set = set ^ arr[i]; 
            }else{
                unset = unset ^ arr[i];
            }
        }
        if(set < unset){
            ans[0] = set;
            ans[1] = unset;
        }else{
            ans[0] = unset;
            ans[1] = set;
        }
       return ans; 
    }
}


//{ Driver Code Starts.
public class Main {

    public static void main(String[] args) throws Exception {
        BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
        int t = Integer.parseInt(br.readLine());
        while (t-- > 0) {

            String line = br.readLine();
            String[] tokens = line.split(" ");

            // Create an ArrayList to store the integers
            ArrayList<Integer> array = new ArrayList<>();

            // Parse the tokens into integers and add to the array
            for (String token : tokens) {
                array.add(Integer.parseInt(token));
            }

            int[] arr = new int[array.size()];
            int idx = 0;
            for (int i : array) arr[idx++] = i;

            // int k = Integer.parseInt(br.readLine());
            // Create Solution object and find closest sum
            Solution ob = new Solution();
            int[] ans = ob.singleNum(arr);

            // Print the result as a space-separated string
            for (int num : ans) {
                System.out.print(num + " ");
            }
            System.out.println(); // New line after printing the results
            System.out.println("~");
        }
    }
}

// } Driver Code Ends