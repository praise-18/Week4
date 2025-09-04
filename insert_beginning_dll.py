class Node:
    def __init__(self, data):
        self.data = data
        self.prev = None
        self.next = None

def insert_at_beginning(head, data):
    newn = Node(data)
    newn.next = head
    if head:
        head.prev = newn
    return newn

def print_list(head):
    cur = head
    while cur:
        print(cur.data, end=" ")
        cur = cur.next
    print()

if __name__ == "__main__":
    head = None
    head = insert_at_beginning(head, 30)
    head = insert_at_beginning(head, 20)
    head = insert_at_beginning(head, 10)
    print("Doubly linked list after inserts at beginning:", end=" ")
    print_list(head)
