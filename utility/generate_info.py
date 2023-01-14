#!/usr/bin/python3
import calendar, time, subprocess
from datetime import datetime
from PIL import Image, ImageFont, ImageDraw
from screeninfo import get_monitors

def main():
    timestamp_monitor(10,10)
    webpage_monitor(10,22)

def run_linux_command(command=""):
    bashCommand = command
    process = subprocess.Popen(bashCommand.split(), stdout=subprocess.PIPE)
    output, error = process.communicate()
    if error:
        print (error)
    return output

def webpage_monitor(start_x_pos, start_y_pos):
    ### Display webpage Status ###
    # Parses a text file that returns
    # The 000 represents the webpage code
    # Lines in text file look like the following:
    # [000] : https://Some.webpage.url
    pos_x=start_x_pos
    pos_y=start_y_pos
    txt_color=(255,255,255)
    # The command below does a bash curl command to get the webpage (error) code. 200 is passing, 400+ is error, 300+ is redirect
    # Yellow should indicate that you probably have the wrong page.
    run_linux_command("./webpage-check-status.sh")
    web_page_status = "Webpages:\n"
    draw.text((pos_x, pos_y), web_page_status, font=font, fill=txt_color)
    with open('webpage-status.txt') as f:
        lines = f.readlines()
        for n in range(len(lines)):
            code=lines[n][1:4]
            if lines[n][8] == 'h':
                if int(code) == 200:
                    draw.text((pos_x, pos_y + 12 * (n+1)), "  UP", font=font, fill=(0,255,0))
                    draw.text((pos_x + 27, pos_y + 12 * (n+1)), "|" + lines[n][8:], font=font, fill=(255,255,255))
                elif int(code) < 400 & int(code) != 0:
                    draw.text((pos_x, pos_y + 12 * (n+1)), " "+code, font=font, fill=(255,255,0))
                    draw.text((pos_x + 27, pos_y + 12 * (n+1)), "|" + lines[n][8:], font=font, fill=(255,255,0))
                else:
                    draw.text((pos_x, pos_y + 12 * (n+1)), "DOWN", font=font, fill=(255,0,0))
                    draw.text((pos_x + 27, pos_y + 12 * (n+1)), "|" + lines[n][8:], font=font, fill=(255,0,0))
            else:
                draw.text((pos_x + 27, pos_y + 12 * (n+1)), "|", font=font, fill=(255,255,255))

def timestamp_monitor(start_x_pos, start_y_pos):
    ### Display the time ###
    #display_text = "width: "+str(monitor_width)+"\nheight: "+str(monitor_height)
    pos_x=start_x_pos
    pos_y=start_y_pos
    txt_color=(255,255,255)
    timestamp_text = "DATE: "
    timestamp=calendar.timegm(time.gmtime())
    timestamp_text += str(datetime.fromtimestamp(timestamp))+" "
    timestamp_text += str(timestamp)
    draw.text((pos_x, pos_y), timestamp_text, font=font, fill=txt_color)

### INIT ###
monitor_width  = get_monitors()[0].width
monitor_height = get_monitors()[0].height
# Create a new image with a white background
image = Image.new('RGB', (monitor_width, monitor_height), (0, 0, 0))
# Create a drawing context
draw = ImageDraw.Draw(image)
# Choose a font
font_size = 12
font = ImageFont.truetype('/usr/share/fonts/truetype/liberation2/LiberationMono-Bold.ttf', font_size)

main()

image.save('image-status.jpg')