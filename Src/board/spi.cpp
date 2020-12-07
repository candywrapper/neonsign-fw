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
	SPI1->CR1 |= SPI_CR1_SPE;

	while (length--) {
		while (!(SPI1->SR & SPI_SR_TXE));
		*(__IO uint8_t *)&(SPI1->DR) = *(data++);
	}
	while (!(SPI1->SR & SPI_SR_TXE));
	while (SPI1->SR & SPI_SR_BSY);

	SPI1->CR1 &= ~SPI_CR1_SPE;
}

void Spi::configureMosiPort()
{
	GPIOA->OSPEEDR |= GPIO_OSPEEDR_OSPEEDR7_0 | GPIO_OSPEEDR_OSPEEDR7_1;
	GPIOA->MODER |= GPIO_MODER_MODER7_1;
}

void Spi::configureClkPort()
{
	GPIOA->OSPEEDR |= GPIO_OSPEEDR_OSPEEDR5_0 | GPIO_OSPEEDR_OSPEEDR5_1;
	GPIOA->MODER |= GPIO_MODER_MODER5_1;
}

void Spi::configureNssPort()
{
	GPIOA->OSPEEDR |= GPIO_OSPEEDR_OSPEEDR4_0 | GPIO_OSPEEDR_OSPEEDR4_1;
	GPIOA->MODER |= GPIO_MODER_MODER4_1;
	GPIOA->PUPDR |= GPIO_PUPDR_PUPDR4_0;
}

void Spi::configureInterface()
{
	SPI1->CR1 |= SPI_CR1_BIDIMODE | SPI_CR1_BIDIOE | SPI_CR1_MSTR |
				 SPI_CR1_CPOL |SPI_CR1_CPHA |
				 SPI_CR1_BR_0 | SPI_CR1_BR_2;

	SPI1->CR2 |= SPI_CR2_SSOE;
}
