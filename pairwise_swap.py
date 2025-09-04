class Node:
    def __init__(self, data):
        self.data = data
        self.next = None

def push(head, data):
    newn = Node(data)
    newn.next = head
    return newn

def pairwise_swap(head):
    cur = head
    while cur and cur.next:
        cur.data, cur.next.data = cur.next.data, cur.data
        cur = cur.next.next
    return head

def print_list(head):
    while head:
        print(head.data, end=" ")
        head = head.next
    print()

if __name__ == "__main__":
    head = None
    for i in range(5,0,-1):
        head = push(head, i)
    print("Original:", end=" ")
    print_list(head)
    head = pairwise_swap(head)
    print("After pairwise swap:", end=" ")
    print_list(head)
