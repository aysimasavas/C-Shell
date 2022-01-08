"# OSPro21" 

GRUP:
AYŞE AYSİMA SAVAŞ 
MELEK SELİN UYSAL 
ŞEYMA GÖL         
RUHİD İBADLI      
YUSUF SÖNMEZ      

PROJEDEKİ DOSYALAR/DİZİNLER
1.bin
2.include
Execute.h
Parsing.h
3.src
Execute.c
Parsing.c
shell.c
Klasör yapısı:
	Header dosyaları ./include isimli klasörde yer almaktadır. İçinde derlenebilir C kodlarının bulunduğu '*.c' 
uzantılı dosyalar ise ./src klasöründe bulumaktadır.

Parsing: 
	Parsing.h header dosyası ve Parsing.c dosyasında bulunan kodlardan oluşmaktadır Parsing de verilen char* (string) 
değerleri belirtilen char (';' veya ' ' gibi) a göre ayrıştırılıp başka bir char* dizisine eklenir yani bir nevi 
komutların hepsinin bulundugu string alınır delimetere göre ayrıştırılıp bir string[] dizisine aktarılır. 
Parsing sadece bunları yapmaz execute işlemi icin komutun tekil mi (ls) yoksa sıralı yani argümanlı mı (ls -l) 
bilgisini döndürür bu bilgi bizim execute işlemi için bir çok döngü ve kontrolden tasarruf etmemizi sağlar.

Execute:
	Execute işlemi parsing tarafından ayrıştırılmış komutları alır o komutları uygulamaya koyulur execvp komutuna 
gönderilen string dizisi ilk degeri komutun yolunu(kendisini) belirtir  ardından gelen deger varmı diye kontrol edilir 
ona göre execvp nin argümanı NULL gönderilir. Her çocuk prosess çakışma ve hata durumları için wait ile beklenir ve en son exit(0) ile sonlanır ilk başlayan prosess ilk sonlanır.

Execute kısmının içinde ayrıca matrix e ait özel komutlarda yer almaktadır bu komutları ayrıntılı öğrenmek için 
'help' komutunu kullanabilirsiniz ayırca linux standart bash de bulunmayan color özelliğini ekledik bu özellik yine 
execute kısmında bulunmakta ve detaylı bilgi için 'color help' komutunu girebilirsiniz.

"cd" komutu changeDirectory function
CD komutu linux shelldeki aynı görevi yapıyor.Eğer bir parametre girilmezse ana dizine gidiyor parametre girildiğinde de parametrede belirtilen dizine gidiyor.

"showpid" komutu showpid function
showpid fonksiyonu, daha önceden oluşturulmuş pid_array isimli proses idlerin saklanacağı diziyi ekrana yazdırmak için tasarlanmıştır. Exec_cmd fonksiyonundan dönen değerler append fonksiyonu ile diziye aktarılır ve bu şekilde idler dinamik uzunluktaki bir dizide saklnamış olur. Saklanan elemanlar komut girildiğinde ekrana bastırılır ve işlem sonlanır.


Çalıştırma notları:
	Kabuk programını ilk olarak derlemeniz gerekmektedir derleme için sadece geçerli dizinde 'make' komutu yeterlidir.

Geliştirme sırasında yaşanan zorluklar:
Görev dağılımı sırasında zorlandık fakat genel olarak iyi bir iş çıkarttığımızı düşünüyoruz.



