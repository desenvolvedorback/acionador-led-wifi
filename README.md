# 🌐 ESP32 Web Server IoT - Controle de LED Remoto

Este é um projeto de estudo de Internet das Coisas (IoT) desenvolvido para a placa **ESP32**. O objetivo é criar um servidor web básico hospedado nativamente no microcontrolador, permitindo que qualquer dispositivo (como um smartphone ou computador) conectado à mesma rede Wi-Fi controle o estado de um LED físico por meio de uma interface gráfica HTML simples.

---

## 📌 Demonstração da Interface
A interface web gerada pelo ESP32 é responsiva e conta com dois botões intuitivos:
* **LIGAR:** Envia um sinal lógico alto (`HIGH`) para a porta GPIO 2, acendendo o LED.
* **DESLIGAR:** Envia um sinal lógico baixo (`LOW`) para a porta GPIO 2, apagando o LED.

---

## 🛠️ Componentes Necessários

Para montar este projeto de forma física, você precisará dos seguintes componentes:

| Quantidade | Componente | Descrição / Observação |
| :---: | :--- | :--- |
| **1** | Placa ESP32 | Modelo padrão de 30 ou 38 pinos (ex: ESP32 Dev Module, NodeMCU-32S) |
| **1** | LED | Qualquer cor (Atenção à polaridade) |
| **1** | Resistor | **220 Ω** (Faixas: Vermelho, Vermelho, Marrom). *Crucial para não queimar o LED sob 3.3V.* |
| **1** | Protoboard | Matriz de contatos para fixação dos componentes |
| **-** | Cabos Jumpers | Fios de conexão (Macho-Macho ou Macho-Fêmea dependendo da montagem) |

---

## 🔌 Montagem Física (Hardware)

> ⚠️ **Atenção:** O ESP32 trabalha com nível lógico de **3.3V** em seus pinos GPIO (diferente dos 5V do Arduino Uno). O uso do resistor correto de 220 Ω protege tanto o LED quanto a integridade do pino da placa.

### Passo a Passo da Conexão:
1.  **Posicione o ESP32** no protoboard de forma centralizada, deixando o vão central separar os pinos de cada lado para permitir o acesso livre às linhas laterais.
2.  **Identifique os terminais do LED:** A perna mais longa é o **Anodo (Positivo)** e a perna mais curta (com o chanfro achatado na cápsula) é o **Catodo (Negativo)**.
3.  Conecte a perna longa (**Anodo**) em um furo isolado do protoboard.
4.  Conecte a perna curta (**Catodo**) diretamente ao pino **GND** do ESP32 (ou use um jumper para interligá-los).
5.  Insira o **resistor em série**: conecte uma extremidade dele na mesma linha da perna longa (Anodo) do LED, e a outra extremidade em uma linha vazia do protoboard.
6.  Utilize um cabo jumper para conectar a extremidade livre do resistor ao pino **GPIO 2** do ESP32.
    * *Nota: A maioria das placas ESP32 possui um LED azul integrado de fábrica conectado internamente a este mesmo pino GPIO 2.*

---

## 💻 Configuração do Ambiente de Desenvolvimento (Arduino IDE)

Este projeto utiliza recursos nativos do ecossistema Expressif para o ESP32, dispensando a instalação de bibliotecas externas de terceiros. No entanto, é necessário preparar a Arduino IDE para reconhecer a placa.

### Passo 1: Adicionar a URL do ESP32
1. Abra a **Arduino IDE**.
2. Vá em **Arquivo > Preferências** (Windows) ou **Arduino IDE > Settings/Preferences** (Mac).
3. No campo **URLs Adicionais para Gerenciador de Placas**, adicione o seguinte endereço:

4. Clique em OK.

Passo 2: Instalar o Pacote da Placa
No menu lateral esquerdo da IDE, clique no ícone do Gerenciador de Placas (ou acesse Ferramentas > Placa > Gerenciador de Placas...).

Na barra de pesquisa, digite ESP32 e localize o pacote mantido pela Espressif Systems.

Clique em Instalar (recomenda-se utilizar a versão estável mais recente).

Passo 3: Seleção e Carregamento
Vá em Ferramentas > Placa > ESP32 e selecione o modelo correspondente (ex: ESP32 Dev Module).

Conecte sua placa ao computador através de um cabo USB de dados de boa qualidade.

Selecione a porta de comunicação correspondente em Ferramentas > Porta.

Copie o código fonte fornecido 'esp32.ino', substitua as credenciais do Wi-Fi e clique no botão Carregar (Seta para a direita).


🕹️ Como Testar e Operar
Abra o Monitor Serial na Arduino IDE e defina o Baud Rate para 115200.

Carregue o código na placa (lembre de manter pressionado o botão BOOT/IO0 se a gravação travar no início).

Após o upload, caso a placa não reinicie sozinha, pressione momentaneamente o botão físico EN/RST do ESP32.

Aguarde a mensagem de confirmação de rede aparecer no monitor:

Plaintext
Wi-Fi conectado!
IP do ESP32: 192.168.X.X
Certifique-se de que o seu celular ou computador esteja conectado exatamente na mesma rede Wi-Fi (TESTEIOT).

Abra qualquer navegador moderno de internet e insira o endereço IP listado no Monitor Serial (Exemplo: http://192.168.1.50).

Pronto! Interaja com os botões LIGAR e DESLIGAR na tela para acionar remotamente o circuito.

