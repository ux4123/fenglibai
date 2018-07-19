import  requests
import cv2
import numpy as np
import urllib

headers =   {
    "Authorization": 'Basic YWRtaW46'
}

#stream = requests.get('http://192.168.2.216/index.asp',headers = headers)
#stream = requests.get('http://192.168.2.216/media/?action=stream',headers = headers)
#￥stream = urllib.request.urlopen('http://192.168.2.216/media/?action=stream',headers)
#stream = requests.get('http://192.168.2.216/media/?action=stream' ,headers = headers,stream=True)


stream = requests.get('http://192.168.2.216/media/?action=stream',headers = headers,stream=True)
print (stream.status_code)
bytes = ''
while True:
    bytes += stream.read(1024)
    a = bytes.find(b'\xff\xd8')
    b = bytes.find(b'\xff\xd9')
    if a != -1 and b != -1:
        jpg = bytes[a:b+2]
        bytes = bytes[b+2:]
        img = cv2.imdecode(np.fromstring(jpg, dtype=np.uint8), cv2.IMREAD_COLOR)
        cv2.imshow('Video', img)
        if cv2.waitKey(1) == 27:
            exit(0)
    else:
        print "else"

'''

 if(r.status_code == 200):
            byte = bytes()
            for chunk in r.iter_content(chunk_size=1024):
                byte += chunk
                a = byte.find(b'\xff\xd8')
                b = byte.find(b'\xff\xd9')
                if a != -1 and b != -1:
                    jpg = byte[a:b+2]
                    byte = byte[b+2:]
                    i = cv2.imdecode(np.fromstring(jpg, dtype=np.uint8), cv2.IMREAD_COLOR)

                    cv2.imshow('ip',i)

                    cv2.resizeWindow('ip', img_width, img_height)

                    if cv2.waitKey(1) == 27:
                        exit(0)
                    if cv2.waitKey(25) & 0xFF == ord('q'):
                        exit(0)
        else:
            print("Received unexpected status code {}".format(r.status_code))


            
import cv2
import urllib
import numpy as np

stream = urllib.urlopen('http://192.168.100.128:5000/video_feed')
bytes = ''
while True:
    bytes += stream.read(1024)
    a = bytes.find(b'\xff\xd8')
    b = bytes.find(b'\xff\xd9')
    if a != -1 and b != -1:
        jpg = bytes[a:b+2]
        bytes = bytes[b+2:]
        img = cv2.imdecode(np.fromstring(jpg, dtype=np.uint8), cv2.IMREAD_COLOR)
        cv2.imshow('Video', img)
        if cv2.waitKey(1) == 27:
            exit(0)
    else:
        print "else"

'''



'''
from cv2 import *
from cv2 import cv
import urllib
import numpy as np
k=0
capture=cv.CaptureFromFile("http://IPADDRESS of the camera/axis-cgi/mjpg/video.cgi")
namedWindow("Display",1)

while True:
    frame=cv.QueryFrame(capture)
    if frame is None:
        print 'Cam not found'
        break
    else:
        cv.ShowImage("Display", frame)
    if k==0x1b:
        print 'Esc. Exiting'
        break
'''