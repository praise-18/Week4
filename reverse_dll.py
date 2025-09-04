class Node:
    def __init__(self, data):
        self.data = data
        self.prev = None
        self.next = None

def push(head, data):
    newn = Node(data)
    newn.next = head
    if head:
        head.prev = newn
    return newn

def reverse_dll(head):
    cur = head
    temp = None
    while cur:
        temp = cur.prev
        cur.prev = cur.next
        cur.next = temp
        head = cur
        cur = cur.prev
    return head

def print_list(head):
    cur = head
    while cur:
        print(cur.data, end=" ")
        cur = cur.next
    print()

if __name__ == "__main__":
    head = None
    for v in [5,4,3,2,1]:
        head = push(head, v)
    print("Original:", end=" ")
    print_list(head)
    head = reverse_dll(head)
    print("Reversed:", end=" ")
    print_list(head)
