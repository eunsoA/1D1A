/**
 * Definition for singly-linked list.
 * function ListNode(val) {
 *     this.val = val;
 *     this.next = null;
 * }
 */

/**
 * @param {ListNode} head
 * @return {boolean}
 */
var hasCycle = function(head) {
    let seen = new Set();
    while(head!=null){
        if(seen.has(head)){
            return true;
        }
        seen.add(head);
        head = head.next;
    }
    return false;
};