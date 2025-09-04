class Node:
    def __init__(self, data):
        self.data = data
        self.next = None  # right pointer
        self.down = None  # down pointer

def merge(a, b):
    if not a: return b
    if not b: return a
    if a.data < b.data:
        a.down = merge(a.down, b)
        a.next = None
        return a
    else:
        b.down = merge(a, b.down)
        b.next = None
        return b

def flatten(root):
    if not root or not root.next:
        return root
    root.next = flatten(root.next)
    root = merge(root, root.next)
    return root

def print_flattened(head):
    cur = head
    while cur:
        print(cur.data, end=" ")
        cur = cur.down
    print()

if __name__ == "__main__":
    # build sample
    head = Node(5)
    head.down = Node(7)
    head.down.down = Node(8)
    head.down.down.down = Node(30)

    head.next = Node(10)
    head.next.down = Node(20)

    head.next.next = Node(19)
    head.next.next.down = Node(22)
    head.next.next.down.down = Node(50)

    head.next.next.next = Node(28)
    head.next.next.next.down = Node(35)
    head.next.next.next.down.down = Node(40)
    head.next.next.next.down.down.down = Node(45)

    flat = flatten(head)
    print("Flattened list:", end=" ")
    print_flattened(flat)
