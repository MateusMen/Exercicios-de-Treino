import math
exit = bool(0)
while exit == 0:
    num1 = float(input("Primeiro Numero\n"))
    select = str(input("Operador (+,-,*,/,**,sq)\n")).strip()
    if select == '+':
        num2 = float(input("Segundo Numero\n"))
        print("O resultado é", (num1+num2))
        exitimput = str(input("\n Fazer outra equação y/n?\n")).strip()
        if exitimput == 'n':
            exit = 1
    elif select == '-':
        num2 = float(input("Segundo Numero\n"))
        print("O resultado é", (num1-num2))
        exitimput = str(input("\n Fazer outra equação y/n?\n")).strip()
        if exitimput == 'n':
            exit = 1
    elif select == '*':
        num2 = float(input("Segundo Numero\n"))
        print("O resultado é", (num1*num2))
        exitimput = str(input("\n Fazer outra equação y/n?\n")).strip()
        if exitimput == 'n':
            exit = 1
    elif select == '/':
        num2 = float(input("Segundo Numero\n"))
        print("O resultado é", (num1//num2))
        exitimput = str(input("\n Fazer outra equação y/n?\n")).strip()
        if exitimput == 'n':
            exit = 1
    elif select == '**':
        num2 = float(input("Segundo Numero\n"))
        print("O resultado é", (num1**num2))
        exitimput = str(input("\n Fazer outra equação y/n?\n")).strip()
        if exitimput == 'n':
            exit = 1
    elif select == 'sq':
        print("O resultado é", (math.sqrt(num1)))
        exitimput = str(input("\n Fazer outra equação y/n?\n")).strip()
        if exitimput == 'n':
            exit = 1
    else:
        print("operação invalida\n")