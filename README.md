![License: MIT](https://img.shields.io/badge/License-MIT-green.svg)
# R2AKT_ESC_DeESC
R2AKT_ESC_DeESC - библиотека для экранирования маркеров начала и конца пакета.
При нахождении байта со значением 0xC0 он будет заменён на специальную последовательность из 2-х байт.
Т.о. при худшем случае размер передаваемых данных удваивается.
Стандартный алгоритм применяемый в протоколе TNC KISS.

### Совместимость
Совместима со всеми платформами, включая x86/x64.

<a id="example"></a>
## Пример
Примеры смотри в **examples**!

<a id="feedback"></a>
## Баги и обратная связь
При нахождении багов создавайте **Issue**.  
Библиотека открыта для доработки и ваших **Pull Request**'ов!
