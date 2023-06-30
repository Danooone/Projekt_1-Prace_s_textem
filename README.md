# Projekt_1-Prace_s_textem
Cílem projektu je vytvořit program, který by emuloval zjednodušený algoritmus hledání kontaktů zadaných pomocí posloupnosti číslic. Vstupem programu je posloupnost číslic. Výstup programu bude obsahovat seznam kontaktů, které odpovídají zadanému číselnému filtru.
# Detailní specifikace
Program implementujte ve zdrojovém souboru ''t9search.c''. Vstupní data budou čtena ze standardního vstupu (stdin), výstup bude tisknut na standardní výstup (stdout).
# Překlad a odevzdání zdrojového souboru
Odevzdání: Odevzdejte zdrojový soubor ''t9search.c'' prostřednictvím informačního systému.
Překlad: Program překládejte s následujícími argumenty:
gcc -std=c99 -Wall -Wextra -Werror t9search.c -o t9search

# Syntax spuštění
Program se spouští v následující podobě: (./t9search značí umístění a název programu):

./t9search CISLO
CISLO zde představuje hledané kritérium, sekvenci číslic 0 až 9, které reprezentují sekvenci hledaných znaků.
Pokud je program spuštěn bez argumentů, program se bude chovat, jako by hledanému kritériu odpovídal každý kontakt ze seznamu.
Implementační detaily
