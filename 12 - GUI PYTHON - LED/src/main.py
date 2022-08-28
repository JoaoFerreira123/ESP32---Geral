from tkinter import Tk, Button
import serial

w = Tk()
w.minsize(400, 200)
w.title('Controle de LED')

esp32 = serial.Serial('COM4', 9600)



def liga():
    esp32.write('1'.encode())

def desliga():
    esp32.write('0'.encode())
    

botao1 = Button(text='Ligar',command=liga, height=20, width=40, font=('Arial', 10))
botao1.grid(row=0, column= 0)
botao2 = Button(text='Desligar', command=desliga, height=20, width=40, font=('Arial', 10))
botao2.grid(row=0,column= 1)

print(botao1.config())

w.mainloop()