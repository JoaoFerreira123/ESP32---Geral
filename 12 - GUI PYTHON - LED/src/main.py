from tkinter import Scale, Tk, Button
import serial

w = Tk()
w.minsize(400, 200)
w.title('Controle de LED')

esp32 = serial.Serial('COM4', 115200)



def liga():
    esp32.write('255'.encode())
    print('255')

def desliga():
    esp32.write('0'.encode())
    print('0')

def pwm(valor):
    valor = valor+"/"
    esp32.write(valor.encode())


botao1 = Button(text='Ligar',command=liga, height=20, width=40, font=('Arial', 10))
botao1.grid(row=0, column= 0)
botao2 = Button(text='Desligar', command=desliga, height=20, width=40, font=('Arial', 10))
botao2.grid(row=0,column= 3)


escala = Scale(from_=255, to=0, command=pwm, showvalue=False, length=200, width=30)
escala.grid(row=0, column=2)


w.mainloop()