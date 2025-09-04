class Node:
    def __init__(self, data):
        self.data = data
        self.next = None

def get_count(head):
    c = 0
    while head:
        c += 1
        head = head.next
    return c

def get_intersection(head1, head2):
    c1 = get_count(head1)
    c2 = get_count(head2)
    d = abs(c1 - c2)
    longer = head1 if c1 > c2 else head2
    shorter = head2 if c1 > c2 else head1
    for _ in range(d):
        longer = longer.next
    while longer and shorter:
        if longer is shorter:
            return longer
        longer = longer.next
        shorter = shorter.next
    return None

if __name__ == "__main__":
    head1 = Node(3)
    head1.next = Node(6)
    head1.next.next = Node(9)
    head1.next.next.next = Node(15)
    head1.next.next.next.next = Node(30)

    head2 = Node(10)
    head2.next = head1.next.next.next  # intersection at 15

    res = get_intersection(head1, head2)
    if res:
        print("Intersection at node with data =", res.data)
    else:
        print("No intersection")
