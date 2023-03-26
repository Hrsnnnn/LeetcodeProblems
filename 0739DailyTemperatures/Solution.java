import java.util.Stack;

import javax.naming.spi.DirStateFactory.Result;

public class Solution {
    public int[] dailyTemperatures(int[] temperatures) {
        int[] res = new int[temperatures.length];
        Stack<Integer> st = new Stack<>();
        for(int i=0;i<temperatures.length;i++) {
            while(!st.empty() && temperatures[st.peek()] < temperatures[i]) {
                int p = st.pop();
                res[p] = i - p;
            }
            st.push(i);
        }
        return res;
    }
}
