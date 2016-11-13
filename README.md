# Dekorator
Dekorator - wzorzec projektowy

Poprawiony przykład wzorca projektowego - Dekoratora -  ze strony:
http://www.algorytm.org/wzorce-projektowe/dekorator-decorator/decorator-c.html

Zamiast klasy OponyZimowe użyłem klasy Navigacja.

Błedem w przykładzie przykładzie było:
- nie zwalnianie wskaźników s1, s2, s3 na końcu programu,
- nie zwalnianie obiektów wskazywanych przez wskaźnik car w klasie Klimatyzacja oraz Navigacja. Zrobiłem to oczywiście w destruktorze obiektów.

P.S. Destruktory każdej klasy zrobiłem "gadające" żeby widać było, co po kolei się dzieje.
