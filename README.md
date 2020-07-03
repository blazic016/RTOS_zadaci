# RTOS_zadaci
## Real-time operation systems, school job
---
### 1. Osetljivost diode

### 2. Arhiva studenata
Napisati program za unos i azuriranje studenata. Studenti se unose sa svojim imenom, prezimenom, brojem indeksa i ocenama.
Prilikom pokretanja, program proverava da li postoji TEKSTUALNA datoteka sa podacima o svakom (4) studentu u pojedinacnim redovima, u formatu:
Ime Prezime BrojIndeksa
Meni omogucava:
1) Unos novog studenta (3)
2) Pretragu studenta po prezimenu gde se ispisuju svi studenti kojima prezime pocinje unetim slovom (3)
3) Ispis svih studenata prethodno unesenih (2)
4) Korigovanje podataka o studentu: unese se redni broj studenta dobijen ispisom svih studenata, zatim (4) se za datog studenta odlucuje koje polje se menja
5) Izlaz, pri cemu se novo uneseni studenti upisuju u datoteku sacuvanih studenata. (4)

### 3. Klijent-server komunikacija
Razviti GNU GCC server koji izvrsava proracun jedne od cetiri osnovne aritmeticke operacije (+ - * /). Izraz koji je 
potrebno proracunati prosleduje klijent aplikacija u formi stringa (npr. 2.304+3.45 ili 2.54*3.45 ili 3.3 - 6 ili 9.2 / 3).
Nakon proracuna, server vraca resenje klijentu takode u formi stringa.
Server prihvata konekcije na proizvoljnom portu (ne koristiti standardni port 80) i odgovara zahtevima pristiglim od strane klijenta.
http://www.cs.rpi.edu/~moorthy/Courses/os98/Pgms/socket.html
