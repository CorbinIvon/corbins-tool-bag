#!/bin/bash
tar \
--exclude='*.exe' \
--exclude='*.mp4' \
--exclude='*.mp3' \
--exclude='*.wav' \
--exclude='*.ini' \
--exclude='*.sys' \
\
-zcvf \
/home/corbin/Archived-Drive-Kerr-laptop-20221108.tar.gz /home/corbin/m1/PerfLogs/ /home/corbin/m1/ProgramData/ /home/corbin/m1/System32/ /home/corbin/m1/Users/ 2>&1 > /home/corbin/archive.log