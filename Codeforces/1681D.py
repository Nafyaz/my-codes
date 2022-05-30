def getDigits(x):
    st = {}
    while(x):
        st.add(x%10)
        x /= 10

    return st

def getLen(x):
    ret = 0
    while(x):
        ret += 1
        x /= 10
    
    return ret

from queue import Queue
def main():
    n = int(input())
    x = int(input())

    len = getLen(x)

    if(len == n):
        print(0)
        return

    q = Queue(0)
    q.put(x)

    for i in range(100):
        st = getDigits()


main()