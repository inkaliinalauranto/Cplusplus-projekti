# Cplusplus-projekti

## Projektin kuvaus:

Projektin lopputuote on yksinkertainen hiihtotarvikkeiden yll�pitoj�rjestelm�, jossa tavarat voi listata kokonaisuudessaan tai kategorioittain, niit� voi vuokrata ja palauttaa sek� lis�t� ja poistaa. K�ytt�liittym�n� projektissa toimii komentokehoiterajapinta, joka ohjaa k�ytt�j�� koko j�rjestelm�n k�ynniss�oloajan.

Koodin puolella on Cplusplus-projekti.cpp-niminen p��ohjelma, jossa hy�dynnet��n Menu-luokasta tehty� instanssia. Menu-luokan lis�ksi ohjelmaan kuuluvat Item-luokka, Items-luokka, jossa tehd��n instansseja Item-luokasta, sek� Items-luokasta periytyv�t Others-, Poles-, SkiBoots- ja Skis-luokat. 

Jokaisessa luokassa koodi on jaettu pienempiin osiin j�senfunktioiksi. Lis�ksi periytyviss� luokissa hy�dynnet��n perittyj� funktioita sek� ylikirjoitettavaa peritty� funktiota. Useassa luokassa k�ytet��n C++ -kielen standardikirjastoja, kuten vector-, string-, iostream- ja fstream-kirjastoja. Ohjelma on kommentoitu yksityiskohtaisesti.

## Projektin tarkasteleminen Visual Studio Community 2022 -editorilla (Windows-k�ytt�j�rjestelm�ll�):

- Jos k�yt� QT Creatoria, siirry seuraavan linkin takana olevaan repositorioon ja seuraa t�m�n repositorion README-tiedostosta l�ytyvi� ohjeita: www..

- Kopioi leikep�yd�lle projektin URL napista "<> Code" avautuvan pikku ikkunan HTTPS-otsikon alapuolella olevasta kent�st�:

![alt text](ohjekuva-1.png)


- Avaa Visual Studio Community 2022 ja valitse oikeasta sivusta Get Started -otsikon alta "Clone a repository":

![alt text](ohjekuva-2.png)


- Liit� leikep�yd�lle kopioitu URL-osoite Clone a repository -otsikolla avautuneen ikkunan Repository location -kentt��n. Path-kentt� t�yttyy automaattisesti. Paina sen j�lkeen oikeasta alakulmasta nappia Clone:

![alt text](ohjekuva-3.png)


- Avautuvasta projekti-ikkunasta p��set tutkimaan mm. l�hde- ja otsikkotiedostoja Solution Explorerin kautta laajentamalla Cplusplus-projekti-valikon nuolen kuvasta. Jos Solution Explorer ei aukea valmiiksi, sen saa auki joko n�pp�in yhdistelm�ll� Ctrl + Alt + L tai yl�valikon kautta painamalla View-kohtaa. Klikkaa valikon ensimm�ist� vaihtoehtoa eli Solution Exploreria:

![alt text](ohjekuva-4.png)


- Otsikko- ja l�hdetiedostot l�ytyv�t kansioiden Header Files ja Source Files alta. Tiedostoja tuplaklikkaamalla saa sen avattua editoriin.
- Projektin saa ajettua vihre�st� nuolisymbolista, jonka vieress� lukee "Local Windows Debugger", tai vaihtoehtoisesti Ctrl + F5 -n�pp�inyhdistelm�ll�:

![alt text](ohjekuva-5.png)


- Kun k�ynnistysnappia on painettu, aukeaa k�ytt�liittym�rajapintana komentokehoite. Nyt ohjelman k�ytt� onnistuu komentokehoitteen kirjallista opastusta seuraamalla.
- Kun lopetat ohjelman k�yt�n, eli sy�t�t valinnaksi merkin 7, muista sulkea komentokehoite. Muuten ohjelman ajaminen uudestaan ei onnistu.

![alt text](ohjekuva-6.png)

