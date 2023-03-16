# MP3 DF Mini Player / SD Card support

[Documentation]{https://github.com/DFRobot/DFRobotDFPlayerMini/blob/master/doc/FN-M16P%2BEmbedded%2BMP3%2BAudio%2BModule%2BDatasheet.pdf}

# Audio files and directories

## Audio Files in root directory

Audio files directly stored in the __root directory__ of the storage device(SD card or USB flash drive) need to be
renamed as 0001.mp3/0001.wav, 0002.mp3/0002.wav, 0003.mp3/0003.wav

## MP3 and ADVERT directories

There are two special purposed folders “MP3” and “ADVERT” that can be chosen by users
to use or not according to the actual needs. Audio files stored in these two folders need to be renamed as
0001.mp3/0001.wav, 0002.mp3/0002.wav, 0003.mp3/0003.wav, .......3000.mp3/3000.wav.

## Other directories and audio files

Ordinary folders must be renamed as 01, 02, 03......99, and the audio files must be renamed as
001.mp3/001.wav, 002.mp3/002.wav, 003.mp3/003.wav, .......255.mp3/255.wav. It is also possible to keep the
original name when you rename a file. For example, the original name is “Yesterday Once More.mp3”, then you can
rename it as “001Yesterday Once More.mp3”.