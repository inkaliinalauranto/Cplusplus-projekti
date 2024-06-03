# Cplusplus-projekti

## Projektin kuvaus:

Projektin lopputuote on yksinkertainen hiihtotarvikkeiden ylläpitojärjestelmä, jossa tavarat voi listata kokonaisuudessaan tai kategorioittain, niitä voi vuokrata ja palauttaa sekä lisätä ja poistaa. Käyttöliittymänä projektissa toimii komentokehoiterajapinta, joka ohjaa käyttäjää koko järjestelmän käynnissäoloajan.

Koodin puolella on Cplusplus-projekti.cpp-niminen pääohjelma, jossa hyödynnetään Menu-luokasta tehtyä instanssia. Menu-luokan lisäksi ohjelmaan kuuluvat Item-luokka, Items-luokka, jossa tehdään instansseja Item-luokasta, sekä Items-luokasta periytyvät Others-, Poles-, SkiBoots- ja Skis-luokat.

Jokaisessa luokassa koodi on jaettu pienempiin osiin jäsenfunktioiksi. Lisäksi periytyvissä luokissa hyödynnetään perittyjä funktioita sekä ylikirjoitettavaa perittyä funktiota. Useassa luokassa käytetään C++ -kielen standardikirjastoja, kuten vector-, string-, iostream- ja fstream-kirjastoja. Tavaratiedot esimerkiksi kirjoitetaan tiedostoon ja luetaan sieltä fstream-kirjaston ominaisuuksia hyödyntämällä. Ohjelma on kommentoitu yksityiskohtaisesti.

## Projektin tarkasteleminen Visual Studio Community 2022 -editorilla (Windows-käyttöjärjestelmällä):

- Jos käytät QT Creatoria, siirry seuraavan linkin takana olevaan repositorioon ja seuraa ko. repositorion README-tiedostosta löytyviä ohjeita: https://github.com/inkaliinalauranto/Cpp-projekti/tree/main
- Visual Studio 2022 Community -version lataaminen onnistuu tarvittaessa seuraavan linkin takaa löytyviä ohjeita seuraamalla: 
- Kopioi leikepöydälle repositorion URL <> Code -napista avautuvan pikku ikkunan HTTPS-otsikon alapuolella olevasta kentästä:

![alt text](ohjekuva-1.png)

- Avaa Visual Studio Community 2022 ja valitse oikeasta sivusta Get Started -otsikon alta "Clone a repository":

![alt text](ohjekuva-2.png)

- Liitä leikepöydälle kopioitu URL-osoite Clone a repository -otsikolla avautuneen ikkunan Repository location -kenttään. Path-kenttä täyttyy automaattisesti. Paina sen jälkeen oikeasta alakulmasta nappia Clone:

![alt text](ohjekuva-3.png)

- Avautuvasta projekti-ikkunasta pääset tutkimaan mm. lähde- ja otsikkotiedostoja Solution Explorerin kautta laajentamalla Cplusplus-projekti-valikkoa nuolen kuvasta. Jos Solution Explorer ei aukea valmiiksi, sen saa auki joko näppäinyhdistelmällä Ctrl + Alt + L tai ylävalikon kautta painamalla View-kohtaa. Klikkaa View-valikon ensimmäistä vaihtoehtoa eli Solution Exploreria:

![alt text](ohjekuva-4.png)

- Otsikko- ja lähdetiedostot löytyvät kansioiden Header Files ja Source Files alta. Tiedostoja tuplaklikkaamalla saa ne avattua editoriin.
- Projektin saa ajettua vihreästä nuolisymbolista, jonka vieressä lukee "Local Windows Debugger", tai vaihtoehtoisesti Ctrl + F5 -näppäinyhdistelmällä:

![alt text](ohjekuva-5.png)

- Kun käynnistysnappia on painettu, aukeaa käyttöliittymärajapintana komentokehoite. Nyt ohjelman käyttö onnistuu komentokehoitteen kirjallista opastusta seuraamalla. Muista painaa aina enter-näppäintä valitsemasi numeron/vaihtoehdon syöttämisen jälkeen.
- Jos ensimmäisellä ajokerralla tulee kymmeniä virheitä, jotka liittyvät esimerkiksi puolipilkku- tai aaltosulkumerkkeihin, johtunee tämä skandinaavisista merkeistä. Vaikka koodi on kirjoitettu englanniksi, on käyttöliittymä suomenkielinen. Niinpä merkkijonot voivat sisältää skandinaavisia merkkejä, jotka editori on saattanut korvata kloonausvaiheessa tai sen jälkeen muilla erikoismerkeillä. Tässä tilanteessa ohjelman voi ajaa virheistä huolimatta. Käyttöliittymä toimii siitä huolimatta, kuten pitää, vaikka skandinaavisten kirjainten tilalla olisikin muita merkkejä.
- Kun poistut ohjelmasta eli syötät valinnaksi numeron 7, muista sulkea komentokehoite. Muuten ohjelman ajaminen uudestaan ei onnistu.

![alt text](ohjekuva-6.png)

## Demonstraatio ohjelman toiminnasta:

Ohjelman toimintaa esittelevä esimerkkivideo löytyy seuraavan linkin takaa: https://youtu.be/wxKt2jZtQ0o
