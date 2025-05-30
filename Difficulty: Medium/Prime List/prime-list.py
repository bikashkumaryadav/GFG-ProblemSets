"""
Definition for singly Link List Node
class Node:
    def __init__(self,x):
        self.val=x
        self.next=None

"""

class Solution:
    def isPrime(self,n):
        primes=[True]*(n+1)
        primes[0]=False
        primes[1]=False
        i=2
        while i**2<=n:
            if primes[i]:
                for j in range(i**2,n+1,i):
                    primes[j]=False
            i+=1
        return primes
        
    def primeList(self, head):
        primes=self.isPrime(10000+10)
        curr=head
        while curr:
            p1,p2=curr.val,curr.val
            while p1>1 and primes[p1]==False:
                p1-=1
            while primes[p2]==False:
                p2+=1
            if primes[p1] and curr.val-p1<=p2-curr.val:
                curr.val=p1
            else:
                curr.val=p2
            curr=curr.next
        return head
        



#{ 
 # Driver Code Starts
class Node:

    def __init__(self, x):
        self.val = x
        self.next = None


def printList(node):
    while (node != None):
        print(node.val, end=" ")
        node = node.next
    print()


def inputList():

    val = [int(i) for i in input().strip().split()
           ]  #all data of linked list in a line
    head = Node(val[0])
    tail = head
    for i in range(1, len(val)):
        tail.next = Node(val[i])
        tail = tail.next
    return head


if __name__ == "__main__":
    t = int(input())
    for _ in range(t):

        head = inputList()

        obj = Solution()
        res = obj.primeList(head)

        printList(res)

        print("~")

# } Driver Code Ends