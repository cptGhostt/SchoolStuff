Autor: Peter Kendra
Projekt: Bludisko s poradím

Tento projekt je jednoduchá 2D logická hra s názvom Labyrint, kde hráč prechádza rôznymi úrovňami s cieľom 
zozbierať všetky checkpointy v správnom poradí. Hráč sa pohybuje po hracej ploche, kde sa nachádzajú rôzne typy prekážok,
ako sú steny, smerové steny a teleporty. Cieľom hráča je strategicky plánovať svoj pohyb tak, aby
dokázal pozbierať všetky checkpointy a zároveň sa neuväznil (keďže na každé políčko sa dá vojsť iba raz). Hra 
obsahuje 3 úrovne, pričom po úspešnom dokončení všetkých sa hra dá reštartovať.


Aplikácia je naprogramovaná v jazyku Java pomocou knižnice JavaFX pre grafické rozhranie. Spúšťa sa cez triedu 
Main, ktorá inicializuje okno a načíta hlavnú obrazovku. V hlavnom menu je možné začať hru tlačidlom „Start“. 
Hráč sa ovláda pomocou šípok alebo kláves WASD. Ak sa hráč ocitne v situácii bez možnosti ďalšieho pohybu, hra 
automaticky ponúkne možnosť reštartovať úroveň. Po úspešnom splnení úrovne sa zobrazí tlačidlo na prechod do 
ďalšej úrovne.