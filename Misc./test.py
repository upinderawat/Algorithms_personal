# Enter your code here. Read input from STDIN. Print output to STDOUT
def fib(t1,t2,n):
    table = [0]*n
    table[0]= t1
    table[1]= t2
    for i in xrange(2,n):
        table[i] = table[i-1]*table[i-1] + table[i-2]
        print table[i]
    return table[n-1]
        


def main():
    (t1,t2,n) = map(int,raw_input().split())
    print (fib(t1,t2,n))
if __name__ == "__main__":
	main()