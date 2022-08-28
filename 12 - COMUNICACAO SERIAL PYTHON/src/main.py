import serial

esp32 = serial.Serial('COM4', 9600)

while True:
    comando = input('Digite L para ligar o LED e D para desligar o Led: ').upper()
    if comando == 'L':
        esp32.write('L'.encode())
    if comando == 'D':
        esp32.write('D'.encode())

# assim que conectar o ESP no USB já tem que rodar o .PY
# se rodar antes de ligar ele não funciona
# se demorar pra rodar ele não permite acesso a porta