# ESP8266_WebServer_Relay-SonOff-
Membuat sebuah smartdoorlock dengan menggunakan SonOff yang memiliki chip ESP8266. Smartdoorlock ini menggunakan WebServer yang terhubung ke Google Spreadsheet yang akan menjadi triger open dan close.
## Reprogram SonOFF
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
### Wiring SonOff
Buka tutup SonOff lalu perhatikan pin dalam foto dibawah ini <br>
<img align="center" width="353" height="346" src="https://github.com/RafiMM0609/ESP8266_WebServer_Relay-SonOff-/blob/main/Pictures/SonOFF.jpeg?raw=true"><br>
berikan 4 head pin male untuk mengeluarkan pin RX, TX, Gnd, Vcc. Hubungkan SonOFF dengan FTDI seperti pada gambar berikut. **Pastikan tegangan FTDI adalah 3.3V**
### Program SonOff
Kamu dapat menekan tombol hitam dan tahan lalu colokan kabel FTDI yang sudah terhubung ke SonOff dengan PC untuk menyalakan SonOff dalam mode flash. Tanda SonOff telah dapat memasuki mode flash adalah lampu indikator LED yang terdapat pada SonOff mati. Setelah itu silahkan ikuti langkah-langkah berikut
#### Install Library yang diperlukan pada arduino IDE
Library yang diperlukan adalah ESP8266, WiFiClientSecure, dan AsyncWebServer.
#### Upload code ________
Hubungkan SonOff dengan PC ke dalam mode flash lalu upload code _____ , pastikan SonOff terhubung ke dalam jaringan WiFi yang mempunyai akses internet
#### Seting Google Sheeet sebagai penerima data
Buat dokumen google sheet sebagai database penerima data yang akan dikirimkan oleh SonOff. Buka apps script dan copy code ____ lalu terapkan untuk program dapat berjalan dengan lancar.
Selamat mencoba....
