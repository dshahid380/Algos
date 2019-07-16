
//main method is hidden, don't write it again.
import java.io.*;
import java.math.*;
import java.security.*;
import java.text.*;
import java.util.*;
import java.util.concurrent.*;
import java.util.regex.*;

class Solution {
    
    public static List<String> reformatDate(List<String> dates) {
        
        HashMap<String, String> month = new HashMap<>();
        month.put("Jan","01");month.put("Feb","02");month.put("Mar","03");
        month.put("Apr","04");month.put("May","05");month.put("Jun","06");
        month.put("Jul","07");month.put("Aug","08");month.put("Sep","09");
        month.put("Oct","10");month.put("Nov","11");month.put("Dec","12");
        
        List<String> res = new ArrayList<String>();
        for(int i=0; i<dates.size(); i++) {
            
            String str = dates.get(i), ans="";
            if(str.length()==12){
                ans = str.substring(8,12)+"-"+month.get(str.substring(4,7))+"-"
            }            
        }
       return result;

    }
}

