#include "spi.h"
#include "stm32f0xx.h"

void Spi::initialize()
{
	configureMosiPort();
	configureClkPort();
	configureNssPort();
	configureInterface();
}

void Spi::send(const uint8_t *data, uint8_t length)
{
	if (*data & 0x1)
		SPI1->CR1 |= SPI_CR1_SPE;
	else
		SPI1->CR1 &= ~SPI_CR1_SPE;


//	SPI1->CR1 |= SPI_CR1_SPE;

//	while (length--) {
//		while (!(SPI1->SR & SPI_SR_TXE));
//		*(__IO uint8_t *)&(SPI1->DR) = *(data++);
//	}
//	while (!(SPI1->SR & SPI_SR_TXE));

//	SPI1->CR1 &= ~SPI_CR1_SPE;
}

void Spi::configureMosiPort()
{
	// without pullup/pulldown
	GPIOA->OSPEEDR |= GPIO_OSPEEDR_OSPEEDR7_0 | GPIO_OSPEEDR_OSPEEDR7_1; // high speed
	GPIOA->MODER |= GPIO_MODER_MODER7_1; // Alternative, push/pull,
}

void Spi::configureClkPort()
{
	// without pullup/pulldown
	GPIOA->OSPEEDR |= GPIO_OSPEEDR_OSPEEDR5_0 | GPIO_OSPEEDR_OSPEEDR5_1; // high speed
	GPIOA->MODER |= GPIO_MODER_MODER5_1; // Alternative, push/pull,
}

void Spi::configureNssPort()
{
	// without pullup/pulldown
	GPIOA->OSPEEDR |= GPIO_OSPEEDR_OSPEEDR4_0 | GPIO_OSPEEDR_OSPEEDR4_1; // high speed
	GPIOA->MODER |= GPIO_MODER_MODER4_1; // Alternative, push/pull,
}

void Spi::configureInterface()
{
	SPI1->CR1 |= SPI_CR1_BR_0 | SPI_CR1_BR_1 | SPI_CR1_BR_2;    // задаем частоту обмена /256
	SPI1->CR1 |= SPI_CR1_CPOL | SPI_CR1_CPHA;                   // задаем режим работы SPI (полярность и фазу)
	SPI1->CR2 |= SPI_CR2_DS_0 | SPI_CR2_DS_1 | SPI_CR2_DS_2;    // задаем формат данных (разрядность)
	SPI1->CR2 |= SPI_CR2_SSOE;                                  // задаем режим внешнего вывода NSS
	SPI1->CR1 |= SPI_CR1_MSTR;                                  // задаем режим работы модуля SPI (ведущий или ведомый)
}
