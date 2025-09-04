class Node:
    def __init__(self, data):
        self.data = data
        self.next = None

def insert_into_cll(head, data):
    newn = Node(data)
    if not head:
        newn.next = newn
        return newn
    cur = head
    while cur.next != head:
        cur = cur.next
    cur.next = newn
    newn.next = head
    return head

def print_cll(head):
    if not head:
        print("Empty")
        return
    cur = head
    while True:
        print(cur.data, end=" ")
        cur = cur.next
        if cur == head:
            break
    print()

if __name__ == "__main__":
    head = None
    head = insert_into_cll(head, 1)
    head = insert_into_cll(head, 2)
    head = insert_into_cll(head, 3)
    print("Circular Linked List:", end=" ")
    print_cll(head)
