// Пример для одного светодиода:                                                       //
#include <Wire.h>                                                                      // Подключаем библиотеку Wire. Для работы с Arduino/Piranha, эту библиотеку можно не подключать.
#include <iarduino_Metro.h>                                                            // Подключаем библиотеку.
                                                                                       //
uint8_t sum;                                                                           // Объявляем переменную для хранения количества найденных модулей Metro.
                                                                                       //
void setup(){                                                                          //
//  Определяем все модули на шине I2C и сохраняем их количество в переменную sum:      //
    sum=iarduino_Metro_Start();                                                        // В качестве аргумента функции iarduino_Metro_Start() можно указать номер адресного вывода (если вывод не указан, то будет использован D12).
//  Теперь нам доступен массив Metro содержащий sum элементов для управления модулями. // Metro[0] управляет ближайшим к Arduino модулем, Metro[1] управляет следующим модулем и т.д до последнего модуля Metro[sum-1].
                                                                                       //
//  Проверяем наличие модулей Metro на шине I2C:                                       //
    while(sum==0){;}                                                                   // Если модули Metro не обнаружены, то входим в бесконечный цикл while, тогда цикл loop выполняться не будет.
    while(Metro[0].model!=MOD_RGB){;}                                                  // Если ближайший к Arduino модуль Metro не является светодиодом, то так же входим в бесконечный цикл while.
}                                                                                      //
                                                                                       //
void loop(){                                                                           //
//  Включаем светодиод на выполнение 1 функции:                                        //
    Metro[0].on( RGB(1) );                                                             // Светодиод будет плавно переливаться всеми цветами радуги.
    delay(10000);                                                                      // Ждём 10 секунд.
//  Включаем светодиод на выполнение 2 функции:                                        //
    Metro[0].on( RGB(2) );                                                             // Светодиод будет переключаться по цветам радуги: красный, жёлтый, зелёный, голубой, синий, фиолетовый и опять красный, ...
    delay(10000);                                                                      // Ждём 10 секунд.
//  Включаем светодиод на выполнение 3 функции:                                        //
    Metro[0].on( RGB(3) );                                                             // Светодиод будет включать случайные цвета (можно использовать как шарапнель ёлочной гирлянды).
    delay(10000);                                                                      // Ждём 10 секунд.
//  Включаем эелёный цвет:                                                             //
    Metro[0].on( 0x00FF00 );                                                           // Включаем зелёный цвет.
    delay(3000);                                                                       // Ждём 3 секунды.
//  Выключаем светодиод:                                                               //
    Metro[0].off();                                                                    // Выключаем светодиод.
    delay(1000);                                                                       // Ждём 1 секунду.
//  Количество функций светодиода зависит от версии его прошивки.                      //
}                                                                                      //