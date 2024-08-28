import sys
if sys.prefix == '/usr':
    sys.real_prefix = sys.prefix
    sys.prefix = sys.exec_prefix = '/home/fourfold/dev/Pepsi-Bot/workspace/install/yolov8_webcam'
