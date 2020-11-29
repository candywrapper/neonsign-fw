/*
 * Краткое описание применяемых команд для реализации работы устройства:
 *      - setModulesCount(count) - задает количество count(1..16) соединенных в одну связку модулей
 * 		- delay(timeout) - ожидать в течении timeout(0..4294967295) мс
 * 		- off(channelIndex) - выключить канал c индексом channelIndex(0..<индекс последнего канала>)
 * 		- on(channelIndex) - включить канал c индексом channelIndex(0..<индекс последнего канала>)
 * 		- random(channelIndex, min, max) - запускает генерацию случайных включений/выключений выхода канала с индексом channelIndex(0..<индекс последнего канала>),
 * 		где определены минимальное и максимальное время между событиями включения/выключения значениями переменных min(0..4294967295) мс и max(0..4294967295) мс
 * 		- repeat(channelIndex, sourceChannelIndex) - устанавливает для канал с индексом channelIndex(0..<индекс последнего канала>)
 * 		режим повторения состояния канала с индексом sourceChannelIndex(0..<индекс последнего канала>)
 *		- invert(channelIndex, sourceChannelIndex) - устанавливает для канал с индексом channelIndex(0..<индекс последнего канала>)
 * 		режим инверсного повторения состояния канала с индексом sourceChannelIndex(0..<индекс последнего канала>)
 *		- input(diIndex) - возвращает состояние цифрового входа с индексом diIndex (0..1)
 *
 *	где <индекс последнего канала> = 8 * <количество модулей> - 1
 *
 */

#include "algorithm.h"


void Algorithm::execute()
{
	// Задать количесто модулей в связке
	setModulesCount(1);

	// Установить начальные состояния всех индикаторов
	for(uint8_t i = 0; i < 8; i++)
		off(i);

	// Реализовать циклический алгоритм работы индикаторов
	for(;;) {
		if (input(0))
			for(;;) {
				on(0);
				delay(500);
				off(0);
				delay(500);
				if (input(1))
					break;
			}

	}
}
