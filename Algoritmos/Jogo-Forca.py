forca = ['''
   +---------+
   |         |
             |
             |
             |
             |
             |
             |
             |
 ============+ ''','''
   +---------+
   |         |
   O         |
             |
             |
             |
             |
             |
             |
 ============+ ''', '''
   +---------+
   |         |
   O         |
  /          |
             |
             |
             |
             |
             |
 ============+ ''', '''
   +---------+
   |         |
   O         |
  / \        |
             |
             |
             |
             |
 ============+ ''', '''
   +---------+
   |         |
   O         |
  /|\        |
             |
             |
             |
             |
 ============+ ''', '''
   +---------+
   |         |
   O         |
  /|\        |
  /          |
             |
             |
             |
 ============+ ''', '''
   +---------+
   |         |
   O         |
  /|\        |
  / \        |
             |
             |
 Cuidado!    |
 ============+ ''', '''
   +---------+
   |         |
  O          |
  /|\        |
  / |        |
             |
             |
 GAME OVER!  |
 ============+ ''']

import urllib.request
import random
import string
pagina = urllib.request.urlopen('http://www.ime.usp.br/~pf/algoritmos/dicios/br').read().decode('iso8859')
palavras = pagina.upper().split()
chances = 0
certas = ''
erradas = ''
sorteada = ''
play = True


def sorteia():
    global sorteada
    sorteada = palavras[random.randint(0,len(palavras))]
    return sorteada

def desenha():
    global chances
    return forca[chances]

def again():
    global play
    global chances
    global certas
    global erradas
    jogar = input("\nJogar novamente? Sim / Não: ")
    if jogar[0].lower() == 's':
        play = True
        certas = ''
        erradas = ''
        chances = 0
        return game()
    else:
        play = False
        return print('\nFim de jogo')

def win():
    global sorteada
    global certas
    for x in sorteada:
        if x not in certas:
            win = False
            break
        else:
            win = True
    return win

def exibir():
    revelando = ''
    global sorteada
    global certas
    for x in sorteada:
        if x in certas:
            revelando += x
        else:
            revelando += '_ '
    return '\nPalavra %d letras: '  %(len(sorteada)) + revelando 

def chute():
    global sorteada
    global certas
    global erradas
    global chances
        
    letra = input('\nChute uma letra: ').upper()
    
    if letra != '':
        if (letra in string.punctuation) or (letra in '0123456789'):
            print('\nDIGITE APENAS LETRAS!')
            return chute()
        elif len(letra) != 1:
            print('\nDIGITE UMA LETRA!')
            return chute()
        elif letra in sorteada:
            if letra not in certas:
                certas += letra
            else:
                print('\nLETRA JÁ DIGITADA')
                return chute()                 
        elif letra not in erradas:
            erradas += letra
            chances += 1
        else:
            print('\nLETRA JÁ DIGITADA')
            return chute()
    else:
        return chute()
    
def game():
    global sorteada
    global certas
    global erradas
    global chances
    global play
    sort = True
    
    while play == True:
        if sort == True:
            sorteada = sorteia()
            sort = False
        while chances < 7:
            print ('\n', desenha())
            print (exibir())
            if len(erradas) > 0:
                print ('Erradas: ' + erradas)
            chute()
            if win() == True:
                print('PARABÉNS, você acertou!')
                print (exibir(), '\n')
                play = False
                break
                
        if chances == 7:
            print (desenha(), '\n\nPalavra: %s \n\nGame Over!' %sorteada)
            break
    again()

game()
