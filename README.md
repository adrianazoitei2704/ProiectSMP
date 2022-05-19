# ProiectSMP
Alarms de Incendiu

Proiect:
Alarma de incendiu

![alt text](https://github.com/[adrianazoitei2704]/[ProiectSMP]/blob/[branch]/proiect.jpg?raw=true)
Componente:

Modul Senzor detector aer MQ-135 x1

Modul buzzer x1

Potențiometru x1

Modul Senzor flacara x1

Ecran LCD 1602 - Afişaj electronic pe doua randuri x1

LED de 5 mm - Culoare LED : Rosu

LED de 5 mm - Culoare LED : Galben

LED de 5 mm - Culoare LED : Verde

Implementare:

Folosim modulul detector de aer pentru a citi valoare puritatii aerului. In functie de rezultatul citi analog, setam un flag boolean drep indicatie a prezentei de fum. Similiar pentru modulul senzor flacara, o variabila booleana este setata, in urma apelului unei functii. Functia citeste digital si comparatia nu este facuta dupa distanta intre sursa de foc si senzor, ea este facuta true sau false daca se detecteaza/nu se detecteaza prezenta de flacara.
