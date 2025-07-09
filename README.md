# 🌞 Projeto: Controle de Servo pela Luminosidade com BH1750 e Display OLED

Este projeto utiliza o **Raspberry Pi Pico** para ler a luminosidade de um ambiente usando o sensor **BH1750**, exibir os dados em um **display OLED SSD1306** e controlar a posição de um **servo motor** de acordo com a quantidade de luz detectada.

---

## 📁 Estrutura do Projeto
``` bash
├── src/
│ ├── bh1750/ # Código para leitura do sensor BH1750
│ ├── init/ # Inicialização de pinos, I2C, etc.
│ ├── pico-ssd1306 # Biblioteca SSD1306 para o display OLED
│ ├── servo/ # Controle do servo motor via PWM
│ └── servo_lum.c # Código principal do projeto (este)
├── CMakeLists.txt # Build system (CMake)
├── pico_sdk_import.cmake # Inclusão do SDK do Raspberry Pi Pico
├── .gitignore # Arquivos ignorados pelo Git
└── README.md # Documentação do projeto
```
---

## 🎯 Objetivo

- Medir a intensidade luminosa com o sensor **BH1750**.
- Exibir o valor de **lux** no display **OLED**.
- Controlar um **servo motor** com base na luminosidade:  
  Quanto mais luz, maior o ângulo do servo (com limite proporcional).

---

## ⚙️ Instalação e Compilação

1. Clone este repositório:
   ```bash
   git clone https://github.com/seuusuario/nome-do-projeto.git
   cd nome-do-projeto
   ```
2. Certifique-se de ter o SDK do Raspberry Pi Pico instalado.

## 🔧 Como Funciona
- Inicializa periféricos: I2C, display, sensor BH1750 e servo motor.

- Lê a luminosidade (em lux) via I2C do BH1750.

- Converte esse valor em um ângulo para o servo motor.

- Exibe a leitura de lux ou mensagem de "Lux muito baixo" no display OLED.

## 🔄 Lógica de Controle
``` bash
if (lux > 10) {
    int angle = (int)(lux + 10); // Converte lux em ângulo
    servo_set_angle(angle);      // Move servo motor
    txt_display("Lux: <valor>"); // Mostra valor no display
} else {
    servo_set_angle(0);          // Servo em 0° se luz for fraca
    txt_display("Lux muito baixo");
}
```


## 📈 Exemplo de Saída Serial
``` bash
Lux: 8.34
Lux: 12.67
Lux: 29.01
```

E no display OLED:
``` bash
Lux: 29.01
```
ou 

``` bash
Lux muito baixo
```

## ✅ Resultados Esperados
- Funcionalidade	Resultado Esperado
- Leitura de Luminosidade	Exibição do valor de lux atualizado no display a cada ~200ms
- Controle de Servo	Posição do servo variando proporcionalmente ao valor de lux
- Exibição em Display OLED	Mensagem “Lux muito baixo” se < 10 lux, ou valor numérico se >= 10 lux
- Estabilidade do Sistema	Loop contínuo, sem travamentos, com reatividade rápida a mudanças de luz

## 👨‍💻 Autor
Antonio José Mota Ferreira Brandão
Projeto desenvolvido para aprendizado e demonstração de sensores e atuadores com o Raspberry Pi Pico.
