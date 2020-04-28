# Line Detector

A basic set up to detect lines that utalises OpenCV2, Canny Edge detection and Probabilistic Hough.

## Set up

Use the following to build your file in Linux:
```
sudo g++ camera_open_main.cpp -o <Your object name> `pkg-config --cflags --libs opencv`
```
Also, remember to create a *.txt file that will hold your IP address to your camera device in the following manner:
```
http://<IP address>:<Port>
```
It is suggested to use the ``` 8080``` port.

## Running
After complilation make sure that you provide the *.txt file as an argument when running in the following manner:
```
./<Your object name> <address file>.txt
```

Enjoy! ;)
