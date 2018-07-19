import threading
import time
import numpy

temp=numpy.array([0,0])

def loop(x):
    print("start")
    for i in range(x):
        time.sleep(1)
        print("%s:%d\n" % (threading.current_thread().name,i))
    print("%s stop6666" %threading.current_thread().name)
    temp[1]=10

t1=threading.Thread(target=loop,args=(6,))

t1.start()

t2=threading.Thread(target=loop,args=(10,))

t2.start()
t2.join()

print("%s stop"%threading.current_thread().name)