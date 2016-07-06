#!/bin/env python3

import bridge
import time 

def back(json):
    print("Callback" + json)
    return
    

bridge.call('foo', back, '{"NumOne": 5, "NumTwo": 2}');

while 1 :
    print('Yo!')
    time.sleep(1)
    
