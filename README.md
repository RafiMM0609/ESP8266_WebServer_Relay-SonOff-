# ESP8266_WebServer_Relay-SonOff-
Membuat sebuah smartdoorlock dengan menggunakan SonOff yang memiliki chip ESP8266. Smartdoorlock ini menggunakan WebServer yang terhubung ke Google Spreadsheet yang akan menjadi triger open dan close.
##Reprogram SonOFF
SonOff sendiri sebenarnya merupakan sebuah hardware yang sudah mempunyai platfom aplikasi sendiri yaitu eWeLink, dalam aplikasi eWeLink terdapat toogle button yang dapat mengatur SonOff dalam keadaan open atau close. Disini kita akan melakukan reprogram SonOff, jadi kita akan membuat dari program sederhana terlebih dahulu untuk dimasukan kedalam SonOff dan bertahap sampai ke WebServer. Dalam percobaan ini kita akan membutuhkan komponen berikut :
- SonOFF
- Solder
- Timah Solder
- FTDI
- USB to Mini USB
- Kabel Jumper
- Pin Head Male
- Solenoid
- Steker 1 
- Stop Kontak 1
- Kabel AC
###Wiring SonOff
Buka tutup SonOff lalu perhatikan pin dalam foto dibawah ini
**![nama file](alamat foto)**
berikan 4 head pin male untuk mengeluarkan pin RX, TX, Gnd, Vcc. Hubungkan SonOFF dengan FTDI seperti pada gambar berikut. **Pastikan tegangan FTDI adalah 3.3V**
