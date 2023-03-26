import javax.swing.BorderFactory;

class ListNode {
    int val;
    ListNode next;
    ListNode(int val) { this.val = val; }
    ListNode(int val, ListNode next) { this.val = val; this.next = next; }
}

public class Solution {

    public static ListNode initList(int[] arr) {
        ListNode start = new ListNode(arr[0]);
        ListNode boat = start;
        for(int i=1; i<arr.length; i++) {
            boat.next = new ListNode(arr[i]);
            boat = boat.next;
        }
        return start;
    }

    public static void DisplayLinkedList(ListNode start) {
        ListNode boat = start;
        while(boat != null) {
            System.out.print(boat.val);
            System.out.print(", ");
            boat = boat.next;
        }
        System.out.println("");
    }

    public static ListNode middleNode(ListNode head) {
        ListNode anchor = head;
        ListNode boat = head;
        int length = 1;

        while(boat.next != null) {
            length += 1;
            boat = boat.next;
        }

        for(int i=0; i<length/2; i++) {
            anchor = anchor.next;
        }

        return anchor;

    }

    public static void main(String[] args) {
        var sol = new Solution();
        int[] arr = new int[]{1, 2, 3, 4, 5, 6};
        ListNode start = sol.initList(arr);
        sol.DisplayLinkedList(start);
        ListNode middle = sol.middleNode(start);
        sol.DisplayLinkedList(middle);
    }
}
