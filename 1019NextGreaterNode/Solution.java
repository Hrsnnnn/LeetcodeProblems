import java.util.Stack;

class ListNode {
    public int val;
    public ListNode next;
    ListNode() {}
    ListNode(int val) { this.val = val; }
    ListNode(int val, ListNode next) { this.val = val; this.next = next; }
}

public class Solution {
    public static class MyEntry {
        public int index;
        public int val;
        public MyEntry(int val, int index) {
            this.index = index;
            this.val = val;
        }
    }
    public static void main(String[] args) {
        System.out.print("this is nothing\n");
        int[] input = {1, 6, 3, 2, 5, 4};
        ListNode l = new ListNode();
        ListNode curr = l;

        for(int i=0;i<input.length;i++) {
            curr.val = input[i];
            curr.next = new ListNode();
            System.out.println(curr.val);
            curr = curr.next;
        }

        int[] res = nextLargerNodes(l);
        System.out.println("this is result:");

        for (int i=0;i<input.length;i++) {
            System.out.println(res[i]);
        }

        // for(int i=0;i<input.length;i++) {
        //     if(l == null) {
        //         System.out.println("this is null");
        //         continue;
        //     }
        //     System.out.println(l.val);
        //     l = l.next;
        // }
        
    }
    public static int[] nextLargerNodes(ListNode head) {
        int[] ret = new int[100];
        ListNode curr = head;
        int i = 0;
        
        Stack<MyEntry> st = new Stack<>();
        for(;curr!=null;) {
            while(!st.empty() && curr != null) {
                if(st.peek().val < curr.val) {
                    //System.out.println("peeking: " + st.peek().val + " " + st.peek().index);
                    MyEntry entr = st.pop();
                    ret[entr.index] = curr.val;
                    Display(ret, 5);
                }
                else {
                    st.push(new MyEntry(curr.val, i));
                    //System.out.println("pushing: " + st.peek().val + " " + st.peek().index);
                    i = i + 1;
                    curr = curr.next;
                }
            }
            if(st.empty()) {
                st.push(new MyEntry(curr.val, i));
                //System.out.println("empty: " + st.peek().val + " " + st.peek().index);
                i = i + 1;
                curr = curr.next;
            }
        }

        return ret;
    }

    public static void Display(int[] a, int length) {
        for(int i=0;i<length;i++) {
            System.out.print(a[i] + " ");
        }
        System.err.println();
    }

    static void set(int[] array, int val, int start, int end) {
        for (int i=start;i<end;i++) {
            array[i] = val;
        }
    }
}