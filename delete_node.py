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

def delete_node(head, del_node):
    if not head or not del_node:
        return head
    if head == del_node:
        head = del_node.next
    if del_node.next:
        del_node.next.prev = del_node.prev
    if del_node.prev:
        del_node.prev.next = del_node.next
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

    cur = head
    while cur and cur.data != 3:
        cur = cur.next
    head = delete_node(head, cur)
    print("After deleting 3:", end=" ")
    print_list(head)

    head = delete_node(head, head)
    print("After deleting head:", end=" ")
    print_list(head)
