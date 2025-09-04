class Node:
    def __init__(self, data):
        self.data = data
        self.next = None

def has_cycle(head):
    slow = fast = head
    while fast and fast.next:
        slow = slow.next
        fast = fast.next.next
        if slow == fast:
            return True
    return False

def is_circular_list(head):
    if not head:
        return True
    cur = head.next
    while cur and cur != head:
        cur = cur.next
    return cur == head

if __name__ == "__main__":
    head = Node(1)
    head.next = Node(2)
    head.next.next = Node(3)
    print("Has cycle?", has_cycle(head))
    print("Is structurally circular?", is_circular_list(head))

    # make circular
    tail = head
    while tail.next: tail = tail.next
    tail.next = head
    print("After making circular:")
    print("Has cycle?", has_cycle(head))
    print("Is structurally circular?", is_circular_list(head))
