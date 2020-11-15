/*
 * Краткое описание применяемых команд для реализации работы устройства:
 *      - setModulesCount(count) - задает количество count(1..16) соединенных в одну связку модулей
 * 		- delay(timeout) - ожидать в течении timeout(0..4294967295) мкс
 * 		- off(channelIndex) - выключить канал c индексом channelIndex(0..<индекс последнего канала>)
 * 		- on(channelIndex) - включить канал c индексом channelIndex(0..<индекс последнего канала>)
 * 		- pwm(channelIndex, period, dutyCycle) - запускает генерацию ШИМ сигнала на выходе канала с индексом channelIndex(0..<индекс последнего канала>),
 * 		периодом ШИМа period(0..4294967295) мкс и скважностью импульса ШИМа dutyCycle(0..100) %.
 * 		- random(channelIndex, min, max) - запускает генерацию случайных включений/выключений выхода канала с индексом channelIndex(0..<индекс последнего канала>),
 * 		где определены минимальное и максимальное время между событиями включения/выключения значениями переменных min(0..4294967295) мкс и max(0..4294967295) мкс
 * 		- repeat(channelIndex, sourceChannelIndex) - устанавливает для канал с индексом channelIndex(0..<индекс последнего канала>)
 * 		режим повторения состояния канала с индексом sourceChannelIndex(0..<индекс последнего канала>)
 *
 *	где <индекс последнего канала> = 8 * <количество модулей> - 1
 *
 */

#include "algorithm.h"


void Algorithm::execute()
{
	// Задать количесто модулей в связке
	setModulesCount(2);

	// Установить начальные состояния всех индикаторов
	for(uint8_t i = 0; i < 16; i++)
		on(i);
uint32_t i=1;
	// Реализовать циклический алгоритм работы индикаторов
	for(;;) {
		on(0);
		delay(i);
		if (i > 7000)
			i = 1;
		else
			i += 6;
		off(0);
		delay(10000);

	}
}
