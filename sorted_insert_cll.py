class Node:
    def __init__(self, data):
        self.data = data
        self.next = None

def sorted_insert_cll(head, data):
    newn = Node(data)
    if not head:
        newn.next = newn
        return newn
    cur = head
    if data <= head.data:
        while cur.next != head:
            cur = cur.next
        cur.next = newn
        newn.next = head
        return newn
    else:
        while cur.next != head and cur.next.data < data:
            cur = cur.next
        newn.next = cur.next
        cur.next = newn
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
    head = sorted_insert_cll(head, 10)
    head = sorted_insert_cll(head, 5)
    head = sorted_insert_cll(head, 20)
    head = sorted_insert_cll(head, 15)
    print("Sorted circular list:", end=" ")
    print_cll(head)
