import pandas as pd
import matplotlib.pyplot as plt
from scipy.interpolate import UnivariateSpline


#Mensagem explicativa
def mensagem_geral():
    print("Nos temos os seguintes dataset para serem visualizados:")
    print("\t1 - Soma dos Pares O(n^2)\n\t2 - Elemento Mais Frequente O(n^2)\n\t3 - Substrings Únicas O(n^3)")
    print("\t4 - Cruzamento de Listas O(n)\n\t5 - Multiplicação de Matrizes O(n^3)\n\t6 - N-ésimo Elemento O(n)")
    print("\t7 - Sequência Crescente O(n)\n\t8 - Permutações de Strings O(n!)\n\t9 - Caminho em Matriz O(n)")
    print("\t10 - Divisores de um Número O(n)")
    print("Digite o respectivo numero")
    print("Para ver essa mensagem denovo digite h ou H")
    print("Para sair do programa digite 'q', 'Q', 'exit' ou 'Exit'")
    
print("\n\n\n\t\tGraficos da Lista Big O\n\n\n")
print("Esse programa visualiza os gráficos do dados de\ntestes de execução dos exercicios da lista Big O\n")
mensagem_geral()

#Loop de interface com o usuario
while(True):
    programa = input("Digite o número do exercício ou ação: ")
    
    if (programa == 'q') or (programa == 'Q') or (programa == 'exit') or (programa == 'Exit'):
        break
    elif (programa == 'h') or (programa == 'H') or (programa == 'help') or (programa == 'Help'):
        mensagem_geral()
    else:
        df = pd.read_csv(f'dados dos exercicios/Dados_{programa}.csv', names=['Input Size', 'Execution Time'])

        # Acessando as colunas
        input_sizes = df['Input Size'].tolist()
        execution_times = df['Execution Time'].tolist()

        spline = UnivariateSpline(input_sizes, execution_times, s=100000000)


        # Mostra o grafico
        plt.style.use('seaborn-v0_8-darkgrid')
        plt.figure(figsize=(14, 7))
        plt.scatter(input_sizes, execution_times, s=10, color='teal', alpha=0.5, label='Dados Originais')
        plt.plot(input_sizes, spline(input_sizes), color='red', label='Linha de Tendência Spline', linewidth=2)
        plt.xlabel("Tamanho do Input",fontsize=14)
        plt.ylabel("Tempo de Execução (s)",fontsize=14)
        plt.title("Analise de Tempo de Execução", fontsize=16)
        plt.grid(True, which="both", linestyle="--", linewidth=0.5, color='gray')
        plt.xticks(fontsize=12)
        plt.yticks(fontsize=12)
        plt.legend(loc='upper left')
        plt.tight_layout()
        plt.show()