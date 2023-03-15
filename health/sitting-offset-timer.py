#!/usr/bin/python3
import time
import keyboard

timer = 0
standing = False
toggle = True
while True:
    print("\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n")
    if keyboard.is_pressed('[') and keyboard.is_pressed(']') and keyboard.is_pressed('\\'):
        if not standing:
            standing = True
            toggle = not toggle
    elif not keyboard.is_pressed(' '):
        if standing:
            standing = False
    if toggle:
        tmp_timer=timer
        hours = int(tmp_timer / 3600)
        tmp_timer = tmp_timer % 3600
        minutes = int(tmp_timer / 60)
        tmp_timer = tmp_timer % 60
        seconds = int(tmp_timer)
        timer += 0.1
        print("Sitting Time:")
        print(f"Time : {hours:02d}:{minutes:02d}:{seconds:02d}")
    else:
        tmp_timer=timer / 6
        hours = int(tmp_timer / 3600)
        tmp_timer = tmp_timer % 3600
        minutes = int(tmp_timer / 60)
        tmp_timer = tmp_timer % 60
        seconds = int(tmp_timer)
        timer -= 0.6
        if timer < 0:
            timer = 0
        print("Standing Time:")
        print(f"Time Remaining : {hours:02d}:{minutes:02d}:{seconds:02d}")
    time.sleep(0.1)
